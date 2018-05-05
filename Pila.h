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
          if (expresion.at(i)=='(') p->apilar('(');
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