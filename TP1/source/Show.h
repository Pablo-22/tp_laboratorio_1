/*
 * Show.h
 */

#ifndef SHOW_H_
#define SHOW_H_

/**
 * @brief Muestra el resultado de A+B.
 *
 * @param primerOperando Operando A
 * @param SegundoOperando Operando B
 * @param resultadoSuma El resultado previamente obtenido.
 */
void showSum(int primerOperando, int segundoOperando, int resultadoSuma);

/**
 * @brief Muestra el resultado de A-B.
 *
 * @param primerOperando Operando A
 * @param SegundoOperando Operando B
 * @param resultadoResta El resultado previamente obtenido.
 */
void showSubtraction(int primerOperando, int segundoOperando, int resultadoResta);

/**
 * @brief Muestra el resultado de A*B.
 *
 * @param primerOperando Operando A
 * @param SegundoOperando Operando B
 * @param resultadoMultiplicacion El resultado previamente obtenido.
 */
void showMultiplication(int primerOperando, int segundoOperando, int resultadoMultiplicacion);

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
void showDivision(int primerOperando, int segundoOperando, int divisionValidada, float resultadoDivision);

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
void showFactorial(int primerOperando, int segundoOperando, int factorialPrimerOperandoValidado, int factorialSegundoOperandoValidado, float factorialPrimerOperando, float factorialSegundoOperando);


#endif /* SHOW_H_ */
