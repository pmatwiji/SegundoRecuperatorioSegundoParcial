#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menu.h"
#include "validaciones.h"

int main()
{
    int option;
    int test;
    char path[50];


    LinkedList* listaLibros = ll_newLinkedList();
    LinkedList* listaEditoriales = ll_newLinkedList();
    //LinkedList* listaFiltrada;


    do
    {
        option = menu();

        switch(option)
        {
        case 1:
            getString("\nIngrese el nombre del archivo a cargar, sin olvidarse de poner al final '.csv': ",path);
            test = controller_load(path,listaLibros);
            if(test==TRUE)
            {
                printf("\nDatos cargados con exito.\n\n");
            }
            while(test!=TRUE)
            {
                printf("\nError, no se pudo cargar los datos.\n");
                getString("\nIngrese el nombre del archivo a cargar, sin olvidarse de poner al final '.csv': ",path);
                test = controller_load(path,listaLibros);
                if(test==TRUE)
                {
                    printf("\nDatos cargados con exito.\n\n");
                    //controller_descripcionEditoriales(listaEditoriales);
                }

            }
            system("pause");
            system("cls");
            break;
        case 2:
            if(ll_isEmpty(listaLibros) == 1)
            {
                printf("\nNo hay datos cargados.\n\n");
            }
            else
            {
                //controller_descripcionEditoriales(listaEditoriales);
                controller_sortLibros(listaLibros);
                printf("\nLista ordenada con exito.\n\n");
                //controller_ListLibros(listaLibros,listaEditoriales);

            }

            system("pause");
            system("cls");
            break;
        case 3:
            if(ll_isEmpty(listaLibros) == 1)
            {
                printf("\nNo hay datos cargados.\n\n");
            }
            else
            {
                controller_descripcionEditoriales(listaEditoriales);
                controller_ListLibros(listaLibros,listaEditoriales);
                /*problema = getInt("Ingrese el problema a filtrar: ");

                switch(problema)
                {
                case 1:
                    //listaFiltrada = ll_filter(listaLibros,llamadas_filtroUno);
                   // controller_guardarFiltrada("filtrada.csv",listaFiltrada);
                    printf("Datos filtrados correctamente\n");
                    break;
                case 2:
                   // listaFiltrada = ll_filter(listaLibros,llamadas_filtroDos);
                   // controller_guardarFiltrada("filtrada.csv",listaFiltrada);
                    printf("Datos filtrados correctamente\n");
                    break;
                case 3:
                    //listaFiltrada = ll_filter(listaLibros,llamadas_filtroTres);
                    //controller_guardarFiltrada("filtrada.csv",listaFiltrada);
                    printf("Datos filtrados correctamente\n");
                    break;

                case 4:
                   // listaFiltrada = ll_filter(listaLibros,llamadas_filtroCuatro);
                   // controller_guardarFiltrada("filtrada.csv",listaFiltrada);
                    printf("Datos filtrados correctamente\n");
                    break;

                case 5:
                    //listaFiltrada = ll_filter(listaLibros,llamadas_filtroCinco);
                   // controller_guardarFiltrada("filtrada.csv",listaFiltrada);
                    printf("Datos filtrados correctamente\n");
                    break;
                default:
                    printf("Datos incorrectos\n");
                    break;
                }*/
            }

            system("pause");
            system("cls");
            break;
        case 4:
            if(ll_isEmpty(listaLibros) == 1)
            {
                printf("\nNo hay datos cargados.\n\n");
            }
            else
            {
                controller_descripcionEditoriales(listaEditoriales);
                ll_map(listaLibros,aplicarDescuentos);
                controller_ListLibros(listaLibros,listaEditoriales);
            }
            system("pause");
            system("cls");
            break;
        case 5:
            printf("\nGracias por utilizar el sistema.\n\n");
            system("pause");
            system("cls");
            break;
        }
    }
    while(option != 5);
    return 0;
}
