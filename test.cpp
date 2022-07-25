#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define Charpoka ios_base::sync_with_stdio(false), cin.tie(NULL),cout.tie(NULL)
#define err 10e-8
#define pb push_back
#define MAX 40000
#define MOD 1e9+7
#define base 10
#define NULL_VALUE -99999
#define endl "\n"
//#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define oset tree< pair<int,int>, null_type,less< pair<int,int> >, rb_tree_tag,tree_order_statistics_node_update>
#define omultiset tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define MX 20000005
typedef long long int ll;
map<char,bool>mp;
struct Trie
{
    struct Trie *child[26];
    bool EoW;
    Trie()
    {
        memset(child,0,sizeof(child));
        EoW=false;
    }
};

struct Trie2
{
    unordered_map<char,Trie2*>mp;
    bool isEnd;
    Trie2()
    {
        isEnd=false;
    }
};

struct Trie *root;
struct Trie2 *root2;

void Insert(string str)
{
    struct Trie *cur=root;
    for(char ch:str)
    {
        int idx=ch-'a';
        if(cur->child[idx]==NULL)
        {
            cur->child[idx]=new Trie;
        }
        cur=cur->child[idx];
    }
    cur->EoW=true;
}

bool Search(string str)
{
    struct Trie *cur=root;
    for(char ch:str)
    {
        int idx=ch-'a';
        if(cur->child[idx]==NULL)
            return false;
        cur=cur->child[idx];
    }
    return cur->EoW;

}

void Insert2(string str)
{
    struct Trie2 *cur=root2;
    for(char ch:str)
    {
        if(!cur->mp.count(ch))
        {
            cur->mp[ch]=new Trie2;
        }
        cur=cur->mp[ch];
    }
    cur->isEnd=true;
}

bool Search2(string str)
{
    struct Trie2 *cur=root2;
    for(char ch:str)
    {
        if(!cur->mp.count(ch))
            return false;
        cur=cur->mp[ch];
    }
    return cur->isEnd;
}

bool delete2(char *str)
{
    struct Trie2 *cur=root2;
    if(cur==NULL)
        return false;
    if(cur!=NULL && cur->mp.find(*str)!=cur->mp.end() && delete2(cur->mp[*str]))
}
int main()
{
    Charpoka;
    root=new Trie;
    root2=new Trie2;
    int n;
    cin>>n;
    while(n--)
    {
        string s;
        cin>>s;
        Insert2(s);
    }
    cin>>n;
    while(n--)
    {
        string s;
        cin>>s;
        if(Search2(s)==true)
        {
            cout<<s<<" is present"<<endl;
        }
        else
        {
            cout<<s<<" isn't present"<<endl;
        }
    }
}