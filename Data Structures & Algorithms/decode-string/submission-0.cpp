class Solution {
public:
    string decodeString(string s) {
        stack<int> countSt;
        stack<string> stringSt;
        int num = 0;
        string curr = "";
        for(auto c : s){
            if(isdigit(c)){
                num = num * 10 + (c - '0');
            }else if(c == '['){
                stringSt.push(curr);
                countSt.push(num);
                num = 0;
                curr = "";
            }else if(c == ']'){
                string prev = stringSt.top();
                stringSt.pop();

                int repeat = countSt.top();
                countSt.pop();

                while(repeat != 0){
                    prev += curr;
                    repeat--;
                }
                curr = prev;
            }else{
                curr += c;
            }
        }
        return curr;
    }
};