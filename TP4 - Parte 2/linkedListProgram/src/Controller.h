/**
 * @brief Switch para llamar a la función correspondiente según la opción elegida en el menú de modificar empleado.
 * 
 * @param option 
 * @param this 
 * @return int Devuelve -1 en caso de error o de cancelar y 0 si se modificó correctamente 
 */
int controller_switchModifyEmployee(int option, Employee* this);
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee, int* id);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee, int* id);
int controller_addEmployee(LinkedList* pArrayListEmployee, int* id);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee, int* id);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee, int* id);


