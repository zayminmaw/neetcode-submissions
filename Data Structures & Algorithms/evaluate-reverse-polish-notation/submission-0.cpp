class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> opr;

        for (string token: tokens) {
            if (token == "+") {
                int b = stoi(opr.top());
                opr.pop();
                int a = stoi(opr.top());
                opr.pop();
                opr.push(to_string(a + b));
            } else if (token == "-") {
                int b = stoi(opr.top());
                opr.pop();
                int a = stoi(opr.top());
                opr.pop();
                opr.push(to_string(a - b));
            } else if (token == "*") {
                int b = stoi(opr.top());
                opr.pop();
                int a = stoi(opr.top());
                opr.pop();
                opr.push(to_string(a * b));
            } else if (token == "/") {
                int b = stoi(opr.top());
                opr.pop();
                int a = stoi(opr.top());
                opr.pop();
                opr.push(to_string(a / b));
            } else {
                opr.push(token);
            }
        }
        return stoi(opr.top());
    }
};
