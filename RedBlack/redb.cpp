#include <iostream>
#include<fstream>

struct Node{
	int key;
	Node *P;
	Node *left;
	Node *right;
	int color;
};
typedef Node *Puntero_Nodo;
class RedBlackTree{
	private:
		Puntero_Nodo root;
		Puntero_Nodo TNULL;
	public:
	void Transplant(Puntero_Nodo u, Puntero_Nodo v){
		if (u->P == nullptr){
			root = v;
		}	
	    	else if (u == u->P->left){
			      u->P->left = v;
		    }
		    else {
			      u->P->right = v;
		    }
		v->P = u->P;
	}
	void DeleteFixup(Puntero_Nodo x){
		Puntero_Nodo s;
		while (x != root && x->color == 0){
			if (x == x->P->left){
				s = x->P->right;
			        if (s->color == 1){
					s->color = 0;
					x->P->color = 1;
					leftRotate(x->P);
					s = x->P->right;
				}
				if (s->left->color == 0 && s->right->color == 0){
					s->color = 1;
					x = x->P;
				}
				else{
					if (s->right->color == 0){
						s->left->color = 0;
						s->color = 1;
						rightRotate(s);
						s = x->P->right;
					}
				s->color = x->P->color;
				x->P->color = 0;
				s->right->color = 0;
				leftRotate(x->P);
				x = root;
				}
			}
			else{
				s = x->P->left;
				if (s->color == 1){
					s->color = 0;
					x->P->color = 1;
					rightRotate(x->P);
					s = x->P->left;
				}
				if (s->right->color == 0 && s->right->color == 0){
					s->color = 1;
					x = x->P;
				}
				else{
				if (s->left->color == 0){
					s->right->color = 0;
					s->color = 1;
					leftRotate(s);
					s = x->P->left;
				}
				s->color = x->P->color;
				x->P->color = 0;
				s->left->color = 0;
				rightRotate(x->P);
				x = root;
				}
      			}
		}
	    x->color = 0;
	  }

