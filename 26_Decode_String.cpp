/*
Problem Satement -

Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 105.

 

Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"
Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"
Example 3:

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"

*/

// Code -

class Solution {
public:
    string decodeString(string s) {
         string ans="";
        stack<char>st;
     
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==']')
            {
                // pop till '[' not came
                while(st.size()>0 && st.top()!='[')
                {
                    ans=st.top()+ans;
                    st.pop();
                }
                
                // at this line we have ']' at top so pop it
                if(st.size()!=0)
                  st.pop();
                  
                  // extract digit
                  string number="";
                  while(st.size()>0 && st.top()>='0' && st.top()<='9')
                  {
                      number=st.top()+number;
                      st.pop();
                  }
                  
                  // concate the string 
                  int digit_n=stoi(number);
                  string temp=ans;
                  for(int i=0;i<digit_n-1;i++)
                       ans+=temp;
        
                  //  push all to stack 
                  for(int i=0;i<ans.size();i++)
                      st.push(ans[i]);
                  
                  // reset ans
                  ans="";
            }
            else
              st.push(s[i]);
        }
        while(st.size()>0)
        {
            ans=st.top()+ans;
            st.pop();
        }
      return ans;  
        
    }
};