#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
} Employee;

/** \brief  Crea un bloque de memoria para un nuevo empleado
 * \param this LinkedList* Puntero a la lista
 * \return un puntero al bloque de memoria
 *
 */
Employee* employee_new();

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr);

void employee_delete();

/** \brief  asigna un numero al parametro Id de un empleado
 * \param this es un puntero al empleado
 * \param id es el numero a asignar
 * \return 1 si asigno correctamente , 0 si hubo un error.
 *
 */
int employee_setId(Employee* this,int id);
/** \brief busca el valor del parametro id de un empleado especifico
 * \param this es un puntero al empleado
 * \param id es donde se guarda el valor del id
 * \return 1 si devolvio correctamente , 0 si hubo un error.
 *
 */
int employee_getId(Employee* this,int* id);

/** \brief  asigna un string al parametro nombre de un empleado
 * \param this es un puntero al empleado
 * \param nombre es el puntero al string a asignar
 * \return 1 si asigno correctamente , 0 si hubo un error.
 *
 */
int employee_setNombre(Employee* this,char* nombre);
/** \brief busca el puntero al parametro nombre de un empleado especifico
 * \param this es un puntero al empleado
 * \param nombre es donde se guarda el puntero al nombre del empleado
 * \return 1 si devolvio correctamente , 0 si hubo un error.
 *
 */
int employee_getNombre(Employee* this,char* nombre);

/** \brief  asigna un numero al parametro horasTrabajadas de un empleado
 * \param this es un puntero al empleado
 * \param horasTrabajadas es el numero a asignar
 * \return 1 si asigno correctamente , 0 si hubo un error.
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
/** \brief busca el valor del parametro HorasTrabajadas de un empleado especifico
 * \param this es un puntero al empleado
 * \param horasTrabajadas es donde se guarda el valor de las horas
 * \return 1 si devolvio correctamente , 0 si hubo un error.
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief  asigna un numero al parametro sueldo de un empleado
 * \param this es un puntero al empleado
 * \param sueldo es el numero a asignar
 * \return 1 si asigno correctamente , 0 si hubo un error.
 *
 */
int employee_setSueldo(Employee* this,int sueldo);
/** \brief busca el valor del parametro sueldo de un empleado especifico
 * \param this es un puntero al empleado
 * \param sueldo es donde se guarda el valor del sueldo
 * \return 1 si devolvio correctamente , 0 si hubo un error.
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);

//-------

/** \brief imprime en pantalla todos los datos de un empleado especifico
 * \param ptr_Empleado es un puntero al empleado
 * \return void
 *
 */
void empleado_imprimir(Employee* ptr_Empleado);

/** \brief Compara el nombre de 2 empleados y retorna un valor para ordenar con ll_sort
 * \param ptr_EmpleadoA es el puntero al 1er empleado a comparar
 * \param ptr_EmpleadoB es el puntero al 2do empleado a comparar
 * \return  0 si son iguales
 *          -1 si el nombre de EmpleadoA < EmpleadoB
 *          1  si el nombre de EmpleadoA > EmpleadoB
 */
int empleado_ordenarNombre(void* ptr_EmpleadoA, void* ptr_EmpleadoB);

/** \brief Compara el id de 2 empleados y retorna un valor para ordenar con ll_sort
 * \param ptr_EmpleadoA es el puntero al 1er empleado a comparar
 * \param ptr_EmpleadoB es el puntero al 2do empleado a comparar
 * \return  0 si son iguales
 *          -1 si el id de EmpleadoA < EmpleadoB
 *          1  si el id de EmpleadoA > EmpleadoB
 */
int empleado_ordenarPorId (void* ptr_EmpleadoA, void* ptr_EmpleadoB);

/** \brief Compara el sueldo de 2 empleados y retorna un valor para ordenar con ll_sort
 * \param ptr_EmpleadoA es el puntero al 1er empleado a comparar
 * \param ptr_EmpleadoB es el puntero al 2do empleado a comparar
 * \return  0 si son iguales
 *          -1 si el sueldo de EmpleadoA < EmpleadoB
 *          1  si el sueldo de EmpleadoA > EmpleadoB
 */
int empleado_ordenarPorSueldo (void* ptr_EmpleadoA, void* ptr_EmpleadoB);

/** \brief Compara las horas trabajadas de 2 empleados y retorna un valor para ordenar con ll_sort
 * \param ptr_EmpleadoA es el puntero al 1er empleado a comparar
 * \param ptr_EmpleadoB es el puntero al 2do empleado a comparar
 * \return  0 si son iguales
 *          -1 si las horas de EmpleadoA < EmpleadoB
 *          1  si las horas de EmpleadoA > EmpleadoB
 */
int empleado_ordenarPorHoras (void* ptr_EmpleadoA, void* ptr_EmpleadoB);



#endif // employee_H_INCLUDED
