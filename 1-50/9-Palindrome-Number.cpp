using namespace std;

class Solution {
   public:
    bool isPalindrome(int x) {
        long long n = x;
        long long remainder;
        long long reversed;

        while (n > 0) {
            remainder = n % 10;
            reversed = reversed * 10 + remainder;
            n /= 10;
        }
        return x == reversed;
    }
};