class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> opr;

        for (string token: tokens) {
            if (token == "+") {
                int b = opr.top();
                opr.pop();
                int a = opr.top();
                opr.pop();
                opr.push(a + b);
            } else if (token == "-") {
                int b = opr.top();
                opr.pop();
                int a = opr.top();
                opr.pop();
                opr.push(a - b);
            } else if (token == "*") {
                int b = opr.top();
                opr.pop();
                int a = opr.top();
                opr.pop();
                opr.push(a * b);
            } else if (token == "/") {
                int b = opr.top();
                opr.pop();
                int a = opr.top();
                opr.pop();
                opr.push(a / b);
            } else {
                opr.push(stoi(token));
            }
        }
        return opr.top();
    }
};
