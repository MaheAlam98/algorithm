#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>adj[N];
int main()
{
      int m,n;
      cout<<"Enter number of node and edges:"<<endl;
      cin >> m >> n;
      for(int i=0;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back[v];
        
        adj[v].push_back[u];
    }

    return 0;
}
