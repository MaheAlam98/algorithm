#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
 vector<vector<int>>adj(N);
 vector<int>in_degree(N);
int main()
{
      int n,m;
      cin>>n>>m;
      int cnt=0;
      while(m--)
      {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        /*u--->v*/
        in_degree[v]++;

      }
      queue<int>q;
      for(int i=0;i<n;i++)
      {
        if(in_degree[i]==0)
        {
            q.push(i);
        }

      }

      while(!q.empty())
      {
        cnt++;
        int p=q.front();
        q.pop();
        cout<<p<<" ";
      for(auto v:adj[p])
      {
        in_degree[v]--;
        if(in_degree[v]==0){
            q.push(v);
        }
      }
      }

    return 0;
}
