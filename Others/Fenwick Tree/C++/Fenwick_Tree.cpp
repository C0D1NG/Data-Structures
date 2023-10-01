#include<bits/stdc++.h>
using namespace std;

int n=1000;
vector<int> tree(n+1, 0);

void update(int i, int delta){
  i++;
  for(;i<=n;i+=i&-i){
    tree[i]+=delta;
  }
}

int query(int i){
  i++;
  int sum=0;
  for(;i>0;i-=i&-i){
    sum+=tree[i];
  }
  return sum;
}

int main(){
  update(5,10);
  cout<<"data[5]+=10"<<endl;
  update(7,3);
  cout<<"data[7]+=3"<<endl;
  cout<<"sum 0-5:"<<query(5)<<endl;
  cout<<"sum 0-6:"<<query(6)<<endl;
  cout<<"sum 0-7:"<<query(7)<<endl;
  update(6,-13);
  cout<<"data[6]+=-13"<<endl;
  cout<<"sum 0-5:"<<query(5)<<endl;
  cout<<"sum 0-6:"<<query(6)<<endl;
  cout<<"sum 0-7:"<<query(7)<<endl;
}
