class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<pair<int, int>> s;

        for (int i = 0; i < heights.size(); i++) {
            int start = i;
            while (!s.empty() && s.top().second > heights[i]) {
                maxArea = max(maxArea, s.top().second * (i - s.top().first));
                start = s.top().first;
                s.pop();
            }
            s.push({start, heights[i]});
        }
        
        while (!s.empty()) {
            maxArea = max(maxArea, s.top().second * ((int)heights.size() - s.top().first));
            s.pop();
        }
        return maxArea;
    }
};
