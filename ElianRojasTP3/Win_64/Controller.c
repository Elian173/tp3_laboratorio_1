#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "InputsElian.h"
#include "string.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return 0 si no cargo los datos , 1 si cargo los datos
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile = fopen(path, "r");
    int retorno = 0;

    if (pFile != NULL && path != NULL && pArrayListEmployee != NULL)
    {
        retorno = parser_EmployeeFromText(pFile, pArrayListEmployee);
    }
    else
    {
        printf("El archivo no existe.\n");
    }

    fclose(pFile);

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return 0 si no cargo los datos , 1 si cargo los datos
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile = fopen(path, "rb");
    int retorno = 0;

    if (pFile != NULL && path != NULL && pArrayListEmployee != NULL)
    {
        retorno = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
    }
    else
    {
        retorno = 0;//El archivo no existe
    }

    fclose(pFile);

    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return  0 si no cargo los datos , 1 si cargo los datos
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{

    Employee* ptr_AuxNuevoEmpleado;
    ptr_AuxNuevoEmpleado = employee_new();
    Employee* ptr_UltimoEmpleado;

    int lastId;
    int retorno = 0;
    char *buffer = (char*) malloc(sizeof(char)*31);

    if(pArrayListEmployee != NULL && ptr_AuxNuevoEmpleado != NULL)
    {
        //guardo los datos de el empleado
        ptr_UltimoEmpleado = ll_get(pArrayListEmployee,ll_len(pArrayListEmployee)-1);
        lastId = ptr_UltimoEmpleado->id;
        employee_setId(ptr_AuxNuevoEmpleado,lastId + 1);

        f_i_PedirNombre(buffer,31,"Ingrese el nombre del empleado");
        employee_setNombre(ptr_AuxNuevoEmpleado, buffer);

        f_i_PedirStringSoloNumeros(buffer,4,"Ingrese las horas trabajadas del empleado:");
        employee_setHorasTrabajadas(ptr_AuxNuevoEmpleado, atoi(buffer));

        f_i_PedirStringSoloNumeros(buffer,6,"Ingrese el sueldo del empleado:");
        employee_setSueldo(ptr_AuxNuevoEmpleado,atoi(buffer));

        //lo agrego al final de la lista
        if(ll_add(pArrayListEmployee, ptr_AuxNuevoEmpleado) == 0)
        {
            retorno = 1;
        }
    }
    else
    {
        printf("Error, no se puede cargar el empleado\n");
    }

    free (buffer);

    return retorno;
}
/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return 0 si no se modifico , 1 si se modifico
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{

    Employee* ptr_EmpleadoAModificar;
    ptr_EmpleadoAModificar = employee_new();

    int retorno = 0;
    int opcion;
    int idBuscado;
    int idComparando;

    int indexAModificar = -1;

    int i = 0;
    char *buffer = (char*) malloc(sizeof(char)*31);

    if(pArrayListEmployee != NULL && ptr_EmpleadoAModificar != NULL)
    {

        f_i_PedirStringSoloNumeros(buffer,7,"Ingrese el id del empleado a modificar:");
        idBuscado = atoi(buffer);

        for(i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            ptr_EmpleadoAModificar = ll_get(pArrayListEmployee, i);
            employee_getId(ptr_EmpleadoAModificar,&idComparando);

            if (idComparando == idBuscado)
            {
                indexAModificar = i;
                break;
            }

        }

        if ( indexAModificar != -1 )
        {
            limpiar();
            menuModificacion();
            f_i_PedirIntEntre(&opcion,1,4,"");
            switch (opcion)
            {
            case 1:
                f_i_PedirNombre(buffer,31,"Ingrese el nombre del empleado");
                employee_setNombre(ptr_EmpleadoAModificar, buffer);
                retorno = 1;
                break;

            case 2:
                f_i_PedirStringSoloNumeros(buffer,4,"Ingrese las horas trabajadas del empleado:");
                employee_setHorasTrabajadas(ptr_EmpleadoAModificar, atoi(buffer));
                retorno = 1;
                break;

            case 3:
                f_i_PedirStringSoloNumeros(buffer,6,"Ingrese el sueldo del empleado:");
                employee_setSueldo(ptr_EmpleadoAModificar,atoi(buffer));
                retorno = 1;
                break;

            case 4:
                break;

            default:
                printf("Error\n");
                break;
            }
        }
    }
    else
    {
        printf("Error, no se puede modificar \n");
    }


    if (indexAModificar == -1)
    {
        printf("El empleado no existe\n");
    }

    free (buffer);

    return retorno;
}


