class Solution {
public:
int minGroups(vector<vector<int>>& in) {
    vector<pair<int,int>> v;
    for(int i = 0; i < in.size(); i++) {
        v.push_back({in[i][0],0});
        v.push_back({in[i][1],1});
    }

    sort(v.begin(), v.end());
    int ans = 0;
    int open = 0;
    for(auto it : v) {
        if(it.second == 0){ 
            open++; 
            ans = max(ans,open);
        }
        else open--;  
    }

    return ans;
}
};