#include <cmath>

class Solution {
   public:
    /**
     * @brief Given a 32-bit signed integer, reverse digits of an integer.
     *
     * @param x
     * @return int
     */
    int reverse(int x) {
        if (x == std::numeric_limits<int>::min()) {
            return 0;
        }

        bool negative = x < 0;
        if (negative){
            x = -x;
        }
        int count = 0;
        int res = 0;
        while (x > 0) {
            int new_digit = x % 10;
            if (res > (std::numeric_limits<int>::max() - new_digit) / 10) {
                return 0;
            }
            res = res * 10 + new_digit;
            x /= 10;
            count++;
        }
        return negative ? -res : res;
    }
};

#include <iostream>

int main(){
    Solution solution;
    std::cout << solution.reverse(1534236469) << std::endl;
}