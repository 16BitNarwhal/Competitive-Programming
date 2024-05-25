class Solution {
public:
    bool dig(char c) { return c>='0' && c<='9'; }
    
    int myAtoi(string s) {
        int i=0;
        while (s[i]==' ') i++;
        int neg = (s[i]=='-' ? -1 : 1);
        if (s[i]=='-' || s[i]=='+') i++;
        while (s[i]=='0') i++;
        if (!dig(s[i])) return 0;
        string num="";
        while (i<s.length() && dig(s[i])) num+=s[i++];
        long long ans=0, ten=1;
        reverse(num.begin(), num.end());
        for (char c : num) {
            ans += ((int)(c-'0'))*ten;
            ten *= 10;
            if (ten >= 3e10) {
                if (neg>0) return INT_MAX;
                else return INT_MIN;
            }
        }
        ans *= neg;
        return max(min(ans, 1LL*INT_MAX), 1LL*INT_MIN);
    }
};