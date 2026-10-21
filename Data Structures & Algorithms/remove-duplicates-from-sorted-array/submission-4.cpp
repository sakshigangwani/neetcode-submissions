class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        for(int j = 0; j < n; j++){
            if(nums[j] != nums[i]){
                i++;
                swap(nums[j], nums[i]);
            }
        }
        return i + 1;
    }
};