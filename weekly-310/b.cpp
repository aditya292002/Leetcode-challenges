class Solution {
public:

int partitionString(string s) {
    int n = s.size();
    int i = 0;
    int cnt = 0;
    while (i < n) {
        unordered_map<char, int> mp;
        while(i < n) {
            if(mp[s[i]] == 0) {
                mp[s[i]] = 1;
                i++;
            }
            else {
                break;
            }
        }
        cnt++;
    }
    return cnt;
}

};