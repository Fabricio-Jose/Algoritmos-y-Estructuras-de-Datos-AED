#include<iostream>
#include<fstream>

template <typename Comparable>
struct AvlNode{
	Comparable element;
	AvlNode *left;
	AvlNode *right;
	int height;

	AvlNode( const Comparable & ele, AvlNode *lt, AvlNode *rt, int h = 0 ): 
		element{ ele }, 
		left{ lt }, 
		right{ rt }, 
		height{ h } { }

	AvlNode( Comparable && ele, AvlNode *lt, AvlNode *rt, int h = 0 ): 
		element{ std::move( ele ) }, 
		left{ lt }, 
		right{ rt }, 
		height{ h } { }

	 int hheight( AvlNode *t ) const {
		 return t == nullptr ? -1 : t->height;
	 }
	static const int ALLOWED_IMBALANCE = 1;
	AvlNode * findMin( AvlNode *t ) const{
		if( t == nullptr ) return nullptr;
		if( t->left == nullptr ) return t;
		return findMin( t->left ); }
	

	void balance( AvlNode * & t ){
	if( t == nullptr )
		return;
	if( hheight( t->left ) - hheight( t->right ) > ALLOWED_IMBALANCE )
		if( hheight( t->left->left ) >= hheight( t->left->right ) )
			rotateWithLeftChild( t );
		else
			doubleWithLeftChild( t );
	else
	if( hheight( t->right ) - hheight( t->left ) > ALLOWED_IMBALANCE )
		if( hheight( t->right->right ) >= hheight( t->right->left ) )
			rotateWithRightChild( t );
	else
		doubleWithRightChild( t );
	t->height = std::max( hheight( t->left ), hheight( t->right ) ) + 1;
	}
	
	void rotateWithLeftChild( AvlNode * & k2 ){
		AvlNode *k1 = k2->left;
		k2->left = k1->right;
		k1->right = k2;
		k2->height = std::max( hheight( k2->left ), hheight( k2->right ) ) + 1;
		k1->height = std::max( hheight( k1->left ), k2->height ) + 1;
		k2 = k1;
	}

	void rotateWithRightChild( AvlNode * & k2 ){
		AvlNode *k1 = k2->right;
		k2->right = k1->left;
		k1->left = k2;
		k2->height =std::max( hheight( k2->right ), hheight( k2->left ) ) + 1;
		k1->height = std::max( hheight( k1->right ), k2->height ) + 1;
		k2 = k1;
	}

	void doubleWithLeftChild( AvlNode * & k3 ){
		rotateWithRightChild( k3->left );
		rotateWithLeftChild( k3 );
	}

	void doubleWithRightChild( AvlNode * & k3 ){
		rotateWithLeftChild( k3->right );
		rotateWithRightChild( k3 );
	}

	void remove( const Comparable & x, AvlNode * & t ){
		if( t == nullptr )
			return;
		if( x < t->element )
			remove( x, t->left );
		else if( t->element < x )
			remove( x, t->right );
		else if( t->left != nullptr && t->right != nullptr ){
			t->element = findMin( t->right )->element;
			remove( t->element, t->right );
		}
		else{
			AvlNode *oldNode = t;
			t = ( t->left != nullptr ) ? t->left : t->right;
			delete oldNode;
		}
		balance( t );
	}

	void insert( const Comparable & x, AvlNode *&t ){	
		if( t==nullptr ){
			t = new AvlNode( x, nullptr, nullptr );
		}
		else if( x < t->element ){
			insert( x, t->left );
		}
		else if( t->element < x ){
			insert( x, t->right );
		}
	
		balance( t );
	}
	void printord(AvlNode * & t){ 
		if(t==nullptr){return;}
		else{ 
			std::cout<<t->element<<std::endl;
			print(t->left);
			print(t->right);

		}
	}

	void print(AvlNode * & t,std::ofstream & os){ 
		if(t==nullptr){return;}
		else{ 
			os<<t->element<<std::endl;
			if(t->left!=nullptr){
				os<<t->element<<" -> "<<t->left->element<<";"<<std::endl;
			}//else { os<<t->element<<" -> null"<<";"<<std::endl; }
			if(t->right!=nullptr){
				os<<t->element<<" -> "<<t->right->element<<";"<<std::endl;
			}//else { os<<t->element<<" -> null"<<";"<<std::endl; }
			print(t->left,os);
			print(t->right,os);

		}
	}
	void graph(AvlNode * & t){
		std::ofstream file("avl.dot");
		file<<"digraph {"<<std::endl;
		t->print(t,file);
		file<<"}"<<std::endl;
		file.close();
		system("dot -Tpdf avl.dot -o avl.pdf");
	}


};
int main(){
	AvlNode<int>* arbol2=nullptr;//=new AvlNode<int>(1,nullptr,nullptr);
//	arbol2->insert(1,arbol2);
	/*arbol2->insert(5,arbol2);	
	arbol2->insert(6,arbol2);	
	arbol2->insert(10,arbol2);	
	arbol2->insert(13,arbol2);	
	arbol2->insert(17,arbol2);	
	arbol2->insert(16,arbol2);	
	arbol2->insert(3,arbol2);	*/
	arbol2->graph(arbol2);
	std::string i="si";
	int x,y;
	while(i=="si"){
		std::cout<<"1--Ingresar Nodo"<<std::endl;
		std::cout<<"2--Remover Nodo"<<std::endl;
		std::cin>>y;
		if(y==1){
			std::cout<<"ingrese nodo: "<<std::endl;
			std::cin>>x;
			arbol2->insert(x,arbol2);
			arbol2->graph(arbol2);
		}
		if(y==2){
			std::cout<<"ingrese nodo a eliminar: "<<std::endl;
			std::cin>>x;
			arbol2->remove(x,arbol2);
			arbol2->graph(arbol2);
		}
		std::cout<<"desea continuar? si/no: "<<std::endl;
		std::cin>>i;
	
	}

//	arbol2->remove(2,arbol2);
//	std::cout<<arbol2->right->left->element<<std::endl;
//	arbol2->graph(arbol2);
	
	
/*	std::ofstream file("avl.dot");
	file<<"digraph {"<<std::endl;
	arbol2->print(arbol2,file);
	file<<"}"<<std::endl;
	file.close();
	system("dot -Tpdf avl.dot -o avl.pdf");*/
	return 0;
}

