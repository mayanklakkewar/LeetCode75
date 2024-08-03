/*   
Problem Statement 

You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.

 

Example 1:

Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r
Example 2:

Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b 
word2:    p   q   r   s
merged: a p b q   r   s
Example 3:

Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q 
merged: a p b q c   d

*/


class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        int n1 = word1.length();
        int n2 = word2.length();
        int i=0,j=0;
        while(i<n1 and j<n2){
            if(n1==0 or n2 == 0){
                break;
            }
            ans.push_back(word1[i]);
            ans.push_back(word2[j]);
            i++;
            j++;
        }
        while(j<n2){
            ans.push_back(word2[j]);
            j++;
        }
        while(i<n1){
            ans.push_back(word1[i]);
            i++;
        }

        return ans;
    }
};