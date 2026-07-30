class Solution {
public:
    string minWindow(string s, string t) {
        if (t.length() == 0) return "";

        unordered_map<char, int> countT;
        unordered_map<char, int> window;

        for (char c: t)
            countT[c] = 1 + countT[c];
        
        int have = 0;
        int need = countT.size();

        int best_l = 0;
        int best_r = 0;
        int best_size = s.length() + 1;

        int l = 0;
        for (int r = 0; r < s.length(); r++) {
            char c = s[r];
            window[c] = 1 + window[c];

            if (window[c] == countT[c])
                have += 1;
            
            while (have == need)
            {
                if (r - l + 1 < best_size)
                {
                    best_l = l;
                    best_r = r;
                    best_size = r - l + 1;
                }

                window[s[l]] -= 1;
                if (window[s[l]] < countT[s[l]])
                    have -= 1;
                l++;
            }
        }
        return (best_size == s.length() + 1 ? "" : s.substr(best_l, best_size));
    }
};
