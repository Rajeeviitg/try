#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> adj[1001];
int dist[1001];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        dist[i]=INT_MAX;
    }
    while(m--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int source;
    cin>>source;
    set<pair<int,int>> s;
    dist[source]=0;
    s.insert({0,source});
    while(s.size())
    {
        auto x=*(s.begin());
        s.erase(x);
        for(auto it:adj[x.second])
        {
          if(dist[it.first]>dist[x.second]+it.second)
          {
              s.erase({dist[it.first],it.first});
              dist[it.first]=dist[x.second]+it.second;
              s.insert({dist[it.first],it.first});
          }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<dist[i]<<endl;
    }
    return 0;

}