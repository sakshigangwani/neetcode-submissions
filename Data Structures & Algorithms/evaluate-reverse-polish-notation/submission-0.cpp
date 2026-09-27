class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> st;
        for(auto c : tokens){
            if(c == "+"){
                int top1 = st.top(); st.pop();
                int top2 = st.top(); st.pop();
                st.push(top1+top2);
            }else if(c == "-"){
                int top1 = st.top(); st.pop();
                int top2 = st.top(); st.pop();
                st.push(top2 - top1);
            }else if(c == "*"){
                int top1 = st.top(); st.pop();
                int top2 = st.top(); st.pop();
                st.push(top2 * top1);
            }else if(c == "/"){
                int top1 = st.top(); st.pop();
                int top2 = st.top(); st.pop();
                st.push(top2 / top1);
            }else{
                st.push(stoi(c));
            }
        }
        return st.top();
    }
};
