#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "terminalFunctions.h"
#include "Employee.h"
#include "Controller.h"
#include "Menu.h"
#include "parser.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    int exit;
    int id;
    Employee_getNextId(&id);

    LinkedList* employeeList = ll_newLinkedList();
    

    do
    {
        option = mainMenu();
        switch(option)
        {
            case 1:
                exit = controller_loadFlights("data.csv",employeeList, &id);
                if(exit == -1)
                {
                    CleanConsole();
                    printf("No se han podido cargar los datos desde el archivo de texto.\n\n");
                }
                else
                {
                    CleanConsole();
                    printf("Se han cargado los datos desde el archivo de texto exitosamente.\n\n");
                }
                break;
            case 2:
                exit = controller_loadFromBinary("data.bin", employeeList, &id);
                if(exit == -1)
                {
                    CleanConsole();
                    printf("No se han podido cargar los datos desde el archivo binario.\n\n");
                }
                else
                {
                    CleanConsole();
                    printf("Se han cargado los datos desde el archivo binario exitosamente.\n\n");
                }
                break;
            case 3:
                exit = controller_addEmployee(employeeList, &id); 
                if(exit == -1)
                {
                    CleanConsole();
                    printf("No se ha podido crear un empleado\n\n");
                }
                else
                {
                    CleanConsole();
                    printf("Se ha añadido un empleado exitosamente.\n\n");
                }
                break;
            case 4:
                exit = controller_editEmployee(employeeList);
                if (exit == -1)
                {
                    CleanConsole();
                    printf("No se ha editado un empleado\n\n");
                }
                else
                {
                    CleanConsole();
                    printf("Se ha editado un empleado exitosamente.\n\n");
                }
                break;
            case 5:
                exit = controller_removeEmployee(employeeList);
                if (exit == -1)
                {
                    CleanConsole();
                    printf("No se ha removido un empleado\n\n");
                }
                else
                {
                    CleanConsole();
                    printf("Se ha eliminado un empleado exitosamente.\n\n");
                }
                
                break;
            case 6:
                exit = controller_ListFlights(employeeList);
                if (exit == -1)
                {
                    CleanConsole();
                    printf("No se han podido listar a los empleados\n\n");
                }
                
                break;
            case 7:
                exit = controller_sortEmployee(employeeList);
                if (exit == -1)
                {
                    CleanConsole();
                    printf("No se ha ordenado a los empleados\n\n");
                }
                else
                {
                    CleanConsole();
                    printf("Se ha ordenado a los empleados exitosamente.\n\n");
                }
                break;
            case 8:
                exit = controller_saveAsText("data.csv", employeeList, &id);
                if(exit == -1)
                {
                    CleanConsole();
                    printf("No se han podido guardar los datos en el archivo de texto.\n\n");
                }
                else
                {
                    CleanConsole();
                    printf("Se han guardado los datos en el archivo de texto exitosamente.\n\n");
                }
                break;
            case 9:
                exit = controller_saveAsBinary("data.bin", employeeList, &id);
                if(exit == -1)
                {
                    CleanConsole();
                    printf("No se han podido guardar los datos en el archivo binario.\n\n");
                }
                else
                {
                    CleanConsole();
                    printf("Se han guardado los datos en el archivo binario exitosamente.\n\n");
                }
            break;
        }
    }while(option != 10);
    return 0;
}

