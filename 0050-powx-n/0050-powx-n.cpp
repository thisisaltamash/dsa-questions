class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;      // Convert to long long to avoid overflow
        double ans = 1.0;

        // Handle negative powers
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        while (N > 0) {
            // If N is odd, multiply answer by current x
            if (N % 2 == 1) {
                ans *= x;
            }

            // Square the base
            x *= x;

            // Divide exponent by 2
            N /= 2;
        }

        return ans;
    }
};