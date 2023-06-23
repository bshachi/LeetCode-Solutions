class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n == 1) return 0;

        int profit_buy = -1*prices[0], last_buy = prices[0];
        int profit_sell = 0, last_sell = INT_MAX;
        int prev_profit_buy, temp;

        for (int i = 1; i < n; i++) {
            temp = max(profit_buy, 
                max(profit_sell - prices[i], 
                profit_buy + last_buy - prices[i]));

            if (temp != profit_buy) last_buy = prices[i];
            prev_profit_buy = profit_buy;
            profit_buy = temp;

            temp = max(profit_sell, 
                max(profit_sell - last_sell + prices[i], 
                prev_profit_buy + prices[i] - fee));
            
            if (temp != profit_sell) last_sell = prices[i];
            profit_sell = temp;
        }  

        return profit_sell;
    }
};