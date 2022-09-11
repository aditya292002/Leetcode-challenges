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

#define un unordered_map
#define fr front
#define con continue
int dir[2][2] = {{1, 0}, {0, 1}};
// vector<vector<int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};
template<class T>void printt(vector<T> vec){cout<<" : [ ";for(auto i : vec){cout<<i<<" ";}cout<<"] "<<endl;}
template<class T>void printt(T var){cout<<" : "<<var<<endl;}
template<class T>void printt(vector<vector<T>> vec){cout<<endl;cout<<"["<<endl;for(auto ii : vec){cout<<"[ ";for(auto a : ii){cout<<a<<" ";}cout<<"]"<<endl;}cout<<"]"<<endl;}
template<class T> void printt(vector<vector<vector<T>>> vec) { cout<<endl;for(auto it3 : vec){cout<<"[ "<<endl;for(auto it2 : it3) {for(auto it1 : it2) {     cout<<it1<<" ";}   cout<<endl;}cout<<"] "<<endl;cout<<endl;}cout<<endl;}
template<class T>void printt(pair<T,T> myPair){cout<<": { "<<myPair.ff<<" "<<myPair.ss<<" }"<<endl;}
template<class T>void printt(queue<T> q) {while(!q.empty()) {cout<<q.front()<<" ";;q.pop();}cout<<endl;}
template<class T>void printt(set<T> s) {for(auto it : s) {cout<<it<<" ";} cout<<endl;}
template<class T>void printt(multiset<T> s) {for(auto it : s) {cout<<it<<" ";} cout<<endl;}

void printArray(int arr[], int n){for(int i = 0; i < n; i++){cout<<arr[i]<<" ";}cout<<endl;}

//--------------------------------------------------------------------------------------------------------------------------------------

int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
    int mod = 1e9 + 7;
    vector<pair<int,int>> v;
    for(int i = 0; i < n; i++) {
        v.push_back({efficiency[i], speed[i]});
    }

    sort(v.begin(), v.end(), greater<pair<int,int>>());
    priority_queue<int, vector<int>, greater<int>>pq;                    
    long ans = INT_MIN,sum=0;                                               
    for(int i=0;i<n;i++)
    {
        int efficiency = v[i].first,speed = v[i].second;
    //     sum+=speed;
    //     pq.push(speed);
    //     if(pq.size()>k)
    //     {
    //         sum-=pq.top();
    //         pq.pop();   
    //     }
    //     ans=max(ans,sum*efficiency);


        if(pq.size() >= k) { sum -= pq.top(); pq.pop(); }
        sum += speed;
        pq.push(speed);
        ans=max(ans,sum*efficiency);
    }


    return ans%mod;
}

int main() {
    // test cases
    // int n = 6; vi speed = {3,5,1,10,3,8}; vi efficiency = {9,7,5,4,3,2}; int k = 2;
    int n = 6; vi speed = {9,9,8}; vi efficiency = {3,2,1}; int k = 2;
    // int n = 6; vi speed = {2,10,3,1,5,8}; vi efficiency = {5,4,3,9,7,2}; int k = 2;
    // int n = 6 , k = 3 ; vi speed = {2,10,3,1,5,8}, efficiency = {5,4,3,9,7,2};
    debug(maxPerformance(n,speed,efficiency,k))
}
