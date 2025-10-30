#include "funciones_escrutinio.cpp"

using namespace std;

int buscarNumeroLista(Partido partidos[MAX_PARTIDOS], int numeroLista)
{
    int posEncontrada = -1;
    int pos = 0;

    while (pos < MAX_PARTIDOS && posEncontrada == -1)
    {
        if (partidos[pos].numeroLista == numeroLista)
        {
            posEncontrada = pos;
        }
        pos++;
    }

    return posEncontrada;
}

void mostrarGanador(int urnas[MAX_PARTIDOS], Partido partidos[MAX_PARTIDOS])
{
    int masVotos = urnas[0];
    int posMasVotos = 0;
    for (int idx = 1; idx < MAX_PARTIDOS; idx++)
    {
        if (urnas[idx] > masVotos)
        {
            masVotos = urnas[idx];
            posMasVotos = idx;
        }
    }

    cout << "El partido ganador es: " << partidos[posMasVotos].nombrePartido << endl;
    cout << "Obtuvo " << masVotos << " votos" << endl;
}

int main()
{
    Partido partidos[MAX_PARTIDOS];
    inicializarPartidos(partidos);

    Voto voto = dameVotoAProcesar();
    int urnas[MAX_PARTIDOS] = {0};

    while (voto.circuito != -1 && voto.mesa != -1)
    {
        cout << "Voto por lista: " << voto.numeroLista << endl;
        int posLista = buscarNumeroLista(partidos, voto.numeroLista);
        if (posLista != -1)
        {
            urnas[posLista] = urnas[posLista] + 1;
        }
        voto = dameVotoAProcesar();
    }

    mostrarGanador(urnas, partidos);

    return EXIT_SUCCESS;
}