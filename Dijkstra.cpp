#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
vector<pair<int,int>>adj[N];
int dis[N];
int p[N];
void dijkstra(int s)
{
    queue<int>q;
    q.push(s);
    dis[s]=0;
    while(!q.empty())
    {
        int parent=q.front();
        q.pop();
        for(int i=0;i<adj[parent].size();i++)
        {
            pair<int,int> child=adj[parent][i];
            int childNode=child.first;
            int cost=child.second;
            if(dis[parent]+cost < dis[childNode])
            {
                dis[childNode]=dis[parent]+cost;
                q.push(childNode);
                p[childNode]=parent;

            }

        }


    }

}
int main()
{

    int n,e;
    cout<<"Enter the number of node and edge:";
    cin>>n>>e;
    cout<<"Enter the edges and its weight:\n";
    for(int i=0;i<e;i++)
    {

        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});

    }
    int s;
    cout<<"Enter the source node\n";
    cin>>s;
    for(int i=0;i<N;i++)
    {

        dis[i]=INT_MAX;
    }
    dijkstra(s);
    
    vector<ll> path;
    ll node = n;
    while (p[node] != node) {
        path.push_back(node);
        node = p[node];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());
    ll cost = 0;
    for(ll i = 0; i < path.size()-1; i++)
    {
        for(auto j : adj[path[i]])
        {
            if(j.first == path[i+1]) cost += j.second;
        }
    }
    cout << "Shortest path: ";
    for (ll i = 1; i < path.size(); i++) {

        cout << path[i] << " ";
    }
    cout << endl;
    cout << "Total Cost: " << cost << endl;

}
