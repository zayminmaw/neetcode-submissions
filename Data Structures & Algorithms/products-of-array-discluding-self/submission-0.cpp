class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            int mul = 1;
            for (int j = 0; j < nums.size(); j++) {
                if (i == j)
                    continue;
                mul *= nums[j];
            }
            ans.push_back(mul);
        }
        return ans;
    }
};
