class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int wordLen = words[0].length();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        unordered_map<string, int> wordMap;
        for (string w : words) {
            wordMap[w]++;
        }

        // Try all possible starting offsets
        for (int i = 0; i < wordLen; i++) {
            int left = i, count = 0;
            unordered_map<string, int> windowMap;

            for (int right = i; right + wordLen <= s.length(); right += wordLen) {
                string word = s.substr(right, wordLen);

                // If word is valid
                if (wordMap.find(word) != wordMap.end()) {
                    windowMap[word]++;
                    count++;

                    // If more than required, shrink window
                    while (windowMap[word] > wordMap[word]) {
                        string leftWord = s.substr(left, wordLen);
                        windowMap[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    // If all words matched
                    if (count == wordCount) {
                        result.push_back(left);

                        // Slide window forward
                        string leftWord = s.substr(left, wordLen);
                        windowMap[leftWord]--;
                        left += wordLen;
                        count--;
                    }
                } 
                else {
                    // Reset window
                    windowMap.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }

        return result;
    }
};