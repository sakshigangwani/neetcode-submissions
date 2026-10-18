class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int el = 0;
        int count = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(count == 0){
                el = nums[i];
            }

            if(el == nums[i]){
                count++;
            }else{
                count--;
            }

            if(count < 0){
                count = 0;
            }
        }
        return el;
    }
};