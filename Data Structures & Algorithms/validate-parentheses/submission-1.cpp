#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            // If it's an opening bracket, push it
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            else {
                // If it's a closing bracket but stack is empty → invalid
                if (st.empty()) return false;

                // Check matching
                char top = st.top();
                if ((c == ')' && top == '(') ||
                    (c == '}' && top == '{') ||
                    (c == ']' && top == '[')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }

        // Valid only if stack is empty at the end
        return st.empty();
    }
};
