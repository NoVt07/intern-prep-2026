#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& h) {
        int n = h.size();
        if (n <= 2) return 0;

        // 1. Tìm đỉnh cao nhất
        int max_val = 0, max_idx = 0;
        for (int i = 0; i < n; i++) {
            if (h[i] > max_val) {
                max_val = h[i];
                max_idx = i;
            }
        }

        int ans = 0;

        // 2. Duyệt từ trái sang đỉnh cao nhất
        int left_max = 0;
        for (int i = 0; i < max_idx; i++) {
            if (h[i] > left_max) {
                left_max = h[i];
            } else {
                ans += left_max - h[i];
            }
        }

        // 3. Duyệt từ phải sang đỉnh cao nhất
        int right_max = 0;
        for (int i = n - 1; i > max_idx; i--) {
            if (h[i] > right_max) {
                right_max = h[i];
            } else {
                ans += right_max - h[i];
            }
        }

        return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n ) {
        vector<int> h(n);
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }
        cout<<trap(h);
        return 0;
    }
}
