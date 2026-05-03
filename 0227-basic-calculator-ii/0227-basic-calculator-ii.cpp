class Solution {
public:
    int calculate(string s) {
        long long curr = 0, last = 0, result = 0;
        char op = '+';

        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                curr = curr * 10 + (s[i] - '0');
            }

            if ((!isdigit(s[i]) && s[i] != ' ') || i == s.size() - 1) {
                if (op == '+') {
                    result += last;
                    last = curr;
                } else if (op == '-') {
                    result += last;
                    last = -curr;
                } else if (op == '*') {
                    last = last * curr;
                } else if (op == '/') {
                    last = last / curr;
                }

                op = s[i];
                curr = 0;
            }
        }

        return result + last;
    }
};