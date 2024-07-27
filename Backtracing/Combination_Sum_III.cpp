class Solution {
public:
    void helper(vector<vector<int>> &ans, vector<int> &output, vector<int>& nums, int k, int n, int index){
        if(k==0){
            if(n==0)
            ans.push_back(output);
            return;
        }
        if(n==0)
            return;

        for(int i=index; i<nums.size(); i++){
            if(nums[i] > n) break;

            output.push_back(nums[i]);
            helper(ans, output, nums, k-1, n-nums[i], i+1);
            output.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
        for(int i=1; i<=9; i++){
            nums.push_back(i);
        }

        vector<vector<int>> ans;
        vector<int> output; 

        helper(ans, output, nums, k, n, 0);

        return ans;
    }
};