//#include <cstdlib>
#include <cstddef>
#include <iostream>
#include <sstream>
#include "token.h"
#include "Lista.h"
#include "Pila.h"

//comentar que como es una lista de string, tengo que redefinir el nodo
//resaltar que solo se cambia la parte int de la lista anterior por string
using namespace std;


int main(){
	Pila *p=new Pila();
     p->cargarExpresion();
     if (p->expresionEsCorrecta()){
     	cout<<"La expresion es correcta"<<endl;
     } else {
    	 cout<<"La expresion es incorrecta"<<endl;
		 }
    
     system("PAUSE");
     return 0;
}
