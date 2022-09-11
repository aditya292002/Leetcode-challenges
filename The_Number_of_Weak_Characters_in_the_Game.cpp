#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define vs vector<string>
#define vvs vector<vs>
#define pb push_back
#define ppb pop_back
#define pii pair<int,int>
#define ff first
#define ss second
#define debug(a) cout<<#a<<" ";printt(a);cout<<endl;
#define ll long long
#define FOR(i,s,e) for(int i = s; i < e;i++)
#define ll long long
#define vs vector<string>
#define nline cout<<endl;
#define sort_(arr) sort(arr.begin(),arr.end());



bool static  waySort(vector<int> &a, vector<int> &b) {
    if(a[0] < b[0]) return true;
    else if(a[0] == b[0]) 
        if(a[1] > b[1]) return true;
    return false;
}

int numberOfWeakCharacters(vector<vector<int>>& p) {
    int n = p.size();
    sort(p.begin(), p.end(), waySort);
    int maxi = p[n-1][1];
    int cnt = 0;
    for(int i = n-2; i >= 0; i--) {
        if(p[i][0] != p[n-1][0]) {
            if(maxi > p[i][1]) {
                cnt++;
            }
        }
        maxi = max(maxi, p[i][1]);
    }
   return cnt;
}
int main() {
    vvi p = {{2,2},{3,3}};
    // vvi p = {{7,9},{10,7},{6,9},{10,4},{7,5},{7,10}};
    cout<<numberOfWeakCharacters<<endl;
}
