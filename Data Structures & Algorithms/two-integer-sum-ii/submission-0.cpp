class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> mp;
        for(int i=0;i<numbers.size();i++){
            int req = target-numbers[i];
            if(mp.find(req) != mp.end()){
                return {mp[req],i+1};
            }
            mp[numbers[i]] = i+1;
        }
        return {-1,-1};
    }
};
