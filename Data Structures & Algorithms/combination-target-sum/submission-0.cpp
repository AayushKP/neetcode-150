class Solution {
public:
    void combi(vector<int> &nums, int target, vector<int> &temp, vector<vector<int>> &ans, int index){
        if(target==0){
            ans.push_back(temp);
            return;
        }

        if(target<0 || index == nums.size()) return;

        temp.push_back(nums[index]);
        combi(nums,target-nums[index],temp,ans,index);
        temp.pop_back();

        combi(nums,target,temp,ans,index+1);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        combi(nums,target,temp,ans,0);
        return ans;
    }
};
