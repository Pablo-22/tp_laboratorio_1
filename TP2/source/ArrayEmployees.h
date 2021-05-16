#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#define LIST_LEN 1000

#define UP 1
#define DOWN 0

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}eEmployee;


/**
 * @brief Hardcodea hasta 7 elementos en la lista principal de empleados. Función creada por cuestiones de pruebas.
 * 
 * @param list 
 * @param amountOfElements Cantidad de elementos a hardcodear.
 */
void hardcodeEmployee(eEmployee list[], int amountOfElements);

/** @brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * @param list Employee* Pointer to array of employees
 * @param len int Array length
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(eEmployee list[], int len);


/** @brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * @param list employee*
 * @param len int
 * @param id int
 * @param name[] char
 * @param lastName[] char
 * @param salary float
 * @param sector int
 * @return int Return (-1) if Error [Invalid length or NULL pointer or without 
free space] - (0) if Ok
 *
*/
int addEmployee(eEmployee list[], int len, int id, char name[],char
lastName[],float salary,int sector);


/**
 * @brief Obtiene los datos para un nuevo empleado.
 * 
 * @param list 
 * @param len 
 * @return int int Return (-1) if Error [Invalid length or NULL pointer or without 
free space] - (0) if Ok
 */
int getNewEmployeeData(eEmployee list[], int len);

/** @brief find an Employee by Id en returns the index position in array.
 *
 * @param list Employee*
 * @param len int
 * @param id int
 * @return Return employee index position or (-1) if [Invalid length or NULL 
pointer received or employee not found]
 *
 */
int findEmployeeById(eEmployee list[], int len,int id);

/** @brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * @param list Employee*
 * @param len int
 * @param id int
 * @return int Return (-1) if Error [Invalid length or NULL pointer or if can't 
find a employee] - (0) if Ok
 *
 */
int removeEmployee(eEmployee list[], int len, int id);


/** @brief Sort the elements in the array of employees, the argument order 
indicate UP or DOWN order
 *
 * @param list Employee*
 * @param len int
 * @param order int [1] indicate UP - [0] indicate DOWN
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(eEmployee list[], int len, int order);


/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(eEmployee list[], int len);


/**
 * @brief Busca el primer lugar con espacio libre
 * 
 * @param list 
 * @param len 
 * @return int Devuelve el índice del lugar encontrado
 */
int lookingForFreeSpace(eEmployee list[], int len);


/**
 * @brief Revisa que la lista principal no esté vacía
 * 
 * @param list 
 * @param len 
 * @return int Devuelve TRUE(1) si está vacío, y FALSE(0) si no esa vacío
 */
int CheckEmpty(eEmployee list[], int len);


/**
 * @brief Recibe y muestra 1 empleado con todos sus datos
 * 
 * @param list 
 * @param nameMaxLen 
 * @param lastNameMaxLen 
 */
void printEmployee(eEmployee list, int nameMaxLen, int lastNameMaxLen);

/**
 * @brief Llama repetidamente a la función printEmployee, para mostrar todos los empleados.
 * 
 * @param list 
 * @param len 
 * @return int 1 if OK
 */
int printEmployees(eEmployee list[], int len);

/**
 * @brief Obtiene el tamaño máximo de los nombres de la lista de empleados. Sirve para darle una alineación correcta al mostrar
 * 
 * @param list 
 * @param len 
 * @return int Devuelve el tamaño máximo encontrado
 */
int getNameMaxLen(eEmployee list[], int len);

/**
 * @brief Obtiene el tamaño máximo de los apellidos de la lista de empleados. Sirve para darle una alineación correcta al mostrar
 * 
 * @param list 
 * @param len 
 * @return int Devuelve el tamaño máximo encontrado
 */
int getLastNameMaxLen(eEmployee list[], int len);

/**
 * @brief Selecciona un empleado mediante su id
 * 
 * @param list 
 * @param len 
 * @return int Devuelve el id seleccionado.
 */
int selectEmployeeId(eEmployee list[], int len);

/**
 * @brief Compara dos nombres y realiza swaps. Es la comparación de un burbujeo, extraída y colocada en otra función para mayor comodidad en su uso
 * 
 * @param list 
 * @param i índice del elemento 1
 * @param j  índice del elemento 2
 * @param order 1 UP ascendente    0 DOWN descendente
 * @return int 
 */
int compareLastNames(eEmployee list[],int i,int j,int order);

/**
 * @brief Compara dos sectores y realiza swaps. Es la comparación de un burbujeo, extraída y colocada en otra función para mayor comodidad en su uso
 * 
 * @param list 
 * @param i índice del elemento 1
 * @param j  índice del elemento 2
 * @param order 1 UP ascendente    0 DOWN descendente
 * @return int 
 */
int compareSectors(eEmployee list[],int i,int j,int order);

/**
 * @brief Swap entre dos elementos
 * 
 * @param list 
 * @param i índice del elemento 1
 * @param j índice del elemento 2
 * @return int devuelve TRUE (1)
 */
int swap(eEmployee list[], int i, int j);

/**
 * @brief Obtiene el promedio de salarios
 * 
 * @param list 
 * @param len 
 * @return float devuelve el promedio
 */
float getAverageSalary(eEmployee list[], int len);

/**
 * @brief Calcula la suma de todos los salarios
 * 
 * @param list 
 * @param len 
 * @return int Devuelve el resultado
 */
int getTotalSalary(eEmployee list[], int len);

/**
 * @brief Cuenta la cantidad de empleados con sueldo mayor al promedio
 * 
 * @param list 
 * @param len 
 * @return int devuelve la cantidad.
 */
int getBetterThanAverage(eEmployee list[], int len);

/**
 * @brief Generador de ID autoincremental. Busca el mayor valor entre las ID existentes, y le suma 1.
 *
 * @param list Estructura sobre la que se generará el ID.
 * @param len Extensión de la estructura.
 * @return int Devuelve el ID generado.
 */
int getIdTrabajo(eEmployee list[], int len);

/**
 * @brief Modifica el nombre de un empleado
 * 
 * @param list 
 * @param index indice del empleado a modificar
 */
void editName(eEmployee list[], int index);

/**
 * @brief Modifica el apellido de un empleado
 * 
 * @param list 
 * @param index indice del empleado a modificar
 */
void editLastName(eEmployee list[], int index);

/**
 * @brief Modifica el salario de un empleado
 * 
 * @param list 
 * @param index indice del empleado a modificar
 */
void editSalary(eEmployee list[], int index);

/**
 * @brief Modifica el sector de un empleado
 * 
 * @param list 
 * @param index indice del empleado a modificar
 */
void editSector(eEmployee list[], int index);









#endif /* ARRAYEMPLOYEES_H_ */
