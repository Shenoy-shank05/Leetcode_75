class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int len = nums.size();
        sort(nums.begin(),nums.end());
        int i =0; 
        int j = len-1;
         int ans = 0;
        while(i<j)
        {
            if(nums[i]+nums[j] == k) {
                ans++; 
                i++;
                j--;
            }
            else if(nums[i]+nums[j] <k){
                 i++;
            }
            else{

                j--;

            } 
        }
        return ans;
        
    }
};