#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>adj[N];
bool visited[N];
void bfs(int s)
{
    queue<int>q;
    q.push(s);
    visited[s]=true;
    while(!q.empty())
    {
        int p=q.front();
        cout<<p<<" "<<endl;
        q.pop();
        for(int v:adj[p])
        {
            if(visited[v]) continue;
            q.push(v);
            visited[v]=true;
        }
    }
}
int main()
{
       int m,n;
      cout<<"Enter number of node and edges:"<<endl;
      cin >> m >> n;
      cout<<"Enter Edge connection:\n";
      for(int i=0;i<n;i++)
    {

        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<"Enter source node:";
    int s;
    cin>>s;
    cout<<"BFS:";
    bfs(s);
    return 0;
}
