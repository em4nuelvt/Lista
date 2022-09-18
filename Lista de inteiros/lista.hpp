#ifndef LISTA_HPP
#define LISTA_HPP
#include <iostream>
#include "no.hpp"
using namespace std;


class Lista{
    private:
        No* primeiro;
        No* ultimo;
    public:
        Lista();
        Lista(int v);
        virtual ~Lista();
        bool vazia();
        void mostrar();
        void inserirInicio(int v);
        void inserirFim(int v);
        int tamanho();
        bool existe(int v);
        void removerUltimo();

};




#endif