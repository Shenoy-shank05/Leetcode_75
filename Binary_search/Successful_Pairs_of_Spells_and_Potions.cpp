class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {

        sort(potions.begin(),potions.end());
        vector<int> ans;
        for(int i=0;i<spells.size();i++){
            int s=0;
            int e=potions.size()-1;
            int index=-1;
            while(s<=e){
               int mid = s + (e - s) / 2; 
            long long product = static_cast<long long>(potions[mid]) * spells[i];
                if(product<success){
                    s=mid+1;

                }
                else{
                    e=mid-1;
                    index=mid;
                }
            }
            if(index==-1){
                 ans.push_back(0);
            }
            else{
                ans.push_back(potions.size()-index);
            }
           

        }

        return ans;
        
    }
};