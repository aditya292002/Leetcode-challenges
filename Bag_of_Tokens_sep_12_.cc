class Solution {
public:
int bagOfTokensScore(vector<int>& tokens, int power) {
    sort(tokens.begin(),tokens.end());
    int ans = 0;
    int n = tokens.size();
    int i = 0, j = n-1, score = 0;
    while(i <= j) {
        if(power >= tokens[i]) {
            power -= tokens[i]; 
            score++; i++;
            ans = max(ans, score);
        }
        else {
            power += tokens[j];
            score--; j--;
        }
        if(score < 0) return 0; 
    }
    return ans;
}
};