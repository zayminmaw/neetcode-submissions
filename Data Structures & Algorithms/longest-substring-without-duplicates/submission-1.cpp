class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int leftPos = 0;
        int rightPos = 0;
        int res = 0;

        while (s[rightPos]) {
            if (seen.count(s[rightPos]) == 0) {
                seen.insert(s[rightPos]);
                rightPos++;
            } else {
                seen.erase(s[leftPos]);
                leftPos++;
            }
            res = max((int)seen.size(), res);
        }

        return res;
    }
};
