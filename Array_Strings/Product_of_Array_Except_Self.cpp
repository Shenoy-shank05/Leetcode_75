class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n=nums.size();
        vector<int> prefixproduct(n);
        vector<int> suffixproduct(n);
        vector<int> ans(n);

        prefixproduct[0]=nums[0];
        suffixproduct[n-1]=nums[n-1];

        int i=1;
        int j=n-2;
        while(i<n && j>=0){

            prefixproduct[i]=nums[i]*prefixproduct[i-1];
            suffixproduct[j]=nums[j]*suffixproduct[j+1];

            i++;
            j--;

        }

        for(int i=0;i<n;i++){

            if(i==0){
                ans[i]=suffixproduct[i+1];
            }
            else if(i==n-1){

                ans[i]=prefixproduct[i-1];
            }

            else{

                ans[i]=prefixproduct[i-1]*suffixproduct[i+1];
            }
        }

        return ans;




        
    }
};