#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "getFunctions.h"
#include "terminalFunctions.h"
#include "LinkedList.h"
#include "Employee.h"
#include "Menu.h"


int mainMenu()
{
	int option;
	option = 0;

	printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto). \n");
	printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario). \n");
	printf("3. Alta de empleado \n");
	printf("4. Modificar datos de empleado \n");
	printf("5. Baja de empleado \n");
	printf("6. Listar empleados \n");
	printf("7. Ordenar empleados \n");
	printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto). \n");
	printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario). \n");
	printf("10. Salir \n");

	option = getInt("\n Elija una opción: ", "Error, intente nuevamente", 1, 10, TRUE);
	return option;
}

int menu_ModifyEmployee()
{
	int option;
	option = 0;

	printf("0. Modificar NOMRBRE \n");
	printf("1. Modificar HORAS TRABAJADAS \n");
	printf("2. Modificar SALARIO \n");
	printf("3. VOLVER \n");

	option = getInt("\n Elija una opción: ", "Error, intente nuevamente", 0, 3, TRUE);
	return option;
}


int menu_sort()
{
	int option;
	option = 0;

	printf("0. Ordenar por NOMRBRE \n");
	printf("1. Ordenar por HORAS TRABAJADAS \n");
	printf("2. Ordenar por SALARIO \n");
	printf("3. VOLVER \n");

	option = getInt("\n Elija una opción: ", "Error, intente nuevamente", 0, 3, TRUE);
	return option;
}