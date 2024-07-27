// class Solution {
// public:
//     int n,m;
//    int t[1001][1001];
//     int doit(string text1, string text2,int i,int j) {
//         if (i>=n || j>=m) {
//             return 0;
//         }
        
//        if(t[i][j]!=-1){
//         return t[i][j];
//        }
        
//         if (text1[i] == text2[j]) {
           
//             return t[i][j] = 1 + doit(text1, text2,i+1,j+1);
//         } 

        
//         return t[i][j]=max(doit(text1, text2,i+1,j),doit(text1, text2,i,j+1) );
//     }

//     int longestCommonSubsequence(string text1, string text2) {
//          n=text1.length();
//          m=text2.length();
//         memset(t,-1,sizeof(t));
//         return doit(text1, text2,0,0);
//     }
// };


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int dp[text1.size()+1][text2.size()+1];
        memset(dp, 0, sizeof dp);
        for(int i=1;i<=text1.size();i++){
            for(int j=1; j<=text2.size(); j++){
                if(text1[i-1]==text2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[text1.size()][text2.size()];
    }
};


