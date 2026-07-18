class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<string> grouped;
        for (int i = 0; i < strs.size(); i++) {
            if (find(grouped.begin(), grouped.end(), strs[i]) == grouped.end())
            {
                ans.push_back(vector<string>{strs[i]});
                grouped.push_back(strs[i]);
                for (int j = 0; j < strs.size(); j++) {
                    string a = strs[i];
                    string b = strs[j];
                    if (i == j || a.length() != b.length())
                        continue;
                    int count = 0;
                    for (int k = 0; k < a.length(); k++) {
                        size_t pos = b.find(a[k]);
                        if (pos != string::npos)
                            b.erase(pos, 1);
                    }
                    if (b.length() == 0)
                    {
                        ans.back().push_back(strs[j]);
                        grouped.push_back(strs[j]);
                    }
                }
            }
        }
        return ans;
    }
};
