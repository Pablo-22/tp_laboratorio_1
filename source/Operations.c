/*
 * Operations.c
 */

#include <stdio.h>
#include <stdlib.h>

#include "Operations.h"
#include "Validations.h"
#include "Menu.h"
#include "Show.h"



int getSum(int primerOperando, int segundoOperando)
{
	int resultadoDeLaSuma;

	resultadoDeLaSuma = primerOperando + segundoOperando;

	return resultadoDeLaSuma;
}


int getSubtraction(int primerOperando, int segundoOperando)
{
	int resultadoDeLaResta;

	resultadoDeLaResta = primerOperando - segundoOperando;

	return resultadoDeLaResta;
}


float getDivision(int primerOperando, int segundoOperando)
{
	float resultadoDeLaDivision;

	resultadoDeLaDivision = (float)primerOperando / segundoOperando;

	return resultadoDeLaDivision;
}


int getMultiplication(int primerOperando, int segundoOperando)
{
	int resultadoDeLaMultiplicacion;

	resultadoDeLaMultiplicacion = primerOperando * segundoOperando;

	return resultadoDeLaMultiplicacion;
}


float getFactorial(int numeroIngresado)
{
	int contador;

	float resultadoDelFactorial;
	resultadoDelFactorial = 1;

	for (contador = 1; contador <= numeroIngresado; ++contador)
	{
		resultadoDelFactorial *= contador;
	}

	return resultadoDelFactorial;
}
