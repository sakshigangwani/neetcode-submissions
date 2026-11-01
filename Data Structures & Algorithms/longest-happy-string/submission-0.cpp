class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> maxHeap;
        if(a > 0) maxHeap.push({a, 'a'});
        if(b > 0) maxHeap.push({b, 'b'});
        if(c > 0) maxHeap.push({c, 'c'});

        string ans = "";
        
        while(!maxHeap.empty()){
            auto [freq, ch] = maxHeap.top();
            maxHeap.pop();

            int n = ans.length();

            if(n >= 2 && ans[n-1] == ch && ans[n-2] == ch){
                if(maxHeap.empty()) break;

                auto [freq2, ch2] = maxHeap.top();
                maxHeap.pop();

                ans += ch2;
                freq2--;
                if(freq2 > 0){
                    maxHeap.push({freq2, ch2});
                }

                maxHeap.push({freq, ch});
            }else{
                ans += ch;
                freq--;

                if(freq > 0){
                    maxHeap.push({freq, ch});
                }
            }
        }
        return ans;
    }
};