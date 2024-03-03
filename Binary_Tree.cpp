#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node* left;
    node* right;

    node(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

node* buildTree(node* root)
{
    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;
    root=new node(data);
    if(data==-1)
    {
        return NULL;
    }
    cout<<"Enter data for inserting in left of "<<data<<":"<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter data for inserting in right of "<<data<<":"<<endl;
    root->right=buildTree(root->right);
    return root;
}

void levelOrderTraversal(node* root)
{
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node *temp=q.front();
        q.pop();
        if(temp==NULL) //ager level traverse hoye geche
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<temp->data<<" ";
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

// InOrder - LNR
// PreOrder - NLR
// PostOrder - LRN

void InOrder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}

void PreOrder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void PostOrder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<" ";
}


void buildFromLevelOrder(node* root)
{
    queue<node*>q;
    q.push(root);
    cout<<"Enter data for root:"<<endl;
    int data;
    cin>>data;
    while(!q.empty())
    {
        node *temp=q.front();
        q.pop();
        cout<<"Enter left node for: "<<root->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata!=-1)
        {
            temp->left=new node(leftdata);
            q.push(temp->left);
        }
        cout<<"Enter right node for: "<<root->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata!=-1)
        {
            temp->right=new node(rightdata);
            q.push(temp->right);
        }
    }
}

int main()
{
    node* root=NULL;
    root=buildTree(root);
    cout<<endl<<"Level Order Traversal:"<<endl;
    levelOrderTraversal(root);
    cout<<endl<<"In Order Traversal:"<<endl;
    InOrder(root);
    cout<<endl<<"Pre Order Traversal:"<<endl;
    PreOrder(root);
    cout<<endl<<"Post Order Traversal:"<<endl;
    PostOrder(root);
    cout<<endl<<"Building Tree From Level Order Data"<<endl;
    buildFromLevelOrder(root);
    levelOrderTraversal(root);
    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
// 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
