class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        int p = x;
        long revertedNumber = 0;
        while (p > 0) {
            revertedNumber = revertedNumber * 10 + p % 10;
            p /= 10;
        }
        cout<<revertedNumber<<endl;
        return x == revertedNumber || x == revertedNumber / 10;
    }
};