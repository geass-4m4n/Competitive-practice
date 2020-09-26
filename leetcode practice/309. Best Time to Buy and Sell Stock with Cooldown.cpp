class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1)
            return 0;
        
        int sell1=0;  //max profit considering a complete transaction upto day before prev day
        int buy2=0;   //max profit considering an incomplete transaction upto prev day
        int sell2=0;  //max profit considering a complete transaction upto prev day
        int i;
        
        sell2=max(sell2,prices[1]-prices[0]);  
        buy2=max(-prices[1],-prices[0]);
        
        for(i=2;i<prices.size();i++)
        {
            int p1=max(sell1-prices[i],buy2);  //calculation of new buy2
            int p2=max(buy2+prices[i],sell2);  //calculation of new sell2
            buy2=p1;
            sell1=sell2;
            sell2=p2;
        }
        
        return sell2;
        
    }
};
