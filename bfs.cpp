#include <bits/stdc++.h>
using namespace std;
int main(){
int n,m;cin>>n>>m;
vector<vector<int>> adj(n+1);
for(int i=0;i<m;i++){int u,v;cin>>u>>v;adj[u].push_back(v);adj[v].push_back(u);}
int start;cin>>start;
vector<int> vis(n+1,0);
queue<int> q;
vis[start]=1;
q.push(start);
while(!q.empty()){
int node=q.front();q.pop();
cout<<node<<" ";
for(auto it:adj[node]){
if(!vis[it]){vis[it]=1;q.push(it);}
}
}
}