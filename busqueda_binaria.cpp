#include <iostream>
#include "funciones_auxiliares_vectores_enteros.cpp"

using namespace std;

const int CANT_ELEMENTOS = 7;

int busquedaBinaria(int vector[], int n, float clave)
{
    int izquierda = 0, derecha = n - 1, central;
    bool encontrado = false;
    while ((izquierda <= derecha) && (!encontrado))
    {
        central = (izquierda + derecha) / 2;
        if (vector[central] == clave)
            encontrado = true;
        // éxito en la búsqueda
        else if (clave < vector[central])
            // a la izquierda de central
            derecha = central - 1;
        else
            // a la derecha de central
            izquierda = central + 1;
    }
    return encontrado ? central : -1;
    // central si encontrado –1 otro caso
}

int main()
{
    int vector1[] = {7, 8, 9, 10, 15, 45, 88};

    imprimirVector("Ordenado", vector1, CANT_ELEMENTOS);

    cout << "Posicion: " << busquedaBinaria(vector1, CANT_ELEMENTOS, 10);

    return EXIT_SUCCESS;
}
