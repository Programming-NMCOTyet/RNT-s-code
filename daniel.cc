#include <iostream>
#include <malloc.h> 
using namespace std;

struct nodo {
    int codigo; 
    char nombre[50];
    int fechaven; 
    nodo* izq; 
    nodo* der; 
};

nodo* raiz = NULL ,*aux, *aux2,*subraiz = NULL;


//posicionamientos
int posicionar(){

    if(aux->codigo < aux2->codigo){

        if(aux2->izq != NULL){

        aux2 = aux2->izq;

        }else{    
            aux2->izq  = aux;
        } 
    }
    else if(aux->codigo > aux2->codigo){
        
        if(aux2->der != NULL){

        aux2 = aux2->der;

        posicionar();

        }else{
            aux2->der  = aux;
        }
    }
    return 0;
}

int posicionarfe(){

    if(aux->fechaven < aux2->fechaven){

        if(aux2->izq != NULL){

        aux2 = aux2->izq;

        posicionarfe();

        }else{
            aux2->izq  = aux;
        } 
    }
    else if(aux->fechaven > aux2->fechaven){
        
        if(aux2->der != NULL){

        aux2 = aux2->der;

        posicionarfe();

        }else{
            aux2->der  = aux;
        }
    }
    return 0;
}


//registro
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

    int fecha = year * 10000 + mes * 100+ dia; 
    return fecha;
}

int registrar(){

    aux = (struct nodo* ) malloc (sizeof (struct nodo));

    cout << "--REGISTRO DE USUARIO--"<<endl<<endl;

    cout << "registre su codigo"<<endl;
    cin >>aux->codigo;

    cout << "registre su nombre"<<endl;
    cin >>aux->nombre;

    aux->fechaven = obtenerFecha();

    aux->izq = aux->der = NULL;

    if(raiz == NULL){
        raiz = aux;
        aux = NULL;
        free(aux);
    }else{
        aux2 = raiz;
        posicionar();

    }
 
    if(subraiz == NULL){
        subraiz = aux;
        aux = NULL;
        free(aux);
    }else{
        aux2 = subraiz;
        posicionarfe();
    }
    return 0;
}


//preorden,inorden y post orden para el codigo
int preorden(nodo *recursive){

    cout << " Su codigo es "<< recursive->codigo << " Su nombre de usuario es "<< recursive->nombre << " Su fecha de vencimiento es "<< recursive->fechaven <<endl<<endl;
    
    if(recursive->izq != NULL)
    preorden(recursive->izq);

    if(recursive->der != NULL)
    preorden(recursive->der);

    return 0;
}

int inorden(nodo *recursive){

    if(recursive->izq != NULL)
    inorden(recursive->izq);

    cout << " Su codigo es "<< recursive->codigo << " Su nombre de usuario es "<< recursive->nombre << " Su fecha de vencimiento es "<< recursive->fechaven <<endl<<endl;

    if(recursive->der != NULL)
    inorden(recursive->der);
    
    return 0;
}

int postorden(nodo *recursive){
    
    if(recursive->izq != NULL)
    postorden(recursive->izq);

    if(recursive->der != NULL)
    postorden(recursive->der);

    cout << " Su codigo es "<< recursive->codigo << " Su nombre de usuario es "<< recursive->nombre << " Su fecha de vencimiento es "<< recursive->fechaven <<endl<<endl;
    
    return 0;
}

//recorridos para el codigo
int recorrer(){
 
    aux = raiz;

    if(aux != NULL){
        preorden(aux);
    }
    return 0;
}

int recorrer2(){

    aux = raiz;

    if(aux != NULL){
        inorden(aux);
    }
    return 0;
}

int recorrer3(){

    aux = raiz;

    if(aux != NULL){
        postorden(aux);
    }
    return 0;
}


//preorden,inorden y post orden para las fechas 
int preordenfe(nodo *recursive){

    cout<< " Su fecha de vencimiento es "<< recursive->fechaven << " Su nombre de usuario es "<< recursive->nombre<< " Su codigo es "<< recursive->codigo <<endl<<endl;
    
    if(recursive->izq != NULL)
    preordenfe(recursive->izq);

    if(recursive->der != NULL)
    preordenfe(recursive->der);

    return 0;
}

int inordenfe(nodo *recursive){

    if(recursive->izq != NULL)
    inordenfe(recursive->izq);

     cout<< " Su fecha de vencimiento es "<< recursive->fechaven << " Su nombre de usuario es "<< recursive->nombre<< " Su codigo es "<< recursive->codigo <<endl<<endl;

    if(recursive->der != NULL)
    inordenfe(recursive->der);
    
    return 0;
}

