class Solution {
public:
    int minFlips(int a, int b, int c) {
        
       int ans=0;
        while(max(a,max(b,c))>0){

            if(a%2==0 && b%2==0 && c%2!=0){
                ans+=1;

            }
            else if(a%2==0 && b%2!=0 && c%2==0){
                ans+=1;
            }
            else if(a%2!=0 && b%2==0 && c%2==0){
                ans+=1;
            }
            else if(a%2!=0 && b%2!=0 && c%2==0){
                ans+=2;
            }
            a=a>>1;
            b=b>>1;
            c=c>>1;


        }
        return ans;
    }
};