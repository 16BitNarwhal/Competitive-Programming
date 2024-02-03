class Solution:
    def addBinary(self, a: str, b: str) -> str:
        if len(a) < len(b):
            a = '0' * (len(b)-len(a)) + a
        elif len(b) < len(a):
            b = '0' * (len(a)-len(b)) + b
        n = len(a)
        res = ''
        carry = 0
        for i in range(n-1, -1, -1):
            x = int(a[i]=='1')
            y = int(b[i]=='1')
            sum = x+y+carry
            res += '0' if sum%2==0 else '1'
            carry = int(sum>1)
        if carry:
            res += '1'
        return res[::-1]