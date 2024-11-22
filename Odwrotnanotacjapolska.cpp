#include <iostream>
using namespace std;
int t[8]={1,2,2,3,2,3,2,2};
int tdl[16];
int main()
{
    for (int i = 0; i < 8; i++)
    {
        tdl[i+8]=t[i];
    }
    for (int i = 7; i >0; i--)
    {
        tdl[i]=tdl[2*i]+tdl[2*i+1];
    }
    for (int i = 0; i < 16; i++)
    {
        cout<<tdl[i]<<" ";
    }

int n,d,k,j;
cin>>n;
for (int i = 0; i < n; i++)
{
    cout<<"podaj ktory ";
    cin>>k; j=k+7;
    cout<<"podaj o ile";
    cin>>d;
    tdl[j]+=d;
    while(j>1)
    {
        j=j/2;
        tdl[j]+=d;
    }
}
for (int i = 0; i < 16; i++)
    {
        cout<<tdl[i]<<" ";
    }
    return 0;
}
