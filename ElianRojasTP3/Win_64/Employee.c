#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

void empleado_imprimir(Employee* ptr_Empleado)
{
    if(ptr_Empleado != NULL)
    {
        printf("%4d %17s %6d %8d\n", ptr_Empleado->id, ptr_Empleado->nombre, ptr_Empleado->horasTrabajadas, ptr_Empleado->sueldo);
    }
}

int empleado_ordenarNombre(void* ptr_EmpleadoA, void* ptr_EmpleadoB)
{

    int retorno;

    char* bufferA = (char*) malloc (sizeof(char)*128);
    char* bufferB = (char*) malloc (sizeof(char)*128);

    employee_getNombre(ptr_EmpleadoA,bufferA);
    employee_getNombre(ptr_EmpleadoB,bufferB);

    if(strcmp(bufferA,bufferB) < 0)
    {
        retorno = 1;
    }
    else if(strcmp(bufferA,bufferB) > 0)
    {
        retorno = -1;
    }
    else
    {
        retorno = 0;
    }

    free(bufferA);
    free(bufferB);

    return retorno;
}

/*int empleado_ordenarNombre(void* ptr_EmpleadoA, void* ptr_EmpleadoB)
{
int j,i;
 int retorno = 1;
 Employee* ptr_EmpleadoA;
 Employee* ptr_EmpleadoB;

 Employee* ptr_AuxEmpleado = employee_new();

 char* bufferA = (char*) malloc (sizeof(char)*128);
 char* bufferB = (char*) malloc (sizeof(char)*128);

 if(pArrayListEmployee != NULL && ptr_AuxEmpleado != NULL)
 {
 for (i = 0 ; i < ll_len(pArrayListEmployee)-1 ; i++)
 {
     ptr_EmpleadoA = ll_get(pArrayListEmployee,i);
    // employee_getNombre(ptr_EmpleadoA,bufferA);

     for (j = i+1 ; j > ll_len(pArrayListEmployee) ; j++)
     {
         ptr_EmpleadoB = ll_get(pArrayListEmployee,j);
         //employee_getNombre(ptr_EmpleadoA,bufferB);

         //if (strcmp(bufferA,bufferB) > 0)
         if(strcmp(ptr_EmpleadoA->nombre,ptr_EmpleadoB->nombre)<0)
         {
             //ptr_AuxEmpleado = ptr_EmpleadoA ;
             //ll_set(pArrayListEmployee,ll_indexOf(pArrayListEmployee,ptr_EmpleadoA),ptr_EmpleadoB);
             //ll_set(pArrayListEmployee,ll_indexOf(pArrayListEmployee,ptr_EmpleadoB),ptr_AuxEmpleado);


            ///ptr_EmpleadoA = ptr_EmpleadoB;
             ///ptr_EmpleadoB = ptr_AuxEmpleado;
         }
     }
 }
 }
 else
 {
     retorno = 0;
 }

 free(ptr_AuxEmpleado);
 free(bufferA);
 free(bufferB);
 return retorno;
 }*/

int empleado_ordenarPorId (void* ptr_EmpleadoA, void* ptr_EmpleadoB)
{
    int retorno;
    int bufferA;
    int bufferB;

    employee_getId(ptr_EmpleadoA,&bufferA);
    employee_getId(ptr_EmpleadoB,&bufferB);

    if(bufferA < bufferB)
    {
        retorno = 1;
    }
    else if(bufferA > bufferB)
    {
        retorno = -1;
    }
    else
    {
        retorno = 0;
    }

    return retorno;
}

int empleado_ordenarPorSueldo (void* ptr_EmpleadoA, void* ptr_EmpleadoB)
{
    int retorno;
    int bufferA;
    int bufferB;

    employee_getSueldo(ptr_EmpleadoA,&bufferA);
    employee_getSueldo(ptr_EmpleadoB,&bufferB);

    if(bufferA < bufferB)
    {
        retorno = 1;
    }
    else if(bufferA > bufferB)
    {
        retorno = -1;
    }
    else
    {
        retorno = 0;
    }

    return retorno;
}


int empleado_ordenarPorHoras (void* ptr_EmpleadoA, void* ptr_EmpleadoB)
{
    int retorno;
    int bufferA;
    int bufferB;

    employee_getHorasTrabajadas(ptr_EmpleadoA,&bufferA);
    employee_getHorasTrabajadas(ptr_EmpleadoB,&bufferB);

    if(bufferA < bufferB)
    {
        retorno = 1;
    }
    else if(bufferA > bufferB)
    {
        retorno = -1;
    }
    else
    {
        retorno = 0;
    }

    return retorno;
}

//-----


Employee* employee_new()
{
    Employee* ptr_NuevoEmpleado = (Employee*)malloc(sizeof(Employee));
    return ptr_NuevoEmpleado;
}

int employee_setId(Employee* ptr_Empleado, int id)
{
    int retorno = 0;

    if(ptr_Empleado != NULL && id > 0)
    {
        ptr_Empleado->id = id;
        retorno = 1;
    }
    return retorno;
}

int employee_getId(Employee* ptr_Empleado, int* id)
{

    int retorno = 0;
    if(ptr_Empleado != NULL)
    {
        *id = ptr_Empleado->id ;
        retorno = 1;
    }
    return retorno;
}

int employee_setNombre(Employee* ptr_Empleado, char* name)
{
    int retorno = 0;

    if(ptr_Empleado != NULL && name != NULL)
    {
        strncpy(ptr_Empleado->nombre, name, sizeof(ptr_Empleado->nombre));
        retorno = 1;
    }
    return retorno;
}

int employee_getNombre(Employee* ptr_Empleado, char* name)
{
    int retorno = 0;

    if(ptr_Empleado != NULL && name != NULL)
    {
        strcpy(name, ptr_Empleado->nombre);
        retorno = 1;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* ptr_Empleado, int horasTrabajadas)
{
    int retorno = 0;

    if(ptr_Empleado != NULL)
    {
        ptr_Empleado->horasTrabajadas = horasTrabajadas;
        retorno = 1;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* ptr_Empleado, int* horasTrabajadas)
{
    int retorno = 0;

    if(ptr_Empleado != NULL)
    {
        *horasTrabajadas = ptr_Empleado->horasTrabajadas;
        retorno = 1;
    }
    return retorno;
}

int employee_setSueldo(Employee* ptr_Empleado, int sueldo)
{
    int retorno = 0;

    if(ptr_Empleado != NULL)
    {
        ptr_Empleado->sueldo = sueldo;
        retorno = 1;
    }
    return retorno;
}

int employee_getSueldo(Employee* ptr_Empleado, int* sueldo)
{
    int retorno = 0;

    if(ptr_Empleado != NULL)
    {
        *sueldo = ptr_Empleado->sueldo ;
        retorno = 1;
    }
    return retorno;
}
