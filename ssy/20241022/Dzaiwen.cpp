#include <bits/stdc++.h>
using namespace std;

const int N = 5e6 + 10;
const int ALPHA = 26;

string s;
long long ans;
vector<int> positions[ALPHA];
int head[ALPHA];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> s;
    int n = s.length();
    
    // 预处理每个字符的位置
    for (int i = 0; i < n; i++) {
        positions[s[i] - 'a'].push_back(i);
    }
    
    // 添加哨兵
    for (int i = 0; i < ALPHA; i++) {
        positions[i].push_back(n);
        positions[i].push_back(n);
    }
    
    vector<int> times;
    times.reserve(ALPHA * 2);
    vector<int> diff(ALPHA * 2);
    
    // 枚举左端点
    for (int left = 0; left < n; left++) {
        times.clear();
        
        // 更新每个字符的head指针
        for (int j = 0; j < ALPHA; j++) {
            while (positions[j][head[j]] < left) head[j]++;
            times.push_back(positions[j][head[j]]);
            times.push_back(positions[j][head[j] + 1]);
        }
        
        // 离散化
        sort(times.begin(), times.end());
        times.erase(unique(times.begin(), times.end()), times.end());
        
        fill(diff.begin(), diff.begin() + times.size(), 0);
        
        // 差分处理
        for (int j = 0; j < ALPHA; j++) {
            int start = lower_bound(times.begin(), times.end(), positions[j][head[j]]) - times.begin();
            int end = lower_bound(times.begin(), times.end(), positions[j][head[j] + 1]) - times.begin();
            diff[start]++;
            diff[end]--;
        }
        
        // 前缀和计算结果
        for (int j = 1; j < times.size(); j++) {
            diff[j] += diff[j - 1];
            if (diff[j - 1]) {
                ans += times[j] - times[j - 1];
            }
        }
    }
    
    cout << ans << '\n';
    return 0;
}