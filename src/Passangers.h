/*
 * Passangers.h
 *
 *  Created on: 29 abr. 2022
 *      Author: flor_
 */

#ifndef PASSANGERS_H_
#define PASSANGERS_H_

#define LIBRE 0
#define OCUPADO 1
#define BAJA -1
#define MAX_CHARS_CADENAS 51

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Inputs.h"

struct
{
	int id;
	char name[MAX_CHARS_CADENAS];
	char lastname[MAX_CHARS_CADENAS];
	float price;
	char flycode[10];
	int typePassanger;
	int statusFlight;
	int isEmpty;
}typedef ePasajero;

///**
//
//*

/**
 *
 */
int ePasajero_ObtenerIdUnico(void);
void ImprimirMenu(void);
int ePasajero_Inicializar(ePasajero listaDePasajeros[], int tam);
int ePasajero_BuscarEspacioLibre(ePasajero listaDePasajeros[], int tam);
int ePasajero_Alta(ePasajero listaDePasajeros[], int tam);
void ePasajero_imprimirUno(ePasajero listaDePasajeros);
int ePasajero_imprimirTodos(ePasajero listaDePasajeros[], int tam, int estado);
int ePasajero_BuscarIndexPorId(ePasajero listaDePasajeros[], int tam);
int ePasajero_Modificar(ePasajero listaDePasajeros[], int tam);
ePasajero ePasajero_ModificarUnPasajero(ePasajero pasajero);
int ePasajero_Baja(ePasajero listaDePasajeros[], int tam);

float obtenerPromedioArray(ePasajero listaDePersonal[], int tam);
int mayorQueElPromedio(ePasajero listaDePersonal[], int tam, float promedio);

int ordenarPorDosCriterios(ePasajero array[], int TAM);
void imprimirListadoOrdenado(ePasajero array[], int TAM);

int cargaForzada(ePasajero array[], int TAM,int pos, char name[], char lastname[], char flycode[], int typePassanger, int statusFlight, int isEmpty, float price);
#endif /* PASSANGERS_H_ */
