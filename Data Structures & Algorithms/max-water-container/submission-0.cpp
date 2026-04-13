class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0, j = heights.size()-1;
        int ans = 0;
        while(i<j){
            int sz = j-i;
            int curr = min(heights[i],heights[j])*sz;
            ans = max(ans,curr);
            if(heights[i]<heights[j]) i++;
            else j--;
        }
        return ans;
    }
};
