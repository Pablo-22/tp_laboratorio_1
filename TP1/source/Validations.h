/*
 * Validations.h
 */

#ifndef VALIDATIONS_H_
#define VALIDATIONS_H_

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
int validateFactorial(int operandoIngresado);


/**
 * @brief Controla si la división se puede resolver.
 *
 * NO se puede resolver si el operando B es igual a 0.
 *
 * @param segundoOperando Solo requiere conocer el operando B.
 * @return int Devuelve 0 si NO se puede resolver, y 1 si se puede.
 */
int validateDivision(int segundoOperando);



#endif /* VALIDATIONS_H_ */
