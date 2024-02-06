class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack: int = []
        for i in tokens:
            if i[-1].isdigit():
                stack.append(int(i))
                continue
            b = stack.pop()
            a = stack.pop()
            if i == '+':
                stack.append(a+b)
            elif i == '-':
                stack.append(a-b)
            elif i == '/':
                if a/b >= 0:
                    stack.append(a//b)
                else:
                    stack.append(-(-a//b))
            else:
                stack.append(a*b)
            print(stack[-1])
        return stack.pop()