#include<iostream>
#include<list>
#include<iterator>
using namespace std;

void showlist(list<int>g){
	list <int> :: iterator it; 
	for(it = g.begin(); it != g.end(); ++it) 
		cout << '\t' << *it; 
	cout << '\n'; 
}
int main()
{
	int I,i,j, n, m, mPrime, numLeft;
	list <int > L;
	list<int>::iterator iter;
	//Initialization
	cout<<"enter N (# of people) & M (# of passes before elimination):";
	cin>>n>>m;
	numLeft = n;
	mPrime = m % n;
	for (I =1 ; I <= n; i++)
	L.push_back(i);
	iter = L.begin();
	// Pass the potato
	for (I = 0; I < n; i++)
	{
	mPrime = mPrime % numLeft;
	if (mPrime <= numLeft/2) // pass forward
		for (j = 0; j < mPrime; j++){
			iter++;
			if (iter == L.end())
			iter = L.begin();
		}
	else
	 // pass backward
	for (j = 0; j < mPrime; j++){
		if (iter == L.begin())
			iter = --L.end();
		else
		iter--;
	}
	cout<<*iter<<" ";
	iter= L.erase(iter);
	if (iter == L.end())
	iter = L.begin();
	}
	cout<<endl;




	/*
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
	showlist(gqlist2);**/
	return 0;
}
