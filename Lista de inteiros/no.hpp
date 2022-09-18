#ifndef NO_HPP
#define NO_HPP
#include <iostream>

using namespace std;

class No{
    private:
        int v;
        No* prox;

    public:
        No();
        No(int Valor);
        void setValor(int valor);
        int obterValor();
        No* obterProx();
        void setProx(No* p);
};

#endif