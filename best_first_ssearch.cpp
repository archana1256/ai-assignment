#include <bits/stdc++.h>
using namespace std;

void bestFirstSearch(int start,int goal,vector<vector<int>>& adj,vector<int>& h){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> visited(adj.size(),0);
    pq.push({h[start],start});
    visited[start]=1;
    while(!pq.empty()){
        int node=pq.top().second;
        pq.pop();
        cout<<node<<" ";
        if(node==goal) return;
        for(auto it:adj[node]){
            if(!visited[it]){
                visited[it]=1;
                pq.push({h[it],it});
            }
        }
    }
}

int main(){
    int n=6;
    vector<vector<int>> adj(n+1);
    adj[1]={2,3};
    adj[2]={1,4,5};
    adj[3]={1,6};
    adj[4]={2};
    adj[5]={2};
    adj[6]={3};
    vector<int> heuristic={0,7,6,2,1,0,3};
    int start=1,goal=5;
    bestFirstSearch(start,goal,adj,heuristic);
}