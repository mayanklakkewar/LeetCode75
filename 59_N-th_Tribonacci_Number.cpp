/*
The Tribonacci sequence Tn is defined as follows: 

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.

 

Example 1:

Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4
Example 2:

Input: n = 25
Output: 1389537
 */

//Code-

class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        
        int t0 = 0, t1 = 1, t2 = 1;
        int tn;
        
        for (int i = 3; i <= n; ++i) {
            tn = t0 + t1 + t2;
            t0 = t1;
            t1 = t2;
            t2 = tn;
        }
        
        return tn;
    }
};