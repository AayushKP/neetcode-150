class Solution {
public:
    int solve(vector<int>& nums, int& n, int i) {
        if (i >= n)
            return 0;

        // Steal current house -> move to i + 2
        int steal = nums[i] + solve(nums, n, i + 2);

        // Skip current house -> move to i + 1
        int skip = solve(nums, n, i + 1);

        // Take the maximum of stealing or skipping
        return max(steal, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        int ans = solve(nums, n, 0);
        return ans;
    }
};

