// Autores: Julian Jimenez y Alejandro Cifuentes
#include <iostream>
#include <vector>
using namespace std;
struct nodo { // se crean las variables a utilizar, incluyendo los nodos por izquierda y derecha.
 int clave;
 int contador;//Cuenta las variables duplicadas en las listas
 struct nodo* left;
struct nodo* right;
 nodo(int clave) : clave(clave), contador(1), left(nullptr), right(nullptr) {}
};

struct BST {// se crea la estructura BSTa donde incluye cada funcion necesaria para su uso.
 nodo* raiz;
 BST() : raiz(nullptr) {}

 void insertar(int clave) {// Se inserta cada nodo, para poder crear el arbol desde la raiz-
  if (raiz == nullptr) {
   raiz = new nodo(clave);
   return;

  }

  nodo* actual = raiz;
  nodo* padre = nullptr;

  while (actual != nullptr) {
   padre = actual;
   if (clave < padre->clave) {// Si el nodo a insertar es menor que su padre se coloca hacia la izquierda
    actual = actual->left;

   }

   else if (clave > padre->clave) {// si el nodo a insertar es mayor que su padre se coloca hacia la derecha
    actual = actual->right;
   }

   else {
    padre->contador++; // en caso de que haya un valor repetido se le suma al contador.
    return;
   }
  }

  if (clave < padre->clave) {// se crea un nodo hacia la izquierda si es menor que el padre
   padre->left = new nodo(clave);
  }else{
   padre->right = new nodo(clave);// se crea un nodo hacia la derecha si es mayor que el padrre
  }
 }

