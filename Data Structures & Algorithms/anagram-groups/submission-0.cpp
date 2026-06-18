class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //we need to push the array in the result
        vector<vector<string>> result;
        unordered_map<string,vector<string>> mp;
        for(int i=0;i<strs.size();i++){
            string key = strs[i];
            sort(key.begin(),key.end());
            mp[key].push_back(strs[i]);
        }

        for(auto m:mp){
            result.push_back(m.second);
        }
        return result;
    }
};
