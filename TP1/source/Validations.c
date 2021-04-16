/*
 * Validations.c
 */

#include <stdio.h>
#include <stdlib.h>


#include "Operations.h"
#include "Validations.h"
#include "Menu.h"
#include "Show.h"


int validateDivision(int segundoOperando)
{
	int valorDeRetorno;

	if (segundoOperando == 0)
	{
		valorDeRetorno = 0;
	}
	else
	{
		valorDeRetorno = 1;
	}

	return valorDeRetorno;
}


int validateFactorial(int operandoIngresado)
{
	int valorDeRetorno;

	if (operandoIngresado < 1)
	{
		valorDeRetorno = 0;
	}
	else
	{
		if (operandoIngresado < 35)
		{
		valorDeRetorno = 1;
		}
		else
		{
			valorDeRetorno = 2;
		}
	}
	return valorDeRetorno;
}
