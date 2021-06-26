/*
 * Menu.h
 *
 *  Created on: 11 may. 2021
 *      Author: pablo22
 */

#ifndef MENU_H_
#define MENU_H_

/**
 * @brief Muestra las opciones del menú principal y lee la opción seleccionada por el usuario
 * 
 * @return int Devuelve la opción seleccionada.
 */
int mainMenu();

/**
 * @brief Submenú para elegir qué dato de un empleado se va a modificar.
 * 
 * @return int Devuelve la opción seleccionada.
 */
int menuModifyEmployee();

/**
 * @brief El switch correspondiente al menú de modificar empleado. Recibe la opción seleccionada, y realiza las tareas correspondientes.
 * 
 * @param option Opción seleccionada en el menuModifyEmployee
 * @param list 
 * @param len 
 */
void switchModifyEmployee(int option, eEmployee list[], int len);

/**
 * @brief Submenú para listados.
 * 
 * @return int Devuelve la opción seleccionada.
 */
int menuPrint();

/**
 * @brief El switch correspondiente al menú de listados. Recibe la opción seleccionada, y realiza las tareas correspondientes.
 * 
 * @param option Opción seleccionada en el menuPrint
 * @param list 
 * @param len 
 */
void switchPrint(int option, eEmployee list[], int len);

#endif /* MENU_H_ */
