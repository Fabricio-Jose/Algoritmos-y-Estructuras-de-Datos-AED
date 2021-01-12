#include <iostream>
#include <math.h>

struct LHE{
    int key;
    int value;
    LHE *next;
    LHE(int k, int v){
        key = k;
        value = v;
        next = NULL;
    }
};

class Hashmap{
    LHE **table;
//    int counter;
public:
    const int TABLE_SIZE = 10;
    int counter=0;
    Hashmap(){
	counter=0;
        table = new LHE*[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = NULL;
        }
    }

    ~Hashmap(){
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i] != NULL) {
                LHE *preventry = NULL;
                LHE *entry = table[i];
                while (entry != NULL) {
                    preventry = entry;
                    entry = entry->next;
                    delete preventry;
                }
            }
        }
    }

    int get(int key){
        int hash = function(key);
        if (table[hash] == NULL) {
            return -1;
        } else {
            LHE *entry = table[hash];
            while (entry != NULL && entry->key != key)
                entry = entry->next;

            if (entry == NULL)
                return -1;
            else
                return entry->value;
        }
    }

    int linear(int key){
    	int linear;
	linear=key+counter;
	counter++;
	linear=linear % TABLE_SIZE;
	return linear;
    }

    int quatric(int key){
    	int a=counter;
	counter++;
	int x = (key + pow(a,2));
	return x % TABLE_SIZE;
    }
    int function(int key){
    	int hash = key % TABLE_SIZE;
	return hash;
    }
    void insert(int key, int value){
        int hash = function(key);//hash function
        if (table[hash] == NULL) {
            table[hash] = new LHE(key, value);
        } else {
            LHE *entry = table[hash];
            while (entry->next != NULL)
                entry = entry->next;
            if (entry->key == key)
                entry->value = value;
            else
                entry->next = new LHE(key, value);
        }
    }

    void remove(int key){
        int hash = function(key);
        if (table[hash] != NULL) {
            LHE *before = NULL;
            LHE *entry = table[hash];
            while (entry->next != NULL && entry->key != key) {
                before = entry;
                entry = entry->next;
            }
            if (entry->key == key) {
                if (before == NULL) {
                    LHE *next = entry->next;
                    delete entry;
                    table[hash] = next;
                } else {
                    LHE *next = entry->next;
                    delete entry;
                    before->next = next;
                }
            }
        }
    }

    void print(){
        LHE *node;
        for (int i = 0; i < TABLE_SIZE; i++) {
            node = table[i];
            if (node){
                std::cout << node->key <<"-"<< node->value;
                if (node->next) {
                    LHE *inner = node->next;
                    while (inner) {
                        std::cout << " --> " <<inner->key<<"-"<<inner->value ;
                        inner = inner->next;
                    }
                }
            std::cout << '\n';
            }
        }
    }
};

int main(){
    Hashmap hash1;
    hash1.insert(1,10);
    hash1.insert(2,5);
    hash1.insert(3,60);
    hash1.insert(4,6);
    hash1.insert(5,80);
    hash1.insert(6,46);
    hash1.insert(7,33);
    hash1.insert(8,1);
    hash1.insert(9,45);
    hash1.insert(10,6);
    hash1.insert(11,27);
    hash1.insert(12,20);
    hash1.insert(52,6);
    hash1.insert(51,27);
    hash1.insert(54,20);

    hash1.print();
    std::cout << '\n';
//    hash1.remove(4);
//    hash1.remove(51);
    hash1.print();
    std::cout << '\n';

    std::cout << hash1.get(2) <<'\n';
}
