class Solution {
public:
    int maxArea(vector<int>& heights) {
        int leftPos = 0;
        int rightPos = heights.size() - 1;
        int res = 0;
        while (leftPos < rightPos) {
            res = max(res, min(heights[rightPos], heights[leftPos]) * (rightPos - leftPos));
            if (heights[rightPos] < heights[leftPos])
                rightPos--;
            else
                leftPos++;
        }
        return res;
    }
};
