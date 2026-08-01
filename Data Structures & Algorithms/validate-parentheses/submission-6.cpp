class Solution {
public:
    bool isValid(string s) {
        stack<char> res;
        unordered_map<char, char> ocp = {{'(', ')'}, {'{', '}'}, {'[', ']'}};

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                res.push(s[i]);
            } else {
                if (!res.empty() && ocp[res.top()] == s[i])
                    res.pop();
                else 
                    return false;
            }
        }
        return res.empty();
    }
};
