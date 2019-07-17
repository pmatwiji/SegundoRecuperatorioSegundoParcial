#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menu.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListeLibro LinkedList*
 * \return int
 *
 */
int parserLibros(FILE* pFile, LinkedList* pArrayListLibros)
{
    char auxId[8];
    char auxTitulo[50];
    char auxAutor[50];
    char auxPrecio[8];
    char auxEditorial[8];

    int retorno = FALSE;
    eLibro* auxLibro;

    if(pFile != NULL)
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxTitulo, auxAutor, auxPrecio,auxEditorial);
        while(!feof(pFile))
        {
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxTitulo, auxAutor, auxPrecio,auxEditorial);
            auxLibro = employee_newParametros(auxId, auxTitulo, auxAutor, auxPrecio,auxEditorial);
            if(auxLibro!=NULL)
            {
                ll_add(pArrayListLibros,auxLibro);
                retorno = TRUE;
            }

        }
    }
    fclose(pFile);
    return retorno;
}


