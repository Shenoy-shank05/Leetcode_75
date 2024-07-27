class Solution {
public:
    string decodeString(string s) {
        stack<string> strStack;
        stack<int> numStack;
        string currentStr;
        int k = 0;

        for (char c : s) {
            if (isdigit(c)) {
                k = k * 10 + (c - '0');
            } else if (c == '[') {
                numStack.push(k);
                strStack.push(currentStr);
                currentStr = "";
                k = 0;
            } else if (c == ']') {
                string decodedStr = strStack.top();
                strStack.pop();
                int repeatTimes = numStack.top();
                numStack.pop();
                for (int i = 0; i < repeatTimes; ++i) {
                    decodedStr += currentStr;
                }
                currentStr = decodedStr;
            } else {
                currentStr += c;
            }
        }

        return currentStr;
    }
};