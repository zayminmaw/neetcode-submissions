class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i - 1] == nums[i])
                continue;
            int leftPos = i + 1;
            int rightPos = nums.size() - 1;
            while (leftPos < rightPos) {
                int threeSum = nums[i] + nums[leftPos] + nums[rightPos];
                if (threeSum < 0)
                    leftPos++;
                else if (threeSum > 0)
                    rightPos--;
                else {
                    vector<int> triplet = {nums[i], nums[leftPos], nums[rightPos]};
                    res.push_back(triplet);
                    leftPos++;
                    while (nums[leftPos] == nums[leftPos - 1] && leftPos < rightPos)
                        leftPos++;
                }
            }
        }

        return res;
    }
};
