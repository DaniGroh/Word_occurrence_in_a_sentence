#include "elementoPalavra.h"
#include <cstring>
#include <iostream>
#include "ListaEncPalavra.h"
#include <fstream>
using namespace std;

ListaEncPalavra::ListaEncPalavra()
{
    inicio = NULL;
}

bool ListaEncPalavra::inserirordenado (char *x,int i)
{
    ElementoPalavra *auxPalavra = new ElementoPalavra;
    ElementoPalavra *auxIndex = new ElementoPalavra;

    if(auxPalavra&&auxIndex)
    {
        int aux3=0;
        auxIndex->setindice(i);
        auxPalavra->setpalavra(x);
        auxPalavra->setproxindex(auxIndex);

        if (inicio == NULL) //se a lista estiver vazia
        {

            inicio = auxPalavra;
            auxPalavra->setprox(NULL);      //insere primeiro item
            return true;
        }
        else
        {
            ElementoPalavra *aux1 = inicio;
            while(aux1!=NULL)
            {
                if(aux1->getpalavra()==auxPalavra->getpalavra())
                {
                    ElementoPalavra *aux2 = aux1->getproxindex();
                    while(aux2->getproxindex()!=NULL)
                        aux2 = aux2->getproxindex();
                    if(aux2->getindice()!=auxIndex->getindice())
                        aux2->setproxindex(auxIndex);

                    aux3=1;
                    break;
                }
                else aux1 = aux1->getprox();
            }
            if(aux3==0)
            {
                ElementoPalavra *aux2 = inicio->getprox();
                ElementoPalavra *ant = inicio;

                if (aux2 == NULL) //se a lista tiver um só elemento
                {
                    if(strcmp(inicio->getpalavra(),x)<0)//se o elemento for maior
                    {
                        //� inserido no final
                        inicio->setprox(auxPalavra);
                        auxPalavra->setprox(NULL);
                        return true;
                    }
                    else //se for maior
                    {
                        auxPalavra->setpalavra(x);
                        auxPalavra->setprox(inicio);   //� inserido no come�o
                        inicio = auxPalavra;
                        return true;
                    }
                }
                if( strcmp(x, inicio->getpalavra())<0) //se o elemento for menor que o inicio
                {
                    auxPalavra->setpalavra(x);
                    auxPalavra->setprox(inicio); //� colocado no come�o
                    inicio=auxPalavra;
                    return true;
                }
                int t=0;
                while(aux2!=NULL) //enquanto auxiliar 2 for igual NULL
                {
                    if( strcmp(x, aux2->getpalavra())<=0 ) //se o elemento for menor que a palavra ja inserida
                    {
                        auxPalavra->setpalavra(x);
                        auxPalavra->setprox(aux2); //o auxilair insere o elemento antes da palavra
                        ant->setprox(auxPalavra);
                        return true;
                    }

                    //cout<<t<<endl;
                    t++;
                    aux2 = aux2->getprox(); //comando que anda com auxiliar 2
                    ant = ant->getprox(); //comando que anda com seu anterior

                }

                auxPalavra->setpalavra(x);
                auxPalavra->setprox(NULL); //cria um auxiliar no final.
                ant->setprox(auxPalavra);
            }
        }
    }
}

 void ListaEncPalavra::listar() // Lista o elemento no arquivo de escrita.
{
    ofstream arq;
    arq.open("escrita.txt");
    if(arq.is_open())
    {
        ElementoPalavra *aux = inicio;
        ElementoPalavra *auxindex= aux->getproxindex();
        if (inicio == 0)
        {
            cout << "Lista vazia" << endl;
        }
        else
        {
            arq << endl;
            arq << aux->getpalavra();

            while(aux != NULL)
            {

                auxindex = aux->getproxindex();

                cout<< aux->getpalavra();
                while(auxindex!=NULL)
                {
                    arq<<" "<<auxindex->getindice();
                    cout<<" "<<auxindex->getindice();
                    auxindex = auxindex->getproxindex();
                }
                aux = aux->getprox();

                cout<<endl;
            }
        }
        arq<<endl;

    }arq.close();
}
bool ListaEncPalavra::listavazia()
{
    if (inicio == 0)
        return true;

    return false;
}

ListaEncPalavra::~ListaEncPalavra()
{
    if (listavazia() == false)
    {
        ElementoPalavra *aux = inicio;

        while (inicio->getprox() != NULL)
        {
            aux = aux->getprox();
            delete inicio;
            inicio = aux;
        }
    }
}


ElementoPalavra *ListaEncPalavra::getinicio()
{
    return inicio;
}
