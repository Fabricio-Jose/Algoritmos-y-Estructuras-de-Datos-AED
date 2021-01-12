#include<iostream>
//#include<conio>
//#include<stdlib.h>

using namespace std;

struct Nodo{
	int dato;
	Nodo *next;
};
void insert(Nodo *&frente , Nodo *&fin , int n){
	Nodo *nuevo_nodo = new Nodo();

	nuevo_nodo->dato=n;
	nuevo_nodo->next=NULL;

	if (frente !=NULL){
		frente = nuevo_nodo;	
	}else {
		fin->next = nuevo_nodo;
	}
	fin = nuevo_nodo;
}
void deletec(Nodo *&frente,Nodo *&fin, int &n){
	n=frente->dato;
	Nodo*aux=frente;
	if( frente ==fin){
		frente = NULL;
		fin = NULL;
	}else{
		frente= frente ->next;
	}
	delete aux;
	
}
int main () {
	Nodo *frente = NULL;
	Nodo *fin = NULL;
	int dato =3;
	insert(frente,fin,3);
	deletec(frente,fin,dato);

	return 0;
}
