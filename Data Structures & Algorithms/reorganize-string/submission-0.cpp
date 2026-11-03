class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        for(auto it : s){
            mp[it]++;
        }

        priority_queue<pair<int, char>> maxHeap;
        for(auto it : mp){
            maxHeap.push({it.second, it.first});
        }

        queue<pair<int,char>> coolDownQueue;
        string ans = "";

        while(!maxHeap.empty()){
            auto it = maxHeap.top();
            maxHeap.pop();

            int count = it.first;
            char ch = it.second;

            ans += ch;
            count--;

            if(!coolDownQueue.empty()){
                maxHeap.push(coolDownQueue.front());
                coolDownQueue.pop();
            }

            if(count > 0){
                coolDownQueue.push({count, ch});
            }
        }

        if(ans.length() != s.length()){
            return "";
        }

        return ans;
    }
};