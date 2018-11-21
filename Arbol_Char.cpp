#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

 
struct Nodo{
	char dato;
	Nodo *der; 
	Nodo *izq;
}; 
void menu();
Nodo *crearNodo(char); 
void insertarNodo(Nodo *&,char);
void mostrarArbol(Nodo *,char);
Nodo *arbol = NULL;
int main(){
	menu();
	return 0;
} 
void menu(){
	char dato;
	int opcion, contador=0;
	do{
		cout<<"\t.:MENU:."<<endl;
		cout<<"1. Insertar un nuevo nodo"<<endl;
		cout<<"2. Mostrar arbol completo:"<<endl;
		cout<<"3. Salir"<<endl;
		cout<<"Opcion: ";
		cin>>opcion; 
		
		switch(opcion){
			case 1: cout<<"\nDigite un numero: ";
			cin>>dato;
			insertarNodo(arbol,dato);
			cout<<"\n";
			system("pause");
			break;
			case 2: cout<<"\nMostrando el arbol completo:\n\n";
			        mostrarArbol(arbol,contador);
			        cout<<"\n";
			        system("pause");
			        break;
		}
		system("cls");
	}while(opcion != 2);
}
Nodo *crearNodo(char n){
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo->dato =n; 
	nuevo_nodo->der = NULL; 
	nuevo_nodo->izq = NULL;
	return nuevo_nodo;
	}
	
	//Funcion para insertar elemento en el arbol
	void insertarNodo(Nodo *&arbol, char n){
		if(arbol == NULL){
			Nodo *nuevo_nodo = crearNodo(n);
			arbol = nuevo_nodo;
		}
	else{
		int ValorRaiz = arbol->dato;
		if(n < ValorRaiz){
			insertarNodo(arbol->izq,n);
		}
		else{
		insertarNodo(arbol->der,n);
		}
	}
} 
//fincion para mostrar arbol 
void mostrarArbol(Nodo *arbol,char cont){
	if(arbol == NULL){
		return;
	}
	else{
		mostrarArbol(arbol->der,cont+1);
		for(char i=0;i<cont;i++){
			cout<<"   ";
		}
		cout<<arbol->dato<<endl;
		mostrarArbol(arbol->izq,cont+1);
	}
}



