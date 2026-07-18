class Solution {
public:
    void backtrack(vector<vector<int>> &ans, vector<int> &temp, int index, vector<int> &nums) {
        if (index == nums.size()) {
            ans.push_back(temp);
            return;
        }

        // Choice 1: Include the current element
        temp.push_back(nums[index]);
        backtrack(ans, temp, index + 1, nums);
        temp.pop_back(); // Backtrack

        // Choice 2: Exclude the current element AND all its duplicates
        // We skip over identical elements to prevent generating the same subset path again
        while (index + 1 < nums.size() && nums[index] == nums[index + 1]) {
            index++;
        }
        backtrack(ans, temp, index + 1, nums);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        //Sort so duplicates are adjacent
        sort(nums.begin(), nums.end());
        
        backtrack(ans, temp, 0, nums);
        return ans;
    }
};