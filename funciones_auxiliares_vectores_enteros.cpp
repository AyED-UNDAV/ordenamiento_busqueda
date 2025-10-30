#include <iostream>

using namespace std;

void imprimirVector(string intro, int vector[], int cantidadElementos)
{

    cout << intro << endl;
    cout << "( ";
    for (int idx = 0; idx < cantidadElementos; idx++)
    {
        cout << vector[idx] << " ";
    }
    cout << " ) " << endl;
}

void swapValor(int vector[], int viejaPos, int nuevaPos)
{
    int temp = vector[viejaPos];
    vector[viejaPos] = vector[nuevaPos];
    vector[nuevaPos] = temp;
}