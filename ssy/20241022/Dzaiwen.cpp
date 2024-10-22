#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long countBadSubstrings(const string& s) {
    int n = s.length();
    vector<int> count(26, 0);
    long long result = 0;
    int left = 0, uniqueCount = 0;

    for (int right = 0; right < n; ++right) {
        if (count[s[right] - 'a'] == 0) {
            uniqueCount++;
        }
        count[s[right] - 'a']++;

        while (uniqueCount > 1) {
            count[s[left] - 'a']--;
            if (count[s[left] - 'a'] == 0) {
                uniqueCount--;
            }
            left++;
        }

        if (uniqueCount == 1) {
            result += right - left + 1;
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    long long badSubstrings = countBadSubstrings(s);
    cout << badSubstrings << endl;

    return 0;
}