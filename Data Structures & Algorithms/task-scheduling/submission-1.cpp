class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        for(auto task : tasks){
            mp[task]++;
        }

        priority_queue<int> maxHeap;
        for(auto it : mp){
            maxHeap.push(it.second);
        }

        queue<pair<int,int>> coolDownQueue;

        int time = 0;

        while(!maxHeap.empty() || !coolDownQueue.empty()){
            time++;
            if(!maxHeap.empty()){
                int count = maxHeap.top();
                maxHeap.pop();

                count--;
                if(count > 0){
                    coolDownQueue.push({count, time + n});
                }
            }

            if(!coolDownQueue.empty() && coolDownQueue.front().second == time){
                maxHeap.push(coolDownQueue.front().first);
                coolDownQueue.pop();
            }
        }
        return time;
    }
};
