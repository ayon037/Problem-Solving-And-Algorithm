#include<bits/stdc++.h>
using namespace std;
int tree[5*1000];
int arr[1001];
void build(int node,int begin,int end)
{
    if(begin==end)
    {
        tree[node]=arr[begin];
        return;
    }
    int left=node*2;
    int right=left+1;
    int mid=(begin+end)/2;
    build(left,begin,mid);
    build(right,mid+1,end);
    tree[node]=tree[left]+tree[right];
}

int query(int node,int begin,int end,int start,int finish)
{
    if(start>end || finish<begin)
    {
        return 0;
    }
    if(begin>=start && end<=finish)
    {
        return tree[node];
    }
    int left=node*2;
    int right=left+1;
    int mid=(begin+end)/2;
    int p1=query(left,begin,mid,start,finish);
    int p2=query(right,mid+1,end,start,finish);
    return p1+p2;
}

void update(int node,int begin,int end,int index,int value)
{
    if(index>end || index<begin)
    {
        return;
    }
    if(begin>=index && end<=index)
    {
        tree[node]=value;
        return;
    }
    int left=node*2;
    int right=left+1;
    int mid=(begin+end)/2;
    update(left,begin,mid,index,value);
    update(right,mid+1,end,index,value);
    tree[node]=tree[left]+tree[right];
}

int main()
{
    int n;
    cin>>n;
    //int arr[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    build(1,1,n);
    int q;
    cin>>q;
    while(q--)
    {
        int idx1,idx2;
        cin>>idx1>>idx2;
        int ans=query(1,1,n,idx1,idx2);
        cout<<ans<<endl;
    }
    return 0;
}