

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        string ans;
        int l=min(word1.length(),word2.length());
        int i;
        for(i=0;i<l;i++){
            ans.push_back(word1[i]);
            ans.push_back(word2[i]);
        }
       while(i<word1.length()){
            ans.push_back(word1[i]);
            i++;
       }
       while(i<word2.length()){
            ans.push_back(word2[i]);
            i++;
       }
        
       return ans;

    }
};