class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        for(int i = 0; i < n; i++){
            if(st.empty()){
                st.push(asteroids[i]);
            }else if(st.top() > 0 && asteroids[i] < 0){
                bool destroyed = false;
                while(!st.empty() && st.top() > 0){
                    if(st.top() < abs(asteroids[i])){
                        st.pop();
                    }else if(st.top() == abs(asteroids[i])){
                        destroyed = true;
                        st.pop();
                        break;
                    }else{
                        destroyed = true;
                        break;
                    }
                }
                if(!destroyed){
                    st.push(asteroids[i]);
                }
            }else{
                st.push(asteroids[i]);
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};