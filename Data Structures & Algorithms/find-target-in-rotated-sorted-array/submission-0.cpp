class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] == target)
                return m;
            if (nums[l] <= nums[m]) {
                // target is bigger than current selected number or
                // target is smaller than left number
                // we have to check right
                if (target > nums[m] || target < nums[l])
                    l = m + 1;
                else 
                    r = m - 1;
            } else {
                // target is smaller than current selected number or
                // target is bigger than left number
                // we have to check right
                if (target < nums[m] || target > nums[r])
                    r = m - 1;
                else
                    l = m + 1;
            }
        }
        return -1;
    }
};
