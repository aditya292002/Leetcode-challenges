#include<bits/stdc++.h>
using namespace std;



// Solution - 1
string pushDominoes_(string dominoes) {
    int n = dominoes.size();
    string rightMoves = dominoes;
    int i = 0;
    int flag = 0;
    while(i < n) {
        if(rightMoves[i] == 'R') 
            flag = 1;
        else if(rightMoves[i] == '.') {
            if(flag == 1) {
                rightMoves[i] = 'R';
            }
        } 
        else {
            flag = 0;
        }
        i++;
    }   


    string leftMoves = dominoes;
    i = n-1;
    flag = 0;
    while(i >= 0) {
        if(leftMoves[i] == 'L') {
            flag = 1;
        }
        else if(leftMoves[i] == '.') {
            if(flag == 1) {
                leftMoves[i] = 'L';
            }
        }
        else {
            flag = 0;
        }
        i--;
    }

    // debug(rightMoves)
    // debug(leftMoves)
    string ans = dominoes;
    vector<pair<int,int>> ranges;


    int start_range;
    i = 0;
    while(i < n) {    
        if(rightMoves[i] == leftMoves[i]) {
            i++;
            continue;
        }

        else if(rightMoves[i] == '.' and leftMoves[i] == 'L') {
            ans[i] = 'L'; i++; continue;
        }        

        else if(rightMoves[i] == 'R' and leftMoves[i] == '.') {
            ans[i] = 'R'; i++; continue;
        }


        ans[i] = '.';

        start_range = i;
        while(i < n and rightMoves[i] != leftMoves[i]) {
            i++;
        }
        i--;
        ranges.push_back({start_range, i});

        i++;
    }

    // debug(ans);
    // debug(ranges)

    for(auto it : ranges) {
            
        int st = it.first;
        int end = it.second;
        
        // debug(st)
        // debug(end)

        while(st < end) {
            ans[st] = ans[st-1];
            ans[end] = ans[end+1];
            // debug(ans)
            st++;
            end--;    
        }

        if(st == end) {
            ans[st] = '.';
        }
    }
    

    return ans;
}



// Solution - 2
// https://leetcode.com/problems/push-dominoes/discuss/2628923/C%2B%2B-or-Two-Pointer-or-Diagram-or-Related-Problems
// Very nice explanation

string pushDominoes(string s) {
    int N = s.size(), right = -1;
    for (int i = 0; i < N; ++i) {
        if (s[i] == 'L') {
            if (right == -1) { 
                // Step 2
                for (int j = i - 1; j >= 0 && s[j] == '.'; --j) {
                  s[j] = 'L';  
                } 
            } else {
                // Step 8
                for (int j = right + 1, k = i - 1; j < k; ++j, --k) {
                    s[j] = 'R';
                    s[k] = 'L';
                } 
                right = -1;
            }
        } else if (s[i] == 'R') {
            if (right != -1) {
                for (int j = right + 1; j < i; ++j) s[j] = 'R';
            }
            right = i;
        }
    }
    if (right != -1) {
        for (int j = right + 1; j < N; ++j) s[j] = 'R';
    }
    return s;
}

int main() {
    // string dominoes = ".L.R...LR..L..";
    // string dominoes = "RR.L";
    string dominoes = "L.....RR.RL.....L.R.";
    cout<<pushDominoes(dominoes)<<endl;;
}