int postordenfe(nodo *recursive){
    
    if(recursive->izq != NULL)
    postordenfe(recursive->izq);

    if(recursive->der != NULL)
    postordenfe(recursive->der);

     cout<< " Su fecha de vencimiento es "<< recursive->fechaven << " Su nombre de usuario es "<< recursive->nombre<< " Su codigo es "<< recursive->codigo <<endl<<endl;
    
    return 0;
}


//recorrido para las fechas 
int recorrerfe(){

    aux = raiz;

    if(aux != NULL){
        preordenfe(aux);
    }
    
    return 0;
}

int recorrerfe2(){

    aux = raiz;

    if(aux != NULL){
        inordenfe(aux);
    }
    
    return 0;
}

int recorrerfe3(){

    aux = raiz;

    if(aux != NULL){
        postordenfe(aux);
    }
    
    return 0;
}


//ubicar
int ubicar(nodo *aux3, int aguja){

    if(aux3->codigo == aguja){

        aux = aux3;
        return 0;
    }
    else{

        if(aux3->izq != NULL){
            ubicar(aux3->izq,aguja);
        }
        if(aux3->der != NULL){
            ubicar(aux3->der,aguja);
        }
    }
    return 0;
}

//ubicar padre
int ubicarpadre(nodo *padre){

    if((padre->izq != NULL)&&(padre->izq != aux)){

       ubicarpadre(padre->izq);
    }
     
    if(padre->izq == aux){

        aux2 = padre;
    }

    if((padre->der != NULL)&& (padre->der != aux)){

        ubicarpadre(padre->der);
    }

    if(padre->der == aux){

        aux2 = padre;
    }

    return 0;
}

//casos de eliminacion 
int casouno(){

    if(aux != raiz){

        ubicarpadre(raiz);
    }

    if(aux2->izq == aux){
       aux2->izq = NULL;
    }
    else if(aux2->der == aux){
        aux2->der = NULL;
    }

    free(aux);
    return 0;
}

int casodos(){

    if(aux != raiz){

       ubicarpadre(raiz);
    }

    if(aux2->izq == aux){

        if (aux->izq != NULL)

        aux2->izq = aux->izq;

        else if (aux->der != NULL)

        aux2->izq = aux->der;


    }else if (aux2->der == aux){

        if (aux->izq != NULL)
    
        aux2->der = aux->izq;
        
        else if (aux->der != NULL)

        aux2->der = aux->der;
    }
    free(aux);
    return 0;
}

int casotres(){

    if(aux != raiz){

       ubicarpadre(raiz);
    }

    if(aux2->der == aux){

        if (aux->der != NULL)

        aux2->der = aux->der;

        else if (aux->izq != NULL)

        aux2->der = aux->izq;


    }else if (aux2->izq == aux){

        if (aux->der != NULL)
    
        aux2->izq = aux->der;
        
        else if (aux->izq != NULL)

        aux2->izq = aux->izq;
    }
    free(aux);
    return 0;
}
  
//eliminar
int eliminar(){
 
    int buscar;

    cout << "Ingrese el valor del codigo que desea eliminar..."<<endl;
    cin>>buscar;

    ubicar(raiz,buscar);

    if((aux->der == NULL)&&( aux->izq == NULL)){

    cout <<" eliminando... "<<endl;
    casouno();        
    }
    else if(((aux->der == NULL)&&( aux->izq != NULL)) || ((aux->der != NULL)&&( aux->izq == NULL))){

    cout <<" eliminando... "<<endl;
    casodos();
    }
    
    else if(((aux->izq == NULL)&&( aux->der != NULL)) || ((aux->izq != NULL)&&( aux->der == NULL))){

    cout <<" eliminando... "<<endl;
    casotres();
    }

    return 0;
}

//menu
int main() {
    int op;
    do {

        cout << "********************************************************" << endl;
        cout << " MENU DE REGISTRO E INFORMACION" << endl<<endl;
        
        cout << "1. Registrar usuario" << endl;

        cout << "2. Preorden del árbol codigo" << endl;
        cout << "3. Inorden del árbol codigo" << endl;
        cout << "4. Postorden del árbol codigo" << endl;

        cout << "5. Preorden del árbol fecha" << endl;
        cout << "6. Inorden del árbol fecha" << endl;
        cout << "7. Postorden del árbol fecha" << endl;

        cout << "8. Eliminar usuario" <<endl<<endl;

        cout << "Seleccione una opción: "<<endl<<endl;
        cout << "********************************************************" << endl;
        cin >> op;

        switch (op) {

        case 1:
            registrar(); 
        break;
        
        case 2:
            recorrer();
        break;

        case 3:
           recorrer2();
        break;

        case 4:
            recorrer3();
        break;

        case 5:
            recorrerfe();
        break;

        case 6:
           recorrerfe2();
        break;

        case 7:
            recorrerfe3();
        break;

        case 8:
            eliminar();
        break;

        }
    } while (op != 9);

    return 0; 
}
