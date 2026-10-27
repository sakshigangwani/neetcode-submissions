class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int> maxHeap;

        for(auto stone : stones){
            maxHeap.push(stone);
        }

        while(maxHeap.size() > 1){
            int stone1 = maxHeap.top(); maxHeap.pop();
            int stone2 = maxHeap.top(); maxHeap.pop();
            if(stone1 == stone2){
                continue;
            }else{
                int stone3 = abs(stone1 - stone2);
                maxHeap.push(stone3);
            }
        }
        if(maxHeap.size() == 1){
            return maxHeap.top();
        }
        return 0;
    }
};
