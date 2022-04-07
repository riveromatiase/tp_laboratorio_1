/*
 * Operaciones.c
 *
 *  Created on: 7 abr. 2022
 *      Author: flor_
 *      desarrollo de las funciones
 */

#include "Operaciones.h"


float SolicitarNumero(char* mensaje, char* ERROR){
	float retorno;
	printf(mensaje);
	scanf("%f",&retorno);
			while(retorno<1){
				printf("%s",ERROR);
				scanf("%f",&retorno);
			}
	return retorno;
}
//------------------------------------------------------
float Descuento(float num1, float porcentajeDescuento){
	float precioConDescuentoTD;

	precioConDescuentoTD = num1 * porcentajeDescuento;

	return precioConDescuentoTD;
}
//------------------------------------------------------
float Interes(float num1, float porcentajeInteres){
	float precioConInteres;

	precioConInteres = num1 * porcentajeInteres;
	return precioConInteres;
}
//----------------------------------------------------------

float PagoBitcoin(float num1, float valorBitcoin){
	float precioPagoBitcoin;

	precioPagoBitcoin = num1 / valorBitcoin;

	return precioPagoBitcoin;
}
//-------------------------------------------------------------
float Division(float num1, float num2, char* ERROR){
	float resultado;

	if(num1>0)
	{
		resultado = num1 / num2;
	}
	else{
		printf("%s",ERROR);
	}
	return resultado;
}
//--------------------------------------------
float Resta(float num1, float num2){
	float retorno;

	if(num1>num2)
	{
		retorno = num1 - num2;
	}
	else{
		if(num2>num1)
		{
			retorno = num2 - num1;
		}
		else{
			retorno = 0;
		}
	}
	return retorno;
}
//------------------------------------------------------
float ComprobacionDistintoNull(void* num1){
	float retorno = 1;

	if(num1!=NULL)
	{
		retorno = 0;
	}
	return retorno;
}
//------------------------------------------------------------
int getIngresoDeOpcion(char* mensaje, char* ERROR)
{
	int opcionIngresada;

	printf("%s",mensaje);
	scanf("%d",&opcionIngresada);
	while(opcionIngresada<0 || opcionIngresada>6)
	{
		printf("%s",ERROR);
			scanf("%d",&opcionIngresada);
	}

	return opcionIngresada;
}
