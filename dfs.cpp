#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>adj[N];
bool visited[N];
void dfs(int s)
{
    visited[s]=true;
    cout<<s<<" ";
    for(int v:adj[s])
    {
      if(visited[v]==true) continue;
      dfs(v);
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
    cout<<"DFS:";
    dfs(s);

    return 0;
}

