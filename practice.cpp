#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int>vi;
typedef vector<ll>vl;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef pair<string,string>pss;
typedef pair<string,int>psi;
typedef pair<int,string>pis;
typedef vector<pii>vii;
typedef vector<pll>vll;
typedef vector<pss>vss;
typedef vector<psi>vsi;
typedef vector<pis>vis;


#define endl '\n'
#define pb push_back
#define F first
#define S second


const int inf=10000000;
const ll infLL=1000000000000;

#define Charpoka ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int mx=100;
map<string,int>dist;
map<string,vsi>adj;
map<string,bool>place;
map<string,bool>::iterator it;
void dijkstra(string s,int n)
{
    for(it=place.begin();it!=place.end();it++)
    {
        dist[it->first]=inf;
    }
    dist[s]=0;
    priority_queue<pis,vis,greater<pis>>pq;
    pq.push({0,s});
    while(!pq.empty())
    {
        string u=pq.top().S;
        int curD=pq.top().F;
        pq.pop();

        if(dist[u]<curD) continue;
        for(auto p:adj[u])
        {
            string v=p.F;
            int w=p.S;
            if(curD+w<dist[v])
            {
                dist[v]=curD+w;
                pq.push({dist[v],v});
            }
        }

    }
}
int main()
{
    Charpoka;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s1;
        string s2;
        int w;
        cin>>s1>>s2;
        w=s1.size()+s2.size();
        place[s1]=true;
        place[s2]=true;
        adj[s1].pb({s2,w*100});
    }

    string s1,s2;
    cin>>s1>>s2;
    dijkstra(s1,n);
    for(it=place.begin();it!=place.end();it++)
    {
        if(it->F==s2)
        {
            cout<<dist[it->first]<<endl;
            break;
        }
        
    }
    return 0;
}

/*

6
school pochinki
rozhok georgopol
rozhok school
georgopol stalber
school stalber
stalber lipovka
rozhok stalber

*/