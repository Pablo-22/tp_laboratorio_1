/*
 ============================================================================
 Name        : tp_laboratorio_1.c
 Author      : Pablo Córdoba
 Version     :
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

/**
 * @brief Muestr el menú todas las opciones para el usuario, y le pide que seleccione una opción.
 * 
 * @param primerOperando El operando A, para poder mostrarlo actualizado en tiempo de ejecución.
 * @param segundoOperando El operando B, para poder mostrarlo actualizado en tiempo de ejecución.
 * @param flagOperacionesCalculadas Un flag, para en caso de que ya se hayan calculado las operaciones, mostrar un mensaje personalizado.
 * 
 * @return int Devuelve la opción seleccionada por el usuario.
 */
int MenuPrincipal(int primerOperando, int segundoOperando, int flagOperacionesCalculadas);


/**
 * @brief Función que calcula la suma entre los dos operandos.
 * 
 * @param primerOperando Operando A.
 * @param segundoOperando Operando B.
 * @return int Devuelve el resultado.
 */
int FuncionSuma(int primerOperando, int segundoOperando);

/**
 * @brief Función que calcula la resta entre los dos operandos.
 * 
 * @param primerOperando Operando A.
 * @param segundoOperando Operando B.
 * @return int Devuelve el resultado.
 */
int FuncionResta(int primerOperando, int segundoOperando);

/**
 * @brief Función que calcula la división entre los dos operandos.
 * 
 * @param primerOperando Operando A.
 * @param segundoOperando Operando B.
 * @return float Devuelve el resultado.
 */
float FuncionDivision(int primerOperando, int segundoOperando);

/**
 * @brief Función que calcula la multiplicación entre los dos operandos.
 * 
 * @param primerOperando Operando A.
 * @param segundoOperando Operando B.
 * @return int Devuelve el resultado.
 */
int FuncionMultiplicacion(int primerOperando, int segundoOperando);

/**
 * @brief Controla si la división se puede resolver.
 * 
 * NO se puede resolver si el operando B es igual a 0.
 * 
 * @param segundoOperando Solo requiere conocer el operando B.
 * @return int Devuelve 0 si NO se puede resolver, y 1 si se puede.
 */
int FuncionValidarDivision(int segundoOperando);

/**
 * @brief Función que calcula el factorial entre los dos operandos
 * 
 * @param numeroIngresado El operando del que se calculará el factorial (se calcula un número a la vez)
 * @return float Devuelve el resultado. Se utiliza el tipo float, debido al amplio tamaño que permite para el valor almacenardo
 */
float FuncionFactorial(int numeroIngresado);

/**
 * @brief Validación para el factorial.
 * 
 * NO se puede resolver el factorial de un número negativo o 0.
 * a todo el plano complejo, excepto a los enteros negativos y al cero.
 * De este último por convención se dice que su factorial es 1, pero es incorrecto.
 * Consultar: https://es.wikipedia.org/wiki/Funci%C3%B3n_gamma
 * 
 * Por otro lado, si el operando es mayor a 34, se desbordará la variable resultado,
 * por lo que no se podrá resolver.
 * 
 * Por estas razones se creó la función para validar cada factorial.
 * 
 * @param operandoIngresado Cualquier operando (A o B) del que se quiera averiguar el factorial.
 * @return int
 * Devuelve 0 si NO se puede calcular el factorial debido a que es igual o menor a 0.
 * Devuelve 1 si SE PUEDE calcular el factorial.
 * Devuelve 2 si NO se puede calcular el factorial debido a que el número desbordaría la variable resultado.
 */
int FuncionValidarFactorial(int operandoIngresado);

/**
 * @brief Se creó una función específica que
 * permite limpiar completamente la consola
 * independiemente del sistema operativo
 * que se utilice.
 */
void FuncionLimpiarConsola();

/**
 * @brief Muestra el resultado de A+B.
 * 
 * @param primerOperando Operando A
 * @param SegundoOperando Operando B
 * @param resultadoSuma El resultado previamente obtenido.
 */
void FuncionMostrarResultadoDeSuma(int primerOperando, int segundoOperando, int resultadoSuma);

/**
 * @brief Muestra el resultado de A-B.
 * 
 * @param primerOperando Operando A
 * @param SegundoOperando Operando B
 * @param resultadoResta El resultado previamente obtenido.
 */
