/*
 * Passangers.c
 *
 *  Created on: 29 abr. 2022
 *      Author: flor_
 */

#include "Passangers.h"
 int idAutomatico = 1000;
//int ePasajero_ObtenerIdUnico(void);
int ePasajero_ObtenerIdUnico() {
	return idAutomatico++;
}

/**
 *
 */
void ImprimirMenu(void)
{
	printf("\n\n\tMENU\n1) Altas\n2) Modificar\n3) Baja\n4) Informar\n5) Harcodeo de datos.\n\n");
}

/**
 *
 * @param listaDePasajero
 */
void ePasajero_imprimirUno(ePasajero listaDePasajero) {
	printf("ID: %d\n",listaDePasajero.id);
	printf("Nombre y Apellido: %s %s\n",listaDePasajero.name, listaDePasajero.lastname);
	printf("Importe del pasaje abonado $%.1f\n",listaDePasajero.price);
	printf("Codigo de vuelo %s\n",listaDePasajero.flycode);
	printf("Cliente nivel: %d\n",listaDePasajero.typePassanger);
	printf("Estado del Vuelo: %d\n\n",listaDePasajero.statusFlight);
	printf("isEmpty = %d\n\n",listaDePasajero.isEmpty);
}

/**
 *
 * @param listaDePasajero
 * @param tam
 * @param estado
 * @return
 */
int ePasajero_imprimirTodos(ePasajero listaDePasajero[], int tam, int estado) {
	int rtn = 1;
	int i;

	if (listaDePasajero != NULL) {
		if (tam > 0) {
			//ESTA TODO BIEN
			for (i = 0; i < tam; i++) {
				if (listaDePasajero[i].isEmpty == estado) {
					ePasajero_imprimirUno(listaDePasajero[i]);
				}
			}
		} else {
			rtn = -2;
		}
	} else {
		rtn = -1;
	}

	return rtn;
}

/**
 *
 * @param listaDePasajero
 * @param tam
 * @return
 */
int ePasajero_Inicializar(ePasajero listaDePasajero[], int tam) {
	int rtn = 0;
	int i;

	if (listaDePasajero != NULL) {
		if (tam > 0) {
			for (i = 0; i < tam; i++) {
				listaDePasajero[i].isEmpty = LIBRE;//inicializa el array y a todos los deja en estado LIBRE
			}
		} else {
			rtn = -2;
		}
	} else {
		rtn = -1;
	}

	return rtn;
}

/**
 *
 * @param listaDePasajero
 * @param tam
 * @return
 */
int ePasajero_BuscarEspacioLibre(ePasajero listaDePasajero[], int tam) {
	int rtn = 0;
	int flag = 0;
	int i;

	if (listaDePasajero != NULL) {
		if (tam > 0) {
			for (i = 0; i < tam; i++) {
				if (listaDePasajero[i].isEmpty == LIBRE) {
					flag = 1;
					rtn = i;//devuelve el numero de indice que estaa libre
					break;//al obtener un indice libre, corta el bucle
				}
			}

			if (flag == 0) {
				rtn = -1;
			}
		} else {
			rtn = -2;
		}
	} else {
		rtn = -3;
	}

	return rtn;
}

/**
 *
 * @param listaDePasajero
 * @param tam
 * @return
 */
