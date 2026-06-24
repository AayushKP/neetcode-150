class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> freq;
        int l = 0;
        int len = 0;

        for (int i = 0; i < s.size(); i++) {

            while (freq[s[i]] > 0) {
                freq[s[l]]--;
                l++;
            }

            freq[s[i]]++;
            len = max(len, i - l + 1);
        }

        return len;
    }
};
