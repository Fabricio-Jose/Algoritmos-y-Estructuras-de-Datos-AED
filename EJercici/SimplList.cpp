#include<iostream>

class Nodo{
	public:
		int dato;
		Nodo* next;
//		Nodo(){};
};

class List{
	public:
		Nodo* head;
		int size;
		List(){
			head=NULL;
			size=0;
		};
		int getsize(){return size;}
		void print(){
			Nodo* aux=head;
			while(aux!=NULL){
				std::cout<<aux->dato<<" ";
				aux=aux->next;
			}
		}
		bool contained(int x){
			Nodo* aux=head;
			while(aux!=NULL){
				if(x==aux->dato){return true;}
				aux=aux->next;
			}
			return false;
		}
		void addDiferent(int x){
			if (head==NULL){
				head = new Nodo;
		       		head->dato=x;
				head->next=0;
			}else{
			Nodo* aux=head;
			
			while(aux->next!=NULL){
				if(aux->dato==x){
					return ;}	
				aux=aux->next;
			}
			Nodo* aux2=new Nodo;
			aux2->dato=x;
			aux2->next=NULL;
			aux->next=aux2;
		}}
		void removenodo(int x){
			Nodo*aux=head;
			Nodo*prev=head;
			if (head==NULL){return;}
			else {if(head->dato==x){
				head=head->next;
				delete aux;
//				return ;
			}else{
				prev=aux;
				aux=aux->next;
			while(aux->next!=NULL){
				if(aux->dato==x){
					prev->next=aux->next;
					delete aux;					
				}
				prev=aux;
				aux=aux->next;
				}
			if(aux->next==NULL){
				prev=prev->next;
				prev->next=NULL;
				delete aux;
			}
			}}
		}

		void simplesort(){
			Nodo *aux1=head;
			Nodo *aux2=head;
			Nodo *prev=head;
			int tempo;
//			tempo=aux2->dato;
			if(head==NULL){return;}
			else {	
				while(aux1->next!=NULL){
//				aux1=aux1->next;
				while(aux2->next!=NULL){
					if(aux1->dato>aux2->dato){
						tempo=aux1->dato;
						aux1->dato=aux2->dato;
						aux2->dato=tempo;
					}
					aux2=aux2->next;
				}//aux2=aux1;
				prev=aux1;
				aux1=aux1->next;
				aux2=aux1;	
				}
			if(aux1->next==NULL){
				if (aux2->dato<prev->dato){
					tempo=aux2->dato;
					aux2->dato=prev->dato;
					prev->dato=tempo;
				}
			}

			}}
		void swap2(int dat){
			Nodo *bef, *p , *aft,*temp;
			bef=head;
			aft=head->next;
			p=head;
			if(p->dato==dat ){
//				aft->next=p;
				p->next=aft->next;
				aft->next=p;
			}else{
				p=p->next;
				aft=aft->next;
			while(p->next!=NULL){
				if (p->dato==dat){
					p->next=aft->next;
					aft->next=p;
					bef->next=aft;
				}
				bef=bef->next;
				aft=aft->next;
				p=p->next;
			}
/*			if(p->next==NULL){
				if(p->dat==dat){
					bef
				}
			}*/
			}
		}

};


int main(){
	List a;
	a.addDiferent(5);
	a.addDiferent(4);
	a.addDiferent(3);
	a.addDiferent(6);
	a.addDiferent(7);
	a.addDiferent(8);
	a.addDiferent(9);
	a.addDiferent(56);
	a.addDiferent(1);
	a.addDiferent(2);
	a.addDiferent(34);
	a.addDiferent(5);
	a.print();
	std::cout<<std::endl;
	a.removenodo(3);
	a.print();
	std::cout<<"ordenado: "<<std::endl;
	a.simplesort();
	a.print();std::cout<<std::endl;
	a.swap2(7);
	a.print();std::cout<<std::endl;

	return 0;
}
