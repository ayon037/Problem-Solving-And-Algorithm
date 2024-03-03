#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cin.exceptions(ios::badbit|ios::failbit)
#define TC() LL T; cin>>T; for(LL tc=1; tc<=T; tc++)


const int MX=1e3+123;
const LL inf=1e18+123;
// vector<pair<string,LL> > adj[MX];
map<string, vector<pair<string, LL> > > adj;
map<string, LL> dist;
map<string, string> par;

void diks(string src)
{
    for(const pair<string, vector<pair<string, LL> > >& p:adj) dist[p.first]=inf, par[p.first]="/";
    dist[src]=0;
    priority_queue<pair<LL,string>, vector<pair<LL,string> >, greater<> > pq;
    pq.push({0,src});
    while (pq.size())
    {
        LL curD=pq.top().first;
        string curN=pq.top().second;
        pq.pop();
        if(curD>dist[curN]) continue;
        for(int i=0; i<adj[curN].size(); i++)
        {
            string v=adj[curN][i].first;
            LL w=adj[curN][i].second;
            if(curD+w<dist[v]) dist[v]=curD+w, par[v]=curN, pq.push({dist[v],v});
        }
    }
}


int main()
{
    int n; cin>>n;
    while (n--)
    {
        string u,v; cin>>u>>v;
        LL w=(u.size()+v.size())*100;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    string s,t; cin>>s>>t;
    diks(s);
    if(dist[t]==inf) cout<<-1<<"\n";
    else cout<<dist[t]<<"\n";
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