class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return *max_element(nums.begin(), nums.end());
        vector<int>dp1(n,INT_MIN), dp2(n,INT_MIN);
        dp1[0] = nums[0];
        dp1[1] = max(dp1[0],nums[1]);
        for(int i=2;i<n-1;i++){
            dp1[i] = dp1[i-2] + nums[i];
            dp1[i] = max(dp1[i],dp1[i-1]);
        }
        dp2[1] = nums[1];
        dp2[2] = max(dp2[1],nums[2]);
        for(int i=3;i<n;i++){
            dp2[i] = dp2[i-2] + nums[i];
            dp2[i] = max(dp2[i],dp2[i-1]);
        }
        return max(dp1[n-2],dp2[n-1]);
    }
};
