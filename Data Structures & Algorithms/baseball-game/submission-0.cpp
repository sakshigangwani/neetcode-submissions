class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size();
        stack<int> st;
        for(int i = 0; i < n; i++){
            if(operations[i] == "C"){
                st.pop();
            }else if(operations[i] == "+"){
                int top1 = st.top();
                st.pop();
                int value = top1 + st.top();
                st.push(top1);
                st.push(value);
            }else if(operations[i] == "D"){
                st.push(2 * st.top());
            }else{
                st.push(stoi(operations[i]));
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