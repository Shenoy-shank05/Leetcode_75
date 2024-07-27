class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0;
        int j=0;
        int count1=0;
        int count0=0;
        int ans=0;
        while(j<nums.size()){

           while(j<nums.size() && count0<=1){
               if(nums[j]==1){
                count1++;
               }
               if(nums[j]==0){
                count0++;
               }
               j++;
           }
           if(j>=nums.size() && count0==0){
            return nums.size()-1;
           }
           j--;
           count0>1?count0--:count0;
           ans=max(ans,count1+count0);
           if(count0>=1){
         
                if(nums[j]==0){
                    count0++;
                }
                else{
                    count1++;
                }
                j++;
                if(nums[i]==0){
                    count0--;
                }
                else{
                    count1--;
                }

                i++;

           }

        }


        return ans-1;
    }
};