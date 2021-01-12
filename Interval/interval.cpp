#include <iostream> 
#include<fstream>

//using namespace std; 

class Interval{ 
	public:
		int low, high; 
}; 

class ITNode{ 
	public:
		Interval *i; 
		int max; 
		ITNode *left, *right; 
}; 

ITNode * newNode(Interval i){ 
	ITNode *temp = new ITNode; 
	temp->i = new Interval(i); 
	temp->max = i.high; 
	temp->left = temp->right = NULL; 
}

ITNode *insert(ITNode *root, Interval i){ 
	if (root == NULL) 
		return newNode(i); 

	int l = root->i->low; 

	if (i.low < l) 
		root->left = insert(root->left, i); 

	else
		root->right = insert(root->right, i); 

	if (root->max < i.high) 
		root->max = i.high; 

	return root; 
} 

bool doOVerlap(Interval i1, Interval i2){ 
	if (i1.low <= i2.high && i2.low <= i1.high) 
		return true; 
	return false; 
} 

Interval *overlapSearch(ITNode *root, Interval i){ 
	if (root == NULL) return NULL; 

	if (doOVerlap(*(root->i), i)) 
		return root->i; 

	if (root->left != NULL && root->left->max >= i.low) 
		return overlapSearch(root->left, i); 

	return overlapSearch(root->right, i); 
} 

ITNode *findmin(ITNode *root){
	if(root==NULL){return NULL;}
	if(root->left==NULL){return root;}
	return findmin(root->left);
}

void del(ITNode *&root, Interval y){
	if(root==NULL){ return;}
	if(y.low < root->i->low){
		del(root->left,y);
	}
	else if(y.low > root->i->low){
		del(root->right,y);
	}else if(root->left != NULL && root->right != NULL){
		root->i = findmin(root->right)->i;
//		root->i;
		del(root->right,*(root->i));
	}
	else{
		ITNode * oldNode = root;
		root=(root->left != NULL) ? root->left : root->right;
		delete oldNode;
//	if(root->i->low==y.low && root->i->high==y.high){
	}
}
void intervalSearch(ITNode *root, Interval x){ 
	if (doOVerlap(*(root->i), x)){ 	
		std::cout << "\nInterval here [" << root->i->low << ", " << root->i->high << "]"; 
	}

	if (root->left != NULL && root->left->max >= x.low) {
		intervalSearch(root->left, x); 
	}
	if (root->right != NULL && root->right->max >= x.low) {
		intervalSearch(root->right, x); 
	}
//	intervalSearch(root->right, x); 
} 

void inorder(ITNode *root){ 
	if (root == NULL) return; 


	std::cout << "[" << root->i->low << ", " << root->i->high << "]"
		<< " max = " << root->max << std::endl; 

	inorder(root->left); 
	inorder(root->right); 

}
void print(ITNode * & t,std::ofstream & os){
	if(t==nullptr){return;}
	else{
		if(t->left!=nullptr){
			os<<"\""<<t->i->low<<","<<t->i->high<<"\""<<" -> \""<<t->left->i->low<<","<<t->left->i->high<<"\" ;"<<std::endl;
		}
		if(t->right!=nullptr){
			os<<"\""<<t->i->low<<","<<t->i->high<<"\""<<" -> \""<<t->right->i->low<<","<<t->right->i->high<<"\" ;"<<std::endl;
		}
		print(t->left,os);
		print(t->right,os);

	}
}
void graph(ITNode * & t){
	std::ofstream file("interval.dot");
	file<<"digraph {"<<std::endl;
	print(t,file);
	file<<"}"<<std::endl;
	file.close();
	system("dot -Tpdf interval.dot -o interval.pdf");
}

int main(){ 
	Interval ints[] = {{15, 20}, {10, 30}, {17, 19}, 
		{5, 20}, {12, 15}, {30, 40} 
	}; 
	int n = sizeof(ints)/sizeof(ints[0]); 
	ITNode *root = NULL; 
	for (int i = 0; i < n; i++) 
		root = insert(root, ints[i]); 

	std::cout << "Inorder traversal of constructed Interval Tree is\n"; 
	inorder(root); 

	graph(root);

	Interval x = {5,20}; 
	Interval g = {5,20}; 
	std::cout<<"\nDeleted:"<<std::endl;
//	std::cout << "\nSearching for interval [" << x.low << "," << x.high << "]"; 
/*	Interval *res = overlapSearch(root, x); 
	if (res == NULL) 
		std::cout << "\nNo Overlapping Interval"; 
	else
		std::cout << "\nOverlaps with [" << res->low << ", " << res->high << "]"; */

	intervalSearch(root,x);
/*	
	del(root,g);
	inorder(root);
	graph*/
	return 0; 
} 

