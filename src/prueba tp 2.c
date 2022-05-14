/*
 ============================================================================
 Name        : prueba.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include "Passangers.h"
#define QTY_PASAJEROS 2000

int main(void) {
	setbuf(stdout, NULL);
	ePasajero Pasajero[QTY_PASAJEROS];
	ePasajero_Inicializar(Pasajero, QTY_PASAJEROS);
	int opcion;
	int rAlta;
	int rIdDAModificar;
	int banderaCase1;
	int banderacase2;
	int rDeBaja;
	int opcionCase4;
	float rPromedioPrecios;
	int ContadorPreciosMayoresPromedio;
	banderaCase1=0;
	banderacase2=0;

	do{
		ImprimirMenu();
		utn_getNumero(&opcion, "ingrese opcion \n", "Error\n", 0, 5, 2);

		switch(opcion)
		{
		case 1:
			rAlta=ePasajero_Alta(Pasajero, QTY_PASAJEROS);
			if(rAlta>=0)
			{
				puts("\nPuede continuar trabajando\n");
			}
			else {
				if (rAlta == -3) {
					puts("LISTA LLENA!");
				} else {
					puts("FALLA EN LA CARGA!");
				}
			}
			ePasajero_imprimirTodos(Pasajero, QTY_PASAJEROS, OCUPADO);
			for(int i=0;i<QTY_PASAJEROS;i++)
			{
				if(Pasajero->id>=1000)
				{
					banderaCase1=1;
					break;
				}
			}
			break;

		case 2:
			for(int i=0;i<QTY_PASAJEROS;i++)
			{
				if(Pasajero->id>=1000)
				{
					banderacase2=1;
					puts("\n\tUd. puede hacer cambios de los registros ingresados\n");
					rIdDAModificar = ePasajero_Modificar(Pasajero, QTY_PASAJEROS);
					break;
					if (rIdDAModificar == 0) {
						puts("MODIFICACION EXITOSA");
						break;
						//eProducto_imprimirTodos(Pasajero, QTY_PASAJEROS, OCUPADO);
					} else {
						puts("HUBO UN ERROR AL INTENTAR MODIFICAR");
						break;
					}
				}
			}
			if(banderacase2==0)
			{
				puts("\nNO PUEDE MODIFICAR, NO TIENE CARGADO NINGUN RESGISTRO");
			}
			break;

		case 3:
			if(banderaCase1==1)
			{
				rDeBaja = ePasajero_Baja(Pasajero, QTY_PASAJEROS);
				if (rDeBaja == 0) {
					puts("\nPRODUCTO DADO DE BAJA");
					ePasajero_imprimirTodos(Pasajero, QTY_PASAJEROS, BAJA);
					break;
				} else {
					puts("\nHUBO UN ERROR AL DAR DE BAJA");
				}
			}
			puts("NO PUEDE DAR DE BAJA, LO QUE NUNCA DIO DE ALTA");
			break;
		case 4:
			if(banderaCase1==1)
			{
			utn_getNumero(&opcionCase4, "\tINFORMAR\n1. Listado de pasajeros ordenados alfabeticamente por apellido.\n2.Total y promedio de los precios de los pasajes\n"
					"3.Cuantos pasajeros superan el precio promedio.\n4.Litsado de los pasajeros por Codigo de Vuelo y Estado de Vuelo 'ACTIVO'.", "ERROR", 1, 3, 2);
			switch(opcionCase4)// OPCIONES DE LO QUE HAY QUE INFORMAR
			{
			case 1:
				if(ordenarPorDosCriterios(Pasajero, QTY_PASAJEROS)==0)
				{
					puts("\tLISTADO ORDENADO ALFABETICAMENTE");
					imprimirListadoOrdenado(Pasajero, QTY_PASAJEROS);
				}
				break;
			case 2:
				rPromedioPrecios= obtenerPromedioArray(Pasajero, QTY_PASAJEROS);
				ContadorPreciosMayoresPromedio = mayorQueElPromedio(Pasajero, QTY_PASAJEROS, rPromedioPrecios);

				if(rPromedioPrecios!= -1 )
				{
					printf("\n\nEl promedio de precios de los pasajes vendidos es $%.2f,",rPromedioPrecios);
					if(ContadorPreciosMayoresPromedio==-1)
					{
						printf(" y %i pasajeros superaron el precio promedio\n", ContadorPreciosMayoresPromedio);
					}
				}else{
					puts("Error en la acumulacion de precios");
				}
				break;
			case 3:
				if(mayorQueElPromedio(Pasajero, QTY_PASAJEROS, rPromedioPrecios)> -1)
				{
					puts("-");
				}else{
					puts("\nNingun pasajero abono por encima del promedio");
				}
				break;
			case 4:
				if(ordenarPorDosCriterios(Pasajero, QTY_PASAJEROS)==0)
				{
					imprimirListadoOrdenado(Pasajero, QTY_PASAJEROS);
				}
				break;

			}//swhit de case 4

			}//if bandera de case 4
			break;
		case 5:
			if(banderaCase1==0)
			{
				puts("\tLOS DATOS SERAN HARCODEADOS\n");
				cargaForzada(Pasajero, QTY_PASAJEROS, 0, "matias", "rivero", "AS956", 2, 0, OCUPADO, 963.52);
				cargaForzada(Pasajero, QTY_PASAJEROS, 1, "FLORENCIA", "CAUDA", "DL1106", 1, 1, OCUPADO, 586.14);
				cargaForzada(Pasajero, QTY_PASAJEROS, 2, "Martina", "PILAR", "AA369", 3, 0, OCUPADO, 759.18);
				cargaForzada(Pasajero, QTY_PASAJEROS, 3, "FACUNDO", "eSTIGARRIBIA", "VD36", 3, 3, OCUPADO, 986.36);
				cargaForzada(Pasajero, QTY_PASAJEROS, 4, "Carmen", "TREJO", "36rt6", 2, 0, OCUPADO, 789.56);
				banderaCase1=1;
				banderacase2=1;
				for(int i=0;i<QTY_PASAJEROS; i++)
				{
					if(Pasajero[i].isEmpty==OCUPADO)
					{
						ordenarNombreyApellido(Pasajero[i].name, Pasajero[i].lastname);
					}
				}
			}else{
				puts("EL HARCODEO DE DATOS NO SE PUEDE REALIZAR PORQUE YA REALIZO UNA CARGA MANUAL");
			}

			break;
		}//fin switch general


	}while(opcion!=0);

	return EXIT_SUCCESS;
}
