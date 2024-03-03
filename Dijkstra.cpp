#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<pair<int,int>>adj[N];
int dis[N];
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
    for(int i=1;i<=n;i++)
    {

        cout<<"node"<<i<<":"<<dis[i]<<endl;
    }
}
