class Solution {
public:
    int t[101][101];
    int solve(int i,int j,int n,int m){
        if(i==n-1 && j==m-1){
            return 1;

        }
        if(i<0 || i>=n || j<0 || j>=m){
            return 0;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }

        int right=solve(i,j+1,n,m);
        int down=solve(i+1,j,n,m);

        return t[i][j]=right+down;
    }
    int uniquePaths(int m, int n) {
        memset(t, -1 ,sizeof(t));
        int ans=solve(0,0,n,m);
        return ans;
    }
};