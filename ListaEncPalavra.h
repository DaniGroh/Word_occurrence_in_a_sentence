#include "elementoPalavra.h"
#include <iostream>
//#ifndef NOLISTA_B_INCLUDED
//#define NOLISTA_B_INCLUDED

using namespace std;

class ListaEncPalavra // Define a lista encadeada.
{
private:
    ElementoPalavra *inicio; // define o primeiro elemento da lista.
public:
    // conjunto de funções.
    ListaEncPalavra();
    ~ListaEncPalavra();
    bool inserirordenado (char*,int);
    void listar ();
    bool listavazia();
    ElementoPalavra *getinicio();
};

//#endif

