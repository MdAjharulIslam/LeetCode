class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int profit=0;
        int minprice=prices[0];
        
        for(int i = 0;i<n;i++){
            if(prices[i]<minprice){
                minprice = prices[i];
            }
            if(prices[i]-minprice>profit){
                profit = prices[i]-minprice;
            }
        }
        return profit;
    }
};