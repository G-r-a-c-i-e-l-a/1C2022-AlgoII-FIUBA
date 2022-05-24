#include <iostream>
#include "funciones_para_vectores.h"

/* 
 * Precondiciones: vector.cantidad debe estar cargado o por lo menos inicializado en 0.
 * Postcondiciones: carga un nuevo arreglo con las posiciones del viejo, agrega la posición y libera
 * la memoria del viejo. 
 */
void cargar_posicion(vector *&vector, int posicion)
{
        int *pos_auxiliar = new int[vector->cantidad + 1];
        
        for (int i = 0; i < vector->cantidad; i++)
                pos_auxiliar[i] = vector->posiciones[i];

        pos_auxiliar[vector->cantidad] = posicion;

        delete [] vector->posiciones;
         
        vector->posiciones = pos_auxiliar;
        vector->cantidad++;
        
}

/* 
 * Precondiciones: ni historia ni frase deben tener caracteres especiales.
 * Postcondiciones: devuelve true si hubo alguna coincidencia de la frase en la historia.
 */
bool hay_coincidencia(char *historia, char *frase)
{
        bool coincidencia = true;
        int j = 0;

        while(frase[j] != 0 && coincidencia){

                if (tolower(historia[j]) != tolower(frase[j]) || historia[j] == 0)                 
                        coincidencia = false;
                j++;
        }

        return coincidencia;
}


vector *buscar_frase(char *historia, char *frase)
{
        vector *vector_aux = new vector;

        vector_aux->cantidad = 0;
        vector_aux->posiciones = nullptr;

        int i = 0;
        while (historia[i] != 0){         

                if(hay_coincidencia(historia+i, frase))
                        cargar_posicion(vector_aux, i);                 
                i++;
        }
        return vector_aux;
}


void imprimir_vector(vector vector)
{
        if (vector.cantidad == 0){
                std::cout << "No se encuentra esa frase en la historia indicada." << std::endl;
                return;
        }

        for (int i = 0; i < vector.cantidad; i++){

                if (i == vector.cantidad - 1)
                        std::cout << vector.posiciones[i];
                else
                        std::cout << vector.posiciones[i] << "-";
        }
        
        std::cout << std::endl;     
}


void liberar_vector(vector *vector)
{
        delete [] vector->posiciones;
        delete(vector);
}
