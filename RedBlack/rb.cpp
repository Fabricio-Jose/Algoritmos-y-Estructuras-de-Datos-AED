#include<iostream>
#include<fstream>

template <typename T>
struct RBNode{
	T key;
	RBNode *left;
	RBNode *right;
	RBNode *p;
	char color;
//	int height;

	RBNode( const T & k, RBNode *lt, RBNode *rt, RBNode *pa, char c= 'r' ): 
		key{ k }, 
		left{ lt }, 
		right{ rt }, 
		p{ pa },
		color{ c } {}
//		height{ h } { }

	RBNode( T && k, RBNode *lt, RBNode *rt, RBNode *pa, char c='r' ): 
		key{ std::move( k ) }, 
		left{ lt }, 
		right{ rt }, 
		p{ pa },
		color{ c }{ }
//		height{ h } { }
	RBNode nulo(RBNode *&y){
		RBNode * nul = new RBNode( 0 , nullptr, nullptr, y, 'r');
		return nul;
	}


	void left_rotate(RBNode *& t,RBNode *& x){
		RBNode * y =x->right;
		x->right = y->left;
		if(y->left!=nullptr){
			y->left->p=x;			
		}
		y->p=x->p;
		if(x->p==nullptr){
			t=y;		
		}
		else{
			if(x==x->p->left){
				x->p->left=y;			
			}
			else{
				x->p->right=y;
			}
		}
		y->left=x;
		x->p=y;	
	}
	void right_rotate(RBNode *& t,RBNode *& x){
		RBNode * s =x->left;
		x->left = s->right;
		if(s->right!=nullptr){
			s->right->p=x;			
		}
		s->p=x->p;
		x->p=s;
		std::cout<<"aiz:"<<x->p->key<<std::endl;
		if(x->p==nullptr){
			t=s;		
				std::cout<<"arturo:"<<std::endl;
		}
		else{
			if(x==x->p->right){
				x->p->right=s;			
				std::cout<<"a222rturo:"<<std::endl;
			}
			else{
				x->p->left=s;
				std::cout<<"raiz:"<<std::endl;
			}
		}
		s->right=x;
		x->p=s;	
		std::cout<<x->key<<std::endl;
		std::cout<<x->p->key<<std::endl;
		
	}
	void insert_fixup(RBNode *& zz, RBNode *& t){
		if(zz->p!=nullptr){
		while(zz->p->color=='r'){
			if(zz->p==zz->p->p->left){
				RBNode * y = zz->p->p->right;	
				if(y==nullptr){
					if(zz==zz->p->right){
						zz=zz->p;
						left_rotate(t,zz);
					}			
					zz->p->color='b';
					zz->p->p->color='r';
					right_rotate(t,zz->p->p);
					if(zz->p==nullptr){break;}
				}else{
				if(y->color=='r'){
					zz->p->color='b';
					y->color='b';
					zz->p->p->color='r';
					zz=zz->p->p;
					if(zz->p==nullptr){break;}
				}
				else{
					if(zz==zz->p->right){
						zz=zz->p;
					left_rotate(t,zz);
					}			
					zz->p->color='b';
					zz->p->p->color='r';
					right_rotate(t,zz->p->p);
					if(zz->p==nullptr){break;}
					}
				}
			}
			else{
				RBNode * y = zz->p->p->left;
				if(y==nullptr){
					if(zz==zz->p->left){
						zz=zz->p;
						right_rotate(t,zz);
					}
					zz->p->color='b';
					zz->p->p->color='r';
					left_rotate(t,zz->p->p);
					if(zz->p==nullptr){break;}

				}else{//case1
					if(y->color=='r'){
						zz->p->color='b';
						std::cout<<"entro"<<zz->p->key<<zz->p->color<<std::endl;
						y->color='b';
						zz->p->p->color='r';
						zz=zz->p->p;
						if(zz->p==nullptr){break;}
					}
					else{
						if(zz==zz->p->left){
							zz=zz->p;
							right_rotate(t,zz);
						}
						zz->p->color='b';
						zz->p->p->color='r';
						left_rotate(t,zz->p->p);
						if(zz->p==nullptr){break;}
					}
				}
			}
		}
		t->color='b';
		}
		else{
			std::cout<<"puntero nulo"<<std::endl;		
			t->color='b';
		}
	}


