class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int n1 = word1.size();
        int n2 = word2.size();
        int i = 0;
        int j = 0;
        while(i < n1 && j < n2){
            ans += word1[i];
            ans += word2[j];
            i++;
            j++;
        }
        while(i < n1){
            ans += word1[i];
            i++;
        }
        while(j < n2){
            ans += word2[j];
            j++;
        }
        return ans;
    }
};