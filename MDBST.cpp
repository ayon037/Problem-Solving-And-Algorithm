#include<bits/stdc++.h>
using namespace std;

const int k=2;
struct Node
{
    int point[k];
    Node *left,*right;
};

struct Node* newNode(int arr[])
{
    struct Node* temp = new Node;
    for(int i=0;i<k;i++)
    {
        temp->point[i]=arr[i];
    }
    temp->left=NULL;
    temp->right=NULL;
    return temp;
};

Node *insertRec(Node *root,int point[],int depth)
{
    if(root==NULL)
    {
        return newNode(point);
    }

    int current_dimension=depth%k;
    if(point[current_dimension]<(root->point[current_dimension]))
    {
        root->left=insertRec(root->left,point,depth+1);
    }
    else
    {
        root->right=insertRec(root->right,point,depth+1);
    }
    return root;
}

Node *Insert(Node *root,int point[])
{
    return insertRec(root,point,0);
}

bool arePointSame(int point1[],int point2[])
{
    for(int i=0;i<k;i++)
    {
        if(point1[i]!=point2[i])
        {
            return false;
        }
    }
    return true;
}

bool searchRec(Node* root,int point[],int depth)
{
    if(root==NULL)
    {
        return false;
    }
    if(arePointSame(root->point,point))
    {
        return true;
    }
    int current_dimension=depth%k;
    if(point[current_dimension]<root->point[current_dimension])
    {
        return searchRec(root->left,point,depth+1);
    }
    return searchRec(root->right,point,depth+1);
}

bool Search(Node *root,int point[])
{
    return searchRec(root,point,0);
}

int main()
{
    struct Node *root=NULL;

    int points[][k] = {{3, 6}, {17, 15}, {13, 15}, {6, 12},
                       {9, 1}, {2, 7}, {10, 19}};

    int n=sizeof(points)/sizeof(points[0]);

    for(int i=0;i<n;i++)
    {
        root=Insert(root,points[i]);
    }

    int point1[]={10,19};

    if(Search(root,point1))
    {
        cout<<"Found"<<endl;
    }
    else
    {
        cout<<"Not Found"<<endl;
    }

    int point2[]={12,19};

    if(Search(root,point2))
    {
        cout<<"Found"<<endl;
    }
    else
    {
        cout<<"Not Found"<<endl;
    }

    return 0;
}

