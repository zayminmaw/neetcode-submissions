class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;

        int leftPos = 0;
        int maxf = 0;
        int res = 0;
        for (int rightPos = 0; rightPos < s.length(); rightPos++) {
            count[s[rightPos]] = count[s[rightPos]] + 1;
            maxf = max(maxf, count[s[rightPos]]);

            while (rightPos - leftPos + 1 - maxf > k) {
                count[s[leftPos]]--;
                leftPos++;
            }
            
            res = max(res, rightPos - leftPos + 1);
        }

        return res;
    }
};
