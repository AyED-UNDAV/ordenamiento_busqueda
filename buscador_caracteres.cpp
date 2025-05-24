#include <iostream>

using namespace std;

const int TOPE = 50;

int buscarCaracteres(char texto[], char caracter1, char caracter2, int tope)
{
    int idx = 0;
    bool caracterEncontrado = false;

    while (texto[idx] != '\0' && idx < tope && caracterEncontrado == false)
    {

        if (texto[idx] == caracter1 || texto[idx] == caracter2)
        {
            caracterEncontrado = true;
        }
        else
        {
            idx++;
        }
    }

    int valorRetorno = -1;

    if (caracterEncontrado)
    {
        valorRetorno = idx;
    }

    return valorRetorno;
}

int main()
{

    char texto[TOPE] = "";
    char car1, car2;

    cout << "ingrese texto: " << endl;
    cin.getline(texto, TOPE);

    cout << "ingrese caracter 1 " << endl;
    cin >> car1;
    cout << "ingrese caracter 2 " << endl;
    cin >> car2;

        int resultadoBusqueda = buscarCaracteres(texto, car1, car2, TOPE);

    if (resultadoBusqueda == -1)
    {
        cout << "NO ESTÆ";
    }
    else
    {
        cout << "AL MENOS UNO";
    }

    return EXIT_SUCCESS;
}