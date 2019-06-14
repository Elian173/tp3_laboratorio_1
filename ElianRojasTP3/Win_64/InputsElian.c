#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

//#define __unix__
#ifdef __unix__
#include <unistd.h>
#else
#include <windows.h>
#endif


void f_i_PedirIntEntre(int * var_dondeAsignar, int min, int max, char mensaje[])
{
    int aux;
    do
    {
        fflush(stdin);
        printf("\n%s\n", mensaje);
        fflush(stdin);
        scanf("%d", &aux);

        if (aux > max || aux < min)
        {
            printf("\n**Error,opcion invalida**");

        };
    }
    while (aux > max || aux < min);
    *var_dondeAsignar = aux;
    return;
}

void menu (void)
{
    printf(
        "/**************************************************** \n"
        "Menu:\n"
        "1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
        "2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n"
        "3. Alta de empleado\n"
        "4. Modificar datos de empleado\n"
        "5. Baja de empleado\n"
        "6. Listar empleados\n"
        "7. Ordenar empleados\n"
        "8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
        "9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
        "10. Salir\n"
        "*****************************************************/\n"
        "Opcion: ");

    return;
}

void menuModificacion(void)
{
    printf(
        "/**************************************************** \n"
        "1. Modificar nombre del empleado.\n"
        "2. Modificar horas trabajadas del empleado\n"
        "3. Modificar sueldo del empleado\n"
        "4. Cancelar\n"
        "*****************************************************/\n"
        "Opcion: ");

    return;
}

int menuOrden(void)
{
    int opc;

    printf(
        "/**************************************************** \n"
        "1.Ordenar empleados por nombre.\n"
        "2.Ordenar empleados por id\n"
        "3.Ordenar empleados por sueldo\n"
        "4 Ordenar empleados por horas trabajadas.\n"
        "5. Cancelar\n"
        "*****************************************************/\n");

    f_i_PedirIntEntre(&opc,1,5,"Opcion:");
    return opc;
}

int menuCriterio (void)
{
    int opc;

    printf("/**************************************************** \n"
           "1.Ordenar de manera descendente.\n"
           "2.Ordenar de manera ascendente.\n");

    f_i_PedirIntEntre(&opc,1,2,"Opcion:");

    if(opc == 2)
    {
        opc = 0;
    }

    return opc;
}

void f_i_PedirNombre(char var_dondeAsignar[],int longitudMaxString, char mensaje[])
{
    int i;
    int no_es_un_nombre;
    char auxiliar[longitudMaxString];

    do
    {
        fflush(stdin);
        printf("%s\n",mensaje);

        fgets(auxiliar,longitudMaxString,stdin);

        for (i=0; i<strlen(auxiliar)-1; i++)
        {
            auxiliar[i] = tolower(auxiliar[i]);
            if ((auxiliar[i]<'a' || auxiliar[i]>'z') && auxiliar[i] != ' ')
            {
                no_es_un_nombre = -1;
                printf("\n**Error, ingrese solo letras y espacios**\n");
                break;
            }
            else
            {
                if (i == 0 || auxiliar[i-1] == ' ')
                {
                    auxiliar[i] = toupper(auxiliar[i]);
                }
                no_es_un_nombre = 0;
            }
        }
    }
    while (no_es_un_nombre);

    int len = strlen(auxiliar);

    if(auxiliar[len-1]=='\n')
    {

        auxiliar[len-1]='\0';

    };

    strcpy(var_dondeAsignar, auxiliar);
    return;
}

void f_i_PedirStringSoloNumeros(char var_dondeAsignar[],int longitudMaxString,char mensaje[])
{

    int i;
    int invalido = 0;
    char auxiliar [longitudMaxString];

    fflush(stdin);
    printf("%s\n",mensaje);

    do
    {

        fflush(stdin);
        fgets(auxiliar,longitudMaxString,stdin);

        for (i=0; i<strlen(auxiliar)-1; i++)
        {
            if (auxiliar[i]<'0' || auxiliar[i]>'9')
            {
                invalido = 1;
                printf("\nError, ingrese solo numeros \n");
                break;
            }
            else
            {
                invalido = 0;
            }

        }

    }
    while (invalido);

    //elimino saltos de linea//
    int len = strlen(auxiliar);

    if(auxiliar[len-1]=='\n')
    {

        auxiliar[len-1]='\0';

    };
    strcpy(var_dondeAsignar,auxiliar);
    return;
}

int f_i_SioNo(char mensaje[])
{
    char r;
    printf("\n%s\n",mensaje);
    printf( "\n --S-- o --N-- \n");
    fflush(stdin);
    r = toupper(getche());
    printf("\n");

    while ( !((r=='S')||(r=='N')) )
    {
        printf ("\nError, ingrese (S/N)... \n");
        fflush(stdin);
        r = toupper(getche());
        printf("\n");
    };
    return (r=='S'); /*Devuelve 1 si se ingresa 'S'*/
}

void f_i_continuar(void)
{
    printf("\n\nPresione una tecla para continuar.\n");
    fflush(stdin);
    getch();
    return;
}

void limpiar (void)
{
    system("cls");
}
