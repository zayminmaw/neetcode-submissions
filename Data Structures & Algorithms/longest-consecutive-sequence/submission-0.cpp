class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums_set(nums.begin(), nums.end());
        int longest = 0;
        for (int n: nums) {
            if (!nums_set.count(n - 1))
            {
                int count = 1;
                while (nums_set.count(n + count)) {
                     count++;
                }
                if (count > longest)
                    longest = count;
            } 
        }
        return longest;
    }
};
