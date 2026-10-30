class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<vector<int>> sortedTasks;
        for(int i = 0; i < n; i++){
            sortedTasks.push_back({tasks[i][0], tasks[i][1], i});
        }

        sort(sortedTasks.begin(), sortedTasks.end());

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

        int i = 0;
        long long time = 0;

        vector<int> ans;

        while(i < n || !minHeap.empty()){
            if(minHeap.empty() && time <= sortedTasks[i][0]){
                time = sortedTasks[i][0];
            }

            while(i < n && sortedTasks[i][0] <= time){
                minHeap.push({sortedTasks[i][1], sortedTasks[i][2]});
                i++;
            }

            auto [processingTime, index] = minHeap.top();
            minHeap.pop();

            ans.push_back(index);

            time += processingTime;
        }

        return ans;
    }
};