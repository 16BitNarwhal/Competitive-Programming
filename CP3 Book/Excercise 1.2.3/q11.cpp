#include <bits/stdc++.h>
using namespace std;
const char * expressionToParse = "3*2+4*1+(4+9)/13";
char peek() {
    return *expressionToParse;
}

char get() {
    return *expressionToParse++;
}

int expression();

int number() {
    int result = get() - '0';
    while (peek() >= '0' && peek() <= '9') {
        result = 10*result + get() - '0';
    }
    return result;
}

int factor() {
    if (peek() >= '0' && peek() <= '9')
        return number();
    else if (peek() == '(')
    {
        get(); // '('
        int result = expression();
        get(); // ')'
        return result;
    }
    else if (peek() == '-')
    {
        get();
        return -factor();
    }
    return 0; // error
}

int term() {
    int result = factor();
    while (peek() == '*' || peek() == '/')
        if (get() == '*')
            result *= factor();
        else
            result /= factor();
    return result;
}

int expression() {
    int result = term();
    while (peek() == '+' || peek() == '-')
        if (get() == '+')
            result += term();
        else
            result -= term();
    return result;
}

int main() {
    int result = expression();
    cout<<result<<"\n";
}