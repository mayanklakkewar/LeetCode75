/*
Problem Statement - 

Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

 

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true


Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false
*/

//Code -

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s==t){
            return true;
        }
        int ptr1 = 0;
        int ptr2 = 0;
        int n1 = s.length();
        int n2 = t.length();

        
        while(ptr1 < n1){
            if(ptr2 >= n2){
                return false;
            }
            if(s[ptr1] == t[ptr2]){
                ptr1++;
                ptr2++;
            }
            else{
                ptr2++;
            }
        }
        return true;
    }
};