#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "InputsElian.h"

/****************************************************
    Menu:
 -   1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
 -   2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
 -   3. Alta de empleado
 -   4. Modificar datos de empleado
 -   5. Baja de empleado
 -   6. Listar empleados
 -   7. Ordenar empleados
 -   8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
 -   9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
 -   10. Salir
*****************************************************/
#define ARCHIVOT "data.csv"
#define ARCHIVOB "data.csv"

//notitas
//case 7 no terminado poner limpiar(),continuar(), comentar todo

int main()
{
    int option;
    int chargedText = 0;
    int chargedBinary = 0;
    int saved = 1;

    LinkedList* listaEmpleados;
    listaEmpleados = ll_newLinkedList();

    do
    {
        menu();

        f_i_PedirIntEntre(&option,1,10,"");

        switch(option)
        {
        //Cargar Texto
        case 1:
            if (chargedText == 1 || chargedBinary == 1)
            {
                printf("Los datos ya fueron cargados\n");
            }
            else
            {
                if(listaEmpleados != NULL)
                {
                    if(controller_loadFromText(ARCHIVOT,listaEmpleados) != 0)
                    {
                        printf("Se cargaron todos los datos\n");
                        chargedText = 1;
                    }
                    else
                    {
                        printf("No se pudieron cargar los datos\n");
                    }
                }
                else
                {
                    printf("Error en la lista\n");
                }
            }
            break;

        //Cargar Binario
        case 2:

            if (chargedText == 1 || chargedBinary == 1)
            {
                printf("Los datos ya fueron cargados\n");
            }
            else
            {
                if(listaEmpleados != NULL)
                {
                    if(controller_loadFromBinary(ARCHIVOB,listaEmpleados) != 0)
                    {
                        printf("Se cargaron todos los datos\n");
                        chargedBinary = 1;
                    }
                    else
                    {
                        printf("No se pudieron cargar los datos\n");
                    }
                }
                else
                {
                    printf("Error en la lista\n");
                }
            }
            break;

        //Nuevo empleado
        case 3:
            if (chargedText == 0 && chargedBinary == 0)
            {
                printf("Primero se deben cargar los datos.\n");
            }
            else
            {
                if (controller_addEmployee(listaEmpleados) == 1)
                {
                    printf("Se cargo el empleado con exito\n");
                    saved = 0;
                }
                else
                {
                    printf("No se cargo el empleado\n");
                }
            }
            break;

        //Modificar empleado
        case 4:

            if (chargedText == 0 && chargedBinary == 0)
            {
                printf("Primero se deben cargar los datos.\n");
            }
            else
            {
                if (controller_editEmployee(listaEmpleados) == 1)
                {
                    printf("Se modifico el empleado con exito\n");
                    saved = 0;
                }
                else
                {
                    printf("No se modifico el empleado\n");
                }
            }

            break;

        //Baja empleado
        case 5:
            if (chargedText == 0 && chargedBinary == 0)
            {
                printf("Primero se deben cargar los datos.\n");
            }
            else
            {
                if(controller_removeEmployee(listaEmpleados) != 0)
                {
                    printf("Se dio de baja el empleado\n");
                    saved = 0;
                }
                else
                {
                    printf("No pudo darse de baja el empleado\n");
                }
            }
            break;

        //Listar todos
        case 6:
            if (chargedText == 0 && chargedBinary == 0)
            {
                printf("Primero se deben cargar los datos.\n");
            }
            else
            {
                if (controller_ListEmployee(listaEmpleados) == 0)
                {
                    printf("No hay ningun empleado que mostrar.\n ");
                };
            }
            break;

        case 7: // no funcionap
            if (chargedText == 0 && chargedBinary == 0)
            {
                printf("Primero se deben cargar los datos.\n");
            }
            else
            {
                if(controller_sortEmployee(listaEmpleados) != 0)
                {
                    printf("Se ordenaron los empleados\n");
                }
                else
                {
                    printf("No se pudo ordenar los empleados\n");
                }
            }
            break;

        //Guardar modo texto
        case 8:
            if (chargedText == 0 && chargedBinary == 0)
            {
                printf("Primero se deben cargar los datos.\n");
            }
            else
            {
                if(controller_saveAsText(ARCHIVOT,listaEmpleados) == 0)
                {
                    printf("Error al guardar los datos\n");
                }
                else
                {
                    printf("Datos guardados con exito.\n");
                    saved = 1;
                }
            }
            break;

        //Guardar modo binario
        case 9:
            if (chargedText == 0 && chargedBinary == 0)
            {
                printf("Primero se deben cargar los datos.\n");
            }
            else
            {
                if(controller_saveAsBinary(ARCHIVOB,listaEmpleados) == 0)
                {
                    printf("Error al guardar los datos\n");
                }
                else
                {
                    printf("Datos guardados con exito.\n");
                    saved = 1;
                }
            }
            break;

        case 10:
            if (saved == 0)
            {
                if(f_i_SioNo("Hay datos sin guardar , salir de todas formas?") == 0)
                {
                    option = 0;
                }
            }
            ll_deleteLinkedList(listaEmpleados);
            break;

        default:
            printf("oops");
            break;
        }
    }
    while(option != 10);
    return 0;

}
