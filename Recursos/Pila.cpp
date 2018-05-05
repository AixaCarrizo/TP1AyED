#include <iostream>
#include "Listas.cpp"
using namespace std;

typedef int tipoDeDato;

class Pila{
	private:
		Lista L;
	public:
		void push(tipoDeDato);
		bool pop();
		tipoDeDato tope();
		bool esVacia();
		void vaciarPila();
};
void Pila::push(tipoDeDato d){
	L.add(d);
}
bool Pila::pop(){
	if(!esVacia()){
		L.borrarCabecera();
		return true;
	}
	else
		return false;
}
tipoDeDato Pila::tope(){
	if(!esVacia())
		return L.cabecera();
	else{
		cout << "Error, la pila esta vacia." << endl;
		return NULL;
	}
}
bool Pila::esVacia(){
	return L.esVacia();
}
void Pila::vaciarPila(){
	while(!esVacia())
		pop();
}

