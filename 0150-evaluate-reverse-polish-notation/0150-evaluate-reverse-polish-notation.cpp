class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operands;
        int res;
        for(string token: tokens){
            if(token != "+" && token != "-" && token != "/" && token != "*")    operands.push(stoi(token));
            else{
                if (token == "+"){
                    res = operands.top();
                    operands.pop();
                    res += operands.top();
                    operands.pop();
                    operands.push(res);
                }
                if (token == "*"){
                    res = operands.top();
                    operands.pop();
                    res *= operands.top();
                    operands.pop();
                    operands.push(res);
                }
                if (token == "-"){
                    res = operands.top();
                    operands.pop();
                    int b = operands.top();
                    operands.pop();
                    b = b - res;
                    operands.push(b);
                }
               if (token == "/"){
                    res = operands.top();
                    operands.pop();
                    int b = operands.top();
                    operands.pop();
                    b = b / res;
                    operands.push(b);
                }
            }
        }
        return operands.top();
    }
};