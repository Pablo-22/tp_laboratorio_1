#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;
    this = (LinkedList*)malloc(sizeof(LinkedList));
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if (this != NULL)
    {
        returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    int len = ll_len(this);
    Node* pNode = NULL;
    if (this != NULL && nodeIndex > -1 && nodeIndex < len)
    {
		pNode = this->pFirstNode;
        for (int i = 0; i < nodeIndex; i++)
        {
            pNode = pNode->pNextNode;   
        }
    }
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int exit = -1;
    int len = ll_len(this);
    Node* pAuxNodoAnterior;
    Node* pAuxNextNode;
    Node* pAuxNode;

    if (this != NULL && nodeIndex > -1 && nodeIndex <= len)
    {
        pAuxNodoAnterior = getNode(this,nodeIndex-1);
        pAuxNextNode = getNode(this, nodeIndex);

        pAuxNode = (Node*)malloc(sizeof(Node)); 
        if (pAuxNode != NULL)
        {
            pAuxNode->pElement = pElement;
            pAuxNode->pNextNode = pAuxNextNode;

            if (pAuxNodoAnterior == NULL)
            {
                this->pFirstNode = pAuxNode;
            }
            else
            {
                pAuxNodoAnterior->pNextNode = pAuxNode;
            }
            this->size++;
            exit = 0;
        }
        
    }
    return exit;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int exit = -1;
    int len;

    if (this != NULL)
    {
        len = ll_len(this);
        exit = addNode(this, len, pElement);
    }
    return exit;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNode;

    pNode = getNode(this, index);
    if (pNode != NULL)
    {
        returnAux = pNode->pElement;
    }
    return returnAux;
}


/** \brief Inserta un elemento en el LinkedList, en el ??ndice especificado.
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int exit = -1;
    Node* pAuxNode;
    if (this != NULL)
    {
        pAuxNode = getNode(this, index);
        if (pAuxNode != NULL)
        {
            pAuxNode->pElement = pElement;
            exit = 0;
        } 
    }
    return exit;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int exit = -1;
    Node* pAuxNode;
    Node* pAuxNextNode;
    Node* pAuxBackNode;
    if (this != NULL)
    {
        pAuxNode = getNode(this, index);
        pAuxNextNode = getNode(this,index+1);
        pAuxBackNode = getNode(this, index-1);
        if (pAuxNode != NULL)
        {
            if (pAuxBackNode == NULL)
            {
                
                this->pFirstNode = pAuxNextNode;
            }
            else
            {
                pAuxBackNode->pNextNode = pAuxNextNode;
            }
            free(pAuxNode);
            this->size--;
            exit = 0;
        }
    }
    

    return exit;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int exit = -1;
    int len;
    if (this != NULL)
    {
        len = ll_len(this);
        for (int i = 0; i < len; i++)
        {
            exit = ll_remove(this,0);
        }
    }
    return exit;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int exit = -1;
    if (this != NULL)
    {
        ll_clear(this);
        free(this);
        exit = 0;
    }
    return exit;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int exit = -1;
    int len;
    void* pAuxElement;

    if (this != NULL)
    {
        len = ll_len(this);
        for (int i = 0; i < len; i++)
        {
            pAuxElement = ll_get(this,i);
            if (pAuxElement == pElement)
            {
                exit = i;
                break;
            }
        }
    }
    return exit;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int exit = -1;
    int len;

    if (this != NULL)
    {
        exit = 1;

        len = ll_len(this);
        if (len > 0)
        {
            exit = 0;
        }
    }
    return exit;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int exit;
    if (this != NULL)
    {
        exit = addNode(this,index,pElement);
    }
    
    return exit;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    void* pAuxElement;
    int len;

    len = ll_len(this);
    if (this != NULL && index > -1 && index < len)
    {
        pAuxElement = ll_get(this, index);
        if (pAuxElement != NULL)
        {
            returnAux = pAuxElement;
            ll_remove(this, index);
        }
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int index;
    if (this != NULL)
    {
        returnAux = 0;
        index = ll_indexOf(this, pElement);
        if (index > -1)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}


/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int exit = -1;
    int len;
    void* pAuxElement;

    if(this != NULL && this2 != NULL)
    {
        len = ll_len(this2);
        exit = 1;
        for (int i = 0; i < len; i++)
        {
            pAuxElement = ll_get(this2, i);
            exit = ll_contains(this, pAuxElement);
            if (exit == 0)
            {
                break;
            }
        }
    }
    return exit;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int len;
    Node* pAuxNode;

	len = ll_len(this);
    if (this != NULL && from > -1 && from < len && to >= from && to <= len )
    {
        cloneArray = ll_newLinkedList();
        for (int i = from; i < to; i++)
        {
            pAuxNode = getNode(this, i);
            ll_add(cloneArray, pAuxNode->pElement);
        }
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int len;    
    if (this != NULL)
    {
        len = ll_len(this);
        cloneArray = ll_subList(this, 0, len);
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                        ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux = -1;
    int len;
    void* pElementA;
    void* pElementB;
    void* pAuxElement;
    int comp;

    if (this != NULL && pFunc != NULL && order > -1 && order < 2)
    {
        len = ll_len(this);
        returnAux = 0;
        for (int i = 0; i < len - 1; i++)
        {
            for (int j = i+1; j < len; j++)
            {
                pElementA = ll_get(this, i);
                pElementB = ll_get(this, j);

                comp = pFunc(pElementA, pElementB);

                if((comp==1 && order==1) || (comp==-1 && order==0))
                {
                    pAuxElement = pElementA;
                    ll_set(this, i, pElementB);
                    ll_set(this, j, pAuxElement);
                }
            }
        } 
    }
    return returnAux;
}
