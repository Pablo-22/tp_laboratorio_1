#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "terminalFunctions.h"
#include "getFunctions.h"


/********** UTN GET ***********************************
 ********** UTN GET ***********************************
 ********** UTN GET **********************************/

int getInt(char mensaje[], char mensajeDeError[], int minimo, int maximo, int realizarValidaciones)
{
	int exit = -1;
	int numeroIngresado;
	char datoIngresado[148];
	datoIngresado[0] = '\n';

	do
	{
		CleanBuffer();
		printf("%s",mensaje);
		scanf("%[^\n]", datoIngresado);
		exit = isValidInt(datoIngresado);
		if (exit == 0)
		{
			numeroIngresado = atoi(datoIngresado);
			if (realizarValidaciones == TRUE && (numeroIngresado < minimo || numeroIngresado > maximo))
			{
				exit = -1;
				printf("%s\n", mensajeDeError);
			}
		}
		else
		{
			printf("%s\n", mensajeDeError);
		}
	} while (exit != 0);	
	return numeroIngresado;
}


float getFloat(char mensaje[], char mensajeDeError[], float minimo, float maximo, int realizarValidaciones)
{
	int exit = -1;
	float numeroIngresado;
	char datoIngresado[148];

	do
	{
		CleanBuffer();
		printf("%s",mensaje);
		scanf("%[^\n]", datoIngresado);
		exit = isValidFloat(datoIngresado);
		if (exit == 0)
		{
			numeroIngresado = atof(datoIngresado);
			if (realizarValidaciones == TRUE && (numeroIngresado < minimo || numeroIngresado > maximo))
			{
				exit = -1;
				printf("%s\n", mensajeDeError);
			}
		}
		else
		{
			printf("%s\n", mensajeDeError);
		}
	} while (exit != 0);

	return numeroIngresado;
}

char getChar(char mensaje[], char mensajeDeError[], char opcion1, char opcion2, int realizarValidaciones)
{
	int exit = -1;
	char datoIngresado;

	do
	{
		CleanBuffer();
		printf("%s",mensaje);
		scanf("%[^\n]", &datoIngresado);
		exit = isValidChar(datoIngresado);
		if ( exit == -1 || (realizarValidaciones == TRUE && (datoIngresado != opcion1 && datoIngresado != opcion2)))
		{
			exit = -1;
			printf("%s\n", mensajeDeError);
		}
	} while (exit != 0);

	return datoIngresado;
}

void getString(char mensaje[], char mensajeDeError[], char cadenaDeSalida[])
{
	int exit;
	do
	{
		cadenaDeSalida[0] = '\0';
		CleanBuffer();
		printf("%s", mensaje);
		scanf("%[^\n]", cadenaDeSalida);
		exit = isValidString(cadenaDeSalida);
		if (exit == -1)
		{
			printf("\n%s\n", mensajeDeError);
		}
	}while(exit == -1);
}


int isValidInt(char datoIngresado[])
{
	int exit = 0;
	int len;
	len = strlen(datoIngresado);

	for (int i = 0; i < len; i++)
	{
		if (isdigit(datoIngresado[i]) == 0)
		{
			exit = -1;
			break;
		}
	}
	return exit;
}

int isValidFloat(char datoIngresado[])
{
	int exit = -1;
	char aux;
	int len;
	len = strlen(datoIngresado);
	if (isValidDecimal(datoIngresado) == 0)
	{
		exit = 0;
		for (int i = 0; i < len; i++)
		{
			aux = datoIngresado[i];
			if (isdigit(aux) == 0 && aux != '.' && aux != ',')
			{
				exit = -1;
				break;
			}
		}
	}
	return exit;
}

int isValidDecimal(char datoIngresado[])
{
	int exit = 0;
	int len = strlen(datoIngresado);
	int commaCounter = 0;
	int periodCounter = 0;

	for (int i = 0; i < len; i++)
	{
		switch (datoIngresado[i])
		{
			case '.':
				periodCounter++;
				break;
			case ',':
				commaCounter++;
			break;
		}
	}
	
	if ((periodCounter > 1 || commaCounter > 1) || (periodCounter > 0 && commaCounter > 0))
	{
		exit = -1;
	}
	return exit;
}

int isValidString(char datoIngresado[])
{
	int exit = -1;
	int len = 0;
	len = strlen(datoIngresado);
	if (len > 0 && isWhiteSpace(datoIngresado) == 0)
	{
		exit = 0;
		for (int i = 0; i < len; i++)
		{
			if (isValidChar(datoIngresado[i]) == -1)
			{
				exit = -1;
				break;
			}
		}
	}
	return exit;
}

int isValidChar(char datoIngresado)
{
	int exit = -1;
	if (isdigit(datoIngresado) == 0)
	{
		exit = 0;
	}
	return exit;
}

int isWhiteSpace(char datoIngresado[])
{
	int exit = 0;
	int spaceCounter = 0;
	int len;
	len = strlen(datoIngresado);
	
	for (int i = 0; i < len; i++)
	{
		if (isspace(datoIngresado[i]) != 0)
		{
			spaceCounter++;
		}
	}

	if (spaceCounter == len || isspace(datoIngresado[0]) != 0)
	{
		exit = -1;
	}
	return exit;
}


/********** UTN GET ***********************************
 ********** UTN GET ***********************************
 ********** UTN GET **********************************/

void indexValidation(int index)
{
	if (index == -1)
	{
		//CleanConsole();
		printf("No se ha encontrado esa ID \nIntente nuevamente: \n\n");
	}
}


void inicializarVector(int vector[], int extensionVector, int valorDeInicio)
{
	int i;

	for (i = 0; i < extensionVector; i++)
	{
		vector[i] = valorDeInicio;
	}
}
