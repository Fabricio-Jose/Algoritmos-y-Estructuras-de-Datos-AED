#include<iostream>
class NodeI{
	public:
		int dato_i;
		NodeI * next_i;
};

class NodeJ{
	public:
		int dato_j;
		NodeJ * next_j;
};

class Node{
	public:
		int dato;
		NodeI * up;
		NodeJ * down;
		Node * next;
};

class Matrix{
	public:
		int *AA_i;
		int *JA_i;
		int *IA_i;
		int *AA_j;
		int *JA_j;
		int *IA_j;

		int *a_j;

		int tam;
		int tam_IA;
		int tam_JA;
		Node * head;
		Node * tail;
		Node * tail_i;
		Node * tail_j;
		Matrix(){
			AA_i=NULL;
			JA_i=NULL;
			IA_i=NULL;
			AA_j=NULL;
			JA_j=NULL;
			IA_j=NULL;
			a_j=NULL;
			tam=0;
			tam_IA=0;
			tam_JA=0;
			head=NULL;
			tail=NULL;
			tail_i=NULL;
			tail_j=NULL;
		};

	int gettam(){
		std::cout<<"el tamaño es: "<<std::endl;
		return tam;
	}
	void print(){
		Node * aux=head;
		while(aux!=NULL){
			std::cout<<aux->dato<<", ";
			std::cout<<aux->up->dato_i<<", ";
			std::cout<<aux->down->dato_j<<std::endl;
			aux=aux->next;
		}
	}
	void print_i(){
		NodeI * aux1=head->up;
		std::cout<<"lista de posicion por filas: ";
		while(aux1!=NULL){
			std::cout<<aux1->dato_i;;
			aux1=aux1->next_i;
		}
		std::cout<<std::endl;
	}
	void print_j(){
		NodeJ * aux1=head->down;
		std::cout<<"lista de posicion por columnas: ";
		while(aux1!=NULL){
			std::cout<<aux1->dato_j;;
			aux1=aux1->next_j;
		}
		std::cout<<std::endl;
	}
	bool find(int x, int i, int j){
		Node *aux;
		aux=head;
		if(aux==NULL){
			return false;
		}
		while(aux!=NULL){
			if(aux->dato==x && aux->up->dato_i==i && aux->down->dato_j==j){
				return true;
			}
			aux=aux->next;
		}
		return false;
	}
		
	void crearNodoCOO( int x, int i, int j){
		Node *aux,*aux1,*aux2,*i_,*j_;
		aux=head;
		aux1=head;
		aux2=head;
		if (aux==NULL){
			aux=new Node;
			aux->next=NULL;
			aux->dato=x;
			aux->up=new NodeI;
			aux->up->dato_i=i;
			aux->up->next_i=NULL;
			aux->down=new NodeJ;
			aux->down->dato_j=j;
			aux->down->next_j=NULL;
			head=aux;
			tail=head;
			tam++;
		}else{	
		aux2=head->next;
		while(aux2!=NULL){
			aux2=aux2->next;
			aux1=aux1->next;
		}
		aux2=new Node;
		aux2->next=NULL;
		aux2->dato=x;

		aux2->up=new NodeI;
		aux2->up->dato_i=i;
		aux2->up->next_i=NULL;
		aux1->up->next_i=aux2->up;
		aux2->down=new NodeJ;
		aux2->down->dato_j=j;
		aux2->down->next_j=NULL;
		tail=aux2;
		aux1->down->next_j=aux2->down;
		aux1->next=aux2;
		tam++;
		}
	}
	
