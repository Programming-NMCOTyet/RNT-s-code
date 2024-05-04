#include <iostream>
#include <malloc.h> 
using namespace std;


struct Nodo {
    int codigo; 
    char nombreEmpr[50];
    int fechaven; 
    Nodo* izq; 
    Nodo* der; 
};


Nodo* raiz = nullptr, *aux;
Nodo* subraiz = nullptr;


int obtenerFecha() {

    int year, mes, dia;

    cout << "Ingrese el año (4 dígitos): ";
    cin >> year;

    cout << "Ingrese el mes (1-12): ";
    cin >> mes;

    cout << "Ingrese el día (1-31): ";
    cin >> dia;

    
    if (mes < 1 || mes > 12 || dia < 1 || dia > 31) {
        cout << "Fecha no válida. Inténtelo nuevamente." << endl;
        return obtenerFecha(); 
    }

    
    int fecha = year * 10000 + mes * 100 + dia; 
    return fecha;
}


void posicionar() {

    Nodo* actual = raiz;

    while (true) { 

        if (aux->codigo < actual->codigo) { 
            if (actual->izq == nullptr) {
                actual->izq = aux;
               break;
            }
            actual = actual->izq; 
        } else {
            if (actual->der == nullptr) {
                actual->der = aux;
              break;
            }
            actual = actual->der; 
        }
    }
}


void posicionarfe() {

    Nodo* actual = subraiz; 
    while (actual != nullptr) { 
        if (aux->fechaven < actual->fechaven) {
            if (actual->izq == nullptr) {
                actual->izq = aux;
                break;
            }
            actual = actual->izq; 
        } else {
            if (actual->der == nullptr) {
                actual->der = aux;
               break;
            }
            actual = actual->der; 
        }
    }
}


void registrar() {

    aux = (Nodo*)malloc(sizeof(Nodo)); 

    cout << "Ingrese el nombre de la empresa: ";
    cin >> aux->nombreEmpr;

    cout << "Ingrese su código (RNT): ";
    cin >> aux->codigo; 

    aux->fechaven = obtenerFecha();

    aux->izq = aux->der = nullptr;

   
    if (raiz == nullptr) {
        raiz = aux; 
    } else {
        posicionar(); 
    }

    
    if (subraiz == nullptr) {
        subraiz = aux;
    } else {
        posicionarfe(); 
    }
}


void preorden(Nodo* aux3) {

    if (aux3 != nullptr) {

        cout << "Código: " << aux3->codigo << ", Nombre de empresa: " << aux3->nombreEmpr << ", Fecha de vencimiento: " << aux3->fechaven <<endl<< endl;
        preorden(aux3->izq); 
        preorden(aux3->der); 
    }
}


void inorden(Nodo* aux3) {

    if (aux3 != nullptr) {

        inorden(aux3->izq);
        cout << "Código: " << aux3->codigo << ", Nombre de empresa: " << aux3->nombreEmpr << ", Fecha de vencimiento: " << aux3->fechaven << endl<<endl;    
        inorden(aux3->der); 
    }
}


void postorden (Nodo* aux3) {

    if (aux3 != nullptr) {

        postorden(aux3->izq); 
        postorden(aux3->der); 
        cout << "Código: " << aux3->codigo << ", Nombre de empresa: " << aux3->nombreEmpr << ", Fecha de vencimiento: " << aux3->fechaven << endl<< endl;
      
    }
}

int main() {
    int op;
    do {

        cout << "********************************************************" << endl;
        cout << " MENU DE REGISTRO E INFORMACION" << endl<<endl;
        
        cout << "1. Registrar usuario" << endl;

        cout << "2. Preorden del árbol principal" << endl;
        cout << "3. In orden del árbol principal" << endl;
        cout << "4. Post orden del árbol principal" << endl;

        cout << "5. Preorden del subárbol" << endl;
        cout << "6. In orden del subárbol" << endl;
        cout << "7. Post orden del subárbol" << endl;

        cout << "8. Salir" << endl;

        cout << "Seleccione una opción: "<<endl<<endl;
        cout << "********************************************************" << endl;
        cin >> op;

        switch (op) {

            case 1:
                registrar(); 
                break;

            case 2:
                cout << "Listado de registro Preorden del árbol principal:" <<endl<< endl;
                preorden(raiz); 
            break;
            case 3:
                cout << "Listado de registro Inorden del árbol principal:" <<endl<< endl;
                inorden(raiz); 
            break;
            case 4:
                cout << "Listado de registro Post orden del árbol principal:" <<endl<<endl;
                postorden(raiz); 
            break;
            case 5:
                cout << "Listado de registro Preorden del árbol segundario:" <<endl<< endl;
                preorden(subraiz); 
            break;
            case 6:
                cout << "Listado de registro Preorden del árbol segundario:" << endl<<endl;
                inorden(subraiz); 
            break;
            case 7:
                cout << "Listado de registro Preorden del árbol segundario:" << endl<< endl;
                postorden(subraiz); 
            break;
            case 8:
                cout << "Saliendo..." << endl;
            break;
            default:
                cout << "Opción no válida vro." << endl;
            break;
        }
    } while (op != 8);

    return 0; 
}

