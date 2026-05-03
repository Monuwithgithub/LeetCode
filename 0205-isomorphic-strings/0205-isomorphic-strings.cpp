class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> mapST(256, -1);
        vector<int> mapTS(256, -1);

        for (int i = 0; i < s.size(); i++) {
            if (mapST[s[i]] == -1 && mapTS[t[i]] == -1) {
                mapST[s[i]] = t[i];
                mapTS[t[i]] = s[i];
            } else {
                if (mapST[s[i]] != t[i] || mapTS[t[i]] != s[i]) {
                    return false;
                }
            }
        }

        return true;
    }
};