#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

#define NOMBRE_LEN 128

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr, int* idNum);

/**
 * @brief Constructor de un empleado con parámetros, pero sin parseo. Se utiliza al descargar los datos desde el archivo binario, que ya se reciben en el tipo de variable correspondiente.
 * 
 * @param id 
 * @param nombre 
 * @param horasTrabajadas 
 * @param sueldo 
 * @return Employee* Devuelve un puntero al emnpleado creado en memoria
 */
Employee* employee_newParametrosNormal(int* id,char* nombre,int* horasTrabajadas, int* sueldo);
void employee_delete();

int employee_setId(Employee* this,int* id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int* horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int* sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

/**
 * @brief Esta función llama a todos los setters de una vez. Se creó para ahorrar código.
 * 
 * @param id 
 * @param nombre 
 * @param horasTrabajadas 
 * @param sueldo 
 * @param this 
 * @return int  Devuelve -1 si hubo un error o 0 si todo se pudo setear correctamente.
 */
int employee_setAll(int* id,char* nombre,int* horasTrabajadas, int* sueldo, Employee* this);

/**
 * @brief Esta función llama a todos los getters de una vez. Se creó para ahorrar código.
 * 
 * @param id 
 * @param nombre 
 * @param horasTrabajadas 
 * @param sueldo 
 * @param this 
 * @return int  Devuelve -1 si hubo un error o 0 si todo se pudo setear correctamente.
 */
int employee_getAll(int* id,char* nombre,int* horasTrabajadas, int* sueldo, Employee* this);


/**
 * @brief La función que pide los datos al usuario cuando quiere añadir un nuevo empleado y llama al constructor con parámetros.
 * 
 * @param listEmployees 
 * @param id 
 * @return Employee*  devuelve un puntero al empleado creado.
 */
Employee* employee_fillData(LinkedList* listEmployees, int* id);
int employee_printAll(LinkedList* listEmployees);
int employee_print(Employee* this);

/**
 * @brief Validación del nombre
 * 
 * @param name 
 * @return int Devuelve -1 si hubo un error o 0 si todo funcionó correctamente.
 */
int isValidName(char* name);

/**
 * @brief Validación de horas trabajadas - Entre 1 y 1000
 * 
 * @param horasTrabajadas 
 * @return int Devuelve -1 si hubo un error o 0 si todo funcionó correctamente.
 */
int isValidHorasTrabajadas(int horasTrabajadas);

/**
 * @brief Validación del sueldo - Entre 1 y 500000
 * 
 * @param sueldo 
 * @return int Devuelve -1 si hubo un error o 0 si todo funcionó correctamente.
 */
int isValidSueldo(int sueldo);

/**
 * @brief Descarga desde el archivo id.txt el próximo id que se utilizará.
 * 
 * @param id Puntero a la variable ID creada en el main donde se cargará el id descargado.
 * @return int Devuelve -1 si hubo un error o 0 si todo funcionó correctamente.
 */
int Employee_getNextId(int* id);

/**
 * @brief Si el tamaño del ll es mayor al número de ID descargado se resetea, es decir, que convierte el valor del id en len + 1
 * 
 * @param id 
 * @param this 
 * @param len 
 */
void Employee_initId(int* id, LinkedList* this, int len);

/**
 * @brief Guarda el próximo id en el archivo.
 * 
 * @param id 
 * @return int Devuelve -1 si hubo un error o 0 si todo funcionó correctamente.
 */
int Employee_saveNextId(int* id);

/**
 * @brief Muestra el listado de empleados al usuario, le pide que seleccione uno mediante su ID y lo retorna como puntero.
 * 
 * @param listEmployees 
 * @return Employee*  retorna puntero al empleado seleccionado.
 */
Employee* employee_selectEmployeeById(LinkedList* listEmployees);

/**
 * @brief Función para modificar el nombre de un empleado.
 * 
 * @param this 
 * @return int Devuelve -1 si hubo un error o 0 si todo funcionó correctamente.
 */
int employee_editName(Employee* this);

/**
 * @brief Función para modificar las horas trabajadas de un empleado.
 * 
 * @param this 
 * @return int Devuelve -1 si hubo un error o 0 si todo funcionó correctamente.
 */
int employee_editHorasTrabajadas(Employee* this);

/**
 * @brief Función para modificar el sueldo de un empleado.
 * 
 * @param this 
 * @return int Devuelve -1 si hubo un error o 0 si todo funcionó correctamente.
 */
int employee_editSueldo(Employee* this);

/**
 * @brief Eliminar un empleado de la Linked List
 * 
 * @param this 
 * @param listEmployees 
 * @return int Devuelve -1 si hubo un error o 0 si todo funcionó correctamente.
 */
int employee_removeEmployee(Employee* this, LinkedList* listEmployees);

/**
 * @brief Obtener el index de un empleado mediante un puntero al mismo.
 * 
 * @param this 
 * @param listEmployees 
 * @return int Devuelve el index del empleado o -1 si hubo error.
 */
int employee_getIndexByPtr(Employee* this, LinkedList* listEmployees);

/**
 * @brief Comparaciones por criterio - Nombre
 * 
 * @param pEmployeeA 
 * @param pEmployeeB 
 * @return int  Devuelven -1 si A < B, 0 si A = B, 1 si A > B
 */
int employee_compareByName(void* pEmployeeA,void* pEmployeeB);

/**
 * @brief Comparaciones por criterio - Sueldo
 * 
 * @param pEmployeeA 
 * @param pEmployeeB 
 * @return int  Devuelven -1 si A < B, 0 si A = B, 1 si A > B
 */
int employee_compareBySueldo(void* pEmployeeA,void* pEmployeeB);

/**
 * @brief Comparaciones por criterio - Horas trabajadas
 * 
 * @param pEmployeeA 
 * @param pEmployeeB 
 * @return int  Devuelven -1 si A < B, 0 si A = B, 1 si A > B
 */
int employee_compareByHorasTrabajadas(void* pEmployeeA,void* pEmployeeB);

/**
 * @brief Guarda los datos en el archivo de texto
 * 
 * @param pArrayListEmployee 
 * @param pFile 
 * @param path 
 * @return int Devuelve -1 si hubo un error o 0 si todo funcionó correctamente.
 */
int employee_saveTxt(LinkedList* pArrayListEmployee, FILE* pFile, char* path);

/**
 * @brief Guarda los datos en el archivo binario
 * 
 * @param pArrayListEmployee 
 * @param pFile 
 * @param path 
 * @return int Devuelve -1 si hubo un error o 0 si todo funcionó correctamente.
 */
int employee_saveBin(LinkedList* pArrayListEmployee, FILE* pFile, char* path);


#endif // employee_H_INCLUDED
