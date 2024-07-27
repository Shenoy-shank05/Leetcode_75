class Solution {
public:

    void check(int i,int j,vector<vector<int>>&grid,int& count){

        int n=grid.size();
        for(int z=0;z<n;z++){
            if(grid[i][z]==grid[z][j]){
                count++;
            }
            else{
                count=0;
                return;
            }

        }
    }
    int equalPairs(vector<vector<int>>& grid) {


       
       
        int ans=0;
        
        for(int i=0;i<grid.size();i++){
             
             for(int j=0;j<grid[0].size();j++){
                int count=0;
                if(grid[i][0]==grid[0][j]){
                    check(i,j,grid,count);
                }
                if(count==grid.size()){
                    ans++;
                }
             }
             
        }

        return ans;
        
    }
};