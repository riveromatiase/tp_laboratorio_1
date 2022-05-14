/*
 * Inputs.c
 *
 *  Created on: 28 abr. 2022
 *      Author: flor_
 */


#include "Inputs.h"

/**
 * brief la funcion devuelve por puntero un numero entero
 * @param pResultado es el puntero en el que se va a devolver la obtencion del numero
 * @param mensaje para mostrar por pantalla
 * @param mensajeError si falla el intento
 * @param minimo numero minimo para validar
 * @param maximo numero maximo para validar
 * @param reintentos la cantidad de veces que se puede volver a ongresar un numero
 * @return devuel -1 si no puedo obtener el numero y 0 si esta todo ok
 */
int utn_getNumero(int *pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >=0)
	{
		while(reintentos > 0)
		{
			reintentos--;
			printf("%s",mensaje);
			if(getInt(&bufferInt)==0)
			{
				if(bufferInt >= minimo && bufferInt<= maximo)
				{
					*pResultado = bufferInt;
					retorno = 0;
					break;
				}
			}
			printf("%s", mensajeError);
		}

	}
	return retorno;
}

/**
 * brief funcion para obtener un numero con coma
 * @param mensaje el texto por el cual se va a pedir el numero
 * @param mensajeError mensaje error si no se pudo obtener el numero
 * @param minimo numero minimo para validar
 * @param maximo numero maximo para validar
 * @param reintentos la cantidad de veces que se puede volver a ongresar un numero
 * @return devuelve el valor obtenido. y si devuelve -1 es que algo salio mal
 */
int utn_getNumeroResultado(char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;

	if(mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >=0)
	{
		while(reintentos > 0)
		{
			reintentos--;
			printf("%s",mensaje);
			if(getInt(&bufferInt)==0)
			{
				if(bufferInt >= minimo && bufferInt<= maximo)
				{
					retorno = bufferInt;
					break;
				}
			}
			printf("%s", mensajeError);
		}

	}
	return retorno;
}

/**
*brief para obtner un numero entero por puntero
 * @param pResultado
 * @return - si salio todo mal, y  si esta todo OK
 */
int getInt(int* pResultado)
{
	int retorno = -1;
	char buffer[64];

	if(pResultado != NULL)
	{
		if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer))
		{
			*pResultado = atoi(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

/**
 *brief para obenet una cadena mediante fgets
 * @param cadena
 * @param longitud
 * @return devuel - si no se pudo, y 0 si salio todo OK
 */
int myGets(char* cadena, int longitud)
{
	int retorno = -1;
	char bufferString[longitud];
	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(bufferString, sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno = 0;
			}
		}

	}
	return retorno;
}

/**
 * brief para saber si lo que recibe es numerico
 * @param cadena
 * @return devuelve - si no lo es, y  si esta todo ok
 */
int esNumerica(char* cadena)
{
	int i=0;
	int retorno = 1;
	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
		{
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;
}

/**
 * brief para obtener una cadena (sin importar que se ingrese)
 * @param cadena
 * @param tamano
 * @param mensaje
 * @param mensajeError
 * @param reintentos
 * @return devuelve -1 si algo fallo, y 0 si salio todo OK
 */
int utn_getCadena(char *cadena, int tamano, char* mensaje, char* mensajeError, int reintentos)
{
	int retorno = -1;
	char bufferCadena [tamano];

	if(cadena != NULL && mensaje != NULL && mensajeError != NULL && reintentos >=0)
	{
		do
		{
			printf("%s",mensaje);
			if (fgets(bufferCadena, sizeof bufferCadena, stdin) != NULL)
			{
				bufferCadena[strcspn(bufferCadena, "\n")] = 0;
				strcpy(cadena,bufferCadena);
				retorno = 0;
				break; //como salio todo bien rompo el do-while
			}
				printf("%s",mensajeError);
			    reintentos--;
		}while(reintentos>=0);
	}
	return retorno;
}

/**
 * brief para obtener un caracter por puntero
 * @param pResultado
 * @param mensaje
 * @param mensajeError
 * @param minimo
 * @param maximo
 * @param reintentos
 * @return devuelve -1 si no se pudo, y 0 si salio todo OK
 */
char utn_getChar(char *pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos)
{
	int retorno = -1;
	char buffer[2];

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >=0)
	{
		do
		{
			printf("%s",mensaje); //se pone %s porque recibe una cadena
			fflush(stdin);
			fgets(buffer,2,stdin);
			strlwr(buffer);
			if (buffer[0]>=minimo && buffer[0]<=maximo)
			{
				*pResultado = buffer[0];
				retorno = 0;
				break; //como salio todo bien rompo el do-while
			}
			printf("%s",mensajeError);
			reintentos--;

		}while(reintentos>=0);
	}
	return retorno;
}


