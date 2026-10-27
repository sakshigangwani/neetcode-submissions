class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long long, pair<int,int>>> maxHeap;
        for(auto point : points){
            int x = point[0];
            int y = point[1];
            int dist = 1LL * x * x + 1LL * y * y;
            maxHeap.push({dist, {x, y}});
            if(maxHeap.size() > k){
                maxHeap.pop();
            }
        }

        vector<vector<int>> ans;
        while(maxHeap.size() != 0){
            auto point = maxHeap.top().second;
            maxHeap.pop();

            ans.push_back({point.first, point.second});
        }
        return ans;
    }
};
