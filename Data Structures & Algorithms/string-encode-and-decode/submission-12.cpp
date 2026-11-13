class Solution {
public:
    string encode(vector<string>& strs) {
        string s = "";
        for(auto str : strs){
            s += to_string(str.length()) + "#" + str;
        }
        return s;
    }

    vector<string> decode(string s) {
        if(s.length() == 0) return {};
        int n = s.length();
        vector<string> ans;
        int i = 0;
        while(i < n){
            int j = i;
            while(s[j] != '#'){
                j++;
            }

            int len = stoi(s.substr(i, j - i));
            string word = s.substr(j+1, len);
            ans.push_back(word);
            i = j + 1 + len;
        }
        return ans;
    }
};
