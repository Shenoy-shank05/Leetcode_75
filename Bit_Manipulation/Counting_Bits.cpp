class Solution {
public:
    vector<int> countBits(int n) {
        


        vector<int> ans;
        int i=0;
        while(i<=n){

            int count=0;
            int temp=i;
            while(temp>0){
                if(temp%2!=0){
                    count++;
                }
                temp=temp>>1;
                
            }
            ans.push_back(count);
            i++;
        }

        return ans;
    }
};