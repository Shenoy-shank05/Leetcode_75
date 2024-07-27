class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        

       int x=flowerbed.size();
       if(x==1 && flowerbed[0]==0){
          n--;
          return n<=0?true:false;

       }
       if( flowerbed[0]==0 && flowerbed[1]==0){
                n--;
                flowerbed[0]=1;

        }
        if(flowerbed[x-1]==0 && flowerbed[x-2]==0){
                n--;
                flowerbed[x-1]=1;

        }
        
        for(int i=1;i<flowerbed.size()-1;i++){
            
           if(flowerbed[i]==0 && flowerbed[i-1]!=1 && flowerbed[i+1]!=1){
                n--;
                flowerbed[i]=1;
            }
            

        }

        return n<=0?true:false;
    }
};