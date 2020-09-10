#include <iostream>
#include <cmath>
#include <stdio.h>
#include <cstdlib>



using namespace std;


class Pair{
    char keyA[100];
    int valueA[100];
    int index;
    int size;

public:
Pair()
{  
    size=100;
    index=0;
    
}
void insert(char key,int val);
int getVal(char key);
};
 
void Pair::insert(char key,int val)
{
    keyA[index]=key;
    valueA[index]=val;
    index++;

}
 int Pair::getVal(char key)
 {
     for(int i=0;i<index;i++){
        if(keyA[i]==key){return valueA[i];}
     }
 }
 