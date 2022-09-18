
#include <iostream>
#include "lista.hpp"
#include "no.hpp"
using namespace std;

Lista::Lista(){///construtor vazio
    primeiro=NULL;
    ultimo=NULL;
}
Lista::Lista(int v){//construtor passando valor
    primeiro = new No(v);
    ultimo=primeiro;
}

Lista::~Lista(){//destrutor
    delete primeiro;
}

bool Lista::vazia(){ //verifica se a lista está vazia
    return primeiro==NULL;
}

void Lista::mostrar(){//imprime todos os elementos
    cout << "Imprimindo todos os elementos"<<endl;
    No *c= primeiro;

    if (vazia()){
        return;
    }
    do{
        cout<< c->obterValor()<<endl;
        c=c->obterProx();
    }while(c);

    cout<<endl;
    return;     
}

void Lista::inserirInicio(int v){ //insere elemento da lista no começo
    No* novo= new No(v);
    novo->setProx(primeiro);
    primeiro=novo;
}

void Lista::inserirFim(int v){//insere elemento da lista no fim da lista

    No* novo= new No(v);

    if(vazia()){
        primeiro=novo;
        ultimo=primeiro;
        return;
    }

    ultimo->setProx(novo);
    ultimo=novo;
}

int Lista::tamanho(){ //retorna o tamanho da lista 
    if (vazia()){
        return 0;
    }
    else{
        int tam =0;
        No *atual= primeiro;

        while(atual){
            tam++;
            atual= atual->obterProx();
        }
        return tam;    
    }
    

}

bool Lista::existe(int v){
    No *atual= primeiro;
    while(atual){
        if (atual->obterValor()==v)
            return true;
        atual= atual->obterProx();    
    }
    return false;
}
void Lista::removerUltimo()//remoção do final
{
    if(!vazia()){
        //se houver somente 1 elemento
        if(primeiro->obterProx()==NULL){
            primeiro=NULL;
        } 
        //se houver 2 elementos 
        else if(primeiro->obterProx()->obterProx()==NULL){
            primeiro->setProx(NULL);
        }
        else{
            No* ant_ant = primeiro;
            No* ant = primeiro->obterProx();
            No* corrente = primeiro->obterProx()->obterProx();

            while(corrente){
                No *aux=ant;
                ant=corrente;
                ant_ant=aux;
                corrente=corrente->obterProx();
            }
            delete ant;
            ant_ant->setProx(NULL);
            ultimo=ant_ant;
        }

    }
    
}