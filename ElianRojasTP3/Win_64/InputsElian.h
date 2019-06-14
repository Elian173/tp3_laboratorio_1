
/**\brief Solicita un número entero al usuario , valida que este dentro de 2 parametros y lo asigna a la variable enviada
 * \param var_dondeAsignar es donde se guarda el valor
 * \param min Es el numero minimo que el usuario puede ingresar
 * \param max Es el numero maximo que el usuario puede ingresar
 * \param mensaje Es el mensaje a ser mostrado
 * \return void
 */
void f_i_PedirIntEntre(int * var_dondeAsignar, int min, int max, char mensaje[]);

/**\brief Imprime un menu de opciones
 * \param
 \return void**/
void menu(void);

/**\brief Imprime un menu de opciones para la modificacion de un empleado
 * \param
 \return void**/
void menuModificacion(void);

/**\brief Imprime un menu de opciones para el orden de los empleados
 * \param
 \return void**/
int menuOrden(void);

/**\brief Imprime un menu de opciones para el orden de los empleados
 * \param
 \return void**/
int menuCriterio (void);

/** \brief Solicita un texto al usuario , valida que sea solo letras y espacios, vuelve la primer letra Mayuscula y el resto minuscula despues de cada espacio
 * elimina saltos de linea
 * \param var_dondeAsignar es donde se guarda el valor
 * \param longitudMaxString es la cantidad maxima de caracteres que puede ingresar el usuario
 * \param mensaje Es el mensaje a ser mostrado
 * \return void
 */
void f_i_PedirNombre(char var_dondeAsignar[],int longitudMaxString, char mensaje[]);

/** \brief Solicita un texto al usuario , valida que sea solo numeros,elimina saltos de linea
* \param var_dondeAsignar es donde se guarda el valor
* \param longitudMaxString es la cantidad maxima de caracteres que puede ingresar el usuario
* \param mensaje Es el mensaje a ser mostrado
* \return void
*/
void f_i_PedirStringSoloNumeros(char var_dondeAsignar[],int longitudMaxString,char mensaje[]);


/** \brief Solicita al usuario y valida que solo se ingrese 'S' o 'N' , arregla mayusculas automaticamente
 * \param mensaje Es el mensaje a ser mostrado
 * \return 1 si el usuario ingreso 'S' , 0 si el usuario ingreso 'N'
 */
int f_i_SioNo(char mensaje[]);

/** \brief Pausa el programa y solicita al usuario que ingrese una tecla para continuar
 * \return void
 */
void f_i_continuar(void);


/** \brief Limpia la pantalla
 * \return void
 */
void limpiar (void);

