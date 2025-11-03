#include<iostream>

class Solution{
public:
    int add(int a, int b){
        return a + b;
    }
};

int main(){
    Solution sol;
    int a,b;
    std::cin >> a >> b; 
    std::cout << sol.add(a, b) << std::endl;
    return 0;
}