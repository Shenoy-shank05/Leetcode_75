class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        for(int i=0;i<arr.size();i++){
            mp1[arr[i]]++;

        }
        for(auto it: mp1){
            mp2[it.second]++;
            if(mp2[it.second]>1){
                return false;
            }

        }
        return true;

        
    }
};