/*
Problem: Asteroid Collision
Difficulty: Medium

My Approach:
Used a stack to simulate collisions between asteroids moving in
opposite directions. When a collision occurs, compare magnitudes
and repeatedly remove smaller asteroids until the incoming asteroid
is destroyed, the collision resolves, or no collision remains possible.

Key Concepts:
- Stack
- Simulation
- Conditional iteration
- Collision handling
- Edge-case analysis

Time Complexity: O(n) amortized
Auxiliary Space Complexity: O(n)

What I Learned:
A stack is useful when a newly arriving element can interact with
and eliminate multiple previously processed elements.

Future Improvement:
Consider simplifying the collision logic while preserving the
three possible outcomes: left survives, right survives, or both
are destroyed.

Revision Note:
Push non-colliding asteroids → resolve collisions → preserve
survivors → reverse stack output.
*/
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        stack<int>st;
        int i=0;
        int n=asteroids.size();
        int k=0;
        while(i<n){
            // 1.
            if(st.empty())
             st.push(asteroids[i]);
             //2.
           else if((asteroids[i]<0&&st.top()>0)){ 
                while(!st.empty()&&(asteroids[i]<0&&st.top()>0)&&(abs(asteroids[i])>=st.top())){
                       if(abs(asteroids[i])==st.top()){
                       st.pop();
                       k=1;
                       break;
                       }
                       else
                       st.pop(); 
                }
                if(k==1)
                k=0;
               else if(!st.empty()&&abs(asteroids[i])<st.top()){
                   k=0;
                }
                else
                st.push(asteroids[i]);    
         }
         //3.
         else
         st.push(asteroids[i]);
         // iteration
            i++;
        }
        // pushing final stack to vector
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        // reversing vector
        reverse(ans.begin(),ans.end());
        return ans;
    }
};