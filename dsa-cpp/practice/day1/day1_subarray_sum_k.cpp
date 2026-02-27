#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k){
    unordered_map<int,int> mp;
    int sum = 0, cnt = 0;
    mp[0] = 1;
    for(int i = 0; i < nums.size(); i++){
        sum += nums[i];
        int cur = sum - k;
        if(mp.count(cur)){
            cnt += mp[cur];
        }
        mp[sum]++;
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    while (cin >> n >> k) {
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        cout << subarraySum(nums, k) << endl;
        return 0;
    }

}
