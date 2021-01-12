#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<thread>
#include<cstdlib>
#include<string>
#include<vector>
#include<numeric>
#include<cmath>
#include<sstream>
#include<chrono>
#include<mutex>

unsigned t0, t1;
class lista{
	private:
		int numElem;
		int *lists;

	public:
		int tamano=numElem;
		int head=0;
		int tam(){
			return numElem;
		}
     		void list(){
			std::cout<<"Ingrese numero de Elementos de la Lista Enlazada:"<<std::endl;
			std::cin>>numElem;
	
			if(numElem==1000000){
				lists = new int[numElem];
				for(int i=0;i<numElem;i++)
					lists[i]=rand();	
			}/*else{

			lists = new int[numElem];
			for(int i=0;i<numElem/2;i++){
				std::cout<<"ingrese elemento: "<<std::endl;
				std::cin>>lists[i];
				//std::cout<<&lists[i]<<std::endl;
				//std::cout<<*&lists[i]<<std::endl;
			}}*/
		}
		void completar(){
			for(int i=(numElem/2)+1;i<numElem;i++){
				lists[i]=rand();	
			}
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
		void push(){
			std::cout<<"Que elemento desea ingresar: "<<std::endl;
			int newElem;
			std::cin>>newElem;
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

		void ordenar(){
			int aux=0;
			for(int i=0;i<numElem;i++){
				for(int j=0;j<numElem;j++){
					if(lists[j]>lists[i]){
						aux=lists[i];
						lists[i]=lists[j];
						lists[j]=aux;
				}}}}
		void insertSort(){
			int aux=0;
			for (int i=1;i<numElem;i++){
				if(lists[i]<lists[i-1]){
				aux=lists[i-1];
				lists[i-1]=lists[i];
				lists[i]=aux;
				int j=i-1;
				int k=i-2;
				while (k>=0){
					if(lists[j]<lists[k]){
						aux=lists[k];
						lists[k]=lists[j];
						lists[j]=aux;
					}
						j--;
						k--;		
				}}}}
		void quickSort(int izq, int der){
			int i=izq, j=der,aux;
			int pivote = lists[(izq+der)/2];
			while(i<=j){
				while(lists[i]<pivote) i++;
				while(lists[j]>pivote) j--;
				if (i<=j){
					aux=lists[i];
					lists[i]=lists[j];
					lists[j]=aux;
					i++;
					j--;
				}
			}
			if(izq<j){quickSort(izq,j);}
			if(der>i){quickSort(i,der);}

		}

		void binarySearch(int a, int b){
			int izq=a,der=b;
			int m=lists[(izq+der)/2];
			
			


		}
		void binarySort(){
			int aux=0;

			int counter=0;
			for(int i=1;i<numElem;i++){
				int split=i;
				int acum;
				while(counter==0){
					while( split!=0  ){
						if(split>0){
							if(lists[i]<lists[split/2]){
								split=split/2;
								if(split-1<0){
									aux=lists[i];
									while(acum>split){
										lists[acum]=lists[acum-1];
										acum--;									
									}
									lists[split];
								}
							aux=lists[i-1];
							lists[i-1]=lists[i];
							lists[i]=aux;
							int j=i-1;
							int k=i-2;			
				}}}
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
		}
		void search(){
			std::cout<<"que elemento busca? "<<std::endl;
			int ser;
			std::cin>>ser;
			for(int i=0;i<numElem;i++){
				if(lists[i]==ser){std::cout<<"posicion: "<<i<<std::endl;break;}
			}
		}


/*		void test2(){
			std::thread t1(&lista::list,this);
			t1.join();
			//mostrar();		
			std::thread t2(&lista::completar,this);
//			t1.join();
			//mostrar();		
			t2.join();
			mostrar();
		
		}*/
		void test(int a){
			
	//		std::thread t1(&lista::insertSort,this);
	//		t1.join();
	//		mostrar();
			std::thread t2(&lista::quickSort,this,0,a/2);
			t2.join();		
//			mostrar();
//			std::cout<<"thread: "<<std::this_thread::get_id()<<std::endl;
			std::thread t3(&lista::quickSort,this,a/2+1,a);
			t3.join();
//			mostrar();
//			std::cout<<"thread: "<<std::this_thread::get_id()<<std::endl;
//			mostrar();

		}

};
//capitulo 5,implementar la lista con iterator, siguiente capitulo esta lista ord y desord que heredan dela calse lista/iterator, yyyyyy al final del
//capi hay un problema para resolver y suar interfaz grafica, q soporte 50 000 datos,

int main(){
	 /*
	t0=clock();
	lista primera;
	primera.list();
	primera.mostrar();
	int a;
	a=primera.tam()-1;
//	primera.test2();
//	primera.insertSort()
//	primera.ordenar();
//	usar insertion sort en parlelo, usar treatts
	//primera.split(0,a);
//	primera.binarySort();
//	primera.test(a);
	primera.quickSort(0,a);
	primera.mostrar();
	//primera.test(a);
//	primera.delet();
//	std::cout<<"desea agregar mas elementos a la lista? "<<std::endl;
	t1= clock();
	double time = (double(t1-t0)/CLOCKS_PER_SEC);
	std::cout << "Execution Time: " << time << std::endl;*/
	int a=4;
	float b=2;
	std::cout<<a-b;
	return 0;
}
//0,82


