class Solution {
public:
     int t[50001][2];
     int doit(vector<int>&prices,int n,int day,int fee,int buy){
        if(day>=n){
            return 0;
        }
        if(t[day][buy]!=-1){
            return t[day][buy];
        }
        if(buy){
            return  t[day][buy]= max(-prices[day]+doit(prices,n,day+1,fee,false),doit(prices,n,day+1,fee,true));
        }
        else{
           return  t[day][buy]= max(-fee + prices[day]+doit(prices,n,day+1,fee,true),doit(prices,n,day+1,fee,false));
        }

       
        
     }
     
    int maxProfit(vector<int>& prices, int fee) {
        memset(t,-1,sizeof(t));
        int n=prices.size();
        return doit(prices,n,0,fee,true);

    }
};