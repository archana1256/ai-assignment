#include <bits/stdc++.h>
using namespace std;

bool DLS(int node,int goal,int depth,vector<vector<int>>& adj,vector<int>& vis){
    if(node==goal){
        cout<<node<<" ";
        return true;
    }
    if(depth<=0) return false;
    vis[node]=1;
    cout<<node<<" ";
    for(auto it:adj[node]){
        if(!vis[it]){
            if(DLS(it,goal,depth-1,adj,vis))
                return true;
        }
    }
    return false;
}

void IDDFS(int start,int goal,int maxDepth,vector<vector<int>>& adj){
    for(int i=0;i<=maxDepth;i++){
        vector<int> vis(adj.size(),0);
        if(DLS(start,goal,i,adj,vis)){
            cout<<"\nGoal found at depth "<<i;
            return;
        }
        cout<<"\n";
    }
    cout<<"Goal not found";
}

int main(){
    int n=6;
    vector<vector<int>> adj(n+1);
    adj[1]={2,3};
    adj[2]={4,5};
    adj[3]={6};
    adj[4]={};
    adj[5]={};
    adj[6]={};
    int start=1,goal=5,maxDepth=5;
    IDDFS(start,goal,maxDepth,adj);
}