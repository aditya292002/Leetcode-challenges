int global_x;

bool helper(int &a, int &b)
{
    if(abs(a - global_x) == abs(b - global_x))
        return a < b;
    
    return abs(a - global_x) < abs(b - global_x);
}

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        global_x = x;
        sort(arr.begin(), arr.end(), helper);

        vector<int> tmp;
        int i = 0;
        while(k!=0) {
            tmp.push_back(arr[i]);
            i++;
            k--;
        }    
        sort(tmp.begin(), tmp.end());
        return tmp;
    }
};