	void crearListEnl(int **matriz,int m,int n){
		for(int i=0;i < m;i++){
			for (int j = 0; j < n; j++){
				if(matriz[i][j]!=0){
					crearNodoCOO(matriz[i][j],i,j);
				}
			}
		}
	}
	void crear_comprimido_filas_i(int **matriz,int m, int n){
		AA_i= new int[tam];
		JA_i= new int[tam];
		int punteroAA=0;
		int punteroIA=0;
		int c,ia_tam=0;
		//comprobando tamaño de IA:
		for(int q=0;q<m;q++){
			c=0;
			for(int w=0;w<n;w++){
				if(matriz[q][w]!=0){
					if(c==0){
						ia_tam++;
						c++;
					}
				}
			}
		}
		ia_tam++;
		IA_i=new int[ia_tam];
		c=0;
		for(int i=0; i < m;i++){
			c=0;
			for(int j=0; j < n;j++){
				if(matriz[i][j]!=0){
					if(c==0){
						AA_i[punteroAA]=matriz[i][j];
						JA_i[punteroAA]=j;
						IA_i[punteroIA]=punteroAA+1;
						punteroAA++;
						punteroIA++;
						c++;
					}
					else{
						if(c==1){
						AA_i[punteroAA]=matriz[i][j];
						JA_i[punteroAA]=j;
						punteroAA++;
						}
					}
				}
			}
		}
		IA_i[punteroIA]=tam+AA_i[0];
		tam_IA=ia_tam;
	}
	void imprimir_comprimido_filas(){
		std::cout<<"lista AA de elementos: ";
		for(int j=0;j<tam;j++){
			std::cout<<AA_i[j]<<",";
		}std::cout<<std::endl;
		std::cout<<"Lista de AJ: ";
		for(int k=0;k<tam;k++){
				std::cout<<JA_i[k]<<",";
		}std::cout<<std::endl;
        std::cout<<"lista IA_i: ";
		for(int i = 0; i < tam_IA;i++){
			std::cout<< IA_i[i]<<",";
		}std::cout<<std::endl;
	}
	void crear_comprimido_columnas_j(int **matriz,int m, int n){
		AA_j= new int[tam];
		IA_j= new int[tam];
		int punteroAA=0;
		int punteroJA=0;
		int c,ja_tam=0;
		//comprobando tamaño de JA:
		for(int w=0;w<n;w++){
			c=0;
			for(int q=0;q<m;q++){
				if(matriz[q][w]!=0){
					if(c==0){
						ja_tam++;
						c++;
					}
				}
			}
		}
		ja_tam++;
		JA_j=new int[ja_tam];
		c=0;
		std::cout<<"tamaño de ja_tam es: "<<ja_tam<<std::endl;

		for(int j=0; j < n;j++){
			c=0;
			for(int i=0; i < m;i++){
				if(matriz[i][j]!=0){
					if(c==0){
						AA_j[punteroAA]=matriz[i][j];
						IA_j[punteroAA]=i;
						JA_j[punteroJA]=punteroAA+1;
						std::cout<<"elemento AA_: "<<AA_j[punteroAA]<<", elemento IA: "<<IA_j[punteroAA]<<", elemento JA_j_"<<JA_j[punteroJA]<<std::endl;
						punteroAA++;
						punteroJA++;
						c++;
					}
					else{
						if(c==1){
						AA_j[punteroAA]=matriz[i][j];
						IA_j[punteroAA]=i;
						punteroAA++;
						}
					}
				}
			}
		}
		JA_j[punteroJA]=tam+AA_j[0];
		tam_JA=ja_tam;
	}
	void imprimir_comprimido_columnas(){
		std::cout<<"lista AA de elementos: ";
		for(int j=0;j<tam;j++){
			std::cout<<AA_j[j]<<",";
		}std::cout<<std::endl; 
 		std::cout<<"lista IA_i: ";
		for(int i = 0; i < tam;i++){
			std::cout<< IA_j[i]<<",";
		}std::cout<<std::endl;
		std::cout<<"Lista de AJ: ";
		for(int k=0;k<tam_JA;k++){
			std::cout<<JA_j[k]<<",";
		}std::cout<<std::endl;
	}
	void generarMCOO(int **matriz, int m, int n){
		Node *aux;
		aux=head;
		for (int i = 0; i < m; i++) {
	 		for (int j = 0; j < n; j++) {
				if(aux!=NULL){
				if(i==aux->up->dato_i  && j==aux->down->dato_j ){
					matriz[i][j] = aux->dato;
					aux=aux->next;
				}
				else{
					matriz[i][j] = 0;
				}
				}else{
					matriz[i][j] = 0;
				}
			}
		}
	}
	void printM(int **matriz,int m, int n){
		for(int i=0;i< m;i++){
		        for(int j=0;j< n;j++){
				std::cout<<matriz[i][j]<<"\t";
		        }
				std::cout<<std::endl;
		}
	}
/*
	//void multiplicacion(int **matriz_a,int **matriz_b){}
	void suma(int **a,int **b,){
		int count;
		Matrix c;
		c=b;
		Node* aux=a->head;
		Node* baux=b->head; 
		Node* caux=c->head;
		while(aux->next!=NULL){
			std::cout<<"aqiiii";
			baux=b.head;
			count=0;
			while(baux->next!=NULL){
				std::cout<<"aqiiii";
				if(aux->up->dato_i==baux->up->dato_i && aux->down->dato_j==baux->down->dato_j){
				caux->dato=aux->dato+baux->dato;	
				count++;
				}
				caux=caux->next;
				baux=baux->next;
			}if(count==0){c.crearNodoCOO(aux->dato,aux->up->dato_i,aux->down->dato_j);}
			aux=aux->next;
		}
	
		
		int r,t;
		std::cin >> r >>t;
		int **matriz_2 = new int *[r];
		for (int i=0;i<r;i++){
			matriz_2[i]=new int[t];
		}
	
		std::cout<<"--------------------------"<<std::endl;
		c.generarMCOO(matriz_2, j, k);
		c.printM(matriz_2, r, t);
	}

*/
};

	void suma(Matrix a,Matrix b){}