/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return 0 si no se borra , 1 si se borra
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;

    int idBuscado;
    int idComparando;

    int indexARemover = -1;

    int i = 0;

    Employee* aux_Empleado = employee_new();
    char *buffer = (char*) malloc(sizeof(char)*8);

    if(pArrayListEmployee != NULL && aux_Empleado != NULL)
    {
        f_i_PedirStringSoloNumeros(buffer,7,"Ingrese el id del empleado a dar de baja:");
        idBuscado = atoi(buffer);

        for(i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            aux_Empleado = ll_get(pArrayListEmployee, i);
            employee_getId(aux_Empleado,&idComparando);

            if (idComparando == idBuscado)
            {
                indexARemover = i;
                break;
            }

        }

        if ( indexARemover != -1 )
        {
            ll_remove(pArrayListEmployee,i);
            retorno = 1;
        }

    }

    if (indexARemover == -1)
    {
        printf("El empleado no existe\n");
    }

    free (buffer);

    return retorno;
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

    int total = 0;
    Employee *ptr_Empleado;
    int i;

    ptr_Empleado = employee_new();

    if(pArrayListEmployee != NULL && ptr_Empleado != NULL)
    {
        printf("Id:        auxNombre:   Horas:   Sueldo:\n");
        for(i = 0; i < ll_len(pArrayListEmployee) ; i++)
        {
            ptr_Empleado = (Employee*) ll_get(pArrayListEmployee,i);
            if(ptr_Empleado != NULL && ptr_Empleado->id != -1)
            {
                empleado_imprimir(ptr_Empleado);
                total++;
            }
        }
    }
    else
    {
        printf("La lista esta vacia.\n");
    }
    return total;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return 1 si ordena , 0 si no ordena
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;

    if(pArrayListEmployee != NULL)
    {
    ll_sort(pArrayListEmployee,empleado_ordenar,0);
    retorno = 1;
    }
    return retorno;


}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return 0 guardo mal , 1 guardo bien
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{

    int retorno = 1;
    int index;
    int size;
    FILE *pFile;
    Employee* ptr_AuxEmpleado;
    pFile = fopen(path,"w");

    if(pFile != NULL && pArrayListEmployee != NULL && path != NULL)
    {

        ptr_AuxEmpleado = employee_new();
        size = ll_len(pArrayListEmployee);

        //fprintf(pFile, "id, nombre, horas, sueldo\n");

        for(index = 0; index < size; index++)
        {
            ptr_AuxEmpleado = (Employee*) ll_get(pArrayListEmployee, index);
            fprintf(pFile, "%d, %s, %d, %d\n",ptr_AuxEmpleado->id, ptr_AuxEmpleado->nombre, ptr_AuxEmpleado->horasTrabajadas, ptr_AuxEmpleado->sueldo);
        }

    }
    else
    {
        //error
        retorno = 0;
    }

    fclose(pFile);

    return retorno;
}


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    int i;
    FILE *pFile;
    Employee* ptr_AuxEmpleado;
    pFile = fopen(path,"wb");

    if(pArrayListEmployee != NULL && path != NULL && pFile != NULL)
    {
        for(i = 0 ; i < ll_len(pArrayListEmployee); i++)
        {
            ptr_AuxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
            fwrite(ptr_AuxEmpleado, sizeof(Employee), 1, pFile );
        }
        fclose(pFile);
    }
    else
    {
        retorno = 0;
    }

    return retorno;

}


