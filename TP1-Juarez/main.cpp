#include <iostream>
#include "funciones_para_vectores.h"


int main(int argc, char **argv)
{
        if (argc < 3){
                std::cout << "ERROR: faltan parámetros" << std::endl;
                std::cout << "Formato válido: " << argv[0] << " historia frase" << std::endl;
                return -1;
        }

        vector *vector = nullptr;
        
        vector = buscar_frase(argv[1], argv[2]);
        imprimir_vector(*vector);
        liberar_vector(vector); 

        return 0;
}
