#include <iostream>
#include "funciones_auxiliares_vectores_enteros.cpp"

const int CANT_ELEMENTOS_BUSQUEDA = 10;

int busqueda_binaria(int vector[], int n, int clave)
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
};

int main()
{
    int vector1[] = {1, 8, 9, 10, 15, 50, 87, 56, 900, 1200};
    // recordar que debe estar ordenado el vector para que se pueda usar el algoritmo de búsqueda binaria
    imprimirVector("Vector ordenado", vector1, CANT_ELEMENTOS_BUSQUEDA);

    // buscamos dos elementos, uno que está, otro que no
    int posicion = busqueda_binaria(vector1, CANT_ELEMENTOS_BUSQUEDA, 10);
    cout << "Posicion devuelta: " << posicion << endl;

    posicion = busqueda_binaria(vector1, CANT_ELEMENTOS_BUSQUEDA, 298);
    cout << "Posicion devuelta: " << posicion << endl;
}
