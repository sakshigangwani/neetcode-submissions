class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int,int> mp;
        for(auto task : tasks){
            mp[task]++;
        }

        priority_queue<int> maxHeap;
        for(auto it : mp){
            maxHeap.push(it.second);
        }

        queue<pair<int, int>> cooldownQueue;

        int time = 0;

        while(!maxHeap.empty() || !cooldownQueue.empty()){
            time++;
            if(!maxHeap.empty()){
                int count = maxHeap.top();
                maxHeap.pop();

                count--;
                if(count > 0){
                    cooldownQueue.push({count, time + n});
                }
            }

            if(!cooldownQueue.empty() && cooldownQueue.front().second == time){
                maxHeap.push(cooldownQueue.front().first);
                cooldownQueue.pop();
            }
        }
        return time;
    }
};
