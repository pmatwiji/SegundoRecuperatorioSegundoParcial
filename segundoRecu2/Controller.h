#define FALSE 0
#define TRUE 1

int controller_load(char* path, LinkedList* pArrayListLibros);
int controller_addeLibro(LinkedList* pArrayListeLibro);
int controller_editeLibro(LinkedList* pArrayListeLibro);
int controller_removeeLibro(LinkedList* pArrayListeLibro);
int controller_ListLibros(LinkedList* this, LinkedList* this2);
int controller_sortLibros(LinkedList* pArrayListLibros);
int controller_guardarSueldos(char* path, LinkedList* pArrayListeLibro);
int controller_saveAsBinary(char* path , LinkedList* pArrayListeLibro);

void controller_listOne(LinkedList* this, LinkedList* this2, int index);
void controller_descripcionEditoriales(LinkedList* this);
int controller_guardarFiltrada(char* path, LinkedList* this);

