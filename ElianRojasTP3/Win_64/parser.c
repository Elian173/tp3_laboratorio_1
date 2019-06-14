#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE *pFile, LinkedList *pArrayListEmployee)
{
    char auxId[31],auxNombre[31],auxHoras[31],auxSueldo[31];
    int retorno = 0;
    int seLeyo = 0;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {

        //descarto la primera linea
        //fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxHoras,auxSueldo);
        do
        {
            seLeyo = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxHoras,auxSueldo);
            if(seLeyo != 4)
            {
                printf("\nError leyendo el archivo\n");
                return retorno;
                break;
            }
            else
            {
                Employee* ptr_NuevoEmpleado = employee_new();

                //ptr_NuevoEmpleado->id = atoi(auxId);
                employee_setId(ptr_NuevoEmpleado,atoi(auxId));

                //strcpy(ptr_NuevoEmpleado->nombre, auxNombre);
                employee_setNombre(ptr_NuevoEmpleado,auxNombre);

                //ptr_NuevoEmpleado->horasTrabajadas = atoi(auxHoras);
                employee_setHorasTrabajadas(ptr_NuevoEmpleado,atoi(auxHoras));

                //ptr_NuevoEmpleado->sueldo = atoi(auxSueldo);
                employee_setSueldo(ptr_NuevoEmpleado,atoi(auxSueldo));

                ll_add(pArrayListEmployee, ptr_NuevoEmpleado);

            }

        }

        while(!feof(pFile));
        fclose(pFile);
        retorno = 1;

    }
    else
    {
        printf("Archivo vacio\n");
        retorno = 0;
    }

    return retorno;

}


int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    int leyo_bien ;
    int index_error;
    Employee* ptr_Empleado;


    if(pFile != NULL && pArrayListEmployee != NULL)
    {

        while(!feof(pFile))
        {
            ptr_Empleado = employee_new();
            leyo_bien = fread(ptr_Empleado, sizeof(Employee),1, pFile);
            ll_add(pArrayListEmployee, ptr_Empleado);

            if(leyo_bien != 1)
            {
                index_error = ll_indexOf(pArrayListEmployee,ptr_Empleado);
                ll_remove(pArrayListEmployee,index_error);
            }
        }
    }
    else
    {
        printf("Archivo vacio\n");
        retorno = 0 ;
    }

    return retorno;
}
