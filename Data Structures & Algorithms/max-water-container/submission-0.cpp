class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int start = 0;
        int end = n - 1;
        int maxArea = INT_MIN;
        while(start < end){
            int width = end - start;
            int height = min(heights[start], heights[end]);
            maxArea = max(maxArea, height * width);
            if(heights[start] <= heights[end]){
                start++;
            }else{
                end--;
            }
        }
        return maxArea;
    }
};
