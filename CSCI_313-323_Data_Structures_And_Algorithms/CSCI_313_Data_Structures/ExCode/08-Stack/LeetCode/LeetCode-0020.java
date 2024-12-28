class Solution {
    public boolean isValid(String s) {
        Stack<Character> S = new Stack<>();

        for (int i=0; i<s.length(); i++){
            char ch = s.charAt(i);
            if (ch == '(' || ch == '[' || ch == '{')
                S.push(ch);
            else {
                if (S.isEmpty()) return false;
                char top = S.pop();

                if (ch == ')' && top != '(') return false;
                if (ch == ']' && top != '[') return false;
                if (ch == '}' && top != '{') return false;
            } //end-else
        } //end-for

        return S.empty();
    }
}