int ePasajero_Alta(ePasajero listaDePasajero[], int tam) {
	int rtn = 1;
	int indexLibre;
	ePasajero auxiliarPasajero;

	//VA A RETORNAR UN INDEX LIBRE SI ENCONTRO O -1 SI NO LO ENCONTRO.
	indexLibre = ePasajero_BuscarEspacioLibre(listaDePasajero, tam);

	if (listaDePasajero != NULL)
	{
		if (tam > 0)
		{
			if (indexLibre >= 0)
			{
				if(rtn==1)
				{
				//CARGO DATOS NO GENERICOS
				if(get_name(auxiliarPasajero.name, 51, "ingrese el nombre del pasajero", "Error, reintente \n", 2)  ==0 &&
						get_name(auxiliarPasajero.lastname, 51, "Ingrese  apellido del Pasajero", "Error, vuelva a ingresarlo\n", 2)==0)
				{
					strcpy(auxiliarPasajero.name,strlwr(auxiliarPasajero.name));
					auxiliarPasajero.name[0]=toupper(auxiliarPasajero.name[0]);
					strcpy(auxiliarPasajero.lastname,strlwr(auxiliarPasajero.lastname));
					auxiliarPasajero.lastname[0]=toupper(auxiliarPasajero.lastname[0]);
					rtn=LIBRE;
				}
				else{
					rtn=OCUPADO;
				}
				if(utn_getCadena(auxiliarPasajero.flycode, 10, "Codigo de Vuelo\n", "Error.\n", 2)==0)
				{
					strcpy(auxiliarPasajero.flycode,strlwr(auxiliarPasajero.flycode));
					rtn=LIBRE;
				}
				else{
					rtn=OCUPADO;
				}
				auxiliarPasajero.price=get_float("Ingrese el valor del pasaje abonado", "ERROR.");
				auxiliarPasajero.typePassanger=utn_getNumeroResultado("Tipo de pasajero\n1. Economico. \n2. Premium. \n3. Ejecutiva. \n4. Primera Clase \n", "Error", 1, 4, 2);
				auxiliarPasajero.statusFlight=utn_getNumeroResultado("Ingrese el estado del Vuelo \n0. Cancelado.\n1. Hora de despegue asignada.\n2. En vuelo.\n3. Aterrizado.\n", "Error\n", 0, 3, 2);
				if(auxiliarPasajero.statusFlight>=0 && auxiliarPasajero.typePassanger>=1)
				{
					rtn=LIBRE;
				}
				else{
					rtn=OCUPADO;
				}


				// FALTA
				//CARGAR LAS FUNCIONES
				//PARA LAS DEMAS VARIABLES

				if(rtn==LIBRE)
				{
					auxiliarPasajero.id = ePasajero_ObtenerIdUnico();//SI ESTA TODO BIEN - LE DOY UN ID UNICO
					auxiliarPasajero.isEmpty = OCUPADO;//CAMBIO ESTADO A OCUPADO
					listaDePasajero[indexLibre] = auxiliarPasajero;//COPIA AUXILIAR EN ARRAY EN POSICION OBTENIDA LIBRE
					rtn = indexLibre;
					puts("CARGA EXITOSA!");

				}
				else{
					puts("FALLO LA CARGA DE DATOS.\nLOS DATOS INGRESADOS NO FUERON GUARDADOS. REINTENTE\n");
				}


			}
		else {
			// -3 ARRAY LLENO
			rtn = -3;
		}


		} else {
			// -2 LEN MAL DEFINIDO
			rtn = -2;
		}
		}
	} else {
		//-1 ARRAY NULO
		rtn = -1;
	}

	return rtn;
}

/**
 *
 * @param listaDePasajeros
 * @param tam
 * @return
 */
int ePasajero_BuscarIndexPorId(ePasajero listaDePasajeros[], int tam) {
	int rtn = 0;
	int flag = 0;
	int i;
	int buscarID;

	if (listaDePasajeros != NULL) {
		if (tam > 0) {
			//ESTA OK

			//MUESTRO TODOS - Le muestro al usuario todos los dados de alta para que elija cual ID dar de baja
			ePasajero_imprimirTodos(listaDePasajeros, tam, OCUPADO);

			//PEDIR UN ID
			buscarID = utn_getNumeroResultado("\nIngrese ID", "ID incorrecto? vuelva  aintentarlo", 1000, 3000, 2);

			for (i = 0; i < tam; i++) {
				if (listaDePasajeros[i].isEmpty == OCUPADO) {
					if (listaDePasajeros[i].id == buscarID) {
						flag = 1;
						rtn = i; //retorno index del ID que estoy buscando
						break;
					}
				}
			}

			if (flag == 0) {
				rtn = -1;
			}
		} else {
			rtn = -2;
		}
	} else {
		rtn = -3;
	}

	return rtn;
}

/**
 *
 * @param listaDePasajeros
 * @param tam
 * @return
 */
int ePasajero_Modificar(ePasajero listaDePasajeros[], int tam) {
	int rtn = 0;
	int indexModificacion;
	ePasajero auxiliarPasajero;

	if (listaDePasajeros != NULL) {
		if (tam > 0) {
			//BUSCA UN INDEX POR ID - RETORNA -1 SI NO ENCUENTRA EL ID EN EL ARRAY
			indexModificacion = ePasajero_BuscarIndexPorId(listaDePasajeros,
					tam);
			if (indexModificacion < 0) {
				//HUBO UN ERROR BUSCANDO EL INDEX
				rtn = -1;
			} else {
				auxiliarPasajero = listaDePasajeros[indexModificacion];
				//MODIFICAR UN Pasajero
				auxiliarPasajero = ePasajero_ModificarUnPasajero(auxiliarPasajero);
				//EXTRA - PREGUNTO SI DESEA CONFIRMAR - REEMPLAZO LA COPIA POR EL ORIGINAL
				listaDePasajeros[indexModificacion] = auxiliarPasajero;
			}

		} else {
			// LEN MAL DEFINIDO
			rtn = -2;
		}
	} else {
		// ARRAY NULO
		rtn = -3;
	}

	return rtn;
}




