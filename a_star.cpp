#include <bits/stdc++.h>
using namespace std;

void AStar(int start,int goal,vector<vector<pair<int,int>>>& adj,vector<int>& h){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> g(adj.size(),INT_MAX);
    vector<int> parent(adj.size(),-1);
    g[start]=0;
    pq.push({h[start],start});
    while(!pq.empty()){
        int node=pq.top().second;
        pq.pop();
        if(node==goal) break;
        for(auto it:adj[node]){
            int neigh=it.first;
            int cost=it.second;
            if(g[node]+cost<g[neigh]){
                g[neigh]=g[node]+cost;
                parent[neigh]=node;
                pq.push({g[neigh]+h[neigh],neigh});
            }
        }
    }
    vector<int> path;
    for(int v=goal;v!=-1;v=parent[v]) path.push_back(v);
    reverse(path.begin(),path.end());
    cout<<"Path: ";
    for(auto x:path) cout<<x<<" ";
    cout<<"\nCost: "<<g[goal];
}

int main(){
    int n=6;
    vector<vector<pair<int,int>>> adj(n+1);
    adj[1]={{2,1},{3,4}};
    adj[2]={{4,2},{5,5}};
    adj[3]={{5,1}};
    adj[4]={{6,7}};
    adj[5]={{6,3}};
    vector<int> h={0,7,6,2,1,1,0};
    int start=1,goal=6;
    AStar(start,goal,adj,h);
}