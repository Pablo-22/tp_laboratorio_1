#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Employee.h"
#include "getFunctions.h"
#include "terminalFunctions.h"

Employee* employee_new(void)
{
    Employee* pAux;
    pAux = (Employee*)malloc(sizeof(Employee));
    return pAux;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr, int* idNum)
{
    Employee* pAux;

    int idAux;
    int horasTrabajadasAux;
    int sueldoAux;

    if (*idNum == -1)
    {
        idAux = atoi(idStr);
    }
    else
    {
        idAux = *idNum;
    }
    
    horasTrabajadasAux = atoi(horasTrabajadasStr);
    sueldoAux = atoi(sueldoStr);

    pAux = employee_new();
    if(pAux != NULL)
    {
        if(employee_setAll(&idAux, nombreStr, &horasTrabajadasAux, &sueldoAux, pAux) == -1)
        {
            free(pAux);
            pAux = NULL;
            printf("\n**Error - Intente nuevamente**\n");
        }
    }
    return pAux;
}


Employee* employee_newParametrosNormal(int* id,char* nombre,int* horasTrabajadas, int* sueldo)
{
    Employee* pAux;

    pAux = employee_new();
    if(pAux != NULL)
    {
        if(employee_setAll(id, nombre, horasTrabajadas, sueldo, pAux) == -1)
        {
            free(pAux);
            pAux = NULL;
            printf("\n**Error - Intente nuevamente**\n");
        }
    }
    return pAux;
}


Employee* employee_fillData(LinkedList* pArrayListEmployee, int* id)
{
    char bufferNombre[128];
    int auxHorasTrabajadas;
    int auxSueldo;
    Employee* pAux = employee_new();

    if(pAux != NULL)
    {
        do
        {
            getString("Ingrese nombre: ","Error, intente nuevamente", bufferNombre);
            auxHorasTrabajadas = getInt("Ingrese cantidad de horas trabajadas: ","Error, intente nuevamente", 0, 0, FALSE);
            auxSueldo = getInt("Ingrese sueldo del empleado: ","Error, intente nuevamente",0,0,FALSE);
            pAux = employee_newParametrosNormal(id,bufferNombre, &auxHorasTrabajadas, &auxSueldo);
        } while (pAux == NULL);
    }
	return pAux;
}


int employee_print(Employee* this)
{
    int exit = -1;
    if(this != NULL)
    {
        printf("ID: %d - NOMBRE: %s - HORAS: %d - SUELDO: %d\n", this->id, this->nombre, this->horasTrabajadas, this->sueldo);
        exit = 0;
    }
    return exit;
}

int employee_printAll(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee = employee_new();
    int exit = -1;
    int i;
    int len = ll_len(pArrayListEmployee);

    CleanConsole();

    if(auxEmployee != NULL && len > 0)
    {
        for (i = 0; i < len; i++)
        {
            auxEmployee = ll_get(pArrayListEmployee, i);
            exit = employee_print(auxEmployee);
        }
    }
    return exit;
}

int employee_setAll(int* id,char* nombre,int* horasTrabajadas, int* sueldo, Employee* this)
{
    int exit = 0;

    if(employee_setId(this, id) == -1 || 
        employee_setNombre(this, nombre) == -1 || 
        employee_setHorasTrabajadas(this, horasTrabajadas) == -1 || 
        employee_setSueldo(this, sueldo) == -1)
    {
        exit = -1;
    }
    return exit;
}

int employee_getAll(int* id,char* nombre,int* horasTrabajadas, int* sueldo, Employee* this)
{
    int exit = 0;

    if(employee_getId(this, id) == -1 || 
        employee_getNombre(this, nombre) == -1 || 
        employee_getHorasTrabajadas(this, horasTrabajadas) == -1 || 
        employee_getSueldo(this, sueldo) == -1)
    {
        exit = -1;
    }
    return exit;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int exit = -1;

    if(this != NULL && nombre != NULL)
    {
        if(isValidName(nombre))
        {
            strncpy(this->nombre, nombre, NOMBRE_LEN);
            exit = 0;
        }
    }

    return exit;
}

int isValidName(char* name)
{
    int exit = 0;

    int len = strlen(name);

    if(name != NULL && len > 0)
    {
        exit = -1;
    }
    return exit;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int exit = -1;

    if(this != NULL && nombre != NULL)
    {
        strncpy(nombre, this->nombre, NOMBRE_LEN);
        exit = 0;
    }
    return exit;
}


int employee_setId(Employee* this,int* id)
{
    int exit = -1;

    if(this != NULL && id != NULL)
    {
        this->id = *id;
        exit = 0;
    }
    return exit;
}


int employee_getId(Employee* this,int* id)
{
    int exit = -1;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        exit = 0;
    }
    return exit;
}


int employee_setHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int exit = -1;

    if(this != NULL && isValidHorasTrabajadas(*horasTrabajadas) == 0)
    {
        this->horasTrabajadas = *horasTrabajadas;
        exit = 0;
    }
    return exit;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int exit = -1;

    if(this != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        exit = 0;
    }
    return exit;
}


