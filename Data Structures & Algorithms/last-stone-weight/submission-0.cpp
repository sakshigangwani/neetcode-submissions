class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;

        for(auto stone : stones){
            maxHeap.push(stone);
        }

        while(maxHeap.size() > 1){
            int largest = maxHeap.top(); maxHeap.pop();
            int second = maxHeap.top(); maxHeap.pop();

            if(largest != second){
                maxHeap.push(largest - second);
            }
        }

        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};
