/*
 ============================================================================
 Name        : TrabajoPractico_01.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 RIVERO Matias
 Div. H
 */


#include "Operaciones.h"

int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	float km;
	float precioAerolineas;
	float precioLatam;
	float precioAerolineasConTD;
	float precioAerolineasConTC;
	float precioAerolineasConBT;
	float precioAerolineasPorKm;
	float precioLatamConTD;
	float precioLatamConTC;
	float precioLatamConBT;
	float precioLatamPorKm;
	float diferencia;
	int banderaOperaciones;
	int banderaCase2;
	opcion =0;
	km =0;
    banderaOperaciones = 0;
    banderaCase2 = 0;
    do{
	puts("\tMENU DE INGRESO DE DATOS DE SU VIAJE");
	printf("1. Ingresar Kilometros:\n");
	printf("2. Ingresar Precio de Vuelos: \n");
	printf("3. Calcular los costos: \n");
	printf("4. Informar los resultados\n");
	printf("5. Carga forzada de los datos\n");
	printf("6. Salir\n\n");


	opcion = getIngresoDeOpcion("Ingrese la opcion que desea realizar \n", "Ingrese opcion valida \n");

	switch(opcion)
	{
	case 1:
		km = SolicitarNumero("\nIngrese los Kilometros de su viaje:\n", "\nERROR, ingrese datos validos: \n");
		//break;

	case 2:
		if(banderaCase2==0)//utilizo una bandera para indicar que todavia no hay ningun dato cargado
		{
			if(km!=0)//la variable km esta inicializada en 0, si se le cargo algo tiene que ser distinto de 0 y por la validacion un numero positivo
			 {
				precioAerolineas = SolicitarNumero("\nIngrese el precio del viaje por AEROLINEAS\n", "Error, ingrese un precio posible\n");
				precioLatam = SolicitarNumero("\nIngrese el precio del viaje por LATAM\n", "Error, ingrese un precio posible\n");
		     }
			  else//si es igual a 0 la bandera, le va a pedir que priemro ingrese los km para poder continuar la carga
			  {
				km = SolicitarNumero("\nAntes de ingresar el valor del vuelo, debe ingresar los Km del viaje: \n", "Error, ingrese un kilometraje valido: ");
			  }
			banderaCase2 = 1;//con el cambio de la bandera, ya evito que se pueda cambiar los datos posteriormente
		}

		break;
	case 3:
		if(banderaCase2==1)//la banderaDeCase en 1 denota que los precios de los vuelo ya estan cargados, de forma manual, o forzada
		{
			if(banderaOperaciones==0)//esta bandera indica que todavia no se realizo ninguna operacion para saber los precios
			{
				precioAerolineasConTD = Descuento(precioAerolineas, 0.90);
				precioAerolineasConTC = Interes(precioAerolineas, 1.25);
				precioAerolineasConBT = PagoBitcoin(precioAerolineas, 4606954.55); //valor del Bitcoin
				precioAerolineasPorKm = Division(precioAerolineas, km, "NO SE PUEDE REALIZAR LA OPERACION");

				precioLatamConTD = Descuento(precioLatam, 0.90);
				precioLatamConTC = Interes(precioLatam, 1.25);
				precioLatamConBT = PagoBitcoin(precioLatam, 4606954.55);//valor bitcoin
				precioLatamPorKm = Division(precioLatam, km, "NO SE PUEDE REALIZAR LA OPERACION");
				diferencia = Resta(precioAerolineas, precioLatam);
				banderaOperaciones = 1;
			}

			puts("\nEl costo de los viajes ya se encuentra a su disposicion, elija la opcion 4 para visualizarlos\n\n");//indica que ya estan los precios para cada tipo de pago

		}
		else
		{
			puts("\nDebe cargar los valores de los vuelos para cada empresa\n");// si la banderaDecase2 es !=1 significa que todavia no se cargaron los valores en los precios de vuelo
		}
		break;
	case 4:
		if(banderaOperaciones==1)// solo si se realizo la carga y posterior cuentas va a imprimir por pantalla los valores
		{
			printf("\nKm´s ingresados: %.1f\n", km);

			printf("\nPrecio Aerolineas $%.2f\n", precioAerolineas);
			printf("a) Precio con descuento es $%.2f\n",precioAerolineasConTD);
			printf("b) Precio con interes es $%.2f\n",precioAerolineasConTC);
			printf("c) Precio pagando con Bitcoin es %f BTC\n",precioAerolineasConBT);
			printf("d) Precio por KM es $%.2f\n",precioAerolineasPorKm);

			printf("\nPrecio Latam $%.2f\n", precioLatam);
			printf("a) Precio con descuento es $%.2f\n",precioLatamConTD);
			printf("b) Precio con interes es $%.2f\n",precioLatamConTC);
			printf("c) Precio pagando con Bitcoin es %f BTC\n",precioLatamConBT);
			printf("d) Precio por KM es $%.2f\n\n",precioLatamPorKm);

			printf("La diferencia de precio es $%.2f\n\n",diferencia);

		}
		else
			puts("\ndebe calcular los valores en la opcion 3.\n");//si no se realizaron las operaciones para saber los precios, no va a mostar por pantalla y va a pedir que se seleccione la opcion 3 para que realice las operaciones

		break;
	case 5:
		km = 7090;
		precioAerolineas = 162965;
		precioLatam = 159339;
		banderaCase2=1;//camnio la bandera para que cuando seleccione el 3, le habilite el ingreso a las operaciones, ya que los datos necesarios ya estan cargados
		break;

	case 6:
		break;

	default:
		printf("Ingese una opcion valida:");
		break;
	}



    }while(opcion!=6);
   // printf("saliste del programa");

	return EXIT_SUCCESS;
}
