#include<iostream>
#include<stdlib.h>
using namespace std;

class A
{
    int a, b, c;
    public:
     inline void get();
     void put();

};
void A :: get() {
    a = 20 ;
    b = 40 ;
    c = a + b ;
}

void A :: put() {
    cout<< "addition "<<c<<endl;
}

int main(){
   A  d; // create object
   d.get(); 
   d.put();
   return 0;
}
