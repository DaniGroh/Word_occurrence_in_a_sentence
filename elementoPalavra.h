#include <iostream>
#ifndef NOLISTA_A_INCLUDED
#define NOLISTA_A_INCLUDED
using namespace std;

class ElementoPalavra // Cria o nó que iremos utilizar para salvar tanto as linhas como as palavras que iremos buscar nos textos.
{
private: // atributos privados.
    char *palavra;
    int indice;
    ElementoPalavra *prox;
    ElementoPalavra *proxindex;
  public:
      // chamadas de função publicas
    ElementoPalavra();
    ElementoPalavra* getprox();
    char* getpalavra();
    void setprox(ElementoPalavra*);
    void setpalavra(char*);
    ElementoPalavra* getproxindex();
    void setproxindex(ElementoPalavra*);
    int getindice();
    void setindice(int);
};

#endif