 bool encontrar(int clave, vector<int>& camino) {// encuentra un valor y muestra su camino
  nodo* actual = raiz;
  while (actual != nullptr) {
   camino.push_back(actual->clave);

   if (actual->clave == clave){
    return true;

   } else if (clave < actual->clave) {
    actual = actual->left;
   }else{
    actual = actual->right;
   }

  }
  return false;
 }
 void preorden() {// organiza la lista desde raiz izquierda-derecha
  if (raiz == nullptr){}

  vector<nodo*> pila;
  pila.push_back(raiz);

  while (!pila.empty()) {
   nodo* actual = pila.back();
   pila.pop_back();

   cout << actual->clave << "  ";

   if (actual->right) {
    pila.push_back(actual->right);

   }if (actual->left) {
    pila.push_back(actual->left);
   }
  }
 }
 void inorden() {// organiza la lista de manera creciente izquierda raiz derecha
  vector<nodo*> pila;
  nodo* actual = raiz;
  while (actual != nullptr || !pila.empty()){
   while (actual != nullptr) {
    pila.push_back(actual);
    actual = actual->left;
   }
   actual = pila.back();
   pila.pop_back();
   cout << actual->clave <<" " ;



   actual = actual->right;
  }
 }
 void postorden() {// organiza la lista desde izquierda-derecha-raiz
  if (raiz == nullptr){}
  vector<nodo*> pila,pila2;
  pila.push_back(raiz);

  while (!pila.empty()) {
   nodo* actual = pila.back();
   pila.pop_back();

   pila2.push_back(actual);

   if (actual->left) {
    pila.push_back(actual->left);
   }if (actual->right) {
    pila.push_back(actual->right);
   }
  }
   while (!pila2.empty()) {
    nodo* actual = pila2.back();
    pila2.pop_back();
    cout << actual->clave << " ";
   }
  }

int altura(){//cuenta los niveles del arbol y los resta por 1 para conocer su altura basado en aristas
   if (raiz == nullptr) {
    return 0;
 }
   vector<nodo*> cola;
   cola.push_back(raiz);
   int pos=0;
   int niveles=0;

   while (pos < cola.size()) {
    int nivel_cont = cola.size()-pos;
    for (int i = 0; i < nivel_cont; i++) {
     nodo* actual = cola[pos++];
     if (actual->left){
      cola.push_back(actual->left);
     }if (actual->right) {
      cola.push_back(actual->right);
     }
    }
    niveles++;
   }
int altura_arista= niveles-1;
  cout << altura_arista << " ";
    return altura_arista;
   }
    int gradoMax() {// cuenta la capacidad maxima de hijos que tenga el arbol y sus subarboles
  if (raiz == nullptr) {
   return 0;
  }
  vector<nodo*> cola;
  cola.push_back(raiz);
  int pos=0;
  int gradoMaxi= 0;
  while (pos < cola.size()) {
   nodo* actual = cola[pos++];
   int grad=0;
   if (actual->left) {
    cola.push_back(actual->left);
    grad++;
   }if (actual->right) {
    cola.push_back(actual->right);
    grad++;
   }if (grad>gradoMaxi) {
    gradoMaxi = grad;
   }
  }
  cout << gradoMaxi << "";
  return gradoMaxi;
 }
void contador(nodo* actual=nullptr) {// sirve para demostrar los valores duplicados y mostrarlos en pantalla
  if (!actual) {
   actual=raiz;
  }if (!actual) {
   return;
  }

  if (actual->contador>1) {
   cout<<endl <<"este numero esta duplicado "<<actual->clave<< ", cantidad de veces duplicado: ("<<actual->contador<<")";

  }else {
   cout << endl<<"no hay duplicados";
  }
 }
   };
 int main () {
  // aqui se ejecuta las funciones del arbol para su correcta ejecucion
  BST arbol;
  BST arbol2;
  vector<int> lista = {3,15,3,8,3,17,25};// primera lista, de manera aleatoria
  cout<<"lista aleatoria: "<<endl;
  for (int x : lista) {// se imprime la lista en este ciclo
   cout << x << " ";
   arbol.insertar(x);//se aplica la funcion de insertar

  }
  arbol.contador();//cuenta los duplicados
  cout << endl;
  cout<<endl;
  //se imprimen los tres recorridos del arbol
  cout<< "arbol preorden"<< endl;
  arbol.preorden();
  cout << endl;
  cout<<endl;
  cout<< "arbol inorden"<< endl;
  arbol.inorden();
  cout << endl;
  cout << endl;
  cout<< "arbol postorden"<< endl;
  arbol.postorden();
  cout << endl;
  cout << endl;
  cout<< "arbol altura:"<< endl;
  arbol.altura();
  cout << endl;
  cout << endl;
  cout<< "arbol grado maximo:"<< endl;
  arbol.gradoMax();
  cout << endl;

  vector<int> camino;

  int numero= 50;
  if (arbol.encontrar(numero, camino)) {// se le asigna un valor a buscar, por medio de condicionales decide si estan o no, ademas muestra su camino
   cout << "numero encontrado con exito: "<<numero << " camino: ";
   for (int x : camino) {
    cout << x << " ";


   }
   cout << endl;
  }
  else {
   cout<<" numero no fue encontrado con exito: "<< numero << " camino: ";
   for (int x : camino) {
    cout << x << " ";

   }
  }
  cout << endl;
  cout <<"Esta lista al estar aleatoria (sin orden) tiene un coste promedio de O(log(n)"<< endl;// Al estar esta lista desorganizada tiene un coste mas barato
  cout << endl;


  vector<int> lista2 ={1,2,3,4,5,6,7,8,9,10};//segunda lista, esta de manera organizada

  cout<<"Lista organizada: ";
  for (int x : lista2) {

   cout << x << " ";
   arbol2.insertar(x);

  }

  // se realiza lo mismo que el arbol anterior, su contador y respectivos recorridos, ademas de encontrar un valor en este
  arbol2.contador();
  cout << endl;
  cout<<endl;
  cout<< "arbol preorden:"<< endl;
  arbol2.preorden();
  cout << endl;
  cout<<endl;
  cout<< "arbol inorden:"<< endl;
  arbol2.inorden();
  cout << endl;
  cout<<endl;
  cout<< "arbol postorden:"<< endl;
  arbol2.postorden();
  cout << endl;
  cout<<endl;
  cout<< "arbol altura:"<< endl;
  arbol2.altura();
  cout << endl;
  cout<<endl;
  cout<< "arbol grado maximo:"<< endl;
  arbol2.gradoMax();
  cout << endl;

  vector<int> camino1;

  int numero1= 11;
  if (arbol2.encontrar(numero1, camino1)) {
   cout << "numero encontrado con exito: "<<numero1 << " camino: ";
   for (int x : camino1) {
    cout << x << " ";


   }
   cout << endl;
  }
  else{
   cout<<"numero no fue encontrado con exito: "<< numero1 << " camino: ";
   for (int x : camino1) {
    cout << x << " ";

   }

   cout << endl;
   cout <<"Esta lista al estar organizada (con orden) tiene un coste mas alto, con un costo promedio de O(n), que es alto"<< endl;// al estar organizada, tiene una mayor altura, por lo tanto un coste mayor
   cout << endl;
  }
 }

