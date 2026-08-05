class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> p;
        stack<float> res;

        for (int i = 0; i < position.size(); i++) {
            p.push_back({position[i], speed[i]});
        }

        sort(p.begin(), p.end());

        for (int i = position.size() - 1; i >= 0; i--) {
            float time = (float)(target - p[i].first) / p[i].second;
            if (!res.empty() && res.top() >= time)
                continue;
            res.push(time);
        }

        return res.size();
    }
};
