#include <iostream>
#include <cstring>

using namespace std;

const int MAX_NOMBRE = 50;
const int MAX_TELEFONO = 50;
const int MAX_EMAIL = 100;
const int MAX_DNI = 10;
const int MIN_EDAD = 18;
const int MIN_ALTURA = 120;
const int MAX_EVENTO_NOMBRE = 100;

struct Persona
{
    int edad;
    int altura;
    char dni[MAX_DNI];
    char email[MAX_EMAIL];
    char nombre[MAX_NOMBRE];
    char telefono[MAX_TELEFONO];
    bool esSoltero;
};

struct Evento
{
    int edadMinima;
    char nombreEvento[MAX_EVENTO_NOMBRE];
    bool esEventoExclusivoParaSolteros;
};

/*
Consigna: hacer un software que le pida los siguientes datos a una persona

nombre - un arreglo de 30 caracteres
edad - int
altura - int
dni - un arreglo de 10 caracteres
email - un arreglo de 100 caracteres

Que cargue los datos y que chequee si la persona puede entrar a un evento
Debe tener como mínimo 18 años y medir más de 120 centímetros por cuestiones de seguridad

Que muestre los datos de la persona y que nos diga si puede ingresar o no
*/

void ingresoDatos(Persona &personaParam)
{
    cout << "ingrese su nombre:\n";
    cin >> personaParam.nombre;

    cout << "ingrese su edad:\n";
    cin >> personaParam.edad;

    cout << "ingrese su dni:\n";
    cin >> personaParam.dni;

    cout << "ingrese su email:\n";
    cin >> personaParam.email;

    cout << "ingrese su altura:\n";
    cin >> personaParam.altura;

    cout << "ingrese su telefono:\n";
    cin >> personaParam.telefono;

    char esSoltero;
    cout << "ingrese si es soltero (s/n):\n";
    cin >> esSoltero;

    if (esSoltero == 's')
    {
        personaParam.esSoltero = true;
    }
    else
    {
        personaParam.esSoltero = false;
    }
}

void mostrarDatos(Persona personaParam)
{

    cout << "***********************" << endl;

    cout << "Nombre: " << personaParam.nombre << endl;
    cout << "Edad: " << personaParam.edad << endl;
    cout << "Email: " << personaParam.email << endl;
    cout << "DNI: " << personaParam.dni << endl;
    cout << "Altura: " << personaParam.altura << endl;
    cout << "Telefono: " << personaParam.telefono << endl;

    cout << "Es soltero?: ";

    if (personaParam.esSoltero)
    {
        cout << "Si";
    }
    else
    {
        cout << "No";
    }

    cout << endl
         << "***********************" << endl;
}

bool puedeIngresarAlEvento(Evento evento, Persona persona)
{
    return (persona.edad > evento.edadMinima && persona.altura > MIN_ALTURA) ||
           (persona.nombre[0] == 'p' || persona.nombre[0] == 'P') ||
           (persona.esSoltero && evento.esEventoExclusivoParaSolteros);
}

void inicializarEvento(Evento &evento)
{
    evento.edadMinima = 0;
    evento.esEventoExclusivoParaSolteros = false;
    strcpy(evento.nombreEvento, "");
}

void inicializarPersona(Persona &persona)
{
    persona.edad = -1;
    persona.altura = -1;
    strcpy(persona.dni, "");
    strcpy(persona.email, "");
    strcpy(persona.nombre, "");
    strcpy(persona.telefono, "");
    persona.esSoltero = false;
}

int main()
{
    Persona personaEvento;
    inicializarPersona(personaEvento);

    // evento
    Evento eventoActual;
    inicializarEvento(eventoActual);
    eventoActual.edadMinima = 15;
    eventoActual.esEventoExclusivoParaSolteros = true;

    ingresoDatos(personaEvento);

    if (puedeIngresarAlEvento(eventoActual, personaEvento) == true)
    {
        cout << "La persona cumple las condiciones para pasar al evento\n";
    }
    else
    {
        cout << "La persona no cumple las condiciones para pasar al evento\n";
    }

    mostrarDatos(personaEvento);

    return EXIT_SUCCESS;
}