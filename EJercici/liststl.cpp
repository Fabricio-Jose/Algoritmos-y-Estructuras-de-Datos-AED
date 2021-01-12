#include <iostream> 
#include <list> 
#include <iterator> 
using namespace std; 

//function for printing the elements in a list 
void showlist(list <int> g) 
{ 
	list <int> :: iterator it; 
	for(it = g.begin(); it != g.end(); ++it) 
		cout << '\t' << *it; 
	cout << '\n'; 
} 
template <typename Object>
void printLots(list <Object> L, list<int> P){
	typename list < int > ::iterator pIter ;
	typename list < Object >::iterator lIter ;
	int start = 0;
	lIter = L.begin();
	for (pIter=P.begin(); pIter != P.end() && lIter != L.end(); pIter++){
		while (start < *pIter && lIter != L.end()){
			start++;
			lIter++;
		}
		if (lIter !=L.end()) cout<<*lIter<<endl;
	}
}
template <typename Iterator, typename Object>
int find(Iterator start, Iterator end,  Object x){	
	Iterator iter = start;
	int p=0;
	while ( iter != end && *iter != x){
		p++;
		iter++;}
	return p;
}


template <typename Object>
list<Object> listUnion( const list<Object> & L1,const list<Object> & L2){
	list<Object> result;
	typename list<Object>:: const_iterator iterL1 = L1.begin();
	typename list<Object>:: const_iterator iterL2= L2.begin();
	while(iterL1 != L1.end() && iterL2 != L2.end()){
		if (*iterL1 == *iterL2){
			result.push_back(*iterL1);
			iterL1++;
			iterL2++;
		}
		else if (*iterL1 < *iterL2){
			result.push_back(*iterL1);
			iterL1++;
		}
		else{
			result.push_back(*iterL2);
			iterL2++;
		}
	}
	return result;
}


template <typename Object>
list<Object> intersection( const list<Object> & L1,
const list<Object> & L2)
{
list<Object> intersect;
typename list<Object>:: const_iterator iterL1 = L1.begin();
typename list<Object>:: const_iterator iterL2= L2.begin();
while(iterL1 != L1.end() && iterL2 != L2.end())
{
if (*iterL1 == *iterL2)
{
intersect.push_back(*iterL1);
iterL1++;
iterL2++;
}
else if (*iterL1 < *iterL2)
iterL1++;
else
iterL2++;
}
return intersect;
}

int main() 
{ 

	list <int> gqlist1, gqlist2; 


	for (int i = 0; i < 10; ++i) 
	{ 
 		gqlist2.push_back(i*2); 
	} 
	for(int i=0;i<6;i++){
		gqlist1.push_back(i*3);
	}
	cout << "\nList 1 (gqlist1) is : "; 
	showlist(gqlist1); 

	cout << "\nList 2 (gqlist2) is : "; 
	showlist(gqlist2); 
	
	printLots(gqlist1,gqlist2);

/*	cout << "\ngqlist1.front() : " << gqlist1.front(); 
	cout << "\ngqlist1.back() : " << gqlist1.back(); 

	cout << "\ngqlist1.pop_front() : "; 
	gqlist1.pop_front(); 
	showlist(gqlist1); 

	cout << "\ngqlist2.pop_back() : "; 
	gqlist2.pop_back(); 
	showlist(gqlist2); 

	cout << "\ngqlist1.reverse() : "; 
	gqlist1.reverse(); 
	showlist(gqlist1); 

	cout << "\ngqlist2.sort(): "; 
	gqlist2.sort(); 
	showlist(gqlist2); */
	
/*	typename list <int>::iterator pIter ;
	typename list <int>::iterator lIter ;
	typename list <int>::iterator l ;
	lIter=gqlist2.begin();
	pIter=gqlist2.end();
	cout<<find(lIter,pIter,8);*/

	cout<<"la union es: ";
	showlist(listUnion(gqlist1,gqlist2));
	cout<<endl<<"la interseccion es: ";
	showlist(intersection(gqlist1,gqlist2));
	cout<<endl;
	return 0; 

} 

