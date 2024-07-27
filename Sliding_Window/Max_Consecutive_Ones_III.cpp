class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {


        int i=0;
        int j=0;
        int count1=0;
        int count0=0;
        int ans=0;
        while(j<nums.size()){

           while(j<nums.size() && count0<=k){
               if(nums[j]==1){
                count1++;
               }
               if(nums[j]==0){
                count0++;
               }
               j++;
           }
           if(j>=nums.size() && count0<k){
            return nums.size();
           }
           j--;
           count0>k?count0--:count0;
           ans=max(ans,count1+count0);
           if(count0>=k){
         
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


        return ans;
        
    }
};