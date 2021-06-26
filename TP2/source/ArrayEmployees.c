#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "TerminalFunctions.h"
#include "GetFunctions.h"
#include "ArrayEmployees.h"
#include "Menu.h"

void hardcodeEmployee(eEmployee list[], int amountOfElements)
{
	int i; //isEmpty, id, nombreMascota, idServicio, Fecha
	int isEmpty[]={FULL,FULL,FULL,FULL,FULL,FULL,FULL,};
	char name[][51]={"Pablo", "German", "Pedro", "Damian", "Maximo", "Martin", "Matias"};
	char lastName[][51]={"Cordoba", "Lopez", "Hernandez", "Rossi", "Trejo", "Novella", "Bustamente"};
	int id[]={45,47,48,43,41,38,50};
	float salary[]={54500,47300,48400,43212,41485,38488,50345};
	int sector[] = {3,4,2,5,2,6,8};

	for(i=0;i<amountOfElements;i++)
	{
		list[i].isEmpty=isEmpty[i];
		strcpy(list[i].name, name[i]);
		strcpy(list[i].lastName, lastName[i]);
		list[i].salary = salary[i];
		list[i].id = id[i];
		list[i].sector = sector[i];
	}
}


int getIdEmployee(eEmployee list[], int len)
{
	int mayorId;
	int idGenerada;
	int i;

	for(i = 0; i < len; i++)
	{
		if (list[i].id > mayorId || i == 0)
		{
			mayorId = list[i].id;
		}
	}

	idGenerada = mayorId + 1;

	return idGenerada;
}


int initEmployees(eEmployee list[], int len)
{
    int i;
	for(i = 0; i < len; i++)
	{
		list[i].isEmpty = EMPTY;
		list[i].id = 0;
	}

	return 1;
}


int getNewEmployeeData(eEmployee list[], int len)
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sectorNumber;
	int flagReturn;
    
    id = getIdEmployee(list, len);

    getString("Ingrese nombre del empleado: ", "Error, intente nuevamente: ", name);
    getString("Ingrese apellido del empleado: ", "Error, intente nuevamente: ",  lastName);
    salary = getFloat("Ingrese salario: ", "Error, intente nuevamente: ", 1, 1000000, TRUE);

    sectorNumber = getInt("Ingrese sector: ", "Error, intente nuevamente: ", 1,100, TRUE);

    flagReturn = addEmployee(list, len, id, name, lastName, salary, sectorNumber);
	return flagReturn;
}


int addEmployee(eEmployee list[], int len, int id, char name[],char
lastName[],float salary,int sector)
{
    int allGoodHere; // FLAG
    int index;

    index = lookingForFreeSpace(list, len);
    if (index == -1)
    {
        allGoodHere = FALSE;
    }
    else
    {
        list[index].id = id;
        strcpy(list[index].name, name);
        strcpy(list[index].lastName, lastName);
        list[index].salary = salary;
        list[index].sector = sector;
        list[index].isEmpty = FULL;
        allGoodHere = TRUE;
    }
    
    return allGoodHere;
}


int lookingForFreeSpace(eEmployee list[], int len)
{
    int i;
	int index;
	index = FULL;

	for (i = 0; i < len; i++)
	{
		if (list[i].isEmpty == EMPTY)
		{
			index = i;
			break;
		}
	}
	return index;
}

int CheckEmpty(eEmployee list[], int len)
{
    int i;
	int flagIsEmpty;
	flagIsEmpty = TRUE;

	for (i = 0; i < len; i++)
	{
		if (list[i].isEmpty == FULL)
		{
			flagIsEmpty = FALSE;
			break;
		}
	}
	return flagIsEmpty;
}

void printEmployee(eEmployee list, int nameMaxLen, int lastNameMaxLen)
{
	if(list.isEmpty == FULL)
	{

		printf("|%d| ", list.id);
		printf("|%*s| ", nameMaxLen, list.name);
		printf("|%*s| ", lastNameMaxLen, list.lastName);
		printf("|%-2d| ", list.sector);
		printf("|$%-5.2f \n", list.salary);
	}
}

int printEmployees(eEmployee list[], int len)
{
	int i;
    int nameMaxLen;
    int lastNameMaxLen;

	nameMaxLen = getNameMaxLen(list, len) * -1;
	lastNameMaxLen = getLastNameMaxLen(list, len) * -1;

	for (i = 0; i < len; i++)
	{
		printEmployee(list[i], nameMaxLen, lastNameMaxLen);
	}

	printf("\n\n");

	return 1;
}



int getNameMaxLen(eEmployee list[], int len)
{
	int maxLen;
	int actualLen;
	int i;

	for (i = 0; i < len; i++)
	{
		actualLen = strlen(list[i].name);

		if (actualLen > maxLen || i == 0)
		{
			maxLen = actualLen;
		}
	}
    return maxLen;
}

int getLastNameMaxLen(eEmployee list[], int len)
{
	int maxLen;
	int actualLen;
	int i;

	for (i = 0; i < len; i++)
	{
		actualLen = strlen(list[i].lastName);

		if (actualLen > maxLen || i == 0)
		{
			maxLen = actualLen;
		}
	}
    return maxLen;
}


int removeEmployee(eEmployee list[], int len, int id)
{
	char confirmacion;
	int indexEmployee;
	int nameMaxLen;
	int lastNameMaxLen;
	int flagReturn = 0;


	indexEmployee = findEmployeeById(list, len, id);

	nameMaxLen = getNameMaxLen(list, len) * -1;
	lastNameMaxLen = getLastNameMaxLen(list, len) * -1;
	printEmployee(list[indexEmployee], nameMaxLen, lastNameMaxLen);

	confirmacion = getChar("¿Está seguro de que desea eliminar este empleado? (s/n): ", "Error, intente nuevamente (s/n): ", 's', 'n', TRUE);

	if(confirmacion == 's')
	{
		list[indexEmployee].isEmpty = EMPTY;
		flagReturn = 1;
	}

	return flagReturn;
}


