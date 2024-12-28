class Solution {
public:
    ///--------------------------------------------------------------------
    /// Simply push open parenthesis to the stack & match with closing parenthesis
    ///
    bool isValid(string s) {
        stack<char> S;

        for (int i=0; i<s.length(); i++){
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                S.push(s[i]);
            else {
                if (S.empty()) return false;
                char top = S.top();
                S.pop();

                if (s[i] == ')' && top != '(') return false;
                if (s[i] == ']' && top != '[') return false;
                if (s[i] == '}' && top != '{') return false;
            } //end-else
        } //end-for

        if (S.empty()) return true;
        else           return false;
    } //end-isValid
};