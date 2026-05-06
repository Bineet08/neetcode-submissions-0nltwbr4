class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,INT_MIN);
        dp[0] = nums[0];
        dp[1] = max(dp[0],nums[1]);
        for(int i=2;i<n;i++){
            dp[i] = dp[i-2] + nums[i];
            dp[i] = max(dp[i],dp[i-1]);
        }
        return dp[n-1];
    }
};
