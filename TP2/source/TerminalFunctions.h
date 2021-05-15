/*
 * TerminalFunctions.h
 *
 *  Created on: 11 may. 2021
 *      Author: pablo22
 */

#ifndef TERMINALFUNCTIONS_H_
#define TERMINALFUNCTIONS_H_


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

#endif /* TERMINALFUNCTIONS_H_ */
