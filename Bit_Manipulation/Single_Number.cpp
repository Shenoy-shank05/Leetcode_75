
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        

        int xori=nums[0];
        for(int i=1;i<nums.size();i++){
            xori^=nums[i];
        }
        return xori;
    }
};