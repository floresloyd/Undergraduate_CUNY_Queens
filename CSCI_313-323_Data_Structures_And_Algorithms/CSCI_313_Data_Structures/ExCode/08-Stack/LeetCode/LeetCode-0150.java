class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> S = new Stack<>();

        for (var token: tokens){
            char ch = token.charAt(0);
            if (token.length() == 1 && !Character.isDigit(ch)){
                // If this is an operator, then pop two operands
                // off the stack and apply the operator
                int operand2 = S.pop();
                int operand1 = S.pop();

                switch(ch){
                    case '+': S.push(operand1 + operand2);
                        break;
                    case '-': S.push(operand1 - operand2);
                        break;
                    case '*': S.push(operand1 * operand2);
                        break;
                    case '/': S.push(operand1 / operand2);
                        break;
                } //end-switch

            } else {
                // Convert the number in string to an integer
                S.push(Integer.parseInt(token));
            } //end-else
        } //end-for

        return S.pop();
    }
}