int findEmployeeById(eEmployee list[], int len,int id)
{
	int i;
	int index;
	index = EMPTY;
	
	for (i = 0; i < len; i++)
	{
		if (id == list[i].id && list[i].isEmpty == FULL)
		{
			index = i;
			break;
		}
	}
	return index;
}


int selectEmployeeId(eEmployee list[], int len)
{
	int id;
	int employeeFound;

	CleanConsole();

	do
	{
		printEmployees(list, len);
		id = getInt("Ingrese ID del empleado: ", "", FALSE, FALSE, FALSE);
		employeeFound = findEmployeeById(list, len, id);
		indexValidation(employeeFound);
	} while (employeeFound == -1);
	
	return id;
}


void editName(eEmployee list[], int index)
{
	char name[51];
	char answer;

	getString("Ingrese el nuevo nombre del empleado: ", "Error, intente nuevamente: ", name);

	printf("El nombre del empleado de ID %d pasará a ser: %s. \n\n", list[index].id, name);
	answer = getChar("¿Desea confirmar este cambio? (s/n): ", "Error, intente nuevamente", 's', 'n', TRUE);
	if(answer == 's')
	{
		strcpy(list[index].name, name);
	}
	CleanConsole();
}

void editLastName(eEmployee list[], int index)
{
	char lastName[51];
	char answer;

	getString("Ingrese nuevo apellido del empleado: ", "Error, intente nuevamente: ", lastName);

	printf("El apellido del empleado de ID %d pasará a ser: %s. \n\n", list[index].id, lastName);
	answer = getChar("¿Desea confirmar este cambio? (s/n): ", "Error, intente nuevamente", 's', 'n', TRUE);
	if(answer == 's')
	{
		strcpy(list[index].lastName, lastName);
	}
	CleanConsole();
}

void editSalary(eEmployee list[], int index)
{
	float salary;
	char answer;

	salary = getFloat("Ingrese salario: ", "Error, intente nuevamente: ", 1, 1000000, TRUE);
	printf("El salario del empleado de ID %d pasará a ser: %.2f. \n\n", list[index].id, salary);
	answer = getChar("¿Desea confirmar este cambio? (s/n): ", "Error, intente nuevamente", 's', 'n', TRUE);
	if(answer == 's')
	{
		list[index].salary = salary;
	}
	CleanConsole();
}

void editSector(eEmployee list[], int index)
{
	int sector;
	char answer;

	sector = getInt("Ingrese sector (1-10): ", "Error, intente nuevamente: ", 1,10, TRUE);
	printf("El sector del empleado de ID %d pasará a ser: %d. \n\n", list[index].id, sector);
	answer = getChar("¿Desea confirmar este cambio? (s/n): ", "Error, intente nuevamente", 's', 'n', TRUE);
	if(answer == 's')
	{
		list[index].sector = sector;
	}
	CleanConsole();
}


int sortEmployees(eEmployee list[], int len, int order)
{
	int i;
    int j;
	int flagCondition;

	for (i = 0; i < len - 1; i++)
	{
		for (j = i+1; j < len; j++)
		{
			flagCondition = compareSectors(list, i, j, order);
			if (flagCondition == FALSE)
			{
				compareLastNames(list, i, j, order);
			}
		}
	}

	return 1;
}

int compareSectors(eEmployee list[],int i,int j,int order)
{
	int flagCondition;

	if (list[i].sector == list[j].sector)
	{
		flagCondition = FALSE;
	}
	else
	{
		if (order == UP)
		{
			if (list[i].sector > list[j].sector)
			{
				flagCondition =	swap(list,i, j);
			}
		}
		else
		{
			if (list[i].sector < list[j].sector)
			{
				flagCondition =	swap(list,i, j);
			}			
		}
	}

	return flagCondition;
}

int compareLastNames(eEmployee list[],int i,int j,int order)
{
	int flagCondition;

	char cadena1[51];
    char cadena2[51];
    char resultOfStringComparation;

	strcpy(cadena1, list[i].lastName);
	strcpy(cadena2, list[j].lastName);

	resultOfStringComparation = strcmp(cadena1, cadena2);

	if (resultOfStringComparation == 1)
	{
		if (order == UP)
		{
			if (resultOfStringComparation > 1)
			{
				flagCondition =	swap(list,i, j);
			}
		}
		else
		{
			if (resultOfStringComparation < 1)
			{
				flagCondition =	swap(list,i, j);
			}
		}
	}
	return flagCondition;
}

int swap(eEmployee list[], int i, int j)
{
	eEmployee auxiliar;

	auxiliar = list[i];
	list[i] = list[j];
	list[j] = auxiliar;

	return TRUE;
}


float getAverageSalary(eEmployee list[], int len)
{
	float accumulator = 0;
	float average;
	int i;

	for (i = 0; i < len; i++)
	{
		accumulator += list[i].salary;
	}

	if(i > 0)
	{
		average = accumulator / i;
	}
	else
	{
		average = 0;
	}
	return average;
}

int getTotalSalary(eEmployee list[], int len)
{
	float accumulator = 0;

	for (int i = 0; i < len; i++)
	{
		accumulator += list[i].salary;
	}
	return accumulator;
}

int getBetterThanAverage(eEmployee list[], int len)
{
	int count = 0;
	float average;
	average = getAverageSalary(list, len);

	for (int i = 0; i < len; i++)
	{
		if(list[i].salary > average)
		{
			count++;
		}
	}
	return count;
}
