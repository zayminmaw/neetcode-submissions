class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> opr;

        for (string token: tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = opr.top();
                opr.pop();
                int a = opr.top();
                opr.pop();
                if (token == "+")
                    opr.push(a + b);
                else if (token == "-")
                    opr.push(a - b);
                else if (token == "*")
                    opr.push(a * b);
                else 
                    opr.push(a / b);
            } else {
                opr.push(stoi(token));
            }
        }
        return opr.top();
    }
};