int main(){
	Matrix a;
	a.crearNodoCOO(2,0,1);
	a.crearNodoCOO(4,0,3);
	a.crearNodoCOO(5,0,4);
	a.crearNodoCOO(10,0,5);
	a.crearNodoCOO(6,1,3);
	a.crearNodoCOO(7,2,2);
	a.crearNodoCOO(8,3,2);
	a.print();
	a.print_i();
	a.print_j();
	int m,n;
	std::cin >> m >> n;
	int **matriz = new int *[m];
	for (int i=0;i<m;i++){
		matriz[i]=new int[n];
	}
	std::cout<<"--------------------------"<<std::endl;
	a.generarMCOO(matriz, m, n);
	a.printM(matriz, m, n);
	std::cout<<a.gettam()<<std::endl;
//	a.crear_comprimido_filas_i(matriz,m,n);
//	a.imprimir_comprimido_filas();
	a.crear_comprimido_columnas_j(matriz,m,n);
	a.imprimir_comprimido_columnas();
	
	Matrix b;
	b.crearNodoCOO(2,0,1);
	b.crearNodoCOO(4,0,3);
	b.crearNodoCOO(5,0,4);
	b.crearNodoCOO(10,0,5);
	b.crearNodoCOO(6,1,3);
	b.crearNodoCOO(7,2,2);
	b.crearNodoCOO(8,3,2);
	b.print();
	b.print_i();
	b.print_j();
	int j,k;
	std::cin >> j >>k;
	int **matriz_1 = new int *[j];
	for (int i=0;i<j;i++){
		matriz_1[i]=new int[k];
	}
	std::cout<<"--------------------------"<<std::endl;
	b.generarMCOO(matriz_1, j, k);
	b.printM(matriz_1, j, k);
	std::cout<<b.gettam()<<std::endl;
//	b.crear_comprimido_filas_i(matriz,j,k);
//	b.imprimir_comprimido_filas();
	b.crear_comprimido_columnas_j(matriz_1,j,k);
	b.imprimir_comprimido_columnas();
/*	
	int count;
	Matrix c;
	c=b;
	Node* aux=a.head;
	Node* baux=b.head; 
	Node* caux=c.head;
	while(aux->next!=NULL){

			std::cout<<"aqiiii";
		baux=b.head;
		count=0;
		while(baux->next!=NULL){
			std::cout<<"aqiiii";
			if(aux->up->dato_i==baux->up->dato_i && aux->down->dato_j==baux->down->dato_j){
			caux->dato=aux->dato+baux->dato;	
			count++;
			}
			caux=caux->next;
			baux=baux->next;
		}if(count==0){c.crearNodoCOO(aux->dato,aux->up->dato_i,aux->down->dato_j);}
		aux=aux->next;
	}

	
	int r,t;
	std::cin >> r >>t;
	int **matriz_2 = new int *[r];
	for (int i=0;i<r;i++){
		matriz_2[i]=new int[t];
	}

	std::cout<<"--------------------------"<<std::endl;
	c.generarMCOO(matriz_2, j, k);
	c.printM(matriz_2, r, t);
*/
	return 0;
}
