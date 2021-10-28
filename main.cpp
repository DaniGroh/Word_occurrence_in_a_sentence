//TRABALHO PR�TICO DE ECO010 - Indice Remissivo
//Pedro Vallese 28882
//Daniel Groh 31061
//Daniel Medeiros 28079


#include <iostream>
#include <fstream>
#include <cstdio>
#include <string.h>
#include "ListaEncPalavra.h"
#include "elementoPalavra.h"

using namespace std;

int main()
{
    ListaEncPalavra B;
    int cont = 0;
    ifstream arquivo; //Cria o arquivo
    setlocale(LC_ALL, "Portuguese");  //Valida o uso de acentos
    locale loc; //Valida o uso de manipulacao de strings
    char n,*encontrada;// char para auxiliar na contagem de linhas
    string palavra,palavrachave;//String para a leitura do texto e a segunda para utilizar como palavra chave
    int contalinha=1,aux0=0; //auxiliares para o funcionamento do programa

    while(aux0==0)
    {
        do
        {
        cout<<"Digite a palavra pra ser encontrada(Nao sera lido espacos)"<<endl;
        cin>>palavrachave;
        cont++;
        cout<<palavrachave[0];
        //cout<<palavrachave;
        arquivo.open("texto.txt"); //abre o arquivo
        if (arquivo.is_open()) //se o arquivo estiver aberto
        {
            while (arquivo.good()) //enquanto ele est� aberto
            {
                arquivo>>palavra; //pega a palavra

                n = (char) arquivo.get(); //le o proximo caractere (normalmente � espa�o (" ") ou pulagem de linha (\n)
                for(int i=0; i<palavra.length(); i++)
                {
                    if(palavra[i] == 'à'||palavra[i] == 'á'||palavra[i] == 'ã')
                        palavra = 'a';
                    if(palavra[i] == 'ê'||palavra[i] == 'é')
                        palavra = 'e';
                    if(palavra[i] == 'ô'||palavra[i] == 'õ')
                        palavra = 'o';
                    if(palavra[i] == 'í')
                        palavra = 'i';
                    if(palavra[i] == 'ú')
                        palavra = 'u';
                    if(palavra[i] == 'ç')
                        palavra = 'c';
                    if(palavra[i]=='?'||palavra[i]==','||palavra[i]=='.'||palavra[i]=='!'||palavra[i]==':'||palavra[i]==';') //Se a palavra for seguida de alguma pontua�ao
                    {
                        palavra.erase(i);//deleta essa pontuaçao do armazenamento
                    }
                }
                for(int i=0; i<palavra.length(); i++)
                    palavra[i]=tolower(palavra[i],loc);//Deixa a palavra inteira em minuscula
                if(palavra==palavrachave) // se a palavra do texto for igual a palavrachave
                {
                    encontrada = new char[palavra.size() + 1]; //cria um char[] com o tamanho da string
                    copy(palavra.begin(), palavra.end(), encontrada); //passa o conteudo da string para o char
                    // cout<<contalinha<<endl;
                    B.inserirordenado(encontrada,contalinha);
                    B.listar();
                }

                if(n=='\n') //se for \n
                    contalinha++; //soma 1 linha
            }
            arquivo.close();
            contalinha=1;
            palavra.erase(palavra.begin(),palavra.end());
        }
    }while(cont = 5);
    }
}
