class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
     
         // nums[i] == target and abs(i - start) is minimized. 
        
        int ans = INT32_MAX;
        for(int i= 0;i < nums.size();i++){
            if(nums[i] == target){
                ans = min(ans,abs(i-start));
            }
        }
        return ans;
    }
};