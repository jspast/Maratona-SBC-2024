#include <bits/stdc++.h>

using namespace std;

bool can_partition(int n, int sum, vector<bool> &inc,
                   vector<int> &val, vector<vector<int8_t>> &tab)
{
    if (sum == 0)
        return true;

    else if (n <= 0)
        return false;

    if (tab[n - 1][sum] != -1)
        return tab[n - 1][sum];

    if (can_partition(n - 1, sum, inc, val, tab))
        return tab[n - 1][sum] = true;

    if (val[n - 1] <= sum) {
        if (can_partition(n - 1, sum - val[n - 1], inc, val, tab)) {
            inc[n - 1] = true;
            return tab[n - 1][sum] = true;
        }
    }

    return tab[n - 1][sum] = false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> in(n);
    int sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> in[i];
        sum += in[i];
    }

    if (sum % 2 != 0) {
        cout << -1 << "\n";
        return 0;
    }

    int target = sum / 2;
    vector<bool> is_a(n, false);

    vector<vector<int8_t>> tab(n, vector<int8_t>(sum, -1));

    if (!can_partition(n, target, is_a, in, tab)) {
        cout << -1 << "\n";
        return 0;
    }

    vector<int> a, b;

    for (int i = 0; i < n; i++) {

        if (is_a[i])
            a.push_back(in[i]);

        else
            b.push_back(in[i]);
    }

    bool first = true;
    int sum_a = 0, sum_b = 0;

    while (!a.empty() || !b.empty()) {

        if (!first)
            cout << " ";
        else
            first = false;

        if (sum_a <= sum_b) {
            cout << a.back();
            sum_a += a.back();
            a.pop_back();
        }
        else {
            cout << b.back();
            sum_b += b.back();
            b.pop_back();
        }
    }

    cout << "\n";

    return 0;
}
