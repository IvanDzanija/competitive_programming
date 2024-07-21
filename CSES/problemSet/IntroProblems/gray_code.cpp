#include <iostream>
#include <set>
#include <stack>
#include <cstring>
#include <algorithm>
#include <cmath>
using ll = int64_t;

int main(void){
    ll n;
    std::cin >> n;
    std::string code = "";
    std::stack<std::string> stack;
    std::set<std::string> seen;
    for (ll i = 0; i < n; ++i){
        code += '0';
    }
    stack.push(code);
    while(!stack.empty()){
        std::string current = stack.top();
        stack.pop();
        if (seen.count(current)) continue;
        seen.insert(current);
        std::cout << current << std::endl;
        for (ll i = 0 ; i < n; ++i){
            std::string newCode = current;
            if (newCode.at(i) == '0') newCode.at(i) = '1';
            else newCode.at(i) = '0';
            stack.push(newCode);
        }
    }

    return 0;
}