class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        unordered_map<char, int> s1Count;
        unordered_map<char, int> s2Count;

        for (int i = 0; i < s1.length(); i++) {
            s1Count[s1[i]] += 1;
            s2Count[s2[i]] += 1;
        }

        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (s1Count['a' + i] == s2Count['a' + i])
                matches++;
        }

        int l = 0;
        for (int r = s1.length(); r < s2.length(); r++) {
            if (matches == 26)
                return true;

            s2Count[s2[r]] += 1;
            if (s2Count[s2[r]] == s1Count[s2[r]])
                matches++;
            else if (s2Count[s2[r]] == s1Count[s2[r]] + 1)
                matches--;

            s2Count[s2[l]] -= 1;
            if (s2Count[s2[l]] == s1Count[s2[l]])
                matches++;
            else if (s2Count[s2[l]] == s1Count[s2[l]] - 1)
                matches--;

            l++;
        }

        return matches == 26;
    }
};
