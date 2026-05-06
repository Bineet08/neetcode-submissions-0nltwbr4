class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string res;
        for(int i=0;i<n;i++){
            string curr1 = pal1(s,i);
            string curr2 = pal2(s,i);
            if(res.size() < curr1.size()) res=curr1;
            if(res.size()<curr2.size()) res = curr2;
        }
        return res;
    }
    string pal1(string &s, int idx){
        int n = s.size();
        string str="";
        int i=0;
        while(idx-i>=0 && idx+i < n && s[idx-i]==s[idx+i]){
            i++;
        }
        str = s.substr(idx-i+1,2*i-1);
        return str;
    }

    string pal2(string &s, int idx){
        int n = s.size();
        string str="";
        int i=0;
        while(idx-i>0 && idx+i < n && s[idx-i-1]==s[idx+i]){
            i++;
        }
        str = s.substr(idx-i,2*i);
        return str;
    }
};
