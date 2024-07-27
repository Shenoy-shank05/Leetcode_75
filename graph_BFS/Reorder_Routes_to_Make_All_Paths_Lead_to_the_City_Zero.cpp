class Solution {
public:

  
void dfs(vector<pair<int,int>>* adj, vector<int>& vis,int& ans, int node) {
    if (vis[node]) {
        return;
    }
    vis[node] = 1;
    for (auto num : adj[node]) {
        if(!vis[num.first]){
            
            if(num.second==1){
            ans++;
        }
        dfs(adj, vis,ans, num.first);

        }
        
    }
}

    int minReorder(int n, vector<vector<int>>& connections) {
   int n1 = connections.size();
    int ans = 0;

    vector<pair<int,int>> adj[n];
    
    vector<int> vis(n, 0);

    for (int i = 0; i < n1; i++) {
        adj[connections[i][0]].push_back({connections[i][1],1});
        adj[connections[i][1]].push_back({connections[i][0],0});
      
    }

    dfs(adj,vis,ans,0);
    return ans;
        
        
   }
};