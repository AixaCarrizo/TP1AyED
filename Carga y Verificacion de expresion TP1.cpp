//#include <cstdlib>
#include <cstddef>
#include <iostream>
#include <sstream>

//comentar que como es una lista de string, tengo que redefinir el nodo
//resaltar que solo se cambia la parte int de la lista anterior por string
using namespace std;

typedef long int tipolista;

class Token{
    protected: 
        tipolista dato;
        Token *next;
    public:
        Token() {next=NULL;};
        Token(tipolista a) {dato=a; next=NULL;};
        void set_dato(tipolista a) {dato=a; };
        void set_next(Token *n) {next=n; };
        tipolista get_dato() {return dato; };
        Token *get_next() {return next; };
        bool es_vacio() {return next==NULL;}
};

class Lista{
    private: Token *czo;
    public:
            Lista() {czo=new Token();};
            Lista(Token *n) {czo=n;};
            //~Lista(void);
            void add(int d);
            bool esvacia(void);
            tipolista cabeza(void);
            Lista *resto(void);
            string toPrint(string p);   
            int suma(int i);
            void impre(void);
            int suma2(void);
            int size();
            void borrar(void); //borra la cabeza
            void borrar_last();//borra el ultimo
            void concat(Lista *l1);
            Lista *copy(void);
            void tomar(int n);
};
tipolista Lista::cabeza(void){ 
  if(esvacia()){
                cout<<" Error, Cabeza de lista vacia";
                return ' '; 
  }
  return czo->get_dato();
}
int Lista::size(){ 
     if (this->esvacia()) return 0;
     return 1+this->resto()->size();
}
void Lista::impre(void){ Token *aux;
  aux=czo;
    while(aux->get_next()!=NULL){
         cout<<aux->get_dato()<<endl;
         aux=aux->get_next();
    }
}
void Lista::add(int d){  
     Token *nuevo=new Token(d);
     nuevo->set_next(czo);
     czo=nuevo;
}
bool Lista::esvacia(void){   
    return czo->es_vacio();
}
Lista *Lista::resto(void){ 
      Lista *l=new Lista(czo->get_next());
      return (l);
}
string Lista::toPrint(string p){ 
     if (this->esvacia()) {
        return p;
     } else {
       std::ostringstream stm;
       stm << this->cabeza()<<" - "<< this->resto()->toPrint(p) << endl;
      //cout<<endl<<" stm.str()= "<<stm.str()<<endl;
       return stm.str();
     }
}
int Lista::suma(int i){    //cout<<" i al entrar= "<<i<<endl;
     if (esvacia()) {return i;
     } else {
        
        //cout<<"this->cabeza()= "<<this->cabeza()<<endl;   
        return resto()->suma(i+cabeza());
     }
}
int Lista::suma2(void){
     if (esvacia()) return 0;
     
     else return cabeza()+resto()->suma2();
}
void Lista::borrar(void){ //borra el nodo cabeza
  if(esvacia()){
  } else {
         Token *tmp=czo;
         czo=czo->get_next();
         delete tmp;
  }
}
void Lista::borrar_last(){ // borra el ultimo nodo
   if(!this->esvacia()){
      if((czo->get_next())->get_next()==NULL){
         delete czo->get_next();
         czo->set_next(NULL);
      }
      else this->resto()->borrar_last(); 
   }  
}
void Lista::concat(Lista *l1){// le transfiere los datos de l1 a this
   if (!(l1->esvacia())){
      this->concat(l1->resto());
      this->add(l1->cabeza());
   }
}
Lista *Lista::copy(void){ 
      Lista *aux=new Lista();
      aux->concat(this);
      return aux;
}
void Lista::tomar(int n){ //deja "vivos" los n primeros nodos y borra el resto
/*   if(!(this->esvacia())) {
      if (n>0) this->resto()->tomar(n-1);
      else     czo->set_next(NULL);
   }
*/
   if(this->size()>n){
      this->borrar_last();
      this->tomar(n);
   }
}

class Pila:public Lista{
	  private:
	  		 string expresion;
      public:
             Pila(){Lista();};
             void apilar(tipolista x){add(x);};
             tipolista tope(void){return cabeza();};
             void desapilar(void){borrar();};
             bool pilavacia(){return esvacia();};
             bool expresionEsCorrecta();
             void cargarExpresion();
             string returnExpresion();
};                  
void Pila::cargarExpresion(){
	Pila *p=new Pila();
	 string cadena;
     cout<<endl<<"Ingrese cadena= "; cin>>cadena;
	 expresion=cadena;           
    }
bool Pila::expresionEsCorrecta(){//se fija que todos los pareentesis esten cerrados
	int error=0;
	Pila *p=new Pila();

     for(int i=0;(i<expresion.length())&&(!error);i++){
          if (expresion.at(i)=='{') p->apilar('{');       
          if (expresion.at(i)=='[') p->apilar('[');
          if (expresion.at(i)=='(') p->apilar('(');
          
          if (expresion.at(i)=='}'){
                                 if (p->pilavacia()) error=1;
                                 else
                                     if(p->tope()!='{') error=1;
                                     else p->desapilar();                     
          }                               
          if (expresion.at(i)==']'){
                                 if (p->pilavacia()) error=1;
                                 else
                                     if(p->tope()!='[') error=1;
                                     else p->desapilar();                     
          }                               
          if (expresion.at(i)==')'){
                                 if (p->pilavacia()) error=1;
                                 else
                                     if(p->tope()!='(') error=1;
                                     else p->desapilar();                     
          }         
} 
    if((!error)&&p->pilavacia())return true;
    else return false;    
}

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
