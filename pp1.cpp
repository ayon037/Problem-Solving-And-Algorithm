#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cin.exceptions(ios::badbit|ios::failbit)
#define TC() LL T; cin>>T; for(LL tc=1; tc<=T; tc++)


struct Trie
{
    struct tnode
    {
        int we=0;
        int val=-1;
        char c=0;
        string pref="/";
        tnode* child[256]={0};
    };
    tnode* root;
    Trie()
    {
        root=new tnode();
    }
    map<tnode*, bool> vis;
    void dfs(tnode* cur)
    {
        vis[cur]=true;
        if(cur->we>0) cout<<cur->pref<<": "<<cur->val<<"\n";
        for(int i=0; i<256; i++)
        {
            tnode* u=cur->child[i];
            if(u!=nullptr&&!vis[u]) dfs(u);
        }
    }
    void ins(string s, int v)
    {
        tnode* cur=root;
        for(int i=0; i<s.size(); i++)
        {
            if(cur->child[s[i]]==nullptr) cur->child[s[i]]=new tnode();
            cur->child[s[i]]->c=s[i], cur->child[s[i]]->pref=s.substr(0, i+1), cur=cur->child[s[i]];
        }
        cur->we++;
        cur->val=v;
    }
    int search(string s)
    {
        tnode* cur=root;
        for(int i=0; i<s.size(); i++)
        {
            if(cur->child[s[i]]==nullptr) return -1;
            cur=cur->child[s[i]];
        }
        // if(cur->we==0) return -1;
        return cur->val;
    }
    bool updt(string s, int v)
    {
        if(search(s)!=-1)
        {
            tnode* cur=root;
            for(int i=0; i<s.size(); i++) cur=cur->child[s[i]];
            dbg(cur->pref);
            return cur->val=v, true;
        }
        return false;
    }
    bool del(string s)
    {
        if(search(s)!=-1)
        {
            tnode* cur=root;
            for(int i=0; i<s.size(); i++) cur=cur->child[s[i]];
            return cur->we=0, cur->val=-1, true;
        }
        return false;
    }
    void print()
    {
        vis.clear();
        dfs(root);
    }
};


int main()
{
    // FIO;

    Trie t;
    while(1)
    {
        int opt; cin>>opt;
        int v; string s;
        if(opt==0) break;
        else if(opt==1) cin>>v>>s, t.ins(s, v);
        else if(opt==2) cin>>s, cout<<t.search(s)<<"\n";
        else if(opt==3) cin>>v>>s, cout<<boolalpha<<t.updt(s, v)<<"\n";
        else if(opt==4) cin>>s, cout<<boolalpha<<t.del(s)<<"\n";
        else if(opt==5) t.print(), cout<<"\n";
    }
}


/*

1
8 mahdi
1
24 adib
1
13 marcus
1
41 adb
1
98 monkey

2
adib
2
monkey
2
asdf
2
mahd

3
75 adib
3
96 monkey
3
55 bleh

5

4
marcus

5

4
abacada

5

0

*/