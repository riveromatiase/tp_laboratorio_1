/*
 * Inputs.h
 *
 *  Created on: 28 abr. 2022
 *      Author: flor_
 */

#ifndef INPUTS_H_
#define INPUTS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int utn_getNumero(int *pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int getInt(int* pResultado);
int myGets(char* cadena, int longitud);
int esNumerica(char* cadena);

int utn_getCadena(char *cadena, int tamano, char* mensaje, char* mensajeError, int reintentos);
char utn_getChar(char *pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);

int ordenarNombreyApellido(char* nombre, char* apellido);

int utn_getNumeroResultado(char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int get_myGets(char* pResultado, int len);
int val_isValidName(char* nombre);
int get_name(char* pResultado,int len,char* mensaje,char* mensajeError,int reintentos);

int validar_soloNumerosFloat(char *pData);
float get_float(char *mensaje, char *errorMensaje);
#endif /* INPUTS_H_ */
