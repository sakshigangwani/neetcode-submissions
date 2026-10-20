class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(auto s : strs){
            ans += to_string(size(s)) + "#" + s;
        }
        return ans;
    }

    vector<string> decode(string s) {
        if(s.length() == 0) return {};
        vector<string> ans;
        int i = 0;
        int n = s.length();
        while(i < n){
            int j = i;
            while(s[j] != '#'){
                j++;
            }

            int length = stoi(s.substr(i, j - i));
            string word = s.substr(j + 1, length);
            ans.push_back(word);

            i = j + 1 + length;
        }
        return ans;
    }
};
