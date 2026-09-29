class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = 0;
        int maxProfit = 0;
        for(int i = 0; i < prices.size(); i++){
            if(prices[right] < prices[left]){
                left = right;
            }else{
                int profit = prices[right] - prices[left];
                maxProfit = max(maxProfit, profit);
            }
            right++;
        }
        return maxProfit;
    }
};
