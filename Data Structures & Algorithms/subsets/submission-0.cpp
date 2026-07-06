class Solution {
public:
    void subset(vector<vector<int>> &ans,vector<int> &temp, vector<int> &nums, int index){
        if(index == nums.size()){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[index]); 
        subset(ans,temp,nums,index+1);
        temp.pop_back();
        subset(ans,temp,nums,index+1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        subset(ans,temp,nums,0);
        return ans;
    }
};
