/*
 * Menu.h
 */

#ifndef MENU_H_
#define MENU_H_

/**
 * @brief Muestr el menú todas las opciones para el usuario, y le pide que seleccione una opción.
 *
 * @param primerOperando El operando A, para poder mostrarlo actualizado en tiempo de ejecución.
 * @param segundoOperando El operando B, para poder mostrarlo actualizado en tiempo de ejecución.
 * @param flagOperacionesCalculadas Un flag, para en caso de que ya se hayan calculado las operaciones, mostrar un mensaje personalizado.
 *
 * @return int Devuelve la opción seleccionada por el usuario.
 */
int mainMenu(int primerOperando, int segundoOperando, int flagOperacionesCalculadas);


/**
 * @brief Se creó una función específica que
 * permite limpiar completamente la consola
 * independiemente del sistema operativo
 * que se utilice.
 */
void cleanConsole();


#endif /* MENU_H_ */
