/* *****************************************************************
 *                      ESTRUCTURA DEL ABB
 * *****************************************************************/

typedef struct abb_nodo_t{
    void* clave;
    void* dato;
    struct abb_nodo_t* izq;
    struct abb_nodo_t* der;
}nodo_t;

typedef struct abb{
    struct nodo_t* raiz;
    abb_comparar_clave_t cmp;
    abb_destruir_dato_t destruir_dato;
    size_t cant;
}abb_t;

/* *****************************************************************
 *                     PRIMITIVAS DEL ABB
 * *****************************************************************/

abb_t* abb_crear(abb_comparar_clave_t cmp, abb_destruir_dato_t destruir_dato){
	abb_t* arbol = malloc(sizeof(abb_t));
	if (arbol == NULL) return NULL;
	arbol->raiz = NULL;
	arbol->cant = 0;
	arbol->cmp =cmp;
	arbol->destruir_dato = destruir_dato;
	return arbol;	
}

bool abb_guardar(abb_t *arbol, const char *clave, void *dato){
	// Caso base: mi arbol esta vacio o el nodo al que llegue es NULL
	if (!arbol->raiz){ 
		arbol->raiz = crear_nodo(clave, dato);
		if (!arbol->raiz) return false;
		arbol->cant++;
		return true;
	}
	if (cmp(clave, arbol->raiz->clave) <= 0){
		abb_guardar(arbol->izq, clave, dato);
	}
	else{
		abb_guardar(arbol->der, clave, dato);
	}
}

/* *****************************************************************
 *                      FUNCIONES AUXILIARES
 * *****************************************************************/
char *strdup (const char *s) {
    char *d = malloc (strlen (s) + 1);   
    if (d == NULL) return NULL;          
    strcpy (d,s);                        
    return d;                            
}

nodo_t* crear_nodo(char* clave, void* dato){
	nodo_t* nodo = malloc(sizeof(nodo_t));
	nodo->clave = strdup(clave);
	nodo->dato = dato;
	nodo->der = NULL;
	nodo->izq = NULL;
	return nodo;
}
