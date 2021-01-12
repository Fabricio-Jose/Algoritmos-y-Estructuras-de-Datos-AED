#include<iostream>

using namespace std;

template <class Type>
struct nodeType
{
	Type info;
	nodeType<Type> *link;	
};

template <class Type>
class linkedListIterator
{   
public:
    linkedListIterator();
    linkedListIterator(nodeType<Type> *ptr);
    Type operator* ();
    linkedListIterator<Type> operator++();
    bool operator==(const linkedListIterator<Type>& right) const;
    bool operator!=(const linkedListIterator<Type>& right) const;
private:
    nodeType<Type> *current;
};

template <class Type>
linkedListIterator<Type>::linkedListIterator()
{
    current = NULL;
}

template <class Type>
linkedListIterator<Type>::linkedListIterator(nodeType<Type> *ptr)
{
    current = ptr;
}

template <class Type>
Type linkedListIterator<Type>::operator*()
{
    return current->info;
}

template <class Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++()
{
    current = current->link;
    return *this;
}

template <class Type>
bool linkedListIterator<Type>::operator==(const linkedListIterator<Type>& right) const
{
    return (current != right.current);
}


template <class Type>
class linkedListType
{
public:
    const linkedListType<Type>& operator=(const linkedListType<Type>&);
    void initializeList();
    bool isEmptyList() const;
    int length() const;
    void destroyList();
    void print() const;
    Type front() const;
    Type back() const;
    virtual bool insertFirst(const Type& newItem) = 0;
    virtual void insertLast(const Type& newItem) = 0;
    virtual void deleteNode(const Type& deleteItem) = 0;
    linkedListIterator<Type> begin();
    linkedListIterator<Type> end();
    linkedListType();
    linkedListType(const linkedListType<Type>& otherList);
    ~linkedListType();
protected:
    int count;
    nodeType<Type> *first;
    nodeType<Type> *last;
private:
    void copyList(const linkedListType<Type>& otherList);
};

template <class Type>
bool linkedListType<Type>::isEmptyList() const
{
    return (first == NULL);
}
template <class Type>
linkedListType<Type>::linkedListType()
{
    first = NULL;
    last = NULL;
    count = 0;
}

template <class Type>
void linkedListType<Type>::destroyList()
{
    nodeType<Type> *temp;
    while (first != NULL){
        temp = first;
        first = first->link;
        delete temp;
    }
    last = NULL;
    count = 0;
}

template <class Type>
void linkedListType<Type>::initializeList()
{
    destroyList();
}

template <class Type>
void linkedListType<Type>::print() const
{
    nodeType<Type> *current;
    current = first;
    while (current != NULL){
        cout<<current->info<<" ";
        current = current->link;
    }
}

template <class Type>
int linkedListType<Type>::length() const
{
    return count;
}

template <class Type>
Type linkedListType<Type>::front() const
{
    assert(first != NULL);
    return first->info;
}

template <class Type>
Type linkedListType<Type>::back() const
{
    assert(last != NULL);
    return last->info;
}

template <class Type>
linkedListIterator<Type> linkedListType<Type>::begin()
{
    linkedListIterator<Type> temp(first);
    return temp;
}

template <class Type>
linkedListIterator<Type> linkedListType<Type>::end()
{
    linkedListIterator<Type> temp(NULL);
    return temp;
}

template <class Type>
void linkedListType<Type>::copyList(const linkedListType<Type>& otherList)
{
    nodeType<Type> *newNode;
    nodeType<Type> *current;
    if (first != NULL)
        destroyList();
    if (otherList.first == NULL){
        first = NULL;
        last = NULL;
        count = 0;
    }
    else{
        current = otherList.first;
        count = otherList.count;
        first = new nodeType<Type>;
        first->info = current->info;
        first->link = NULL;
        last = first;
        current = current->link;
        
        while(current != NULL){
            newNode = new nodeType<Type>;
            newNode->info = current->info;
            newNode->link = NULL;
            last->link = newNode;
            last = newNode;
            current = current->link;
        }
    }
}

template <class Type>
linkedListType<Type>::~linkedListType()
{
    destroyList();
}

template <class Type>
linkedListType<Type>::linkedListType(const linkedListType<Type>& otherList)
{
    first = NULL;
    copyList(otherList);
}

template <class Type>
const linkedListType<Type>& linkedListType<Type>::operator=(const linkedListType<Type>& otherList)
{
    if (this != &otherList){
        copyList(otherList);
    }
    return *this;
}

template <class Type>
class unorderedLinkedList: public linkedListType<Type>
{
public:
    bool search(const Type& searchItem) const;
    void insertFirst(const Type& newItem);
    void insertLast(const Type& newItem);
    void deleteNode(const Type& deleteItem);
};

template <class Type>
bool unorderedLinkedList<Type>::search(const Type& searchItem) const
{
    nodeType<Type> *current;
    bool found = false;
    current = first;
    
    while(current != NULL && !found)
        if(current->info == searchItem)
            found = true;
        else
            current = current->link;
    return found;
}

