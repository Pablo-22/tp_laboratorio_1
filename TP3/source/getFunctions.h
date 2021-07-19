#ifndef GETFUNCTIONS_H_
#define GETFUNCTIONS_H_

#define CHAR_LEN 148

/**
 * @brief Get the Int object
 * 
 * @param mensaje  Mensaje que se mostrará al usuario.
 * @param mensajeDeError Mensaje en caso de que se ingrese un dato erróneo.
 * @param minimo Valor mínimo que debe tener el número ingresado.
 * @param maximo Valor máximo que debe tener el número ingresado.
 * @param realizarValidaciones 0 si no se realizarán las validaciones, 1 si se realizarán. (Se ha definido TRUE 1 y FALSE 0).
 * @return int Se devuelve el entero obtenido.
 */
int getInt(char mensaje[], char mensajeDeError[], int minimo, int maximo, int realizarValidaciones);

/**
 * @brief Get the Float object
 * 
 * @param mensaje Mensaje que se mostrará al usuario.
 * @param mensajeDeError Mensaje en caso de que se ingrese un dato erróneo.
 * @param minimo Valor mínimo que debe tener el número ingresado.
 * @param maximo Valor máximo que debe tener el número ingresado.
 * @param realizarValidaciones 0 si no se realizarán las validaciones, 1 si se realizarán. (Se ha definido TRUE 1 y FALSE 0).
 * @return float Se devuelve el valor obtenido.
 */
float getFloat(char mensaje[], char mensajeDeError[], float minimo, float maximo, int realizarValidaciones);

/**
 * @brief Get the Char object
 * 
 * @param mensaje Mensaje que se mostrará al usuario.
 * @param mensajeDeError Mensaje en caso de que se ingrese un dato erróneo.
 * @param opcion1 El caracter ingresado podrá tomar el valor indicado en esta variable.
 * @param opcion2 El caracter ingresado podrá tomar el valor indicado en esta variable.
 * @param realizarValidaciones 0 si no se realizarán las validaciones, 1 si se realizarán. (Se ha definido TRUE 1 y FALSE 0). 
 * @return char Se devuelve el valor obtenido.
 */
char getChar(char mensaje[], char mensajeDeError[], char opcion1, char opcion2, int realizarValidaciones);

/**
 * @brief Get the String object
 * 
 * @param mensaje Mensaje que se mostrará al usuario.
 * @param mensajeDeError Mensaje que se mostrará en caso de error.
 * @param cadenaDeSalida variable char[] donde se guardará la cadena obtenida.
 */
void getString(char mensaje[], char mensajeDeError[], char cadenaDeSalida[]);


/**
 * @brief Las funciones de búsqueda de índices, retornan -1 en caso de no encontrar el índice buscado. En ese caso, esta función devuelve un mensaje de error.
 * 
 * @param indice Indice devuelto por la función de buscar índice.
 */
void indexValidation(int indice);

/**
 * @brief Controla que el contenido de la cadena sean números válidos
 * 
 * @param datoIngresado 
 * @return int  -1 si error (la cadena contiene caracteres no numéricos), 0 si OK
 */
int isValidInt(char datoIngresado[]);

/**
 * @brief Controla que el dato ingresado sea un texto válido
 * 
 * @param datoIngresado 
 * @return int -1 si error (la cadena está vacía, tiene solo espacios, o el primer caracter es un espacio, o contiene números), 0 si OK
 */
int isValidString(char datoIngresado[]);

/**
 * @brief Controla que la cadena contenga un float válido
 * 
 * @param datoIngresado 
 * @return int -1 si ERROR (la cadena contiene caracteres que no sean numéricos, o punto, o coma, la cadena contiene más de un punto o una coma), 0 si OK
 */
int isValidFloat(char datoIngresado[]);

/**
 * @brief Controla que la variable no contenga caracteres numéricos
 * 
 * @param datoIngresado 
 * @return int -1 si ERROR, 0 si OK
 */
int isValidChar(char datoIngresado);

/**
 * @brief Controla que la cadena no esté en blanco, no contenga solo espacios, y que el primer caracter no sea espacio.
 * 
 * @param datoIngresado 
 * @return int -1 si ERROR, 0 si OK
 */
int isBlankString(char datoIngresado[]);

/**
 * @brief Verifica que el contenido total de la cadena no sean espacios, y que el primer caracter no sea espacio.
 * 
 * @param datoIngresado 
 * @return int -1 si ERROR, 0 si OK
 */
int isWhiteSpace(char datoIngresado[]);

/**
 * @brief Controla que la cadena tenga máximo un punto o una coma.
 * 
 * @param datoIngresado 
 * @return int  -1 si ERROR, 0 si OK
 */
int isValidDecimal(char datoIngresado[]);

#endif /* GETFUNCTIONS_H_ */
