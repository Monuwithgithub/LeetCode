class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, maxLen = 1;
        int n = s.size();

        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                int currLen = right - left + 1;
                if (currLen > maxLen) {
                    start = left;
                    maxLen = currLen;
                }
                left--;
                right++;
            }
        };

        for (int i = 0; i < n; ++i) {
            // Odd length palindrome
            expandAroundCenter(i, i);
            // Even length palindrome
            expandAroundCenter(i, i + 1);
        }

        return s.substr(start, maxLen);
    }
};
