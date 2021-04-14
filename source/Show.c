/*
 * Show.c
 */

#include <stdio.h>
#include <stdlib.h>

#include "Operations.h"
#include "Validations.h"
#include "Menu.h"
#include "Show.h"



void showSum(int primerOperando, int segundoOperando, int resultadoSuma)
{
	printf("El resultado de %d+%d es: %d \n", primerOperando, segundoOperando, resultadoSuma);
}

void showSubtraction(int primerOperando, int segundoOperando, int resultadoResta)
{
	printf("El resultado de %d-%d es: %d \n", primerOperando, segundoOperando, resultadoResta);
}

void showMultiplication(int primerOperando, int segundoOperando, int resultadoMultiplicacion)
{
	printf("El resultado de %d*%d es: %d \n", primerOperando, segundoOperando, resultadoMultiplicacion);
}

void showDivision(int primerOperando, int segundoOperando, int divisionValidada, float resultadoDivision)
{
	//En este caso se elige un if y no un switch, debido a que el flag solo tiene 2 valores posibles
	if (divisionValidada == 0)
	{
		printf("No es posible dividir por 0 \n");
	}
	else
	{
		printf("El resultado de %d/%d es: %.2f \n", primerOperando, segundoOperando, resultadoDivision);
	}
}

void showFactorial(int primerOperando, int segundoOperando, int factorialPrimerOperandoValidado, int factorialSegundoOperandoValidado, float factorialPrimerOperando, float factorialSegundoOperando)
{
	switch (factorialPrimerOperandoValidado)
	{
		case 0:
			printf("\nNo se ha calculado el factorial de %d. \nNo existe el factorial de un número negativo o 0.\n", primerOperando);
		break;

		case 1:
			printf("\nEl factorial de %d es: %.0f \n", primerOperando, factorialPrimerOperando);
		break;

		case 2:
			printf("\nNo se ha calculado el factorial de %d. \nNúmero fuera de rango\n", primerOperando);
		break;
		}

	switch (factorialSegundoOperandoValidado)
	{
		case 0:
			printf("\nNo se ha calculado el factorial de %d. \nNo existe el factorial de un número negativo o 0.\n", segundoOperando);
		break;

		case 1:
			printf("\nEl factorial de %d es: %.0f \n", segundoOperando, factorialSegundoOperando);
			break;

		case 2:
			printf("\nNo se ha calculado el factorial de %d. \nNúmero fuera de rango\n", segundoOperando);
		break;
	}
}
