#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "menu.h"
#include "validaciones.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListeLibro LinkedList*
 * \return int
 *
 */
int controller_load(char* path, LinkedList* pArrayListLibros)
{
    int retorno = FALSE;
    FILE* pFile;

    pFile = fopen (path, "r");
    if(pFile!=NULL)
    {
        parserLibros(pFile,pArrayListLibros);
        retorno = TRUE;
    }
    fclose(pFile);
    return retorno;
}

void controller_descripcionEditoriales(LinkedList* this)
{
    Editoriales* auxEditoriales;

    auxEditoriales= editoriales_newParametros(1,"PLANETA");
    ll_add(this,auxEditoriales);
    //printf("\n%d - %s\n", auxEditoriales->id, auxEditoriales->descripcion);
    auxEditoriales= editoriales_newParametros(2,"SIGLO XXI EDITORES");
    ll_add(this,auxEditoriales);
    //printf("\n%d - %s\n", auxEditoriales->id, auxEditoriales->descripcion);
    auxEditoriales= editoriales_newParametros(3,"PEARSON");
    ll_add(this,auxEditoriales);
    //printf("\n%d - %s\n", auxEditoriales->id, auxEditoriales->descripcion);
    auxEditoriales= editoriales_newParametros(4,"MINOTAURO");
    ll_add(this,auxEditoriales);
    //printf("\n%d - %s\n", auxEditoriales->id, auxEditoriales->descripcion);
    auxEditoriales= editoriales_newParametros(5,"SALAMANDRA");
    ll_add(this,auxEditoriales);
    //printf("\n%d - %s\n", auxEditoriales->id, auxEditoriales->descripcion);
    auxEditoriales= editoriales_newParametros(6,"PENGUIN BOOKS");
    ll_add(this,auxEditoriales);
    //printf("\n%d - %s\n", auxEditoriales->id, auxEditoriales->descripcion);
}

int controller_sortLibros(LinkedList* pArrayListLibros)
{
    int retorno = FALSE;
    if(pArrayListLibros!=NULL)
    {
        printf("Aguarde unos segundos...\n");
        ll_sort(pArrayListLibros,sortPorEditorialId,1);
        retorno = TRUE;
    }
    return retorno;
}

void controller_listOne(LinkedList* this, LinkedList* this2, int index)
{
    eLibro* auxLibro;
    Editoriales* auxEditoriales;
    int auxId;
    char auxTitulo[50];
    char auxAutor[50];
    int auxPrecio;
    char auxDescEditorial[50];
    int auxEditorial;

    int idEditorial;
    char descEditorial[50];

    int j;

    auxLibro = ll_get(this, index);

    employee_getId(auxLibro,&auxId);
    employee_getTitulo(auxLibro,auxTitulo);
    employee_getAutor(auxLibro,auxAutor);
    employee_getPrecio(auxLibro,&auxPrecio);
    employee_getEditorial(auxLibro, &auxEditorial);
    //employee_getDescProblema(auxLlamada, auxDescProblema);


    for(j=0;j<ll_len(this);j++)
    {
        auxEditoriales = ll_get(this2,j);
        editoriales_getId(auxEditoriales,&idEditorial);
        if(auxEditorial == idEditorial)
        {
            editoriales_getDescripcion(auxEditoriales,descEditorial);
            strcpy(auxDescEditorial, descEditorial);
            employee_setDescEditorial(auxLibro, auxDescEditorial);
        }
    }


    printf("| %-4d | %-50s |  %-15s | %-7d  | %-4d  %-20s |\n", auxId, auxTitulo, auxAutor, auxPrecio, auxEditorial,  auxDescEditorial);

}

int controller_ListLibros(LinkedList* this, LinkedList* this2)
{

    int i;

    int retorno = FALSE;
    printf("========================================================================================================================\n"
           "|                                                     LISTADO                                                          |\n"
           "========================================================================================================================\n"
           "|  ID  |                         TITULO                     |       AUTOR      |  PRECIO  |          EDITORIAL         |\n"
           "========================================================================================================================\n");

    for(i=0; i<ll_len(this); i++)
    {
        controller_listOne(this,this2, i);
        retorno = TRUE;
    }
    printf("========================================================================================================================\n");
    return retorno;
}

/*

int controller_guardarFiltrada(char* path, LinkedList* this)
{
    FILE* pFileText;
    eLibro* llamada;
    int retorno = FALSE;
    int id;
    char fecha[50];
    int cliente;
    int problema;
    char descripcion[50];
    char resolucion[8];

    int i;
    pFileText = fopen(path, "w");
    if(pFileText != NULL && this != NULL)
    {
        fprintf(pFileText, "id_llamada,fecha,numero_cliente,id_problema,solucionado\n");
        for(i=0; i < ll_len(this); i++)
        {
            llamada = ll_get(this,i);
            if(llamada!=NULL)
            {
                employee_getId(llamada, &id);
                employee_getFecha(llamada,fecha);
                employee_getCliente(llamada,&cliente);
                employee_getProblema(llamada,&problema);
                employee_getDescProblema(llamada,descripcion);
                employee_getResolucion(llamada,resolucion);

                fprintf(pFileText, "%d,%s,%d,%d %s,%s\n", id, fecha, cliente, problema, descripcion, resolucion);
            }

        }
        retorno = TRUE;
    }
    fclose(pFileText);
    return retorno;
}

*/


