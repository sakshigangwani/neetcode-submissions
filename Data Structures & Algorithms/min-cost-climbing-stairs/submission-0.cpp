class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev2 = cost[0];
        int prev = cost[1];
        for(int i = 2; i < cost.size(); i++){
            int curr = min(prev2, prev) + cost[i];
            prev2 = prev;
            prev = curr;
        }
        return min(prev2, prev);
    }
};
