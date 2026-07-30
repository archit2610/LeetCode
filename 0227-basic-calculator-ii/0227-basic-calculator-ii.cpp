class Solution {
public:
    int calculate(string s) {
        stack<int> cal;

        int num = 0;
        char op = '+';

        for (int i = 0; i < s.size(); i++) {

            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }

            if ((!isdigit(s[i]) && s[i] != ' ') || i == s.size() - 1) {

                if (op == '+') {
                    cal.push(num);
                }
                else if (op == '-') {
                    cal.push(-num);
                }
                else if (op == '*') {
                    int top = cal.top();
                    cal.pop();

                    cal.push(top * num);
                }
                else if (op == '/') {
                    int top = cal.top();
                    cal.pop();

                    cal.push(top / num);
                }

                op = s[i];
                num = 0;
            }
        }

        int result = 0;

        while (!cal.empty()) {
            result += cal.top();
            cal.pop();
        }

        return result;
    }
};