class Solution {
public:


    void bfs(int i,vector<int>* adj, vector<int>& vis){

        queue<int> q;
        q.push(i);
        vis[i]=1;
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
    int findCircleNum(vector<vector<int>>& cities) {
        
       
        int n=cities.size();
        vector<int> adj[n];
        vector<int> vis(n,0);
        int m=cities[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(cities[i][j]==1 ){
                  adj[i].push_back(j);
                }
               
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                bfs(i,adj,vis);
            }
        }


        return count;

        

    }
};