/*

Problem Satement -

We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

 

Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
Example 2:

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.
Example 3:

Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.

*/

//Code -

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        for(int i=0; i<n; i++){
            int a = asteroids[i];
            while(!st.empty() && a < 0 && st.top()>0){
                int sum = st.top() + a;
                if(sum < 0){
                    st.pop();
                }
                else if(sum>0){
                    a=0;
                }
                else{
                    st.pop();
                    a=0;
                }
            }
            if(a != 0){
                st.push(a);
            }
        }
        //reversed order
        n = st.size();
        vector<int> v(n);
        int i = n-1;
        while(!st.empty()){
            v[i] = st.top();
            st.pop();
            i--;
        }
        return v;
    }
};