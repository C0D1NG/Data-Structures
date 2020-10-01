#PROBLEM:NAIVE PATTERN SEARCHING


Input:  txt[] = "THIS IS A TEST TEXT"
        pat[] = "TEST"
Output: Pattern found at index 10

Input:  txt[] =  "AABAACAADAABAABA"
        pat[] =  "AABA"
Output: Pattern found at index 0
        Pattern found at index 9
        Pattern found at index 12
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void search(char* pat, char* txt)
{
    
    int m=strlen(txt);
    int n=strlen(pat);
    int k=0;
    for(int i=0;i<m;i++)
    {
        if(pat[0]==txt[i])
        {
            k=i;
            int flag=0;    
            for(int j=1;j<n;j++)
            {
                if(pat[j]==txt[i+j])
                {
                    continue;
                }
                else
                {
                    flag=1;
                    break;
                }
            
            }
            if(flag==0)
            {
                cout<<"present at index "<<k<<endl;
            }
        }
        
    }
}

int main()
{
    char txt[] ="AAAAAAAAAAAAAAAAAB";
    char pat[] = "AAAAB";
    search(pat, txt);
    return 0;
}
