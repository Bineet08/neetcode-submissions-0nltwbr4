class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return n;
        sort(nums.begin(),nums.end());
        int ans = 1;
        int prev = nums[0];
        int curr = 1;
        for(int i=0;i<n;i++){
            if(prev==nums[i]) continue;
            if(prev+1==nums[i]) curr++;
            else curr = 1;
            prev = nums[i];
            ans = max(ans,curr);
        }
        return ans;
    }
};
