class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += pal1(s,i) + pal2(s,i);
        }
        return ans;
    }
    int pal1(string &s, int idx){
        int n = s.size();
        int i = 0;
        int ans = 0;
        while(idx-i>=0 && idx+i<n && s[idx-i]==s[idx+i]){
            ans++;
            i++;
        }
        return ans;
    }
    int pal2(string &s, int idx){
        int n = s.size();
        int i = 0;
        int ans = 0;
        while(idx-i>0 && idx+i<n && s[idx-i-1]==s[idx+i]){
            ans++;
            i++;
        }
        return ans;
    }
};
