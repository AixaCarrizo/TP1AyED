Algoritmos y Estructuras de Datos
Enunciado Primer Parcial A˜no 2018
Realizar un programa que eval´ue una expresi´on aritm´etica con notaci´on
tradicional. La expresi´on contiene solamente n´umeros enteros, las cuatro operaciones
aritm´eticas b´asicas y par´entesis. La expresi´on est´a compuesta por
una serie de “tokens”, donde cada token es un n´umero, un operador aritm´etico
o los par´entesis.
La evaluaci´on de la expresi´on es la tradicional de izquiera a derecha, pero
todas las operaciones tienen igual prioridad. Ejemplo:
5 − 2 ∗ 2 = 3 ∗ 2 = 6
Por lo que para definir prioridades en las operaciones debe utilizar par´entesis.
El ejemplo anterior, bajo el orden de prioridad aritm´etico tradicional,
debe escribirse como:
5 − (2 ∗ 2) = 5 − 4 = 1
Para resolver la expresi´on debe leer la lista de tokens y utilizar la estructura
de Pila, donde se almacenen tokens que contienen el primer operando
y el simbolo de la operaci´on. Ante la lectura del segundo operando, debe
desapilar el operador y el primer operando, evaluar, y apilar el resultado. La
existencia de varias operaciones implica la utilizaci´on como primer operando
del resultado parcial obtenido, como es mostrado en el primer ejemplo.
Si el token tiene un par´entesis que abre, esto genera una nueva expresi´on,
y deber´a apilar en la pila principal un enlace a una nueva pila que contenga
la nueva expresi´on, la cual ser´a evaluada de igual forma, hasta que llegue un
par´entesis que cierra, lo cual implica que la expresi´on ha terminado, y debe
devolver el resultado de la subexpresi´on a la expresi´on llamadora original.
1
Un n´umero negativo se representa entre parentesis con el signo menos
antes de la cifra, por ejemplo:
5 − (2 ∗ (−2)) = 5 − (−4) = 9
En este caso, al abrir el par´entesis del n´umero negativo se genera la nueva
pila, pero se apila en forma inicial solamente el signo menos. Al encontrar
el parentesis que cierra al n´umero −2 se devuelve el resultado del n´umero
negativo. Tenga en cuenta que este tipo de excepci´on es v´alido solo para el
signo menos, no para los otros signos de las operaciones.
El resultado de la expresi´on es el tope de la pila luego de haberse leido
todos los tokens de la lista.
Los clases que deber´a utilizar para resolver el problema son:
Token: que contiene un n´umero, o un operador o un enlace
Lista de Tokens: que contiene la expresi´on a evaluar
Pila: que contiene tokens y es utilizada como auxiliar para el procesamiento
Deber´a codificar la soluci´on usando Clases de C++, con m´etodos que
respeten el comportamiento expuesto.
La expresi´on puede ser dada desde teclado o bien leida desde archivo,
independiente de la clase calculadora e invocada desde el m´etodo main del
programa.
Es un bonus definir una funci´on verificar que devuelva falso si la expresion
no es correcta.
Podr´a utilizar el c´odigo de las clases lista y pila dados en clases pr´acticas.
El tipo de dato contenido en las clases Lista y Pila debe ser de la clase Token.
Esta deber´a tener un m´etodo que determine que tipo de valor contiene el
token.
