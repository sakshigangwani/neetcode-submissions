class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size();
        stack<int> st;
        for(auto it : operations){
            if(it == "+"){
                int top = st.top(); st.pop();
                int sum = top + st.top();
                st.push(top);
                st.push(sum);
            }else if(it == "D"){
                st.push(2 * st.top());
            }else if(it == "C"){
                st.pop();
            }else{
                st.push(stoi(it));
            }
        }
        int sum = 0;
        while(!st.empty()){
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};