	void DeleteNode(Puntero_Nodo node, int key_){
		Puntero_Nodo z = TNULL;
		Puntero_Nodo x, y;
		while (node != TNULL){
			if (node->key == key_){
				z = node;
			}
			if (node->key <= key_){
				node = node->right;
			}
			else{
			        node = node->left;
		        }
		}
	    if (z == TNULL) {
	        std::cout << "Dato no encontrado en el arbol..." << std::endl;
      		return;
	    }
	    y = z;
	    int y_original_color = y->color;
	    if (z->left == TNULL){
		      x = z->right;
		      Transplant(z, z->right);
	    }
	    else if (z->right == TNULL) {
		      x = z->left;
		      Transplant(z, z->left);
	    }
		    else {
		      y = Find_min(z->right);
		      y_original_color = y->color;
		      x = y->right;
		      if (y->P == z) {
		          x->P = y;
		      }
		      else{
		          Transplant(y, y->right);
  		          y->right = z->right;
			      y->right->P = y;
		      }
		      Transplant(z, y);
		      y->left = z->left;
		      y->left->P = y;
		      y->color = z->color;
		    }
	    delete z;
    	if (y_original_color == 0){
		      DeleteFixup(x);
	    }
  	}
void InsertFixup(Puntero_Nodo k)  {
	Puntero_Nodo u;
    while (k->P->color == 1){
    	if (k->P == k->P->P->right){
	        u = k->P->P->left;
    	    if (u->color == 1){
				u->color = 0;
	            k->P->color = 0;
      		    k->P->P->color = 1;
		        k = k->P->P;
       		}
	        else{
		        if (k == k->P->left){
		            k = k->P;
		            rightRotate(k);
		        }
		        k->P->color = 0;
         		k->P->P->color = 1;
		        leftRotate(k->P->P);
	        }
      	}
	    else{
	        u = k->P->P->right;
	        if (u->color == 1){
				u->color = 0;
	            k->P->color = 0;
	            k->P->P->color = 1;
	            k = k->P->P;
          	}
	        else{
		        if (k == k->P->right){
		            k = k->P;
		            leftRotate(k);
		        }
		        k->P->color = 0;
        		k->P->P->color = 1;
		        rightRotate(k->P->P);
        	}
      	}
	    if (k == root){
	        break;
    	}
    }
    root->color = 0;
}
void postp(Puntero_Nodo node, std::ofstream & os){
    if (node != TNULL)
    {
        if(node->color==0){
            os << node->key<<" [color=\"black\",fontcolor=white, style=filled]"<< std::endl;
      ,fontcolor=red  }else{
            os << node->key<<" [color=\"red\",fontcolor=white,style=filled]"<< std::endl;
        }
        if(node->left!=nullptr){
            if(node->left!=TNULL){
                if(node->left->color==0){
                    os << node->left->key<<" [color=\"black\",fontcolor=white,style=filled]"<< std::endl;
                }else{
                    os << node->left->key<<" [color=\"red\",fontcolor=white,style=filled]"<< std::endl;
                }
				os<<node->key<<" -> "<<node->left->key<<";"<<std::endl;
            }
        }
        if(node->right!=nullptr){
            if(node->right!=TNULL){
                if(node->left->color==0){
                    os << node->right->key<<" [color=\"black\",fontcolor=white,style=filled]"<< std::endl;
                }else{
                    os << node->right->key<<" [color=\"red\",fontcolor=white,style=filled]"<< std::endl;
                }
				os<<node->key<<" -> "<<node->right->key<<";"<<std::endl;
            }
        }
        postp(node->left,os);
        postp(node->right,os);
      
    }
  }
  	void graph(Puntero_Nodo node){
		std::ofstream file("Red-Black.dot");
		file<<"digraph {"<<std::endl;
		postp(node,file);
		file<<"}"<<std::endl;
		file.close();
		system("dot -Tpdf Red-Black.dot -o Red-Black.pdf");
	}
  RedBlackTree()
  {
    TNULL = new Node;
    TNULL->color = 0;
    TNULL->left = nullptr;
    TNULL->right = nullptr;
    root = TNULL;
  }
  Puntero_Nodo Find_min(Puntero_Nodo node)
  {
    while (node->left != TNULL)
    {
      node = node->left;
    }
    return node;
  }
  void leftRotate(Puntero_Nodo x)
  {
    Puntero_Nodo y = x->right;
    x->right = y->left;
    if (y->left != TNULL)
    {
      y->left->P = x;
    }
    y->P = x->P;
    if (x->P == nullptr)
    {
      root = y;
    }
    else if (x == x->P->left)
    {
      x->P->left = y;
    }
    else
    {
      x->P->right = y;
    }
    y->left = x;
    x->P = y;
  }
  void rightRotate(Puntero_Nodo x)
  {
    Puntero_Nodo y = x->left;
    x->left = y->right;
    if (y->right != TNULL)
    {
      y->right->P = x;
    }
    y->P = x->P;
    if (x->P == nullptr)
    {
      root = y;
    }
    else if (x == x->P->right)
    {
      x->P->right = y;
    }
    else
    {
      x->P->left = y;
    }
    y->right = x;
    x->P = y;
  }
  void insert(int key_)
  {
    Puntero_Nodo node = new Node;
    node->P = nullptr;
    node->key = key_;
    node->left = TNULL;
    node->right = TNULL;
    node->color = 1;
    Puntero_Nodo y = nullptr;
    Puntero_Nodo x = root;
    while (x != TNULL)
    {
      y = x;
      if (node->key < x->key)
      {
        x = x->left;
      }
      else
      {
        x = x->right;
      }
    }
    node->P = y;
    if (y == nullptr)
    {
      root = node;
    }
    else if (node->key < y->key)
    {
      y->left = node;
    }
    else
    {
      y->right = node;
    }
    if (node->P == nullptr)
    {
      node->color = 0;
      return;
    }
    if (node->P->P == nullptr)
    {
      return;
    }
    InsertFixup(node);
  }
  
  void deleteNode(int key)
  {
    DeleteNode(root, key);
  }
  void print_2(){
  	if(root){
		graph(root);
	}
  }
};
int main(){
RedBlackTree arbol1;
std::string i="si";
int x,y;
while(i=="si"){
	std::cout<<"1--Ingresar Nodo"<<std::endl;
	std::cout<<"2--Remover Nodo"<<std::endl;
	std::cin>>y;
	if(y==1){
		std::cout<<"ingrese nodo: "<<std::endl;
		std::cin>>x;
		arbol1.insert(x);
		arbol1.print_2();
	}
	if(y==2){
		std::cout<<"ingrese nodo a eliminar: "<<std::endl;
		std::cin>>x;
		arbol1.deleteNode(x);
		arbol1.print_2();
	}
	std::cout<<"desea continuar? si/no: "<<std::endl;
	std::cin>>i;
}
	return 0;
}

