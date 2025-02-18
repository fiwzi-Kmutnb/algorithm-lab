#include <iostream>
#include <vector>

using namespace std;

void permutations(int n, int k, vector<int>& curr_perm, vector<vector<int>>& result, vector<bool>& used) {
    if (curr_perm.size() == k) {
        result.push_back(curr_perm);
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            used[i] = true;
            curr_perm.push_back(i);
            permutations(n, k, curr_perm, result, used);
            curr_perm.pop_back();
            used[i] = false;
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> result;
    vector<int> curr_perm;
    vector<bool> used(n + 1, false);
    
    permutations(n, k, curr_perm, result, used);
    for (const auto& perm : result) {
        for (int num : perm) {
            cout << num << ' ';
        }
        cout << endl;
    }
    cout << result.size() << endl;
    
    return 0;
}
