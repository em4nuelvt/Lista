#include <iostream>
using namespace std;

class No{

    private:
        int v;
        No* prox;
    public:
        No(){}
        No(int valor){
            this->v=valor;
            this->prox=NULL;
        }

        void setValor(int valor){
            this->v=valor;
        }
        int obterValor(){
            return this->v;
        }

        No* obterProx(){
            return prox;
        }

        void setProx(No* p){
            this->prox=p;
        }
};

class Lista{
    private:
        No* primeiro;
        No* ultimo;
    public:
        Lista(){///construtor vazio
            primeiro=NULL;
            ultimo=NULL;
        }
        Lista(int v){//construtor passando valor
            primeiro = new No(v);
            ultimo=primeiro;
        }

        virtual ~Lista(){//destrutor
            delete primeiro;
        }

        bool vazia(){ //verifica se a lista está vazia
            return primeiro==NULL;
        }

        void mostrar(){//imprime todos os elementos
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

        void inserirInicio(int v){ //insere elemento da lista no começo
            No* novo= new No(v);
            novo->setProx(primeiro);
            primeiro=novo;
        }

        void inserirFim(int v){//insere elemento da lista no fim da lista

            No* novo= new No(v);

            if(vazia()){
                primeiro=novo;
                ultimo=primeiro;
                return;
            }

            ultimo->setProx(novo);
            ultimo=novo;
        }

        int tamanho(){ //retorna o tamanho da lista 
            if (vazia()){
                return 0;
            }
            else{
                int tamanho =0;
                No *atual= primeiro;

                while(atual){
                    tamanho++;
                    atual= atual->obterProx();
                }    
            }

        }

        bool existe(int v){
            No *atual= primeiro;
            while(atual){
                if (atual->obterValor()==v)
                    return true;
                atual= atual->obterProx();    
            }
            return false;
        }
        void remover()//remoção do final
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

};

int main(){
    Lista l(1);
    l.inserirFim(2);
    l.inserirInicio(4);
    l.remover();
    l.mostrar();
    
    return 0;
}