/**
 *
 * @param pasajero
 * @return
 */

ePasajero ePasajero_ModificarUnPasajero(ePasajero pasajero) {

	int opcion;
	utn_getNumero(&opcion, "\nIngrese la opcion de lo que desea modificar\n1. Nombre\n2. Apellido\n3.Categoria del Cliente\n4.Estado del Vuelo\5.Codigo del vuelo\n6.Precion\n7. Todos los datos\n0.CANCELAR Modificacion", "Opcion no habilitada", 0, 7, 2);

	//While - para cargar cuantos datos quiera el usuario

	switch (opcion) {
	case 1:
		get_name(pasajero.name, 51, "\nRe-ingrese el nombre", "error\n", 2);
		break;
	case 2:
		get_name(pasajero.lastname, 51, "\nRe-ingrese el apellido", "error\n", 2);
		break;
	case 3:
		utn_getNumero(pasajero.typePassanger, "\nRe-ingrese la categoria de cliente del pasajero", "Error", 1, 4, 2);
		break;
	case 4:
		utn_getNumero(pasajero.statusFlight, "\nRe-ingrese el estado del vuelo", "Error", 0, 3, 2);
		break;
	case 5:
		utn_getCadena(pasajero.flycode, 10, "\nRe-ingrese el codigo de vuelo", "error\n", 2);
		break;
	case 6:
		pasajero.price= get_float("Re-ingrese el valor del pasaje abonado", "ERROR.");

		break;
	case 7:
		utn_getCadena(pasajero.name, 51, "\nRe-ingrese el nombre", "error\n", 2);
		utn_getCadena(pasajero.lastname, 51, "\nRe-ingrese el apellido", "error\n", 2);
		utn_getNumero(pasajero.typePassanger, "\nRe-ingrese la categoria de cliente del pasajero", "Error", 1, 4, 2);
		utn_getNumero(pasajero.statusFlight, "\nRe-ingrese el estado del vuelo", "Error", 0, 3, 2);
		utn_getCadena(pasajero.flycode, 10, "\nRe-ingrese el codigo de vuelo", "error\n", 2);
		pasajero.price=get_float("Re-ingrese el valor del pasaje abonado", "ERROR.");
		break;
	default:
		puts("Opcion ingresada invalida!\n\n");
		break;
	}

	return pasajero;
}


/**
 *
 * @param listaDePasajeros
 * @param tam
 * @return
 */
int ePasajero_Baja(ePasajero listaDePasajeros[], int tam) {
	int rtn = 0;
	int indexBaja;
	int opcion;

	if (listaDePasajeros != NULL) {
		if (tam > 0) {

			//BUSCA UN INDEX POR ID - RETORNA -1 SI NO ENCUENTRA EL ID EN EL ARRAY
			indexBaja = ePasajero_BuscarIndexPorId(listaDePasajeros, tam);
			if (indexBaja < 0) {
				//HUBO UN ERROR BUSCANDO EL INDEX
				rtn = -1;
			} else {
				//SI ENCONTRO ME QUEDO CON EL INDEX Y CAMBIO EL ESTADO
				//EXTRA - PREGUNTO SI DESEA DAR DE BAJA - ME LO PUEDO GUARDAR EN UN AUX Y MOSTRARLO PREVIO A ELIMINAR

				utn_getNumero(&opcion, "Si desea continuar con la baja, ingrese 1", "Error.\n", 1, 1, 2);
				if(opcion==1)
				{
					listaDePasajeros[indexBaja].isEmpty = BAJA;
				}
				else{
					puts("Ha cancelado la baja\n");
				}
			}

		} else {
			// LEN MAL DEFINIDO
			rtn = -2;
		}
	} else {
		// ARRAY NULO
		rtn = -3;
	}

	return rtn;
}

/**
 *
 * @param listaDePersonal
 * @param tam
 * @return
 */
float obtenerPromedioArray(ePasajero listaDePersonal[], int tam)
{
	float retorno =-1;
	int contador;
	float acumulador;
	float aux;
	acumulador = 0;
	contador = 0;


	if(listaDePersonal != NULL )
	{
		for(int i=0;i<tam;i++)
		{
			if(listaDePersonal[i].isEmpty==1)
			{
				acumulador=acumulador + listaDePersonal[i].price;
				contador++;
				//printf("%d\t\n",contador);
				//printf("acumulador %.1f",acumulador);
			}
		}
		if(acumulador!=0 && contador >0)
		{
			printf("\nEl total de los pasajes vendidos es de %.2f",acumulador);
			retorno=acumulador;
			aux=acumulador/contador;
			if(aux>0)
			{
				retorno=aux;
			}
		}
	}

	return retorno;
}

