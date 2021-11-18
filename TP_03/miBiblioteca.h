#ifndef MIBIBLIOTECA_H_INCLUDED
#define MIBIBLIOTECA_H_INCLUDED



#endif // MIBIBLIOTECA_H_INCLUDED



/** \brief Muestra un menú inicial de opciones para seleccionar
 * \return int La opción seleccionada por el usuario, para luego usar de criterio en un switch
 */

int menu();


/** \brief Muestra un menú inicial de opciones para seleccionar
 * \return int La opción seleccionada por el usuario, para luego usar de criterio en un switch
 */

int menuInformes();


/** \brief permite el ingreso de un entero y lo guarda en el puntero compo
 * \param texto[] char El mensaje a mostrar, hace referrencia al tipo de dato
 * \param campo int* puntero a entero donde se guarda el valor cargado
 * \param min int El mínimo de caracteres a ingresar
 * \param max int El máximo de caracteres a ingresar
 * \return (-1) si hubo error, (0) en caso de carga correcta
 *
 */

int ingresarIntPos(char texto[],int* campo,int minimo,int limite);


/** \brief permite el ingreso de string
 *
 * \param texto[] char El mensaje a mostrar, hace referrencia al tipo de dato
 * \param campo char* puntero a char donde se guarda el valor cargado
 * \param tam int tamanio maximo del string
 * \return (-1) si hubo error, (0) en caso de carga correcta
 *
 */

int ingresarStr(char texto[],char* campo,int tam);


/** \brief
 *
 * \param texto[] char El mensaje a mostrar, hace referrencia al tipo de dato
 * \param campo float* puntero a float donde se guarda el valor cargado
 * \param minimo int El mínimo de caracteres a ingresar
 * \param limite int El máximo de caracteres a ingresar
 * \return (-1) si hubo error, (0) en caso de carga correcta
 *
 */

int ingresarFloatPos(char texto[],float* campo,int minimo,int limite);


/** \brief
 *
 * \param texto[] char El mensaje a mostrar, hace referrencia al tipo de dato
 * \param campo char* puntero a char donde se guarda el valor cargado
 * \param parametroUno char caracter parametro a validar
 * \param parametroDos char caracter parametro a validar
 * \return (-1) si hubo error, (0) en caso de carga correcta
 *
 */

int ingresarChar(char texto[], char* campo,char parametroUno, char parametroDos);
