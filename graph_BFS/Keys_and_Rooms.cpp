class Solution {
public:
   
    void bfs(vector<int>* adj,vector<int>& vis){
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            vis[node]=1;
            for(auto num: adj[node]){
                if(!vis[num]){
                    q.push(num);
                   
                }
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        
       
        int n=rooms.size();
        vector<int> adj[n];
         vector<int> vis(n,0);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<rooms[i].size();j++){
                adj[i].push_back(rooms[i][j]);
            }
        }

        bfs(adj,vis);
        for(int i=0;i<n;i++){
           if(!vis[i]){
            return false;
           }
            

        }
        return true;
    }
};