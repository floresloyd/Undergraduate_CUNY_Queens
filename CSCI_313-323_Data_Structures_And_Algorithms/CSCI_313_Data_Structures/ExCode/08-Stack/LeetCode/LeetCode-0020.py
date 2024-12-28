class Solution:
    def isValid(self, s: str) -> bool:
        S = []
        for ch in s:
            if ch == '(' or ch == '[' or ch == '{':
                S.append(ch)
            else:
                if len(S) == 0: return False
                top = S.pop()

                if ch == ')' and top != '(': return False
                if ch == ']' and top != '[': return False
                if ch == '}' and top != '{': return False
        return len(S) == 0