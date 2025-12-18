class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();

        long long sum1 = 0;
        long long sum2 = 0;
        for(int i = 0; i < n ; i++){
            sum1 += 1LL* prices[i] * strategy[i];
            if(i< k/2){
                continue;
            }else if(i< k ){
                sum2 +=prices[i];
            }else{
                sum2 += 1LL * prices[i]*strategy[i];
            }
        }
            long long profit = max(sum1, sum2);

            for(int i = 0; i < n-k;i++){
                long long new_sum = sum2;
                new_sum += 1LL * prices[i] * strategy[i];
                new_sum -= 1LL * prices[i+k] * strategy[i+k];
                new_sum += prices[i+k];
                new_sum -= prices[i+(k/2)];
                profit = max(profit, new_sum);
                sum2 = new_sum;
            }
            return profit;

        
    }
};