/**
 *
 * @param listaDePersonal
 * @param tam
 * @param promedio
 * @return
 */
int mayorQueElPromedio(ePasajero listaDePersonal[], int tam, float promedio)
{
	int rtn = -1;
	int contadorMayor;

	contadorMayor=0;

	if(listaDePersonal != NULL && tam>0 && promedio!=0)
	{
		for(int i=0; i<tam;i++)
		{
			if(listaDePersonal->isEmpty==OCUPADO)
			{

				if(listaDePersonal->price > promedio)
				{
				contadorMayor++;
				}

			}
		}
	}
	if(contadorMayor>0)
	{
		printf("\nCantidad de pasajeros que abonaron por encima del promedio son %d\t\n",contadorMayor);
	}
	return rtn;
}

/**
 *
 * @param array
 * @param TAM
 * @return
 */
int ordenarPorDosCriterios(ePasajero array[], int TAM)
{
	int respuesta = -1;
	int banderaSwap;
	ePasajero buffer;
	if(array != NULL)
	{
		if(TAM > 0)
		{
			do
			{
				banderaSwap=0;
				for(int i=0;i<TAM;i++)
				{
					if(array[i].isEmpty==OCUPADO)
					{
						if(strncmp(array[i].lastname, array[i+1].lastname, MAX_CHARS_CADENAS) >0 ||
								(strncmp(array[i].lastname, array[i+1].lastname, MAX_CHARS_CADENAS) ==0&& array[i].typePassanger < array[i+1].typePassanger))
						{
							banderaSwap=1;
							buffer = array[i];
							array[i]=array[i+1];
							array[i+1]=buffer;
							respuesta =0;
						}
					}

				}
				TAM--;
			}while(banderaSwap);
		}
	}
	return respuesta;
}

/**
 *
 * @param array
 * @param TAM
 */
void imprimirListadoOrdenado(ePasajero array[], int TAM)
{
	if (array != NULL) {
		if (TAM > 0) {
			//ESTA TODO BIEN
			for (int i = 0; i < TAM; i++) {
				if (array[i].isEmpty == OCUPADO) {
					printf(" %s %s\t",array[i].lastname, array[i].name);
					printf("Cliente nivel: %d\n",array[i].typePassanger);
				}
			}
}
	}
}

/**
 *@brief ordenar el array por tipo
 * @param array recibe array de pasajeros
 * @param TAM
 * @return
 */
int ordenarArraycase4_3(ePasajero array[], int TAM)
{
	int respuesta = -1;
	int banderaSwap;
	ePasajero buffer;
	if(array != NULL)
	{
		if(TAM > 0)
		{
			do
			{
				banderaSwap=0;
				for(int i=0;i<TAM;i++)
				{
					if(array[i].isEmpty==OCUPADO)
					{
						if(strncmp(array[i].flycode, array[i+1].flycode, MAX_CHARS_CADENAS) >0 ||
								(strncmp(array[i].flycode, array[i+1].flycode, MAX_CHARS_CADENAS) ==0 && array[i].typePassanger < array[i+1].typePassanger))
						{
							banderaSwap=1;
							buffer = array[i];
							array[i]=array[i+1];
							array[i+1]=buffer;
							respuesta =0;
						}
					}

				}
				TAM--;
			}while(banderaSwap);
		}
	}
	return respuesta;
}

/**
 *
 * @param array
 * @param TAM
 * @param pos
 * @param name
 * @param lastname
 * @param flycode
 * @param typePassanger
 * @param statusFlight
 * @param isEmpty
 * @param price
 * @return
 */
int cargaForzada(ePasajero array[], int TAM,int pos, char name[], char lastname[], char flycode[], int typePassanger, int statusFlight, int isEmpty, float price)
{
	int retorno = -1;

	if(pos >= 0 && pos <= TAM)
	{


		array[pos].id = ePasajero_ObtenerIdUnico();
		strncpy(array[pos].name, name, 51);
		strncpy(array[pos].lastname, lastname, 51);
		strncpy(array[pos].flycode, flycode, 10);
		array[pos].typePassanger= typePassanger;
		array[pos].statusFlight=statusFlight;
		array[pos].price=price;
		array[pos].isEmpty = OCUPADO;
		retorno = 0;
	}
	return retorno;
}
