#include <iostream>
#include <malloc.h>  
using namespace std;

struct Nodo {
    int codigo;
    char nombre[50];
    int fechaven;
    char dia[30];
    char mes[30];
    Nodo* izq;
    Nodo* der;
};

Nodo* raiz = nullptr, *aux,*aux2;
Nodo* subraiz = nullptr;


void preorden(Nodo* aux3) {
    if (aux3 != nullptr) {

        cout << "su codigo es :" << " - "<<aux3->codigo<<endl;
        cout<<"su nombre es :"<< " - " << aux3->nombre << endl;  
        cout<<"su fecha de vencimiento es :"<< " - "  << aux3->fechaven << " - " << aux3->mes << " - " << aux3->dia <<endl;
        
        preorden(aux3->izq);
        preorden(aux3->der);
    }
}

void inorden(Nodo* aux3) {

    if (aux3 != nullptr) {

        inorden(aux3->izq);

        cout << "su codigo es :" << " - "<<aux3->codigo<<endl;
        cout<<"su nombre es :"<< " - " << aux3->nombre << endl; 
        cout<<"su fecha de vencimiento es :"<< " - "  << aux3->fechaven << " - " << aux3->mes << " - " << aux3->dia <<endl;

        inorden(aux3->der);
    }
}

void postorden(Nodo* aux3) {
    if (aux3 != nullptr) {

        postorden(aux3->izq);
        postorden(aux3->der);

        cout << "su codigo es :" << " - "<<aux3->codigo<<endl;
        cout<<"su nombre es :"<< " - " << aux3->nombre << endl;
        cout<<"su fecha de vencimiento es :"<< " - "  << aux3->fechaven << " - " << aux3->mes << " - " << aux3->dia <<endl;

    }
}

void posicionar() {

    while (aux2 != nullptr) {
        if (aux->codigo < aux2->codigo) {
            if (aux2->izq == nullptr) {
                aux2->izq = aux;
                
            }
            aux2 = aux2->izq;
        } else {
            if (aux2->der == nullptr) {
                aux2->der = aux;
                
            }
            aux2 = aux2->der;
        }
    }
}

void posicionarfe() {

    aux2 = subraiz;  

    while (aux2 != nullptr) {
        if (aux->fechaven < aux2->fechaven) {
            if (aux2->izq == nullptr) {
                aux2->izq = aux;
               
            }
            aux2 = aux2->izq;
        } else {
            if (aux2->der == nullptr) {
                aux2->der = aux;
                
            }
            aux2 = aux2->der;
        }
    }
}

void registrar(){

    aux = (Nodo*)malloc(sizeof(Nodo));

    cout << "Ingrese su nombre: ";
    cin >> aux->nombre;

    cout << "Ingrese su codigo: ";
    cin >> aux->codigo;

    cout << "Ingrese su fecha de vencimiento: ";
    cin >> aux->fechaven;

    cout << "Ingrese el mes: ";
    cin >> aux->mes;

    cout << "Ingrese el día: ";
    cin >> aux->dia;

    aux->izq = aux->der = nullptr;

    if (raiz == nullptr) {
        raiz = aux;  
    } else {
        aux2 = raiz;
        posicionar();
    }

    if (subraiz == nullptr) {
        subraiz = aux;  
    } else {
        aux2 = subraiz;
        posicionarfe();
    }

    aux = nullptr; 
}

int main() {
    int op;

    do {
        cout << "*****************" << endl;

        cout << "MENU" << endl;
        
        cout << "1. Registrar usuario" << endl;
        cout << "2. Preorden del árbol principal" << endl;
        cout << "3. Inorden del árbol principal" << endl;
        cout << "4. Postorden del árbol principal" << endl;
        cout << "5. Preorden del subárbol" << endl;
        cout << "6. Inorden del subárbol" << endl;
        cout << "7. Postorden del subárbol" << endl;
        cout << "8. Eiminar codigo"<<endl;

        cout << "*****************" << endl;
      
        cin >> op;

        switch (op) {
            case 1:
                registrar();
                break;

            case 2:

            cout << "LISTADO DE REGISTRO.."<<endl<<endl;
                preorden(raiz);
                break;

            case 3:
             cout << "LISTADO DE REGISTRO.."<<endl<<endl;
                inorden(raiz);
                break;

            case 4:
             cout << "LISTADO DE REGISTRO.."<<endl<<endl;
                postorden(raiz);
                break;

            case 5:
              cout << "LISTADO DE REGISTRO.."<<endl<<endl;
                preorden(subraiz); 
                break;

            case 6:
             cout << "LISTADO DE REGISTRO.."<<endl<<endl;
                inorden(subraiz);  
                break;

            case 7:
             cout << "LISTADO DE REGISTRO.."<<endl<<endl;
                postorden(subraiz);  
                break;

            case 8:
                
                break;
            
            default:
                cout << "Opción inválida. Elige un número entre 1 y 8." << endl;
        }

    } while (op != 8);

    return 0;
}
