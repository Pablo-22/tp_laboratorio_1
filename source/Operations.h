/*
 * Operations.h
 */

#ifndef OPERATIONS_H_
#define OPERATIONS_H_


/**
 * @brief Función que calcula la suma entre los dos operandos.
 *
 * @param primerOperando Operando A.
 * @param segundoOperando Operando B.
 * @return int Devuelve el resultado.
 */
int getSum(int primerOperando, int segundoOperando);


/**
 * @brief Función que calcula la resta entre los dos operandos.
 *
 * @param primerOperando Operando A.
 * @param segundoOperando Operando B.
 * @return int Devuelve el resultado.
 */
int getSubtraction(int primerOperando, int segundoOperando);


/**
 * @brief Función que calcula la división entre los dos operandos.
 *
 * @param primerOperando Operando A.
 * @param segundoOperando Operando B.
 * @return float Devuelve el resultado.
 */
float getDivision(int primerOperando, int segundoOperando);


/**
 * @brief Función que calcula la multiplicación entre los dos operandos.
 *
 * @param primerOperando Operando A.
 * @param segundoOperando Operando B.
 * @return int Devuelve el resultado.
 */
int getMultiplication(int primerOperando, int segundoOperando);


/**
 * @brief Función que calcula el factorial entre los dos operandos
 *
 * @param numeroIngresado El operando del que se calculará el factorial (se calcula un número a la vez)
 * @return float Devuelve el resultado. Se utiliza el tipo float, debido al amplio tamaño que permite para el valor almacenardo
 */
float getFactorial(int numeroIngresado);


#endif /* OPERATIONS_H_ */
