class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();

        vector<bool> dp(n, false);

        int bestStart = 0;
        int maxLen = 1;

        for (int start = n - 1; start >= 0; start--) {
            bool prev = false;

            for (int end = start; end < n; end++) {
                bool old = dp[end];

                if (s[start] == s[end] &&
                    (end - start <= 2 || prev)) {

                    dp[end] = true;

                    int len = end - start + 1;

                    if (len > maxLen) {
                        maxLen = len;
                        bestStart = start;
                    }
                } else {
                    dp[end] = false;
                }

                prev = old;
            }
        }

        return s.substr(bestStart, maxLen);
    }
};