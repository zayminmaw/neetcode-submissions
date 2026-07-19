class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> freq;

        for (int n: nums) {
            if (freq[n])
                freq[n]++;
            else
                freq[n] = 1;
        }

        for (int i = 0; i < k; i++) {
            unordered_map<int, int>::iterator it = freq.begin();
            unordered_map<int, int>::iterator big = it;
            while (it != freq.end()) {
                if (big->second < it->second)
                    big = it;
                ++it;
            }
            ans.push_back(big->first);
            freq.erase(big);
        }

        return ans;
    }
};
