// problem link
// https://leetcode.com/problems/climbing-stairs/description/


class Solution {
public:
    int climbStairs(int n) {
        long long int a = 1;
        long long int b = 1;

        while(n--)
        {
           long long int val = a+b;
            a = b;
            b = val;
        }

        return a;

    }
};
