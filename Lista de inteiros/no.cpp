
#include <iostream>
#include "no.hpp"
using namespace std;

No::No(){}
No::No(int valor){
    this->v=valor;
    this->prox=NULL;
}

void No::setValor(int valor){
    this->v=valor;
}
int No::obterValor(){
    return this->v;
}

No* No::obterProx(){
    return prox;
}

void No::setProx(No* p){
    this->prox=p;
}