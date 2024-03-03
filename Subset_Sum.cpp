#include<bits/stdc++.h>
using namespace std;
#define Charpoka ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cin.exceptions(ios::badbit|ios::failbit)
#define endl '\n'
#define pb push_back
#define ll long long int
#define mx 100001
#define infinity 1<<30

//int n=4;
//int arr[n];

int n,arr[]={10,5,7,8,22,6,12};
bool bul[7]={};

/*void func(string str)
{
   if(str.size()==n)
   {
      cout<<str<<endl;
      return;
   }
   for(int i=0;i<n;i++)
   {
      int f=0;
      char c='A'+i;
      for(int j=0;str[j];j++)
      {
         if(str[j]==c)
            f++;
      }
      if(f==0)
      {
         func(str+c);
      }
   }
   return;
}*/

void sum(int ind,int ekhn_porjonto_jogfol)
{
   if(ind==7)
   {
      if(ekhn_porjonto_jogfol==n)
      {
         for(int i=0;i<7;i++)
         {
            if(bul[i])
               cout<<arr[i]<<" ";
         }
         cout<<endl;
      }
      
      
      return;
   }
   for(int i=0;i<2;i++)
   {
      bul[ind]=(bool)i;
      sum(ind+1,ekhn_porjonto_jogfol+i*arr[ind]);
   }
   return;
}


int main()
{
   Charpoka;
   cin>>n;
   sum(0,0);

}