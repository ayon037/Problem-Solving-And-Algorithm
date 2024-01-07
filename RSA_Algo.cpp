#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll MX = 1e8;
vector<bool>Prime(MX+1,true);
#define MAX 100000
string str;
ll multiply(ll x,ll res[],ll res_size)
{
    ll carry=0;
    for(int i=0;i<res_size;i++)
    {
        int prod=res[i]*x+carry;
        res[i]=prod%10;
        carry=prod/10;
    }
    while (carry)
    {
        res[res_size]=carry%10;
        carry=carry/10;
        res_size++;
    }
    return res_size;
}

void power(ll x, ll n)
{
    str="";
    if(n==0)
    {
        str="1";
        return;
    }
    ll res[MAX];
    ll res_size = 0;
    ll temp = x;
    while (temp != 0)
    {
        res[res_size++]=temp%10;
        temp=temp/10;
    }
    for(int i=2;i<=n;i++)
        res_size=multiply(x,res,res_size);

    for (int i=res_size-1;i>=0;i--)
    {
        stringstream ss;
        ss<<res[i];
        string s;
        ss>>s;
        str+=s;
    }
}

void PrimeFinder(ll n)
{
    Prime[1]=false;
    for(ll i=2;i*i<=n;i++)
    {
        if(Prime[i]==true)
        {
            for(ll j=i*i;j<=n;j+=i)
            {
                Prime[j]=false;
            }
        }
    }
}
int main()
{
    while(1)
    {
        ll p,q;
        cout<<"Enter two prime numbers: ";
        cin>>p>>q;
        bool f1=true,f2=true;
        PrimeFinder(p);
        PrimeFinder(q);
        if(Prime[p]==false)
            f1=false;
        if(Prime[q]==false)
            f2=false;
        if(f1==false || f2==false)
        {
            cout<<"Current inputs are not valid!!!"<<endl;
            continue;
        }
        ll n=p*q;
        ll euler=(p-1)*(q-1);
        ll e;
        for(ll i=2;i<euler;i++)
        {
            ll gc=__gcd(i,euler);
            if(gc==1)
            {
                e=i;
                break;
            }
        }
        cout<<"Public Key: ("<<e<<" , "<<n<<")"<<endl;
        ll d;
        for(ll i=1;i<n;i++)
        {
            if((i*e)%euler==1)
            {
                d=i;
                break;
            }
        }
        cout<<"Private Key: ("<<d<<" , "<<n<<")"<<endl;
        ll message;
        cout<<endl;
        cout<<"Enter Message: ";
        cin>>message;
        ll ciphertext=0;
        power(message, e);
        for (ll i= 0;i<str.size();i++)
            ciphertext=(ciphertext*10+str[i]-'0')%n;
        cout<<"Encrypted Message: "<<ciphertext<<endl;
        power(ciphertext,d);
        ll plaintext=0;
        for (ll i= 0;i<str.size();i++)
            plaintext=(plaintext*10+str[i]-'0')%n;
        cout<<"Decrypted Message: "<<plaintext<<endl;
        break;
    }

    return 0;
}