int employee_setSueldo(Employee* this,int* sueldo)
{
    int exit = -1;

    if(this != NULL && isValidSueldo(*sueldo) == 0)
    {
        this->sueldo = *sueldo;
        exit = 0;
    }
    return exit;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int exit = -1;

    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        exit = 0;
    }
    return exit;
}



int isValidHorasTrabajadas(int horasTrabajadas)
{
    int exit = -1;
    if(horasTrabajadas > 0 && horasTrabajadas < 1000)
    {
        exit = 0;
    }
    return exit;
}


int isValidSueldo(int sueldo)
{
    int exit = -1;

    if(sueldo > 0 && sueldo < 500000)
    {
        exit = 0;
    }
    return exit;
}

void Employee_initId(int* nextId, LinkedList* this, int len)
{
    if (len > *nextId)
    {
        *nextId = len + 1;
    }
}

int Employee_getNextId(int* nextId)
{
    FILE* pFileId;
    char bufferId[10];
    int exit = -1;

    pFileId = fopen("/home/pablocordoba/eclipse-workspace-new/TP3/source/nextId.txt", "r");

    if (pFileId != NULL)
    {
        fgets(bufferId, 9, pFileId);
        *nextId = atoi(bufferId);
        exit = 0;
    }
    fclose(pFileId);
    return exit;
}


int Employee_saveNextId(int* nextId)
{
    FILE* pFileId;
    int exit = -1;

    pFileId = fopen("/home/pablocordoba/eclipse-workspace-new/TP3/source/nextId.txt", "w");

    if (pFileId != NULL)
    {
        fprintf(pFileId,"%d", *nextId);
        exit = 0;
    }
    fclose(pFileId);
    return exit;
}



Employee* employee_selectEmployeeById(LinkedList* pArrayListEmployee)
{
    int exit;
    int selectedId;
    int flagIdFinded = 0;
    int len;
    Employee* pAux;
    int auxId;
    int i = 0;

    CleanConsole();
    len = ll_len(pArrayListEmployee);
    employee_printAll(pArrayListEmployee);


    do
    {
        if (i > 0)
        {
            printf("Error, intente nuevamente\n");
        }
        selectedId = getInt("Seleccione un ID: ", "", 0, 0, FALSE);
        for (i = 0; i < len; i++)
        {
            pAux = ll_get(pArrayListEmployee, i);
            if (pAux != NULL)
            {
                exit = employee_getId(pAux, &auxId);
                if (exit != -1 && auxId == selectedId)
                {
                    flagIdFinded = 1;
                    break;
                }
            }
        } 
    }while (flagIdFinded < 1);

    return pAux;
}


int employee_editName(Employee* this)
{
	char name[128];
	char answer;
    int id;
    int exit;
    exit = employee_getId(this, &id);
    if (exit > -1)
    {
        getString("Ingrese el nuevo nombre del empleado: ","Error, intente nuevamente", name);

        printf("El nombre del empleado de ID %d pasará a ser: %s. \n\n", id, name);
        answer = getChar("¿Desea confirmar este cambio? (s/n): ", "Error, intente nuevamente", 's', 'n', TRUE);
        if(answer == 's')
        {
            exit = employee_setNombre(this, name);
        }
        else
        {
            exit = -1;
        }
    }
	CleanConsole();
    return exit;
}


int employee_editHorasTrabajadas(Employee* this)
{
	int horasTrabajadas;
	char answer;
    int id;
    int exit;
    exit = employee_getId(this, &id);
    if (exit > -1)
    {
        do
        {
            horasTrabajadas = getInt("Ingrese la nueva cantidad de horas trabajadas: ", "", 0, 0, FALSE);
            exit = isValidHorasTrabajadas(horasTrabajadas);
        }while (exit == -1);
        

        printf("la cantidad de horas trabajadas del empleado de ID %d pasará a ser: %d. \n\n", id, horasTrabajadas);
        answer = getChar("¿Desea confirmar este cambio? (s/n): ", "Error, intente nuevamente", 's', 'n', TRUE);
        if(answer == 's')
        {
            exit = employee_setHorasTrabajadas(this, &horasTrabajadas);
        }
        else
        {
            exit = -1;
        }
    }
	CleanConsole();
    return exit;
}


int employee_editSueldo(Employee* this)
{
	int sueldo;
	char answer;
    int id;
    int exit = -1;
    exit = employee_getId(this, &id);
    if (exit > -1)
    {
        do
        {
            sueldo = getInt("Ingrese el nuevo sueldo: ", "", 0, 0, FALSE);
            exit = isValidSueldo(sueldo);
        } while (exit == -1);

        printf("El sueldo del empleado de ID %d pasará a ser: %d. \n\n", id, sueldo);
        answer = getChar("¿Desea confirmar este cambio? (s/n): ", "Error, intente nuevamente", 's', 'n', TRUE);
        if(answer == 's')
        {
            exit = employee_setSueldo(this, &sueldo);
        }
        else
        {
            exit = -1;
        }
    }
	CleanConsole();
    return exit;
} 


