#include <climits>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.length();

        // Step 1: skip spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Step 2: check sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // Step 3: convert digits
        long long result = 0;

        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Step 4: check overflow
            if (result > (LLONG_MAX / 10)) break;

            result = result * 10 + digit;

            // Clamp to int range
            if (sign * result > INT_MAX) return INT_MAX;
            if (sign * result < INT_MIN) return INT_MIN;

            i++;
        }

        return (int)(sign * result);
    }
};