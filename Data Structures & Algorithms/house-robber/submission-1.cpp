class Solution {
public:
    int solve(vector<int>& nums, vector<int>& dp, int& n, int i) {
        if (i >= n)
            return 0;

        if(dp[i]!=-1) return dp[i];
        // Steal current house -> move to i + 2
        int steal = nums[i] + solve(nums,dp, n, i + 2);

        // Skip current house -> move to i + 1
        int skip = solve(nums,dp, n, i + 1);

        // Take the maximum of stealing or skipping
        return dp[i] = max(steal, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);        
        int ans = solve(nums,dp, n, 0);
        return ans;
    }
};

