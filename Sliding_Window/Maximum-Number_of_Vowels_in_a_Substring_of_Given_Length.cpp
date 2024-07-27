class Solution {
public:
    int maxVowels(string s, int k) {
        

       
       int i=0;
       int j=k-1;
       int maxVowels=0;
       int ans=0;
       
       for(int z=i;z<=j;z++){
        if(s[z]=='a' || s[z]=='e' || s[z]=='i' || s[z]=='o' || s[z]=='u'){
            maxVowels++;
        }

       }
        
       while(j<s.length()){
        j++;
        ans=max(maxVowels,ans);
        if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u'){
            maxVowels++;
        }
         if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
            maxVowels--;
        }
        i++;
       


       }
       return ans;

    }
};