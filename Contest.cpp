#include<bits/stdc++.h>
using namespace std;
#define Charpoka ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cin.exceptions(ios::badbit|ios::failbit)
#define endl '\n'
#define pb push_back
#define ll long long int
#define mx 100001
int arr[mx];
int tree[4*mx+1];

class Node
{
    public:
        int key;
        Node **forward;
        memset(forward,0,sizeof(Node*));

        Node(int key,int level)
        {
            this->key=key;
            forward=new Node*[level+1];
        }
}

class SkipList
{
    public: 
        int MaxLvl;
        float p;
        int level;
        Node *head;
        int randomLevel()
        {
            float r=rand()/RAND_MAX;
            int levl=0;
            if(r<p && lvl<MaxLvl)
            {
                lvl++;
                r=rand()/RAND_MAX;
            } 
            return lvl;
        }

        int createNode(int x,int level)
        {
            Node *n=newNode
        }
        SkipList(int MaxLvl,float p)
        {
            this->MaxLvl=MaxLvl;
            this->p=p;
            level=0;
            head=new Node(-1,level); 
        }
        void insertElement(int x)
        {
            Node *current=head;
            Node *update[MaxLvl+1];
            memset(update,0,sizeof(Node*)*(MaxLvl));

            for(int i=level;i>=0;i--)
            {
                if(current->forward[i]!=NULL && current->forward[i]->key<x)
                {
                    current=current->forward[i];
                }
                update[i]=current;
            }
            current=current->forward[0];
            if(current==NULL || current->key!=x)
            {
                
            }
            int newlevel;
            newlevel=randomLevel();

            if(newLevel>level)
            {
                for(int i=level+1;i<newlevel;i++)
                {
                    update[i]=head;
                }
                level=newlevel;
            }
            Node *n=createNode(int x,int newlevel);

            for(int i=0;i<level;i++)
            {
                n->forward[i]=update[i]->forward[i];
                update[i]->forward[i]=n;
            } 
        }

        void display()
        {
            Node *current=head;
            for(int i=0;i<level;i++)
            {
                cout<<"Level "<<i<<": "<<endl;
                while(current->forward[i]!=NULL)
                {
                    cout<<current->forward[i]->key<<" ";
                    current=current->forward[i];
                }
                cout<<endl;
            }
        }

}

int main()
{
    Charpoka;
    SkipList lst(4,0.5);
    lst.insertElement(2);
    lst.display();

}