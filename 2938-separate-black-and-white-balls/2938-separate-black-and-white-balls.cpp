class Solution {
public:
    long long minimumSteps(string s) {
        int n=s.length();
        int c=0;
        long long b=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                c++;
            }
            else{
                b+=c;
            }
        }
        return b;
    }
};