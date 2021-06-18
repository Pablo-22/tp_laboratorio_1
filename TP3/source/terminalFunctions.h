#ifndef SOURCE_TERMINALFUNCTIONS_H_
#define SOURCE_TERMINALFUNCTIONS_H_

#define EMPTY -1
 #define FULL 0

 //TRUE - FALSE
 #define TRUE 1
 #define FALSE 0

/**
 * @brief Función para limpiar el buffer de entrada, 
 *        para el ingreso de caracteres.
 * 
 */
void CleanBuffer();

/**
 * @brief Limpia la terminal.
 * 
 */
void CleanConsole();

#endif /* SOURCE_TERMINALFUNCTIONS_H_ */
