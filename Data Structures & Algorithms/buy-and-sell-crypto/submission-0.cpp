class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxPrice = INT_MIN;
        int maxProfit = 0;
        for(int i=1;i<prices.size();i++){
            maxPrice = max(minPrice,prices[i]);
            maxProfit = max(maxProfit,maxPrice - minPrice);
            minPrice = min(prices[i],minPrice);
        }
        return maxProfit;
    }
};
