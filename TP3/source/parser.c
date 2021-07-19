#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "getFunctions.h"
#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int exit = -1;

    char auxId[128];
    char auxHorasTrabajadas[128];
    char auxSueldo[128];
    char auxNombre[128];
    int flagId = -1;
    int* pFlagId = &flagId;

    Employee* pAux; 

    if (pFile != NULL && pArrayListEmployee != NULL)
    {

        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);

        while (!feof(pFile))
        {
            
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
            
            if (feof(pFile))
            {
                break;
            }

            pAux = employee_newParametros(auxId, auxNombre, auxHorasTrabajadas, auxSueldo, pFlagId);
            if (pAux != NULL)
            {
                exit = ll_add(pArrayListEmployee, pAux);  
            }
        }
    }
    return exit;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int exit = -1;

    int auxId;
    int auxHorasTrabajadas;
    int auxSueldo;
    char auxNombre[CHAR_LEN];
    Employee* pAux; 

    if (pFile != NULL && pArrayListEmployee != NULL)
    {
        while (!feof(pFile))
        {
            pAux = employee_new();
            if(fread(pAux, sizeof(Employee),1, pFile) == 1)
            {
                if(employee_getAll(&auxId, auxNombre, &auxHorasTrabajadas, &auxSueldo, pAux) > -1 && pAux != NULL)
                {
                    exit = ll_add(pArrayListEmployee, pAux);  
                }
                else
                {
                    free(pAux);
                }
            }            
        }
    }
    return exit;
}


/*
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int exit = -1;

    Employee* pAux;
    while (!feof(pFile))
    {
        pAux = employee_new();
        if (feof(pFile))
        {
            break;
        }
        if (fread(pAux, sizeof(Employee),1,pFile)== 1)
        {
            employee_print(pAux);
            ll_add(pArrayListEmployee,pAux);
            exit = 0;
        }
    }
    return exit;
}
*/
