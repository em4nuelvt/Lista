#include "lista.hpp"
#include "no.hpp"
#include <iostream>

using namespace std;

int main(){
    Lista l(1);
    l.inserirFim(2);
    l.inserirInicio(4);
    l.removerUltimo();
    l.mostrar();
    return 0;
}