class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& a = nums1;
        vector<int>& b = nums2;

        if (a.size() > b.size())
            swap(a, b);

        int total = a.size() + b.size();
        int half = total / 2;

        int l = 0;
        int r = a.size() - 1;
        while (true) {
            int i = (l + r) >> 1;
            int j = half - i - 2;

            int a_left = (i >= 0) ? a[i] : INT_MIN;
            int a_right = (i + 1 < a.size()) ? a[i + 1] : INT_MAX;
            int b_left = (j >= 0) ? b[j] : INT_MIN;
            int b_right = (j + 1 < b.size()) ? b[j + 1] : INT_MAX;

            if (a_left <= b_right && b_left <= a_right) {
                if (total % 2) {
                    return min(b_right, a_right);
                } else {
                    return (max(a_left, b_left) + min(a_right, b_right)) / 2.0;
                }
            } else if (a_left > b_right) {
                r = i - 1;
            } else if (b_left > a_right) {
                l = i + 1;
            }
        }
    }
};
