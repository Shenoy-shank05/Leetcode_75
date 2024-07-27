class Solution {
public:

    void solve(int idx,string digits,string temp,vector<string>&ans,unordered_map<char,string>mp){
        if(idx>=digits.length()){
            ans.push_back(temp);
            return;
        }
        char d=digits[idx];
        string str=mp[d];

        for(int i=0;i<str.length();i++){
            temp.push_back(str[i]);
            solve(idx+1,digits,temp,ans,mp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        
        unordered_map<char,string> mp;
        if(!digits.length()){
            return {};
        }
       
       mp['1']="";
       mp['2']="abc";
       mp['3']="def";
       mp['4']="ghi";
       mp['5']="jkl";
       mp['6']="mno";
       mp['7']="pqrs";
       mp['8']="tuv";
       mp['9']="wxyz";

       vector<string> ans;
       solve(0,digits,"",ans,mp);  
       return ans;     
    }
};