class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> st;
        for(auto it : tokens){
            if(it == "+"){
                int top1 = st.top(); st.pop();
                int top2 = st.top(); st.pop();
                st.push(top1 + top2);
            }else if(it == "-"){
                int top1 = st.top(); st.pop();
                int top2 = st.top(); st.pop();
                st.push(top2 - top1);
            }else if(it == "*"){
                int top1 = st.top(); st.pop();
                int top2 = st.top(); st.pop();
                st.push(top2 * top1);
            }else if(it == "/"){
                int top1 = st.top(); st.pop();
                int top2 = st.top(); st.pop();
                st.push(top2 / top1);
            }else{
                st.push(stoi(it));
            }
        }
        return st.top();
    }
};
