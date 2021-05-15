#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

#include "TerminalFunctions.h"
#include "GetFunctions.h"
#include "ArrayEmployees.h"
#include "Menu.h"


int mainMenu()
{
	int option;
	option = 0;

	printf("1. ALTA empleado \n");
	printf("2. MODIFICACIÓN empleado \n");
	printf("3. BAJA empleado \n");
	printf("4. Menú MOSTRAR \n");
	printf("5. SALIR \n");

	option = getInt("\n Elija una opción: ", "Error, intente nuevamente", 1, 5, TRUE);
	return option;
}

int menuModifyEmployee()
{
	int option;
	option = 0;

	printf("0. Modificar NOMRBRE \n");
	printf("1. Modificar APELLIDO \n");
	printf("2. Modificar SALARIO \n");
	printf("3. Modificar SECTOR \n");
	printf("4. VOLVER \n");

	option = getInt("\n Elija una opción: ", "Error, intente nuevamente", 0, 4, TRUE);
	return option;
}

void switchModifyEmployee(int option, eEmployee list[], int len)
{
	int id;
    int index;

	{
		switch (option)
		{
			case 0:
				//NOMBRE
				id = selectEmployeeId(list, len);
				index = findEmployeeById(list, len, id);
				editName(list, index);
				break;
			case 1:
				//APELLIDO
				id = selectEmployeeId(list, len);
				index = findEmployeeById(list, len, id);
				editLastName(list, index);
				break;
			case 2:
				//SALARIO
				id = selectEmployeeId(list, len);
				index = findEmployeeById(list, len, id);
				editSalary(list, index);
				break;
			case 3:
				//SECTOR
				id = selectEmployeeId(list, len);
				index = findEmployeeById(list, len, id);
				editSector(list, index);
			break;
		}
	}
}



int menuPrint()
{
	int option;

	printf("0. Listado de los empleados ordenados\n   por sector y por apellido alfabéticamente. \n\n");
	printf("1. Total y promedio de los salarios,\n   y cuántos empleados superan el salario promedio. \n\n");
	printf("2. VOLVER. \n");

	option = getInt("\n Elija una opción: ", "Error, intente nuevamente", 0, 2, TRUE);
	return option;
}

void switchPrint(int option, eEmployee list[], int len)
{
	int order;
	float averageSalary;
	float totalSalary;
	int betterThanAverage;
	switch (option)
	{
		case 0:
			//NOMBRE
			order = getInt("Seleccione orden ascendente(1) o descendente(0): ", "Error, intente nuevamente: ", DOWN, UP, TRUE);
			sortEmployees(list, len, order);
			printf("Empleados ordenados por sector y alfabéticamente por apellido\n\n");
			printEmployees(list, len);
			break;
		case 1:
			//APELLIDO
			totalSalary = getTotalSalary(list, len);
			averageSalary = getAverageSalary(list, len);
			betterThanAverage = getBetterThanAverage(list, len);

			printf("El total de salarios es: $%.2f\n", totalSalary);
			printf("El salario promedio es: $%.2f\n", averageSalary);
			printf("La cantidad de empleados con salarios mayor que el promedio es: %d\n\n", betterThanAverage);
		break;
	}
}
