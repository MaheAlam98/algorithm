#include<bits/stdc++.h>
using namespace std;
void topologySort(vector<vector<int>>& graph, vector<bool>& visited, int curr, stack<int>& st) {
    if(visited[curr]) return ;
    visited[curr] = true;
    for(auto v:graph[curr]) {
        if(!visited[v]){
            topologySort(graph,visited,v,st);
        }
    }
    st.push(curr);
}
void dfs(vector<vector<int>>& graph, vector<bool>& visited, int curr) {
    if(visited[curr])  return;
    visited[curr] = true;
    cout << curr << " " ;
    for(auto v:graph[curr]) {
        // cout << v << endl;
        if(!visited[v]){
            dfs(graph,visited,v);
        }
    }
}
int main() {
    int v, i, n,src,dst;
    cout << "Enter number of vertices:";
    cin >> v;
    vector<vector<int>> graph(v+1), rev_graph(v+1);
    cout << "Enter number of edges and edges:";
    cin >> n;
    for(i=0; i<n; i++) {
        cin >> src >> dst;
        graph[src].push_back(dst);
        rev_graph[dst].push_back(src);
    }
    vector<bool>visited(v+1,false);
    int start;
    cout << "Start :";
    cin >> start;
    stack<int>st;
    topologySort(graph,visited,start,st);
    visited = vector<bool>(v+1,false);
       int scc=0;
    while(!st.empty()){

        if(!visited[st.top()]){
            dfs(rev_graph,visited,st.top());
            cout << endl;
            scc++;
        }
        st.pop();
    }
    cout<<"total scc:"<<scc<<endl;

}
