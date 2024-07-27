class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        

        vector<vector<int>> ans(2);
        unordered_map<int,int> mp;
        unordered_map<int,int> mp2;
        for(int i=0;i<nums2.size();i++){
            mp[nums2[i]]=1;
        }

        for(int i=0;i<nums1.size();i++){
            if(mp.find(nums1[i])==mp.end() && mp2[nums1[i]]==0){
                ans[0].push_back(nums1[i]);
                mp2[nums1[i]]=1;
               
            }
            else{
                mp[nums1[i]]=0;
            }
        }
        for(auto it:mp){
            if(it.second!=0){
                ans[1].push_back(it.first);
                
            }
        }

        return ans;

    }
};