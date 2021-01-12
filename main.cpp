#include <iostream>
#include <vector>

using namespace std;


class DisjSets
{
public:
    explicit DisjSets(int numELements);
    int find(int x)const;
    int find(int x);
    void unionSets(int root1, int root2);

private:
    vector<int> s;
};

DisjSets::DisjSets(int numElements):s{numElements,-1}
{
}

void DisjSets::unionSets(int root1, int root2)
{
    s[root2] = root1;
}

int DisjSets::find(int x)const
{
    if(s[x]<0)
        return x;
    else
        return find(s[x]);
}
/*
void DisjSets::unionSets(int root1, int root2)
{
    if(s[root2]<s[root1])
        s[root1]=root2;
    else
    {
        if(s[root1]==s[root2])
            --s[root1];
        s[root2]=root1;
    }
}

int DisjSets::find(int x){
    if(s[x]<0)
        return x;
    else
        return s[x]=find(s[x]);
}
*/
int main()
{
    DisjSets s(5);
    s.unionSets(0,2);
    s.unionSets(4,2);
    s.unionSets(3,1);
    //for(int i = 0;i<5;i++){
      //  cout<<s[i]<<" ";
    //}

    return 0;
}
