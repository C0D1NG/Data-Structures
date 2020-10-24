#include <iostream>
#include <vector>
using namespace std;

vector<int>postorder(vector<int> pre,int si,int ei){
  if(si==ei){
      vector<int> lst(1);
      lst[0]=pre[si];
      return lst;
  }
  else if(si>ei){
      vector<int> lst(0);
      return lst;
  }


int i;
for(i=si;i<=ei;i++){
    if(pre[i]>pre[si])break;
}

vector<int> lip=postorder(pre,si+1,i-1);
vector<int> rip=postorder(pre,i,ei);
vector<int> final(ei-si+1);

for(int j=0;j<lip.size();j++){
    final[j]=lip[j];
}
int k;

 k=lip.size();

for(int j=0;j<rip.size();j++){
    final[k]=rip[j];
    k++;
}

final[ei-si]=pre[si];

return final;



}


int main(){
int n;
cout<<"enter no.of elements"<<endl;
cin>>n;
vector<int> tree(n);
cout<<"enter elements"<<endl;
for(int i=0;i<n;i++)cin>>tree[i];
vector<int> ans=postorder(tree,0,n-1);
for(int i=0;i<n;i++){
    cout<<ans[i]<<endl;
}

}