void FuncionMostrarResultadoDeResta(int primerOperando, int segundoOperando, int resultadoResta);

/**
 * @brief Muestra el resultado de A*B.
 * 
 * @param primerOperando Operando A
 * @param SegundoOperando Operando B
 * @param resultadoMultiplicacion El resultado previamente obtenido.
 */
void FuncionMostrarResultadoDeProducto(int primerOperando, int segundoOperando, int resultadoMultiplicacion);

/**
 * @brief Si la división fue validada muestra el resultado.
 * Si la división no fue validada muestra un mensaje personalizado.
 * 
 * @param primerOperando Operando A
 * @param SegundoOperando Operando B
 * 
 * @param divisionValidada 0 si NO se puede resolver, y 1 si se puede.
 * @param resultadoDivision  Si la división fue válida, el resultado obtenido.
 */
void FuncionMostrarResultadoDeDivision(int primerOperando, int segundoOperando, int divisionValidada, float resultadoDivision);

/**
 * @brief Muestra distintos mensajes según la validación previa de cada factorial, o el resultado.
 * 
 * @param primerOperando Operando A
 * @param SegundoOperando Operando B
 * 
 * @param factorialPrimerOperandoValidado 
 * 0 si NO se puede calcular el factorial debido a que es igual o menor a 0.
 * Devuelve 1 si SE PUEDE calcular el factorial.
 * Devuelve 2 si NO se puede calcular el factorial debido a que el número desbordaría la variable resultado.
 * 
 * @param factorialSegundoOperandoValidado 
 * 0 si NO se puede calcular el factorial debido a que es igual o menor a 0.
 * Devuelve 1 si SE PUEDE calcular el factorial.
 * Devuelve 2 si NO se puede calcular el factorial debido a que el número desbordaría la variable resultado.
 * 
 * @param factorialPrimerOperando Si fue válido, el resultado obtenido.
 * @param factorialSegundoOperando Si fue válido, el resultado obtenido.
 */
void FuncionMostrarResultadoFactorial(int primerOperando, int segundoOperando, int factorialPrimerOperandoValidado, int factorialSegundoOperandoValidado, float factorialPrimerOperando, float factorialSegundoOperando);

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
		opcion = MenuPrincipal(primerOperando, segundoOperando, flagOperacionesCalculadas);
		
		switch(opcion)
		{
			case 1:
				printf("\n Ingresar 1er operando. A = ");
				scanf("%d", &primerOperando);

				flagOperacionesCalculadas = 0;

				FuncionLimpiarConsola();
			break;

			case 2:
				printf("\n Ingresar 2do operando. B = ");
				scanf("%d", &segundoOperando);

				flagOperacionesCalculadas = 0;

				FuncionLimpiarConsola();
			break;

			case 3:
				//Las operaciones solo se ejecutan una vez por cada cambio en los operandos.
				if (flagOperacionesCalculadas != 1)
				{
					resultadoSuma = FuncionSuma(primerOperando, segundoOperando);

					resultadoResta = FuncionResta(primerOperando, segundoOperando);

					//VALIDAR DIVISION (Se controla que el segundo operando no sea 0).
					divisionValidada = FuncionValidarDivision(segundoOperando);
					if (divisionValidada != 0) //Si la validación de la división arroja cualquier resultado que no sea 0, se ejecuta la operación de división.
					{
						resultadoDivision = FuncionDivision(primerOperando, segundoOperando);
					}

					resultadoMultiplicacion = FuncionMultiplicacion(primerOperando, segundoOperando);


					//VALIDAR FACTORIAL 1 (Se controla que el PRIMER operando no sea negativo o 0).
					factorialPrimerOperandoValidado = FuncionValidarFactorial(primerOperando);
					if (factorialPrimerOperandoValidado != 0) //Si la validación del factorial arroja cualquier resultado que no sea 0, se ejecuta la función de factorial.
					{
						factorialPrimerOperando = FuncionFactorial(primerOperando);
					}

					//VALIDAR FACTORIAL 2 (Se controla que el SEGUNDO operando no sea negativo o 0).
					factorialSegundoOperandoValidado = FuncionValidarFactorial(segundoOperando);
					if (factorialSegundoOperandoValidado != 0) //Si la validación del factorial arroja cualquier resultado que no sea 0, se ejecuta la función de factorial.
					{
						factorialSegundoOperando = FuncionFactorial(segundoOperando);
					}

					flagOperacionesCalculadas = 1; //Ya se han calculado las operaciones para los operandos ingresados.
				}
				FuncionLimpiarConsola();
			break;

			case 4:
				FuncionLimpiarConsola();
				printf("--------MOSTRAR RESULTADOS--------\n\n");

				FuncionMostrarResultadoDeSuma(primerOperando, segundoOperando, resultadoSuma);

				FuncionMostrarResultadoDeDivision(primerOperando, segundoOperando, divisionValidada, resultadoDivision);

				FuncionMostrarResultadoDeResta(primerOperando, segundoOperando, resultadoResta);

				FuncionMostrarResultadoDeProducto(primerOperando, segundoOperando, resultadoMultiplicacion);

				FuncionMostrarResultadoFactorial(primerOperando, segundoOperando, factorialPrimerOperandoValidado, factorialSegundoOperandoValidado, factorialPrimerOperando, factorialSegundoOperando);

				printf("\n--------FIN RESULTADOS--------\n\n");
			break;
		}

	}while(opcion != 5);

}









