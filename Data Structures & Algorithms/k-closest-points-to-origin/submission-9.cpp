class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<int,pair<int,int>>> maxHeap;
        for(auto point : points){
            int x = point[0];
            int y = point[1];
            int dist = (x * x) + (y * y);
            maxHeap.push({dist, {x, y}});
        }

        vector<vector<int>> ans;

        while(maxHeap.size() > k){
            maxHeap.pop();
        }

        while(maxHeap.size() != 0){
            auto it = maxHeap.top();
            ans.push_back({it.second.first, it.second.second});
            maxHeap.pop();
        }

        return ans;
    }
};
