#include <bits/stdc++.h>
using namespace std;

bool DLS(int node,int goal,int depth,vector<vector<int>>& adj,vector<int>& vis){
    if(node==goal){
        cout<<"Goal found: "<<node;
        return true;
    }
    if(depth==0) return false;
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            if(DLS(it,goal,depth-1,adj,vis))
                return true;
        }
    }
    return false;
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
    int start=1,goal=5,depth=2;
    vector<int> vis(n+1,0);
    if(!DLS(start,goal,depth,adj,vis))
        cout<<"Goal not found within depth";
}