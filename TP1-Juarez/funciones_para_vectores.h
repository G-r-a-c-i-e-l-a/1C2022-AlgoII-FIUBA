#if !defined(_FUNCIONES_PARA_VECTORES_)
#define _FUNCIONES_PARA_VECTORES_


struct vector {
        int cantidad;
        int *posiciones;
};


/*
 * Precondiciones: ni historia ni frase deben tener caracteres especiales.
 * Postcondiciones: devuelve el vector cargado (tope y posiciones) con las coincidencias encontradas.
 */
vector *buscar_frase(char *historia, char *frase);


/*
 * Precondiciones: -
 * Postcondiciones: imprime por pantalla el vector de posiciones con el formato requerido
 * o una frase particular si está vacío.
 */
void imprimir_vector(vector vector);


/*
 * Precondiciones: -
 * Postcondiciones: libera la memoria reservada para el struct vector y el arreglo de posiciones.
 */
void liberar_vector(vector *vector);


#endif // _FUNCIONES_PARA_VECTORES_

