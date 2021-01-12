#include<iostream>
#include<string>
#include<stdlib.h>
#include<cctype>
#include<bits/stdc++.h>
#include<locale>
#include<sstream>

struct Nodo{
	char dato;
	Nodo *next;
	Nodo *nextdown;
	Nodo *left;
};
void agregarPila(Nodo *&pila,char n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->next=pila;
	pila = nuevo_nodo;
}
char sacarPila(Nodo *&pila,char &n ){
	Nodo *aux = pila;
	n = aux->dato;
	pila = aux ->next;
	delete aux;
	return n;
}
void agregarPila2(Nodo *&pila,char n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->nextdown=pila;
	pila = nuevo_nodo;
}
char sacarPila2(Nodo *&pila,char &n ){
	Nodo *aux = pila;
	n = aux->dato;
	pila = aux ->nextdown;
	delete aux;
	return n;
}

void agregarPila3(Nodo *&pila,char n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->left=pila;
	pila = nuevo_nodo;
}
char sacarPila3(Nodo *&pila,char &n ){
	Nodo *aux = pila;
	n = aux->dato;
	pila = aux ->left;
	delete aux;
	return n;
}
	


int main(){
//	Nodo *pila=NULL;
//string a="2 4 5 3 + 1 - + *";
	Nodo *pila=NULL;
	char dat;
	int temporal=0;
	while(dat!='x'){
		std::cin>>dat;
		if(dat!='x'){	
			agregarPila(pila,dat);
			char y=dat;
			if(y=='+'){
				if(temporal==0){
				sacarPila(pila,dat);
				dat=pila->dato;
				char beta1 = sacarPila(pila,dat);
				dat=beta1;
				int alfa1=beta1-'0';
				char beta2= sacarPila(pila,dat);
				int alfa2=beta2-'0';
				temporal=alfa1+alfa2;
				std::cout<<"la suma es: "<<temporal<<std::endl;}
				else{
					sacarPila(pila,dat);
					dat=pila->dato;
					char beta2=sacarPila(pila,dat);
					dat=beta2;
					int alfa2=beta2-'0';
					temporal=temporal+alfa2;
					std::cout<<"la suma es: "<<temporal<<std::endl;
				}
				//sacarPila(pila,dato);
			}else if(y=='-'){			
				if(temporal==0){
				sacarPila(pila,dat);
				dat=pila->dato;
				char beta1 = sacarPila(pila,dat);
				dat=beta1;
				int alfa1=beta1-'0';
				char beta2= sacarPila(pila,dat);
				int alfa2=beta2-'0';
				temporal=alfa1-alfa2;
				std::cout<<"la resta es: "<<temporal<<std::endl;}
				else{
					sacarPila(pila,dat);
					dat=pila->dato;
					char beta2=sacarPila(pila,dat);
					dat=beta2;
					int alfa2=beta2-'0';
					temporal=temporal-alfa2;
					std::cout<<"la resta es: "<<temporal<<std::endl;
				}
//				std::cout<<"la resta es: "<<temporal<<std::endl;
			}else if(y=='*'){	
				if(temporal==0){
				sacarPila(pila,dat);
				dat=pila->dato;
				char beta1 = sacarPila(pila,dat);
				dat=beta1;
				int alfa1=beta1-'0';
				char beta2= sacarPila(pila,dat);
				int alfa2=beta2-'0';
				temporal=alfa1*alfa2;
				std::cout<<"la multiplicacion es: "<<temporal<<std::endl;}
				else{
					sacarPila(pila,dat);
					dat=pila->dato;
					char beta2=sacarPila(pila,dat);
					dat=beta2;
					int alfa2=beta2-'0';
					temporal=temporal*alfa2;
					std::cout<<"la multipicacion es: "<<temporal<<std::endl;
				}
	//			sacarPila(pila,dat);
	//			std::cout<<"la multipli es: "<<temporal<<std::endl;
			}else if(y=='/'){	
				if(temporal==0){
				sacarPila(pila,dat);
				dat=pila->dato;
				char beta1 = sacarPila(pila,dat);
				dat=beta1;
				int alfa1=beta1-'0';
				char beta2= sacarPila(pila,dat);
				int alfa2=beta2-'0';
				temporal=alfa1/alfa2;
				std::cout<<"la division es: "<<temporal<<std::endl;}
				else{
					sacarPila(pila,dat);
					dat=pila->dato;
					char beta2=sacarPila(pila,dat);
					dat=beta2;
					int alfa2=beta2-'0';
					temporal=temporal/alfa2;
					std::cout<<"la division es: "<<temporal<<std::endl;
				}
	//			sacarPila(pila,dat);
	//			std::cout<<"la division es: "<<temporal<<std::endl;
		}
		}
		
	}
	//resolvPostfix(pila,dato,contador);
//	cout<<resolvPostfix(pila,dato);	
/*	while(pila!=NULL){
//		sacarPila(pila,dato);
		if (pila!=NULL){cout<<sacarPila(pila,dato)<<" , ";}
			else{cout<<sacarPila(pila,dato)<<".";}
}*/
	return 0;
}
