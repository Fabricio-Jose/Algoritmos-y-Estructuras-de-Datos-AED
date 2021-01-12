#include <iostream> 
using namespace std; 

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
	temp->left = nullptr;
	temp->right = nullptr; 
}

ITNode *insert(ITNode *root, Interval i){ 
	if (root == nullptr) 
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
	if (root == nullptr) return nullptr; 

	if (doOVerlap(*(root->i), i)) 
		return root->i; 

	if (root->left != nullptr && root->left->max >= i.low) 
		return overlapSearch(root->left, i); 

	return overlapSearch(root->right, i); 
} 

ITNode *findmin(ITNode *root){
	if(root==nullptr){return nullptr;}
	if(root->left==nullptr){return root;}
	return findmin(root->left);
}

void del(ITNode *&root, const Interval & y){
	if(root==nullptr) return;
	if(y.low < root->i->low)
		del(root->left,y);
	else if(y.low > root->i->low)
		del(root->right,y);
	else if(root->left != nullptr && root->right != nullptr){
		cout<<"here:"<<root->i->low<<endl;
		root->i = findmin(root->right)->i;
		cout<<"here:"<<root->i->low<<endl;
//		root->i;
		del(root->right,*(root->i));
	}
	else{
		ITNode * oldNode = root;
		cout<<"here else:"<<oldNode->i->low<<endl;
		root=nullptr;
	//	root=(root->left != nullptr) ? root->left : root->right;
/*		if(root->left != nullptr){
			root=root->left;
		}else if(root->right != nullptr){
			root=root->right;
		}else root=nullptr;*/
		cout<<"hereelse 2:"<<root->i->low<<endl;
		delete oldNode;
//	if(root->i->low==y.low && root->i->high==y.high){
	}
}
void intervalSearch(ITNode *root, Interval x){ 
	if (doOVerlap(*(root->i), x)){ 	
		cout << "\nInterval here [" << root->i->low << ", " << root->i->high << "]"; 
	}

	if (root->left != nullptr && root->left->max >= x.low) {
		intervalSearch(root->left, x); 
	}
	if (root->right != nullptr && root->right->max >= x.low) {
		intervalSearch(root->right, x); 
	}
//	intervalSearch(root->right, x); 
} 

void inorder(ITNode *root){ 
	if (root == nullptr) return; 


	cout << "[" << root->i->low << ", " << root->i->high << "]"
		<< " max = " << root->max << endl; 

	inorder(root->left); 
	inorder(root->right); 

} 
int main(){ 
	Interval ints[] = {{15, 20}, {10, 30}, {17, 19}, 
		{5, 20}, {12, 15}, {30, 40} 
	}; 
	int n = sizeof(ints)/sizeof(ints[0]); 
	ITNode *root = nullptr; 
	for (int i = 0; i < n; i++) 
		root = insert(root, ints[i]); 

	cout << "Inorder traversal of constructed Interval Tree is\n"; 
	inorder(root); 

//	Interval x = {13, 14}; 
	Interval g = {30,40}; 
	cout<<"\nDeleted:"<<endl;
//	cout << "\nSearching for interval [" << x.low << "," << x.high << "]"; 
/*	Interval *res = overlapSearch(root, x); 
	if (res == nullptr) 
		cout << "\nNo Overlapping Interval"; 
	else
		cout << "\nOverlaps with [" << res->low << ", " << res->high << "]"; */

//	intervalSearch(root,x);
	del(root,g);
	cout<<"inorder prinT:!"<<endl;
	inorder(root);
	return 0; 
} 
/*#include <iostream> 
using namespace std; 

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
	temp->left = nullptr;
	temp->right = nullptr; 
}

ITNode *insert(ITNode *root, Interval i){ 
	if (root == nullptr) 
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
	if (root == nullptr) return nullptr; 

	if (doOVerlap(*(root->i), i)) 
		return root->i; 

	if (root->left != nullptr && root->left->max >= i.low) 
		return overlapSearch(root->left, i); 

	return overlapSearch(root->right, i); 
} 

ITNode *findmin(ITNode *root){
	if(root==nullptr){return nullptr;}
	if(root->left==nullptr){return root;}
	return findmin(root->left);
}
*/
/*
void del(ITNode *&root, const Interval & y){
	if(root==nullptr) return;
	if(y.low < root->i->low)
		del(root->left,y);
	else if(y.low > root->i->low)
		del(root->right,y);
	else if(root->left != nullptr && root->right != nullptr){
		cout<<"here:"<<root->i->low<<endl;
		root->i = findmin(root->right)->i;
		cout<<"here:"<<root->i->low<<endl;
//		root->i;
		del(root->right,*(root->i));
	}
	else{
		ITNode * oldNode = root;
		cout<<"here else:"<<oldNode->i->low<<endl;
		root=nullptr;
	//	root=(root->left != nullptr) ? root->left : root->right;
		cout<<"hereelse 2:"<<root->i->low<<endl;
		delete oldNode;
//	if(root->i->low==y.low && root->i->high==y.high){
	}
}
void intervalSearch(ITNode *root, Interval x){ 
	if (doOVerlap(*(root->i), x)){ 	
		cout << "\nInterval here [" << root->i->low << ", " << root->i->high << "]"; 
	}

	if (root->left != nullptr && root->left->max >= x.low) {
		intervalSearch(root->left, x); 
	}
	if (root->right != nullptr && root->right->max >= x.low) {
		intervalSearch(root->right, x); 
	}
//	intervalSearch(root->right, x); 
} 

void inorder(ITNode *root){ 
	if (root == nullptr) return; 


	cout << "[" << root->i->low << ", " << root->i->high << "]"
		<< " max = " << root->max << endl; 

	inorder(root->left); 
	inorder(root->right); 

} 
int main(){ 
	Interval ints[] = {{15, 20}, {10, 30}, {17, 19}, 
		{5, 20}, {12, 15}, {30, 40} 
	}; 
	int n = sizeof(ints)/sizeof(ints[0]); 
	ITNode *root = nullptr; 
	for (int i = 0; i < n; i++) 
		root = insert(root, ints[i]); 

	cout << "Inorder traversal of constructed Interval Tree is\n"; 
	inorder(root); 

//	Interval x = {13, 14}; 
	Interval g = {30,40}; 
	cout<<"\nDeleted:"<<endl;
//	cout << "\nSearching for interval [" << x.low << "," << x.high << "]"; 
	Interval *res = overlapSearch(root, x); 
	if (res == nullptr) 
		cout << "\nNo Overlapping Interval"; 
	else
		cout << "\nOverlaps with [" << res->low << ", " << res->high << "]"; 

//	intervalSearch(root,x);
	del(root,g);
	cout<<"inorder prinT:!"<<endl;
	inorder(root);
	return 0; 
} 
*/
