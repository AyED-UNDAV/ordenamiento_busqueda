#include <iostream>
#include <cstring>

using namespace std;

int main() {
    // 🔢 strlen - Longitud de la cadena
    char mensaje[] = "Hola mundo";
    cout << "👉 strlen: Longitud de 'Hola mundo' = " << strlen(mensaje) << endl;

    // 📥 strcpy - Copiar una cadena
    char destino[30];
    strcpy(destino, "Texto copiado");
    cout << "👉 strcpy: Copiado en 'destino' = " << destino << endl;

    // ➕ strcat - Concatenar cadenas
    char saludo[30] = "Hola, ";
    char nombre[] = "Juan";
    strcat(saludo, nombre);
    cout << "👉 strcat: Resultado de concatenar = " << saludo << endl;

    // 🔍 strstr - Buscar una subcadena
    char texto[] = "Programar en C++ es divertido";
    char* encontrado = strstr(texto, "C++");
    if (encontrado != nullptr) {
        cout << "👉 strstr: Subcadena 'C++' encontrada: " << encontrado << endl;
    } else {
        cout << "👉 strstr: Subcadena no encontrada." << endl;
    }

    // ⚖️ strcmp - Comparar cadenas
    char a[] = "hola";
    char b[] = "hola";
    if (strcmp(a, b) == 0) {
        cout << "👉 strcmp: Son iguales" << endl;
    } else {
        cout << "👉 strcmp: Son diferentes" << endl;
    }

    return 0;
}
