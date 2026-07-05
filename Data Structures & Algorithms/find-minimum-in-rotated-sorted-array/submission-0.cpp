class Solution {
public:
    int findMin(vector<int> &nums) {
        int l=0;
        int r=nums.size()-1;

        while(l<r){
            //for pivot index the right part of mid should be small
            int mid = l+(r-l)/2;
            if(nums[mid] > nums[r]){
                l=mid+1;
            }
            else{
                r= mid;
            }
        }
        return nums[l];
    }
};
