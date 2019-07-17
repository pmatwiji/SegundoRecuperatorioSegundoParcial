#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menu.h"

eLibro *employee_new()
{
    eLibro* libroReturn;
    libroReturn = (eLibro*) malloc(sizeof(eLibro));
    return libroReturn;
}

eLibro* employee_newParametros(char* idStr, char* tituloStr, char* autorStr, char* precioStr, char* editorialStr)
{
    eLibro* libroReturn;
    libroReturn = employee_new();

    if(libroReturn!=NULL)
    {
        employee_setId(libroReturn, atoi(idStr));
        employee_setTitulo(libroReturn, tituloStr);
        employee_setAutor(libroReturn, autorStr);
        employee_setPrecio(libroReturn, atoi(precioStr));
        employee_setEditorial(libroReturn, atoi(editorialStr));

    }

    return libroReturn;
}

Editoriales *editoriales_new()
{
    Editoriales* editorialReturn;
    editorialReturn = (Editoriales*) malloc(sizeof(Editoriales));
    return editorialReturn;
}

Editoriales* editoriales_newParametros(int id, char* descripcion)
{
    Editoriales* editorialReturn;
    editorialReturn = editoriales_new();

    if(editorialReturn!=NULL)
    {
        editoriales_setId(editorialReturn, id);
        editoriales_setDescripcion(editorialReturn, descripcion);
    }

    return editorialReturn;
}

int employee_setId(eLibro* this, int id)
{
    int retorno = FALSE;

    if(this!=NULL && id>0)
    {
        this->id=id;
        retorno = TRUE;
    }

    return retorno;
}


int employee_setTitulo(eLibro* this, char* titulo)
{
    int retorno = FALSE;

    if(this!=NULL)
    {
        strcpy(this->titulo,titulo);
        retorno = TRUE;
    }

    return retorno;
}

int employee_setAutor(eLibro* this, char* autor)
{
    int retorno = FALSE;

    if(this!=NULL)
    {
        strcpy(this->autor,autor);
        retorno = TRUE;
    }

    return retorno;
}



int employee_setPrecio(eLibro* this, int precio)
{
    int retorno = FALSE;

    if(this!=NULL && precio>0)
    {
        this->precio=precio;
        retorno = TRUE;
    }

    return retorno;
}

int employee_setEditorial(eLibro* this, int editorial)
{
    int retorno = FALSE;

    if(this!=NULL && editorial>0)
    {
        this->editorial = editorial;
        retorno = TRUE;
    }

    return retorno;
}

int employee_setDescEditorial(eLibro* this, char* descEditorial)
{
    int retorno = FALSE;

    if(this!=NULL)
    {
        strcpy(this->descEditorial,descEditorial);
        retorno = TRUE;
    }

    return retorno;
}

int employee_getId(eLibro* this,int* id)
{
    int retorno = FALSE;

    if(this!=NULL && id>0)
    {
        *id = this->id;
        retorno = TRUE;
    }

    return retorno;
}


int employee_getTitulo(eLibro* this,char* titulo)
{
    int retorno = FALSE;

    if(this!=NULL)
    {
        strcpy(titulo,this->titulo);
        retorno = TRUE;
    }

    return retorno;
}

int employee_getAutor(eLibro* this,char* autor)
{
    int retorno = FALSE;

    if(this!=NULL)
    {
        strcpy(autor,this->autor);
        retorno = TRUE;
    }

    return retorno;
}

int employee_getPrecio(eLibro* this,int* precio)
{
    int retorno = FALSE;

    if(this!=NULL)
    {
        *precio = this->precio;
        retorno = TRUE;
    }

    return retorno;
}

int employee_getDescEditorial(eLibro* this,char* descEditorial)
{
    int retorno = FALSE;

    if(this!=NULL)
    {
        strcpy(descEditorial,this->descEditorial);
        retorno = TRUE;
    }

    return retorno;
}

int employee_getEditorial(eLibro* this,int* editorial)
{
    int retorno = FALSE;

    if(this!=NULL)
    {
        *editorial=this->editorial;
        retorno = TRUE;
    }

    return retorno;
}






int editoriales_setId(Editoriales* this, int id)
{
    int retorno = FALSE;

    if(this!=NULL && id>0)
    {
        this->id=id;
        retorno = TRUE;
    }

    return retorno;
}




int editoriales_getId(Editoriales* this,int* id)
{
    int retorno = FALSE;

    if(this!=NULL && id>0)
    {
        *id = this->id;
        retorno = TRUE;
    }

    return retorno;
}


int editoriales_setDescripcion(Editoriales* this, char* descripcion)
{
    int retorno = FALSE;

    if(this!=NULL)
    {
        strcpy(this->descripcion,descripcion);
        retorno = TRUE;
    }

    return retorno;
}

int editoriales_getDescripcion(Editoriales* this,char* descripcion)
{
    int retorno = FALSE;

    if(this!=NULL)
    {
        strcpy(descripcion,this->descripcion);
        retorno = TRUE;
    }

    return retorno;
}


int sortPorEditorialId(void* auxLibroUno, void* auxLibroDos)
{
    int retorno = FALSE;
    if(((eLibro*)auxLibroUno)->editorial > ((eLibro*)auxLibroDos)->editorial)
    {
        retorno = TRUE;
    }
    return retorno;
}

void aplicarDescuentos (void* this)
{
    eLibro* libro;
    int auxPrecio;
    int auxEditorial;

    if(this!=NULL)
    {
        libro = (eLibro*)this;
        auxPrecio = libro->precio;
        auxEditorial = libro->editorial;

        if(auxEditorial == 1)
        {
            employee_setPrecio(libro, (auxPrecio*0.80));
        }

        if(auxEditorial == 2)
        {
            employee_setPrecio(libro, (auxPrecio*0.90));
        }
    }
}


/*

int llamadas_filtroUno(void* this)
{
    eLibro* llamadas;
    int auxProblema;
    int retorno = FALSE;

    if(this!=NULL)
    {
        llamadas = (eLibro*)this;
        auxProblema = llamadas->problema;

        if(auxProblema==1)
        {
            retorno = TRUE;
        }
    }
    return retorno;
}

int llamadas_filtroDos(void* this)
{
    eLibro* llamadas;
    int auxProblema;
    int retorno = FALSE;

    if(this!=NULL)
    {
        llamadas = (eLibro*)this;
        auxProblema = llamadas->problema;

        if(auxProblema==2)
        {
            retorno = TRUE;
        }
    }
    return retorno;
}

int llamadas_filtroTres(void* this)
{
    eLibro* llamadas;
    int auxProblema;
    int retorno = FALSE;

    if(this!=NULL)
    {
        llamadas = (eLibro*)this;
        auxProblema = llamadas->problema;

        if(auxProblema==3)
        {
            retorno = TRUE;
        }
    }
    return retorno;
}

int llamadas_filtroCuatro(void* this)
{
    eLibro* llamadas;
    int auxProblema;
    int retorno = FALSE;

    if(this!=NULL)
    {
        llamadas = (eLibro*)this;
        auxProblema = llamadas->problema;

        if(auxProblema==4)
        {
            retorno = TRUE;
        }
    }
    return retorno;
}

int llamadas_filtroCinco(void* this)
{
    eLibro* llamadas;
    int auxProblema;
    int retorno = FALSE;

    if(this!=NULL)
    {
        llamadas = (eLibro*)this;
        auxProblema = llamadas->problema;

        if(auxProblema==5)
        {
            retorno = TRUE;
        }
    }
    return retorno;
}

*/



