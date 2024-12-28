class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        S = []
        for token in tokens:
            if len(token)==1 and not token.isdigit():
                operand2 = S.pop()
                operand1 = S.pop()
                                
                if token == "+":
                    S.append(operand1 + operand2) 
                elif token == "-":
                    S.append(operand1 - operand2) 
                elif token == "*":
                    S.append(operand1 * operand2) 
                else: # token == "/"
                    S.append(int(operand1 / operand2))
            else:
                S.append(int(token))
        return S[0]
