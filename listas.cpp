#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

class Nodo{
    private:
            int dato;
            Nodo *next;
    public:
           Nodo() {next=NULL;}; //constructor del nodo que se crea cuando se crea la lista, hace que next apunte a null
           Nodo(int a) {dato=a; next=NULL;}; //este constructor se utiliza al añadir elementos, recibe el elemento a añadir y al nodo que crea le setea dato en dicho elemento y next en null
           void set_dato(int a) {dato=a; };
           void set_next(Nodo *n) {next=n; }; //recibe la direccion a la que apunta czo y la guarda en el next de nuevo
           int get_dato() {return dato; }; //devuelve el parametro dato del nodo desde que se llamo a este metodo
           Nodo *get_next() {return next; };
           bool es_vacio() {return next==NULL;} //si el next del czo recibido es null devuelve 1 sino devuelve cero
};

class Lista{
    private:
            Nodo *czo;
    public:
            Lista() {czo=new Nodo();}; //constructor para la creacion de la lista por primera vez, crea un nodo llamado czo y le reserva en memoria el tamaño de un nodo
            Lista(Nodo *n) {czo=n;};
            //~Lista(void);
            void add(int d); //agrega un elemento a la lista
            bool esvacia(void);
            int cabeza(void);
            Lista *resto(void);
            void print();   
            int suma(int i);
};

void Lista::add(int d)
{  
     Nodo *nuevo=new Nodo(d); //crea un puntero a nodo nuevo al cual le reserva el espacio en memoria de un nodo y manda al constructor de dicho nodo el elemento a agregar
     nuevo->set_next(czo); //setea el next de nuevo en la direccion a la que apunta comienzo
     czo=nuevo; //hace que czo apunte al nodo nuevo guardando en czo la direccion del nodo nuevo
}

bool Lista::esvacia(void)
{   
    return czo->es_vacio(); //envia la direccion a la que apunta czo al metodo es_vacio de la clase nodo, y retorna el uno o cero que de dicho metodo
}

int Lista::cabeza(void)
{ 
  if(esvacia()){ //consulta si la lista desde la que se llama cabeza es vacia, si lo es imprime el error y retorna menos uno
                cout<<" Error, Cabeza de lista vacia";
                return -1; 
  }
  return czo->get_dato(); //si no se cumplio el if anterior, llama al metodo get_dato de la clase nodo a partir del nodo czo de la lista desde la que se llamo a cabeza
}

Lista *Lista::resto(void)
{ 
      Lista *l=new Lista(czo->get_next());
      return (l);
}

void Lista::print() //va imprimiendo los elementos de la lista hasta que se acaba
{ 
     if (this->esvacia()) //como this es un puntero a si mismo, apunta a l que es la lista desde la que se llamo a la funcion, y entonces consulta si l es vacia
     {
         cout << "La lista no contiene elementos..!";
     }
     else
     {
         Nodo *nuevo = new Nodo();
         nuevo = czo->get_next();
         
         while((nuevo->next) != NULL)
         {
             cout << endl << nuevo->get_dato();
             nuevo = nuevo->get_next();
         }
         
         delete nuevo;
     }    
}

int Lista::suma(int i)
{
     if (this->esvacia())
     {
         return i;
     } 
     else
     {   
         return this->resto()->suma(i+this->cabeza());
     }
}

int main()
{
    Lista *l=new Lista(); //crea un puntero a lista l, y le asigna en memoria el tamaño de una lista
    Lista *r=new Lista(); //crea un puntero a lista r, y le asigna en memoria el tamaño de una lista
    Lista *l2=new Lista(); //crea un puntero a lista 12, y le asigna en memoria el tamaño de una lista
    l->add(11);
    l->add(22);
    l->add(33);
    r->add(1);
    r->add(2);
    cout << "La lista es: " << l->print();
    cout<< "suma:" << l->suma(0) << endl;
   
    system("pause");
    return 0;
}
