#include<bits/stdc++.h>
using namespace std;

void build(int node,int L,int R,float c[],float g[],float tree1[],float tree2[])
{
    if(L==R)
    {
        tree1[node]=c[L];
        tree2[node]=(c[L]*g[L])/tree1[node];
        //cout<<"Tree1: "<<tree1[node]<<endl;
        //cout<<"Tree2: "<<tree2[node]<<endl;
        return;
    }

    int left=node*2;
    int right=left+1;
    int mid=(L+R)/2;
    build(left,L,mid,c,g,tree1,tree2);
    build(right,mid+1,R,c,g,tree1,tree2);
    tree1[node]=tree1[left]+tree1[right];
    tree2[node]=(tree2[left]*tree2[right])/tree1[node];
    //cout<<"Tree1: "<<tree1[node]<<endl;
    //cout<<"Tree2: "<<tree2[node]<<endl;
}


float query(int node,int L,int R,float tree2[],int p,int q)
{
    if(p>R || q<L)
        return 0;
    if(L>=p && R<=q)
        return tree2[node];
    int left=node*2;
    int right=left+1;
    int mid=(L+R)/2;
    float c=query(left,L,mid,tree2,p,q);
    float g=query(right,mid+1,R,tree2,p,q);
    return (c+g)/((float)(p-q+1));
}

int main()
{
    int n;
    cin>>n;
    float c[n+1],g[n+1],tree1[4*n+1],tree2[4*n+1];
    memset(c,0,sizeof(c));
    memset(g,0,sizeof(g));
    memset(tree1,0,sizeof(tree1));
    memset(tree2,0,sizeof(tree2));

    for(int i=1;i<=n;i++)
    {
        cin>>c[i]>>g[i];
    }

    build(1,1,n,c,g,tree1,tree2);

    /*for(int i=1;i<=4*n;i++)
    {
        cout<<tree2[i]<<" ";
    }*/

    int q;
    cin>>q;
    int cnt=1;
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        float p=query(1,1,n,tree2,a,b);
        cout<<"Query - "<<cnt<<": "<<p<<endl;
        cnt++;
    }
    return 0;
    

}

/*

4
20.5 3.25
18 4.0
22 3.67
20 3.81

2
2 4
1 3

*/
