class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1)
            return 0;
        vector<int> hold(prices.size(), 0), sell(prices.size(), 0);
        // sell[i] = 到第 i 天結束時，沒有持股的最大 profit
        // hold[i] = 到第 i 天結束時，持股的最大 profit
        hold[0] = -1 * prices[0];
        for(int i = 1; i < prices.size(); i++){
            int prev_sell = (i >= 2) ? sell[i - 2] : 0;
            hold[i] = max(hold[i - 1], prev_sell - prices[i]);
            sell[i] = max(sell[i - 1], hold[i - 1] + prices[i]);
        }
        return sell[prices.size() - 1];
    }
    /*
    int maxProfit(vector<int>& prices) {
        bool canBuy = true;
        int curr_idx = 0;
        return recursion(prices, curr_idx, canBuy);
    }
    int recursion(vector<int>& prices, int curr_idx, bool canBuy){
        if(curr_idx >= prices.size())
            return 0;
        if(canBuy){
            int skip = recursion(prices, curr_idx + 1, canBuy);
            int buy = recursion(prices, curr_idx + 1, !canBuy) - prices[curr_idx];
            return max(skip, buy);
        }
        else{
            int skip = recursion(prices, curr_idx + 1, canBuy);
            int sell = recursion(prices, curr_idx + 2, !canBuy) + prices[curr_idx];
            return max(skip, sell);
        }
    }*/
};