/**
 * brief para ordenar un nombre y apeliido, dejando las todo en miniscula y solo la primer letra de cada palabra en mayuscula
 * @param nombre
 * @param apellido
 * @return -1 si no se pudo, y 0 si esta todo OK
 */
int ordenarNombreyApellido(char* nombre, char* apellido)
{
	int retorno=-1;

	strlwr(nombre);
	strlwr(apellido);//todo a minuscula        y strupr() todo a MAYUSCULA
	nombre[0]=toupper(nombre[0]);
	apellido[0] =toupper(apellido[0]);

	for(int i = 0; i<64; i++)
	{
		if(isspace(apellido[i]) && apellido[i]+1 != '\0')
		{
			apellido[i+1] = toupper(apellido[i+1]);

		}
	}
	for(int i = 0; i<64; i++)
		{
			if(isspace(nombre[i]) && nombre[i]+1 != '\0')
			{
				nombre[i+1] = toupper(nombre[i+1]);
				retorno=0;
			}
		}

	return retorno;
}

/**
 * brief para solicitar un numero float, con coma
 * @param mensaje
 * @param errorMensaje
 * @return retorna el valor float validado
 */
float get_float(char *mensaje, char *errorMensaje){
	char buffer[12];
	float rtn;

	printf("%s", mensaje);
	fflush(stdin);
	gets(buffer);
	while(validar_soloNumerosFloat(buffer)==0){
		printf("%s",errorMensaje);
		fflush(stdin);
		gets(buffer);
	}
	rtn= atof(buffer);
	return rtn;
}

/**
 * brief para validar numero float, con coma
 * @param pData
 * @return devuelve -1 si no se pudo validar, y 0 si esta todo OK
 */
int validar_soloNumerosFloat(char *pData){
	int contadorSigno = 0;
	int rtn = -1;

	if(strlen(pData)> 0){
		for(int i=0; i<strlen(pData); i++){
			if(pData[i]=='.' || pData[i]== ','){
				contadorSigno++;
			}
			else{
				if(isdigit(pData[i])==0){
					if(i==0){
						if(pData[0]!= '-'){
							rtn = 0;
							break;
						}
					}else{
						rtn = 0;
						break;
					}
				}
			}
		}

	}
		return rtn;
}

/**
 * brief funcion para obtener un nombre, solo con caracteres
 * @param pResultado puntero a donde se va a guardar la cadena obtenida
 * @param len la longitud maxima de la cadena
 * @param mensaje lo que se va  amostrar por pantalla para que vea el usuario
 * @param mensajeError para mostrar que tuvo un error
 * @param reintentos cantidad maxima de reintentos por errores
 * @return -2 si no pudo realizar la primera validacion, -1 si agoto lo reintentos, y 0 si esta todo ok
 */
int get_name(char* pResultado,int len,char* mensaje,char* mensajeError,int reintentos)
{
	int returnFunction = -2;
	char buffer[len];
	if(pResultado != NULL && len > 0 && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		returnFunction = -1;
		while(reintentos >= 0)
		{
			printf("%s",mensaje);
			if(get_myGets(buffer, len) && val_isValidName(buffer))
			{
				strcpy(pResultado,buffer);
				returnFunction = 0;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}
	}
	return returnFunction;
}

/**
 * brief para validar que lo que se haya ingresado en la funcion principal sea un nombre solo de caracteres
 * @param nombre
 * @return devuelve -1 si no se obtuvo, y 0 si esta todo ok
 */
int val_isValidName(char* nombre)
{
	int i=0;
	int returnFunction = -1;
	if(nombre != NULL)
	{
		returnFunction = 1;
		while(nombre[i] != 0) // busco el final
		{
			if(!((nombre[i]>='a' && nombre[i]<='z') || (nombre[i]>='A' && nombre[i]<='Z') || nombre[i]==' '))
			{
				returnFunction = 0;
				break;
			}
			i++;
		}
	}
	return returnFunction;
}

/**
 * brief funcion para obtener un cadena de caracteres
 * @param pResultado
 * @param len la longitud de la cadena
 * @return devuel -1 si no se pudo. y 0 si esta todo ok
 */
int get_myGets(char* pResultado, int len)
{
	int returnFunction = -1;
	fflush(stdin);
	if(pResultado != NULL && len > 0 && fgets(pResultado,len,stdin)==pResultado)
	{
		fflush(stdin);
		if(pResultado[strlen(pResultado)-1]== '\n')
		{
			pResultado[strlen(pResultado)-1]='\0';
		}
		returnFunction = 1;
	}
	return returnFunction;
}
