/*
 * Operaciones.h
 *
 *  Created on: 7 abr. 2022
 *      Author: flor_
 *      aca van todos lo includes que vaya a usar
 *      y las definiciones de las funciones
 */

#ifndef OPERACIONES_H_
#define OPERACIONES_H_
#include <stdio.h>
#include <stdlib.h>

float SolicitarNumero(char* mensaje, char* ERROR);
float Descuento(float num1, float porcentajeDescuento);
float Interes(float num1, float porcentajeInteres);
float PagoBitcoin(float num1, float valorBitcoin);
float Division(float num1, float num2, char* ERROR);
float Resta(float num1, float num2);
float ComprobacionDistintoNull(void* num1);
int getIngresoDeOpcion(char* mensaje, char* ERROR);



#endif /* OPERACIONES_H_ */
