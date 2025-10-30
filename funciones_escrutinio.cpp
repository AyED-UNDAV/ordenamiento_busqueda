#include <cstring>
#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>

const int MAX_NOMBRE = 50;
const int MAX_PARTIDOS = 10;
const int MAX_CIRCUITOS = 50;
const int MAX_MESAS = 1000;

struct Voto
{
    int numeroLista;
    int circuito;
    int mesa;
};

struct Partido
{
    char nombrePartido[MAX_NOMBRE];
    int numeroLista;
};

Partido partidosTemporal[MAX_PARTIDOS] = {
    {"Partido Azul", 10},
    {"Partido Violeta", 254},
    {"Partido Rojo y Blanco", 3},
    {"Partido Rojo", 42},
    {"Partido Verde", 7},
    {"Partido Amarillo", 1},
    {"Partido Celeste", 124},
    {"Partido Negro", 88},
    {"Partido Blanco", 256},
    {"Partido Celeste y Blanco", 10}};

bool deboGenerarMasVotos()
{
    int dado = rand() % 100;
    return dado != 99;
}

bool esVotoAnulado()
{
    int dado = rand() % 6;
    return dado == 0;
}

int obtenerIndiceAleatorio(int tamaño)
{
    int indice = rand() % tamaño;
    return indice;
}

int dameNumeroLista()
{
    int numeroLista = -1;
    if (esVotoAnulado())
    {
        std::cout << "ANULADO!";
        numeroLista = rand() % 100;
    }
    else
    {
        int indice = obtenerIndiceAleatorio(MAX_PARTIDOS);
        numeroLista = partidosTemporal[indice].numeroLista;
    }

    return numeroLista;
}

/*
 *   Se usa para obtener datos a procesar
 *   Devuelve votos con números de lista que pueden ser válidos (o sea, estar dentro de los partidos),
 *   pero también puede devolver números inexistentes.
 *   Si no hay más votos para procesar devuelve -1 en circuito o mesa.
 *
 */
Voto dameVotoAProcesar()
{
    Voto voto;
    if (deboGenerarMasVotos())
    {
        voto.circuito = rand() % MAX_CIRCUITOS;
        voto.mesa = rand() % MAX_MESAS;
        voto.numeroLista = dameNumeroLista();
    }
    else
    {
        voto.circuito = -1;
    }

    return voto;
}
/*
 *   Se debe llamar una sola vez para inicializar los partidos que participan en la contienda
 *   El array 'partidos' pasado por parámetro lo devuelve completo con datos válidos
 *
 */
void inicializarPartidos(Partido partidos[])
{
    // esto lo hacemos para generar una semilla de randomización
    srand(time(0));
    memcpy(partidos, partidosTemporal, sizeof(partidosTemporal));
}
