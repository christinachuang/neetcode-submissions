class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int max_profit = 0, curr_buy = INT_MAX;
        for(auto& p : prices){
            if(p < curr_buy)
                curr_buy = p;
            else
                max_profit = max(max_profit, p - curr_buy);
        }
        return max_profit;
    }
};
