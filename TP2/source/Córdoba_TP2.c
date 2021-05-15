/*
 ============================================================================
 Name        : Córdoba_TP2.c
 Author      : Pablo Córdoba
 Copyright   : Prohibida la venta y distribución de este código dentro de los límites de la República Argentina
 Description : Trabajo Práctico número 2
 ============================================================================
 */


#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

#include "TerminalFunctions.h"
#include "GetFunctions.h"
#include "ArrayEmployees.h"
#include "Menu.h"

int main(void) 
{
    int option;
	eEmployee list[LIST_LEN];
	int flagEmpty;
	int id;
	int flagReturn;

	initEmployees(list, LIST_LEN);
	
	//UNCOMMENT TO HARCODE 
	//hardcodeEmployee(list, 7);

	do
	{
		option = mainMenu();
		flagEmpty = CheckEmpty(list, LIST_LEN);

		switch (option)
		{

			case 1:
				//ALTA
				CleanConsole();
				flagReturn = getNewEmployeeData(list, LIST_LEN);
				if(flagReturn == FALSE)
				{
					printf("No se ha podido realizar el alta\nNo hay lugar disponible para cargar nuevos empleados.");
				}
				break;
			case 2:
				//MODIFICAR
				CleanConsole();
				if(flagEmpty == FALSE)
				{
					option = menuModifyEmployee();
					switchModifyEmployee(option, list, LIST_LEN);
				}
				else
				{
					printf("No hay elementos para modificar. \n\n");
				}		
				break;
			case 3:
				//BAJA
				CleanConsole();
				if(flagEmpty == FALSE)
				{
					id = selectEmployeeId(list, LIST_LEN);
					flagReturn = removeEmployee(list, LIST_LEN, id);
					if(flagReturn == 1)
					{
						printf("\nEmpleado eliminado\n");
					}
					else
					{
						printf("\nEliminación cancelada\n");
					}
				}
				else
				{
					printf("No hay elementos para eliminar. \n\n");
				}	
				break;
			case 4:
				//INFORMAR
				CleanConsole();
				if(flagEmpty == FALSE)
				{
					option = menuPrint();
					switchPrint(option, list, LIST_LEN);
				}
				else
				{
					printf("No hay elementos para mostrar. \n\n");
				}
			break;
		}
	} while(option != 5);

	return 1;
}
