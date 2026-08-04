class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> s;

        for (int i = 0; i < temperatures.size(); i++) {
            while (!s.empty() && s.top().first < temperatures[i]) {
                pair<int, int> cur = s.top();
                s.pop();
                res[cur.second] = i - cur.second;
            }
            s.push({temperatures[i], i});
        }

        return res;
    }
};
