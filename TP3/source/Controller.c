#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "getFunctions.h"
#include "terminalFunctions.h"
#include "Employee.h"
#include "parser.h"
#include "Menu.h"  


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee, int* id)
{
    int exit;
    int len;
    FILE* pFile = fopen(path, "r");
    fclose(pFile);

    if (pFile != NULL)
    {
        ll_clear(pArrayListEmployee);
        exit = parser_EmployeeFromText(pFile, pArrayListEmployee);

        len = ll_len(pArrayListEmployee);

        if (exit > -1)
        {
            Employee_initId(id, pArrayListEmployee, len);
        }
    }
    return exit;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee, int* id)
{
    int exit = -1;
    int len;
    FILE* pFile = fopen(path, "rb");

    ll_clear(pArrayListEmployee);
    if (pFile != NULL)
    {
        exit = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
        fclose(pFile);

        len = ll_len(pArrayListEmployee);

        if (exit > -1)
        {
            Employee_initId(id, pArrayListEmployee, len);
        }
    }
    return exit;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* id)
{
    int exit = -1;
    Employee* ptrEmployee;
    int flagIsEmpty;

    CleanConsole();
    flagIsEmpty = ll_isEmpty(pArrayListEmployee);

    if(flagIsEmpty == 0)
    {
        ptrEmployee = employee_fillData(pArrayListEmployee, id);
        if (ptrEmployee != NULL)
        {
            exit = ll_add(pArrayListEmployee, ptrEmployee);
            if (exit > -1)
            {
                *id = *id + 1;
            }
        }
    }
    return exit;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int exit = -1;
    int option;
    Employee* pAux;
    int flagIsEmpty;
    flagIsEmpty = ll_isEmpty(pArrayListEmployee);
    if (flagIsEmpty == 0)
    {
        pAux = employee_selectEmployeeById(pArrayListEmployee);
        if (pAux != NULL)
        {
            option = menu_ModifyEmployee();
            exit = controller_switchModifyEmployee(option, pArrayListEmployee);
        }  
    }
    
    return exit;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int exit = -1;
    Employee* pAux;
    int flagIsEmpty;
    flagIsEmpty = ll_isEmpty(pArrayListEmployee);
    if (flagIsEmpty == 0)
    {
        pAux = employee_selectEmployeeById(pArrayListEmployee);
        if (pAux != NULL)
        {
            exit = employee_removeEmployee(pAux, pArrayListEmployee);
        }
    }
    return exit;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int exit = employee_printAll(pArrayListEmployee);
    return exit;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int exit = -1;
    int order;
    int option;

    int flagIsEmpty;
    flagIsEmpty = ll_isEmpty(pArrayListEmployee);
    if (flagIsEmpty == 0)
    {
        option = menu_sort();

        switch (option)
        {
            case 0:
                //NOMBRE
                order = getInt("Seleccione orden ascendente(1) o descendente(0): ", "Error, seleccione orden ascendente(1) o descendente(0): ", 0, 1, TRUE);
                exit = ll_sort(pArrayListEmployee, employee_compareByName, order);
                break;
            case 1:
                //HORAS TRABAJADAS
                order = getInt("Seleccione orden ascendente(1) o descendente(0): ", "Error, seleccione orden ascendente(1) o descendente(0): ", 0, 1, TRUE);
                exit = ll_sort(pArrayListEmployee, employee_compareByHorasTrabajadas, order);
                break;
            case 2:
                //SUELDO
                order = getInt("Seleccione orden ascendente(1) o descendente(0): ", "Error, seleccione orden ascendente(1) o descendente(0): ", 0, 1, TRUE);
                exit = ll_sort(pArrayListEmployee, employee_compareBySueldo, order);
            break;
        }
    }
    return exit;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee, int* id)
{
    int exit = -1;
    int flagIsEmpty;
    FILE* pFile = fopen(path, "r");
    fclose(pFile);

    flagIsEmpty = ll_isEmpty(pArrayListEmployee);
    if (flagIsEmpty == 0)
    {
        exit = employee_saveTxt(pArrayListEmployee, pFile, path);
        if (exit > -1)
        {
            exit = Employee_saveNextId(id);
        } 
    }
    return exit;
}

/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee, int* id)
{
    int exit = -1;
    int flagIsEmpty;
    FILE* pFile;

    flagIsEmpty = ll_isEmpty(pArrayListEmployee);
    if (flagIsEmpty == 0)
    {
        pFile = fopen(path, "wb");
        fclose(pFile);
        exit = employee_saveBin(pArrayListEmployee, pFile, path);
        if (exit > -1)
        {
            exit = Employee_saveNextId(id);
        }
    }
    return exit;
}


int controller_switchModifyEmployee(int option, Employee* this)
{
    int exit = -1;
	switch (option)
	{
		case 0:
			//NOMBRE
			exit = employee_editName(this);
			break;
		case 1:
			//HORAS TRABAJADAS
			exit = employee_editHorasTrabajadas(this);
			break;
		case 2:
			//SUELDO
			exit = employee_editSueldo(this);
		break;
	}
    return exit;
}