int MenuPrincipal(int primerOperando, int segundoOperando, int flagOperacionesCalculadas)
{
	int opcion;
	opcion = 0;

	printf("1. Ingresar 1er operando (A = %d) \n", primerOperando);
	printf("2. Ingresar 2do operando (B = %d) \n", segundoOperando);
	
	if (flagOperacionesCalculadas == 0)
	{
		printf("3. Calcular todas las operaciones \n");
	}
	else
	{
		printf("Ya se han calculado las operaciones para los valores ingresados \n");
	}
	
	printf("4. Informar resultados \n");
	printf("5. Salir \n");

	printf("\n Elija una opción: ");
	scanf("%d", &opcion);

	return opcion;
}

int FuncionSuma(int primerOperando, int segundoOperando)
{
	int resultadoDeLaSuma;

	resultadoDeLaSuma = primerOperando + segundoOperando;

	return resultadoDeLaSuma;
}

int FuncionResta(int primerOperando, int segundoOperando)
{
	int resultadoDeLaResta;

	resultadoDeLaResta = primerOperando - segundoOperando;

	return resultadoDeLaResta;
}

int FuncionValidarDivision(int segundoOperando)
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

float FuncionDivision(int primerOperando, int segundoOperando)
{
	float resultadoDeLaDivision;

	resultadoDeLaDivision = (float)primerOperando / segundoOperando;

	return resultadoDeLaDivision;
}

int FuncionMultiplicacion(int primerOperando, int segundoOperando)
{
	int resultadoDeLaMultiplicacion;

	resultadoDeLaMultiplicacion = primerOperando * segundoOperando;

	return resultadoDeLaMultiplicacion;
}

int FuncionValidarFactorial(int operandoIngresado)
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

float FuncionFactorial(int numeroIngresado)
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

void FuncionLimpiarConsola()
{
	/* El símbolo _WIN32 está definido solamente en Windows y con la construcción utilizada el compilador verá, por ejmplo, la instrucción #include<windows.h> solo si es Windows. En una compilación para linux, es como si esa línea del fuente no existiera.*/

	#ifdef _WIN32
    	system("cls");
	#else
    	system("clear");
	#endif
}

void FuncionMostrarResultadoDeSuma(int primerOperando, int segundoOperando, int resultadoSuma)
{
	printf("El resultado de %d+%d es: %d \n", primerOperando, segundoOperando, resultadoSuma);
}

void FuncionMostrarResultadoDeResta(int primerOperando, int segundoOperando, int resultadoResta)
{
	printf("El resultado de %d-%d es: %d \n", primerOperando, segundoOperando, resultadoResta);
}

void FuncionMostrarResultadoDeProducto(int primerOperando, int segundoOperando, int resultadoMultiplicacion)
{
	printf("El resultado de %d*%d es: %d \n", primerOperando, segundoOperando, resultadoMultiplicacion);
}

void FuncionMostrarResultadoDeDivision(int primerOperando, int segundoOperando, int divisionValidada, float resultadoDivision)
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

void FuncionMostrarResultadoFactorial(int primerOperando, int segundoOperando, int factorialPrimerOperandoValidado, int factorialSegundoOperandoValidado, float factorialPrimerOperando, float factorialSegundoOperando)
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