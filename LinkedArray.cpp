#include<iostream>
#include<stdlib.h>
class lista{
	private:
		int numElem;
		int *lists;

	public:
	//	int a;
     		void list(){
			std::cout<<"Ingrese numero de Elementos de la Lista Enlazada:"<<std::endl;
			std::cin>>numElem;
	//		a=numElem;
			if(numElem==500000){
				lists = new int[numElem];
				for(int i=0;i<numElem;i++)
					lists[i]=rand();	
			}else{

			lists = new int[numElem];
			for(int i=0;i<numElem;i++){
				std::cout<<"ingrese elemento: "<<std::endl;
				std::cin>>lists[i];
				//std::cout<<&lists[i]<<std::endl;
				//std::cout<<*&lists[i]<<std::endl;
			}}
		}
		void mostrar(){
			std::cout<<"\n\nMostrando lista:\n";
			for(int i=0;i<numElem;i++){
				std::cout<<lists[i]<<" ";}
			std::cout<<""<<std::endl;
		}
		void delet(){
			delete[] lists;
		}
		void pushfront(){
			std::cout<<"Que elemento desea ingresar al inicio: "<<std::endl;
			int newElem;
			std::cin>>newElem;//if(numElem
			int *temp=new int[numElem];
			for(int i=0;i<numElem;i++){
				temp[i]=lists[i];}
			delete[] lists;
			++numElem;
			lists = new int[numElem];
			lists[0]=newElem;
			for(int i=0;i<numElem;i++){
				lists[i+1]=temp[i];	
			}
			delete[] temp;		
		}

		void pushback(){
			std::cout<<"Que elemento desea ingresar al final: "<<std::endl;
			int newElem;
			std::cin>>newElem;
			int *temp=new int[numElem];
			for(int i=0;i<numElem;i++){
				temp[i]=lists[i];}
			delete[] lists;
			++numElem;
			lists = new int[numElem];
			lists[numElem-1]=newElem;
			for(int i=0;i<numElem-1;i++){
//				if(i+1==numElem){lists[i+1]=newelem;}
				lists[i]=temp[i];
			}
			delete[] temp;
		}