template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem)
{
    nodeType<Type> *newNode;
    newNode = new nodeType<Type>;
    newNode->info = newItem;
    newNode->link = first;
    first = newNode;
    count++;
    
    if(last == NULL)
        last = newNode;
}

template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type& newItem)
{
    nodeType<Type> *newNode;
    newNode = new nodeType<Type>;
    newNode->info = newItem;
    newNode->link = NULL;
    
    if(first == NULL)
    {
        first = newNode;
        last = newNode;
        count++;
    }
    else
    {
        last->link = newNode;
        last = newNode;
        
        count++;
    }
}

template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current;
    nodeType<Type> *trailCurrent;
    bool found;
    
    if(first == NULL)
        cout<<"Lista vacia."<<endl;
    else
    {
        if(first->info == deleteItem)
        {
            current = first;
            first = first->link;
            count--;
            
            if(first == NULL)
                last = NULL;
            
            delete current;
        }
        else
        {
            found = false;
            trailCurrent = first;
            current = first->link;
            
            while(current != NULL && !found)
            {
                if (current->info != deleteItem)
                {
                    trailCurrent = current;
                    current = current->link;
                }
                else
                    found = true;
            }
            if(found)
            {
                trailCurrent->link = current->link;
                count--;
                
                if(last = current)
                    last = trailCurrent;
                delete current;
            }
            else
                cout<<"El Item a ser borrado no esta en "<<"la lista."<<endl;
        }
    }    
}

template <class Type>
class orderedLinkedList: public linkedListType<Type>
{
public:
    bool search(const Type& searchItem) const;
    void insert(const Type& newItem);
    void insertFirst(const Type& newItem);
    void insertLast(const Type& newItem);
    void deleteNode(const Type& deleteItem);
};

template <class Type>
bool orderedLinkedList<Type>::search(const Type& searchItem) const
{
    bool found = false;
    nodeType<Type> *current;
    current = first;
    
    while(current != NULL && !found)
        if(current->info == searchItem)
            found = true;
        else
            current = current->link;
    if(found)
        found = (current->info == searchItem);
    return found;
}

template <class Type>
void orderedLinkedList<Type>::insert(const Type& newItem)
{
    nodeType<Type> *current;
    nodeType<Type> *trailCurrent;
    nodeType<Type> *newNode;
    
    bool found;
    
    newNode = new nodeType<Type>;
    newNode->info = newItem;
    newNode->link = NULL;
    
    if(first == NULL)
    {
        first = newNode;
        last = newNode;
    }
    else
    {
        current = first;
        found = false;
        
        while (current != NULL && !found)
            if (current->info >= newItem)
                found = true;
            else
            {
                trailCurrent = current;
                current = current->link;
            }
        if (current == first)
        {
            newNode->link = first;
            first = newNode;
            count++;
        }
        else
        {
            trailCurrent->link = newNode;
            newNode->link = current;
            
            if (current == NULL)
                last = newNode;
            count++;
        }
    }
}

template <class Type>
void orderedLinkedList<Type>::insertFirst(const Type& newItem)
{
   insert(newItem);
}

template <class Type>
void orderedLinkedList<Type>::insertLast(const Type& newItem)
{
   insert(newItem);
}

template <class Type>
void orderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current;
    nodeType<Type> *trailCurrent;
    bool found;
    
    if(first == NULL)
        cout<<"Lista vacia."<<endl;
    else
    {
       current = first;
       found = false;
       
       while (current != NULL && !found)
           if (current->info >= deleteItem)
               found = true;
           else
           {
                trailCurrent = current;
                current = current->link;
           }
        if (current == NULL)
            cout<<"EL Item a borrar no esta en la lista."<<endl;
        else
            if (current->info == deleteItem)
            {
                if(first == current)
                {
                    first = first->link;
                    
                    if(first == NULL)
                        last = NULL;
                    delete current;
                }
                else
                {
                    trailCurrent->link = current->link;
                    
                    if (current == last)
                        last = trailCurrent;
                    delete current;
                }
                count--;
            }
            else
                cout<<"El Item a ser borrado no esta en la lista."<<endl;
    }    
}
int main(){
    
    orderedLinkedList<int> list1, list2;
    int num;
    
    cout<<"Line 7: Enter numbers ending with -999."<<endl;
    cin>>num;
    
    while(num != -999){
        list1.insert(num);
        cin>>num;
    }
    
    cout<<endl;
    
    cout<<"Line 15: list1 ";
    list1.print();
    cout<<endl;
    
    list2 = list1;
    list2.print();
    cout<<endl;
    
    cout<<"Line 22: Enter the number to be deleted: ";
    cin>>num;
    cout<<endl;
    
    list2.deleteNode(num);
    
    cout<<"Line 26: After deleting "<<num<<", list2: "<<endl;
    list2.print();
    cout<<endl;
    
    return 0;
}
