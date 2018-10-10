#include <iostream>
#include <cstdlib>
#include<stdio.h>

using namespace std;

struct nodo{
     int nro;
     struct nodo *izq, *der;
};

typedef struct nodo *ABoBi;


ABoBi crearNodo(int);
void insertar(ABoBi &, int);
void preOrden(ABoBi);
void enOrden(ABoBi);
void postOrden(ABoBi);
void verArbol(ABoBi, int );




int main()
{
	system("COLOR 3F");
    ABoBi arbol = NULL;   // ARBOL CREADO

    int n;  // EL NUMERO DE NODOS QUE DESEA AGREGAR AL ARBOL
    int x; // ELEMENTO A INSERTAR EN CADA NODO

    cout << "\n\t\t  ..[ ARBOL BINARIO DE BUSQUEDA ]..  \n\n";

    cout << " INGRESE EL NUMERO DE NODOS A INGRESAR EN EL ARBOL:  ";
    cin >> n;
    cout << endl;

    for(int i=0; i<n; i++)
    {
        cout << " NUMERO DEL NODO " << i+1 << ": ";
        cin >> x;
        insertar( arbol, x);
    }

    cout << "\n Mostrando ABB \n\n";
    verArbol( arbol, 0);

    cout << "\n Recorridos del ABB";

    cout << "\n\n PRE-ORDEN  :  ";   preOrden(arbol);
	cout << "\n\n IN-ORDEN   :  ";   enOrden(arbol);
    cout << "\n\n POST-ORDEN :  ";   postOrden(arbol);
    

    cout << endl << endl;

    system("pause");
    return 0;
}

ABoBi crearNodo(int x)
{
     ABoBi nuevoNodo = new(struct nodo);
     nuevoNodo->nro = x;
     nuevoNodo->izq = NULL;
     nuevoNodo->der = NULL;

     return nuevoNodo;
}
void insertar(ABoBi &arbol, int x)
{
     if(arbol==NULL)
     {
           arbol = crearNodo(x);
     }
     else if(x < arbol->nro)
          insertar(arbol->izq, x);
     else if(x > arbol->nro)
          insertar(arbol->der, x);
}

void preOrden(ABoBi arbol)
{
     if(arbol!=NULL)
     {
          cout << arbol->nro <<" ";
          preOrden(arbol->izq);
          preOrden(arbol->der);
     }
}

void enOrden(ABoBi arbol)
{
     if(arbol!=NULL)
     {
          enOrden(arbol->izq);
          cout << arbol->nro << " ";
          enOrden(arbol->der);
     }
}

void postOrden(ABoBi arbol)
{
     if(arbol!=NULL)
     {
          postOrden(arbol->izq);
          postOrden(arbol->der);
          cout << arbol->nro << " ";
     }
}

void verArbol(ABoBi arbol, int n)
{
     if(arbol==NULL)
          return;
     verArbol(arbol->der
	 , n+1);

     for(int i=0; i<n; i++)
         cout<<"   ";

     cout<< arbol->nro <<endl;

     verArbol(arbol->izq, n+1);
}
