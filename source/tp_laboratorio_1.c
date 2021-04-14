/*
 ============================================================================
 Name        : tp_laboratorio_1.c
 Author      : Pablo Córdoba
 Copyright   : Prohibida la venta y distribución de este código dentro de los límites de la República Argentina

ENUNCIADO:

Hacer una calculadora.
Para ello el programa iniciará y contará con un menú de opciones:

 1. Ingresar 1er operando (A=x)

 2. Ingresar 2do operando (B=y)

 3. Calcular todas las operaciones
 	 a) Calcular la suma (A+B)
 	 b) Calcular la resta (A-B)
 	 c) Calcular la division (A/B)
 	 d) Calcular la multiplicacion (A*B)
 	 e) Calcular el factorial (A!)

 4. Informar resultados
 	 a) “El resultado de A+B es: r”
 	 b) “El resultado de A-B es: r”
 	 c) “El resultado de A/B es: r” o “No es posible dividir por cero”
 	 d) “El resultado de A*B es: r”
 	 e) “El factorial de A es: r1 y El factorial de B es: r2”

 5. Salir

 Todas las funciones matemáticas del menú se deberán realizar en una biblioteca
 aparte,que contenga las funciones para realizar las cinco operaciones.

 •En el menú deberán aparecer los valores actuales cargados en los operandos
 A y B(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)

 •Deberán contemplarse los casos de error (división por cero, etc)

 •Documentar todas las funciones
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>

#include "Operations.h"
#include "Validations.h"
#include "Menu.h"
#include "Show.h"


int main(void)
{
	int opcion;
	int flagOperacionesCalculadas;

	int primerOperando;
	int segundoOperando;

	int resultadoSuma;
	int resultadoResta;

	float resultadoDivision;
	int divisionValidada;

	int resultadoMultiplicacion;

	float factorialPrimerOperando;
	int factorialPrimerOperandoValidado;

	float factorialSegundoOperando;
	int factorialSegundoOperandoValidado;

	//INICIALIZACIÓN
	primerOperando = 0;
	segundoOperando = 0;
	flagOperacionesCalculadas = 0;

	setbuf(stdout, NULL);

	do
	{
		opcion = mainMenu(primerOperando, segundoOperando, flagOperacionesCalculadas);
		
		switch(opcion)
		{
			case 1:
				printf("\n Ingresar 1er operando. A = ");
				scanf("%d", &primerOperando);

				flagOperacionesCalculadas = 0;

				cleanConsole();
			break;

			case 2:
				printf("\n Ingresar 2do operando. B = ");
				scanf("%d", &segundoOperando);

				flagOperacionesCalculadas = 0;

				cleanConsole();
			break;

			case 3:
				//Las operaciones solo se ejecutan una vez por cada cambio en los operandos.
				if (flagOperacionesCalculadas != 1)
				{
					resultadoSuma = getSum(primerOperando, segundoOperando);

					resultadoResta = getSubtraction(primerOperando, segundoOperando);

					//VALIDAR DIVISION (Se controla que el segundo operando no sea 0).
					divisionValidada = validateDivision(segundoOperando);
					if (divisionValidada != 0) //Si la validación de la división arroja cualquier resultado que no sea 0, se ejecuta la operación de división.
					{
						resultadoDivision = getDivision(primerOperando, segundoOperando);
					}

					resultadoMultiplicacion = getMultiplication(primerOperando, segundoOperando);


					//VALIDAR FACTORIAL 1 (Se controla que el PRIMER operando no sea negativo o 0).
					factorialPrimerOperandoValidado = validateFactorial(primerOperando);
					if (factorialPrimerOperandoValidado != 0) //Si la validación del factorial arroja cualquier resultado que no sea 0, se ejecuta la función de factorial.
					{
						factorialPrimerOperando = getFactorial(primerOperando);
					}

					//VALIDAR FACTORIAL 2 (Se controla que el SEGUNDO operando no sea negativo o 0).
					factorialSegundoOperandoValidado = validateFactorial(segundoOperando);
					if (factorialSegundoOperandoValidado != 0) //Si la validación del factorial arroja cualquier resultado que no sea 0, se ejecuta la función de factorial.
					{
						factorialSegundoOperando = getFactorial(segundoOperando);
					}

					flagOperacionesCalculadas = 1; //Ya se han calculado las operaciones para los operandos ingresados.
				}
				cleanConsole();
			break;

			case 4:
				cleanConsole();
				printf("--------MOSTRAR RESULTADOS--------\n\n");

				showSum(primerOperando, segundoOperando, resultadoSuma);

				showDivision(primerOperando, segundoOperando, divisionValidada, resultadoDivision);

				showSubtraction(primerOperando, segundoOperando, resultadoResta);

				showMultiplication(primerOperando, segundoOperando, resultadoMultiplicacion);

				showFactorial(primerOperando, segundoOperando, factorialPrimerOperandoValidado, factorialSegundoOperandoValidado, factorialPrimerOperando, factorialSegundoOperando);

				printf("\n--------FIN RESULTADOS--------\n\n");
			break;
		}

	}while(opcion != 5);

	cleanConsole();
}
