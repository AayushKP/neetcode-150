class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        //n+2 just to keep that n-1th step -> n+1 (2 steps jump) in bound
        vector<int> dp(n+2,0);

        for(int i=n-1;i>=0;i--){
            // dp[i] is min cost to reach the top while standing at i and you can take either 1 step or 2  step from any step
            dp[i]= cost[i]+ min(dp[i+1],dp[i+2]);
        }

        // we can either start from 0 or 1, so whichever path costs min that's our way
        return min(dp[0],dp[1]);
    }
};
