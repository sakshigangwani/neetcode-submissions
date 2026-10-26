class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(auto s : strs){
            ans += to_string(s.length()) + "#" + s;
        }
        return ans;
    }

    vector<string> decode(string s) {
        if(s.size() == 0) return {};
        int i = 0;
        vector<string> ans;
        while(i < s.length()){
            int j = i;
            while(s[j] != '#'){
                j++;
            }
            int len = stoi(s.substr(i, j));
            string word = s.substr(j + 1, len);
            ans.push_back(word);
            i = j + 1 + len;
        }
        return ans;
    }
};
