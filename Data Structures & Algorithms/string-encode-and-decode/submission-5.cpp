class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";

        for (string s: strs) {
            ans += to_string(s.length());
            ans += ",";
            ans += s;
            ans += ",";
        }

        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        string len = "0";
        bool isLen = true;
        int i = 0;
        while (s[i]) {
            if (s[i] == ',')
            {
                isLen = !isLen;
                i++;
                if (!isLen)
                {
                    ans.push_back(s.substr(i, stoi(len)));
                    i += stoi(len); 
                    len = "0";
                }
                continue;
            }
            if (isLen) {
                len += s[i];
                i++;
            }   
        }
        return ans;
    }
};
