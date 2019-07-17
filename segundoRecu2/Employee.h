#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char titulo[50];
    char autor[50];
    int precio;
    int editorial;
    char descEditorial[50];
}eLibro;

typedef struct
{
    int id;
    char descripcion[50];
}Editoriales;

eLibro* employee_new();
eLibro* employee_newParametros(char* idStr, char* tituloStr, char* autorStr, char* precioStr, char* editorialStr);
void employee_delete(eLibro* this);

Editoriales *editoriales_new();
Editoriales* editoriales_newParametros(int id, char* descripcion);

int editoriales_setId(Editoriales* this, int id);
int editoriales_getId(Editoriales* this,int* id);

int editoriales_setDescripcion(Editoriales* this, char* descripcion);
int editoriales_getDescripcion(Editoriales* this,char* descripcion);




int employee_setId(eLibro* this,int id);
int employee_getId(eLibro* this,int* id);

int employee_setTitulo(eLibro* this, char* titulo);
int employee_getTitulo(eLibro* this,char* titulo);

int employee_setAutor(eLibro* this, char* autor);
int employee_getAutor(eLibro* this,char* autor);

int employee_setPrecio(eLibro* this, int precio);
int employee_getPrecio(eLibro* this,int* precio);

int employee_setEditorial(eLibro* this, int editorial);
int employee_getEditorial(eLibro* this,int* editorial);

int employee_setDescEditorial(eLibro* this, char* descEditorial);
int employee_getDescEditorial(eLibro* this,char* descEditorial);

int sortPorEditorialId(void* auxLibroUno, void* auxLibroDos);

void aplicarDescuentos (void* this);

int llamadas_filtroUno(void* this);
int llamadas_filtroDos(void* this);
int llamadas_filtroTres(void* this);
int llamadas_filtroCuatro(void* this);
int llamadas_filtroCinco(void* this);


void employee_calcularSueldo(void* auxeLibro);
int employee_empleadosPlatudos (void* auxeLibro);
int employee_empleadosExplotados (void* auxeLibro);
int employee_empleadosConIdBajo (void* auxeLibro);

int sorteLibroById(void* auxeLibroUno, void* auxeLibroDos);
int sorteLibroByName(void* auxeLibroUno, void* auxeLibroDos);
int sorteLibroByHorasTrabajadas(void* auxeLibroUno, void* auxeLibroDos);
int sorteLibroBySueldo(void* auxeLibroUno, void* auxeLibroDos);

#endif // employee_H_INCLUDED