		void ordenar(){
			int aux=0;
			for(int i=0;i<numElem;i++){
				for(int j=0;j<numElem;j++){
					if(lists[j]>lists[i]){
						aux=lists[i];
						lists[i]=lists[j];
						lists[j]=aux;
					}			
			}
		}
		}
		void Merge(int p, int q,int r){

			int n1,n2,i,j,k; 
    		        n1=q-p+1;
			n2=r-q;             
			int L[n1],R[n2];
    			for(i=0;i<n1;i++) {
		       		 L[i]=lists[p+i];
    			}
    			for(j=0;j<n2;j++){
			        R[j]=lists[q+j+1];}
			i=0,j=0;
    			for(k=p;i<n1&&j<n2;k++){
			        if(L[i]<R[j]){
			            lists[k]=L[i++];
			     	} else  {
		        	    lists[k]=R[j++];
				        }
			    }
    			while(i<n1){
			        lists[k++]=L[i++];
			    }
    			while(j<n2){
			        lists[k++]=R[j++];
			    }
			}
		void split(int p,int r){
		  
		    int q;                                
		    if(p<r){
		        q=(p+r)/2;
		        split(p,q);
		        split(q+1,r);
		        Merge(p,q,r);
		    }
		}
			void quickSort(int x,int y){
			int counter=0;
			int tam=y;
			int _x=x;
			if(y==1){std::cout<<"ya";}
			if(y==0){std::cout<<"ser";}
			if((y-x)==0){std::cout<<"cero";}
			if((y-x)==1){std::cout<<"terminado.";}
			else{
				if((y-x)%2==0){
				int aux;
				int j=(((y+x)/2)-1);
				int k=x;
				int l=y-1;
				while ((k!=l)){
					if(lists[k]>lists[j]) {
						if(lists[l]<lists[j]){ 
							aux=lists[k];
							lists[k]=lists[l];
							lists[l]=aux;
							l--;
							k++;
						}else{if(lists[l]==lists[j]){
							aux=lists[k];
							lists[k]=lists[l];
							lists[l]=aux;
							k++;
							}else{if((lists[l]>lists[j])){
								l--;
							}}}}
					else{
					if(lists[k]==lists[j]){
						if(lists[l]<lists[j]){
								aux=lists[k];
								lists[k]=lists[l];
								lists[l]=aux;
								l--;						
							}else{if(lists[l]>lists[j]){
								l--;
							} 
							counter++;
						}}
					else{
					if(lists[k]<lists[j]){
						if(lists[l]<lists[j]){
							k++;
						}else{if(lists[l]==lists[j]){
							k++;
						}else{if(lists[l]>lists[k]){
							k++;
							l--;		
						}}	}}}
					
				}}
				if(counter==0){
				quickSort(_x,tam/2);
				quickSort(tam/2,tam);}
				if(counter>0){
				quickSort(_x,(tam/2)+1);
				quickSort((tam/2)+1,tam);
				}}
				
				if((y-x)%2==1){
				int aux;
				int j=((y/2));
				int k=x;
				int l=y-1;
				while ((k!=l)){
					if(lists[k]>lists[j]) {
						if(lists[l]<lists[j]){ 
							aux=lists[k];
							lists[k]=lists[l];
							lists[l]=aux;
							l--;
							k++;
						}else{if(lists[l]==lists[j]){
							aux=lists[k];
							lists[k]=lists[l];
							lists[l]=aux;
							k++;
							}else{if((lists[l]>lists[j])){
								l--;
							}}}}
					else{
					if(lists[k]==lists[j]){
						if(lists[l]<lists[j]){
								aux=lists[k];
								lists[k]=lists[l];
								lists[l]=aux;
								l--;						
							}else{if(lists[l]>lists[j]){
								l--;
							} 
							counter++;
						}}
					else{
						if(lists[k]<lists[j]){
							if(lists[l]<lists[j]){
								k++;
							}else{if(lists[l]==lists[j]){
								k++;
							}else{if(lists[l]>lists[k]){
								k++;
								l--;		
						}	}}}}}
					
				}
				std::cout<<counter<<std::endl;
				if(counter>0){
				//	counter=0;
					quickSort(_x,(tam/2)+1);
					quickSort((tam/2)+1,tam);}
				if(counter=0){
				//	counter=0;
					quickSort(_x,tam/2);	
					quickSort(tam/2,tam);
				}}}

		}
		

		void deletelement(){
			std::cout<<"que elemento desea eliminar: "<<std::endl;
			int borrar;
			std::cin>>borrar;
			int *temp=new int[numElem];
			for(int i=0;i<numElem;i++){
				temp[i]=lists[i];
			}delete[] lists;
			--numElem;
			lists = new int[numElem];
			int i=0,j=0;
			while(i<=numElem){
				if(temp[i]!=borrar){
					lists[j]=temp[i];}
				if(temp[i]==borrar){
					lists[j]=temp[i+1];
					i++;

				}
				i++;
				j++;
				
			}delete[] temp;
			/*
			for(int i=0;i<=numElem;i++){
				lists[i]=temp[i];
				if(temp[i]==borrar){
					lists[i]=temp[i+1];
					i=i+1;				
				}
			}*/

		
		}
		void search(){
			std::cout<<"que elemento busca? "<<std::endl;
			int ser;
			std::cin>>ser;
			for(int i=0;i<numElem;i++){
				if(lists[i]==ser){std::cout<<"posicion: "<<i<<std::endl;break;}
			}
		
		}



};
//capitulo 5,implementar la lista con iterator, siguiente capitulo esta lista ord y desord que heredan dela calse lista/iterator, yyyyyy al final del
//capi hay un problema para resolver y suar interfaz grafica, q soporte 50 000 datos,

int main(){
	lista primera;
	primera.list();
	primera.mostrar();
//	usar insertion sort en parlelo, usar treats
//	primera.delet();
//	primera.pushfront();
//	primera.pushback();
//	primera.ordenar();
//	primera.deletelement();
	int b;
	std::cin>>b;
//	int b=primera.a;
	primera.split(0,b);
	primera.mostrar();
	primera.delet();
//	std::cout<<"desea agregar mas elementos a la lista? "<<std::endl;
	return 0;
}

