class Solution {
public:
    char toLowerCase(char ch){
        if(ch >= 'a' && ch <= 'z'){
            return ch;
        }
        return ch + 32;
    }
    bool isAlpha(char ch){
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')){
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.length() - 1;
        while(start < end){
            if(!isAlpha(s[start])){
                start++;
                continue;
            }

            if(!isAlpha(s[end])){
                end--;
                continue;
            }

            if(toLowerCase(s[start]) != toLowerCase(s[end])){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};
