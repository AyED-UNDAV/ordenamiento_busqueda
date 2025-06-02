#include <iostream>
#include "funciones_auxiliares_vectores_enteros.cpp"

using namespace std;

const int CANT_ELEMENTOS = 7;

/**
 *
 * Idea principal:
 * Recorrer el arreglo y en cada paso, insertar el elemento actual en la posición correcta dentro de la porción ya ordenada.
 *
 */
void ordenarPorInsercion(int vector[])
{
    for (int outIdx = 1; outIdx < CANT_ELEMENTOS; outIdx++)
    {
        bool hayaCambio = true;
        int inIdx = outIdx - 1;
        while (hayaCambio && inIdx >= 0)
        {
            if (vector[inIdx] > vector[inIdx + 1])
            {
                swapValor(vector, inIdx, inIdx + 1);
            }
            else
            {
                hayaCambio = false;
            }
            inIdx--;
        }
    }
}

int main()
{
    int vector2[] = {88, 8, 9, 10, 7, 15, 1};
    imprimirVector("Vector 2 sin orden", vector2, CANT_ELEMENTOS);

    ordenarPorInsercion(vector2);
    imprimirVector("Vector 2 ordenado por insercion", vector2, CANT_ELEMENTOS);

    return EXIT_SUCCESS;
}