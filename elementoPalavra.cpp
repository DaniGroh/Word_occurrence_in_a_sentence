#include "elementoPalavra.h"
#include "cstring"
#include "elemento.h"
#include "ListaEnc.h"

using namespace std;

ElementoPalavra::ElementoPalavra()//Construtor, ele seta os valores dos atributos na hora que um Elemento palavra é criado.
{
    palavra = NULL;
    prox = NULL;
    indice = NULL;
    proxindex = NULL;
}

ElementoPalavra* ElementoPalavra::getprox() // Retorna o proxima elemento.
{
    return prox;
}
char *ElementoPalavra::getpalavra()// Retorna a palavra que esta no objeto.
{
    return palavra;
}
void ElementoPalavra::setprox(ElementoPalavra *proximo) // Define o proximo elemento na lista encadeada.
{
    prox = proximo;
}
void ElementoPalavra::setpalavra(char *x) // Define a palavra que esta no objeto.
{
        if(palavra)
            delete palavra;
        palavra = new char[strlen(x)];
        strcpy(palavra,x);
}
ElementoPalavra* ElementoPalavra::getproxindex()
{
    return proxindex;
}
void ElementoPalavra::setproxindex(ElementoPalavra *ind)
{
    proxindex = ind;
}

int ElementoPalavra::getindice()  // Retorna a linha em que esta a palavra.
{
    return indice;
}

void ElementoPalavra::setindice(int _indice) // Define a linha em que se encontra a palavra.
{
    indice = _indice;
}