int employee_removeEmployee(Employee* this, LinkedList* pArrayListEmployee)
{
    char answer;
    int id;
    int index;
    int exit = -1;

    exit = employee_getId(this, &id);
    if (exit > -1)
    {
        printf("Se eliminará al siguiente empleado:\n");
        employee_print(this);
        answer = getChar("¿Desea confirmar esta eliminación? (s/n): ", "Error, intente nuevamente", 's', 'n', TRUE);
        if(answer == 's')
        {
            index = employee_getIndexByPtr(this, pArrayListEmployee);
            exit = ll_remove(pArrayListEmployee, index);
        }
        else
        {
            exit = -1;
        }
        
    }
    return exit;
}


int employee_getIndexByPtr(Employee* this, LinkedList* pArrayListEmployee)
{
    int exit;
    int len;
    Employee* pAux;
    int id;
    int auxId;
    int i = -1;

    len = ll_len(pArrayListEmployee);

    exit = employee_getId(this, &id);
    if (exit > -1)
    {
        for (i = 0; i < len; i++)
        {
            pAux = ll_get(pArrayListEmployee, i);
            exit = employee_getId(pAux, &auxId);
            if (exit != -1 && auxId == id)
            {
                break;
            }
        }
    }
    return i;
}


int employee_compareByName(void* pEmployeeA,void* pEmployeeB)
{
    char nameA[128];
    char nameB[128];
    int result;

    if (employee_getNombre((Employee*)pEmployeeA, nameA) > -1 && 
        employee_getNombre((Employee*)pEmployeeB, nameB) > -1)
    {
        result = strcmp(nameA, nameB); 
        /*El strcmp no devuelve exactamente 1/0/-1, sino números 
        mayores/menores/iguales a cero, por lo que hace falta 
        realizar las siguientes comparaciones. */
        if(result > 0)
        {
            result = 1;
        }
        else
        {
            if(result < 0)
            {
                result = -1;
            }
            else
            {
                result = 0;
            }
        }
    }
    return result;
}

int employee_compareBySueldo(void* pEmployeeA,void* pEmployeeB)
{
    int sueldoA;
    int sueldoB;
    int result;

    if (employee_getSueldo((Employee*)pEmployeeA, &sueldoA) != -1 &&
        employee_getSueldo((Employee*)pEmployeeB, &sueldoB) != -1)
    {
        if(sueldoA > sueldoB)
        {
            result = 1;
        }
        else
        {
            if(sueldoA < sueldoB)
            {
                result = -1;
            }
            else
            {
                result = 0;
            }
        }      
    }
    return result;
}


int employee_compareByHorasTrabajadas(void* pEmployeeA,void* pEmployeeB)
{
    int horasTrabajadasA;
    int horasTrabajadasB;
    int result;

    if (employee_getHorasTrabajadas((Employee*)pEmployeeA, &horasTrabajadasA) != -1 &&
        employee_getHorasTrabajadas((Employee*)pEmployeeB, &horasTrabajadasB) != -1)
    {
        if(horasTrabajadasA > horasTrabajadasB)
        {
            result = 1;
        }
        else
        {
            if(horasTrabajadasA < horasTrabajadasB)
            {
                result = -1;
            }
            else
            {
                result = 0;
            }
        }      
    }
    return result;
}


int employee_saveTxt(LinkedList* pArrayListEmployee, FILE* pFile, char* path)
{
    int exit = -1;
    int len;
    char nombreAux[128];
    int idAux;
    int horasTrabajadasAux;
    int sueldoAux;
    Employee* pAux;

    len = ll_len(pArrayListEmployee);
    pFile = fopen(path, "w");
    if (pFile != NULL && pArrayListEmployee != NULL)
    {
        fprintf(pFile, "%s,%s,%s,%s\n","id","nombre","horasTrabajadas","sueldo");
        for (int i = 0; i < len; i++)
        {
            pAux = ll_get(pArrayListEmployee, i);
            if (pAux != NULL)
            {
                if (employee_getAll(&idAux, nombreAux, &horasTrabajadasAux, &sueldoAux, pAux) > -1)
                {
                    fprintf(pFile, "%d,%s,%d,%d\n", idAux, nombreAux, horasTrabajadasAux, sueldoAux);
                    exit = 0;
                }
            }
        }
    }
    fclose(pFile);
    return exit;
}


int employee_saveBin(LinkedList* pArrayListEmployee, FILE* pFile, char* path)
{
    int exit = -1;
    int len;
    char nombreAux[128];
    int idAux;
    int horasTrabajadasAux;
    int sueldoAux;
    Employee* pAux;

    len = ll_len(pArrayListEmployee);
    pFile = fopen(path, "wb");
    if (pFile != NULL && pArrayListEmployee != NULL)
    {
        for (int i = 0; i < len; i++)
        {
            pAux = ll_get(pArrayListEmployee, i);
            if (pAux != NULL)
            {
                if (employee_getAll(&idAux, nombreAux, &horasTrabajadasAux, &sueldoAux, pAux) > -1)
                {
                    if(fwrite(pAux, sizeof(Employee),1, pFile) == 1)
                    {
                        exit = 0;
                    }
                }
            }
        }
    }
    fclose(pFile);
    return exit;
}
