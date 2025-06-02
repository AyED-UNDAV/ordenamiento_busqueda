#include <iostream>
#include "funciones_auxiliares_vectores_enteros.cpp"

using namespace std;

const int CANT_ELEMENTOS = 7;

int buscarMinimoYDevolverPosicion(int vector[], int desde)
{
    int minimo = vector[desde];
    int posCambio = desde;
    for (int idx = desde + 1; idx < CANT_ELEMENTOS; idx++)
    {
        if (vector[idx] < minimo)
        {
            minimo = vector[idx];
            posCambio = idx;
        }
    }
    return posCambio;
}

/**
 * Idea principal:
 *
 * Recorrer el arreglo, y en cada posición buscar el mínimo (o máximo) del resto y colocarlo en esa posición.
 */
void ordenarPorSeleccion(int vector[])
{
    for (int outIdx = 0; outIdx < CANT_ELEMENTOS; outIdx++)
    {
        int posMinimo = buscarMinimoYDevolverPosicion(vector, outIdx);
        swapValor(vector, outIdx, posMinimo);
    }
}

int main()
{

    int vector1[] = {15, 8, 9, 10, 7, 1, 88};
    imprimirVector("Vector sin orden", vector1, CANT_ELEMENTOS);

    ordenarPorSeleccion(vector1);
    imprimirVector("Ordenado por selección", vector1, CANT_ELEMENTOS);

    return EXIT_SUCCESS;
}