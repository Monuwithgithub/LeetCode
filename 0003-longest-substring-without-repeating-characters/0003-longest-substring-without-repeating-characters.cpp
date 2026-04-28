#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int left = 0, maxLen = 0;

        for (int right = 0; right < s.length(); right++) {
            
            // If character already seen, move left pointer
            if (mp.find(s[right]) != mp.end()) {
                left = max(left, mp[s[right]] + 1);
            }

            // Update last seen index
            mp[s[right]] = right;

            // Update max length
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};