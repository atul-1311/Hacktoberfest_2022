#include <bits/stdc++.h>
using namespace std;

void solve(int node, int parent, unordered_map<int,vector<int>> &adj, vector<bool> &visited, vector<int> &ans, bool &possible){
      if(visited[node]){
            if(ans[node]==ans[parent])
            possible=false;
            
            return;
      }
      if(!possible)
      return;
      
      visited[node]=true;
      if(ans[parent]==1)
      ans[node]=2;
      else
      ans[node]=1;
      
      for(auto neighbour: adj[node]){
            solve(neighbour,node,adj,visited,ans,possible);
      }
}

void buildTeams(int n, int m, unordered_map<int,vector<int>> &adj){
      vector<bool> visited(n+1, false);
      vector<int> ans(n+1, 0);
      bool possible=true;
      
      for(int i=1;i<=n;i++){
            if(!visited[i]){
                  ans[i]=2;
                  solve(i,i,adj,visited,ans,possible);
            }
      }
      
      if(possible){
            for(int i=1;i<=n;i++){
                  cout<<ans[i]<<" ";
            }
      }else{
            cout<<"IMPOSSIBLE";
      }
}

int main(){
     int n,m;
     cin>>n>>m;
     
     unordered_map<int,vector<int>> adj;
     for(int i=0;i<m;i++){
           int x,y;
           cin>>x>>y;
           adj[x].push_back(y);
           adj[y].push_back(x);
     }
     
     buildTeams(n,m,adj);
}
