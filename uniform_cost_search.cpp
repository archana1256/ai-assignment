#include <bits/stdc++.h>
using namespace std;

void UCS(int start,int goal,vector<vector<pair<int,int>>>& adj){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> cost(adj.size(),INT_MAX);
    vector<int> parent(adj.size(),-1);

    pq.push({0,start});
    cost[start]=0;

    while(!pq.empty()){
        auto top=pq.top();
        pq.pop();

        int currCost=top.first;
        int node=top.second;

        if(node==goal) break;

        for(auto it:adj[node]){
            int neigh=it.first;
            int weight=it.second;

            if(currCost+weight < cost[neigh]){
                cost[neigh]=currCost+weight;
                parent[neigh]=node;
                pq.push({cost[neigh],neigh});
            }
        }
    }

    vector<int> path;
    for(int v=goal;v!=-1;v=parent[v]) path.push_back(v);
    reverse(path.begin(),path.end());

    cout<<"Path: ";
    for(auto x:path) cout<<x<<" ";
    cout<<"\nCost: "<<cost[goal];
}

int main(){
    int n=6;
    vector<vector<pair<int,int>>> adj(n+1);

    adj[1]={{2,1},{3,4}};
    adj[2]={{4,2},{5,5}};
    adj[3]={{5,1}};
    adj[4]={{6,7}};
    adj[5]={{6,3}};

    int start=1,goal=6;
    UCS(start,goal,adj);
}