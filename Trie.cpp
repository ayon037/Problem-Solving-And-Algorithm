#include<bits/stdc++.h>
using namespace std;
struct Trie
{
    Trie *children[26];
    int EoW;
};
Trie *root;

int relPos(char ch)
{
    int i=(int)ch;
    return i-97;
}

Trie *createNode()
{
    Trie *n=(Trie*)malloc(sizeof(Trie));
    for(int i=0;i<26;i++)
    {
        n->children[i]=NULL;
    }
    n->EoW=0;
    return n;
}

void createEdge(Trie *u,Trie *v,char ch)
{
    int r=relPos(ch);
    u->children[r]=v;
}

void Insert(string x)
{
    Trie *u=root;
    int len=x.size();

    for(int i=0;i<len;i++)
    {
        char ch=(char)x[i];
        int r=relPos(ch);
        if(u->children[r]==NULL)
        {
            createEdge(u,createNode(),ch);
            u=u->children[r];
        }
    }
    u->EoW++;
}

void printTrie(Trie *u=root,string s="")
{
    if(u->EoW==1)
    {
        cout<<s<<endl;
        //return;
    }
    for(int i=0;i<26;i++)
    {
        if(u->children[i]!=NULL)
        {
            char ch=(char)(i+97);
            printTrie(u->children[i],s+ch);
        }
    }
}

int Search(string str,Trie *cur=root,int i=0)
{
    if(cur==NULL)
    {
        return 0;
    }

    if(i==str.size())
    {
        if(cur->EoW==0)
            return 0;
        return 1;
    }

    int c=(char)str[i];
    int r=relPos(c);
    return Search(str,cur->children[r],i+1);
}

bool isLeaf(Trie *u)
{
    for(int i=0; i<26; i++) if(u->children[i]!=NULL) return false;
    return true;
}


void removeEdge(Trie *u,char ch,int d)
{
    if(d==0)
        return;
    int r=relPos(ch);
    Trie *v=u->children[r];
    u->children[r]=NULL;
    free(v);
}



bool isJunction(Trie *u)
{
    if(u->EoW==1)
        return true;
    if(isLeaf(u))
        return false;
    return true;
}

int Delete(string key,Trie *u=root,int i=0)
{
    if(u==NULL)
        return 0;
    if(i==key.size())
    {
        if(u->EoW==1)
            return 0;
        if(isLeaf(u)==false)
        {
            u->EoW=0;
            return 0;
        }
        return 1;
    }

    int r=relPos(key[i]);
    int d=Delete(key,u->children[r],i+1);
    removeEdge(u,key[i],d);
    if(isJunction(u)==true)
    {
        d=0;
    }
    return d;

}

int main()
{
    root = createNode();
    int n;
    cin>>n;
    while(n--)
    {

        string x;
        cin>>x;
        Insert(x);
    }
    printTrie();

}