	void insert(const T & z, RBNode *&t){
		RBNode * y=nullptr;
		RBNode * x=t;
		RBNode * a=nullptr;
		while (x!=nullptr){
			y=x;
			if(z < x->key){
				x=x->left;
			}else { x=x->right; }
		}//z->p=y;
		if(y==nullptr){
			t= new RBNode(z, nullptr, nullptr,y,'r');
			a=t;
		}
		else{ 
			if(z < y->key){
				y->left = new RBNode( z , nullptr, nullptr, y, 'r');
				a=y->left;
		}
			else {
				y->right = new RBNode( z , nullptr, nullptr, y, 'r');
				a=y->right;
			}
		}
		insert_fixup(a,t);
	}

};
int main(){
	RBNode<int>* arbol2=nullptr;//=new AvlNode<int>(1,nullptr,nullptr);
	arbol2->insert(47,arbol2);
	std::cout<<arbol2->key<<std::endl;
	std::cout<<arbol2->color<<std::endl;
	arbol2->insert(60,arbol2);
	std::cout<<"key, color y padre"<<arbol2->right->key<<arbol2->right->color<<arbol2->right->p->key<<std::endl;
	arbol2->insert(22,arbol2);
	std::cout<<"key, color y padre"<<arbol2->left->key<<arbol2->left->color<<arbol2->left->p->key<<std::endl;
	arbol2->insert(12,arbol2);
	std::cout<<"key, color y padre"<<arbol2->left->left->key<<arbol2->left->left->color<<arbol2->left->left->p->key<<std::endl;
	std::cout<<"key, color y padre"<<arbol2->right->key<<arbol2->right->color<<arbol2->right->p->key<<std::endl;
	std::cout<<"key, color y padre"<<arbol2->left->key<<arbol2->left->color<<arbol2->left->p->key<<std::endl;
	std::cout<<"crashing"<<std::endl;
	arbol2->insert(6,arbol2);
	std::cout<<"key, color y padre"<<arbol2->left->left->key<<arbol2->left->left->color<<arbol2->left->left->p->key<<std::endl;
	std::cout<<"key, color y padre"<<arbol2->left->right->key<<arbol2->left->right->color<<arbol2->left->right->p->key<<std::endl;
	std::cout<<"key, color y padre"<<arbol2->right->key<<arbol2->right->color<<arbol2->right->p->key<<std::endl;
	std::cout<<"key, color y padre"<<arbol2->left->key<<arbol2->left->color<<arbol2->left->p->key<<std::endl;
/*	std::cout<<arbol2->left->left->key<<std::endl;
	std::cout<<arbol2->left->left->p->key<<std::endl;
	std::cout<<arbol2->left->p->key<<std::endl;
	std::cout<<arbol2->left->right->p->key<<std::endl;*/
/*	arbol2->insert(13,arbol2);
	std::cout<<"newcrash"<<std::endl;
	std::cout<<arbol2->left->color<<std::endl;
	std::cout<<arbol2->left->left->color<<std::endl;
	std::cout<<arbol2->left->right->color<<std::endl;*/

/*	arbol2->insert(41,arbol2);
	arbol2->insert(20,arbol2);
	arbol2->insert(52,arbol2);
	arbol2->insert(16,arbol2);*/
	/*std::cout<<arbol2->key<<std::endl;
	std::cout<<arbol2->left->left->key<<std::endl;
	std::cout<<arbol2->left->left->color<<std::endl;
	std::cout<<arbol2->color<<std::endl;
	std::cout<<arbol2->right->color<<std::endl;
	std::cout<<arbol2->right->right->color<<"right"<<std::endl;*/
	/*std::cout<<arbol2->right->right->right->color<<std::endl;
	std::cout<<arbol2->right->right->right->right->color<<std::endl;*/
	return 0;
}

