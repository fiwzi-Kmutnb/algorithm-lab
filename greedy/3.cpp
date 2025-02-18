#include <iostream>
#include <vector>
using namespace std;

void pwm(vector<int>& items, int k, int start, vector<int>& current, int& count) {
    if (current.size() == k) {
        for (int i = 0; i < k; ++i) {
            cout << current[i] << " ";
        }
        cout << endl;
        count++;
        return;
    }
    
    for (int i = start; i < items.size(); ++i) {
        current.push_back(items[i]); 
        pwm(items, k, i + 1, current, count);  
        current.pop_back(); 
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> items(n);
    for (int i = 0; i < n; ++i) {
        items[i] = i + 1; 
    }
    
    vector<int> current;
    int count = 0;
    
    pwm(items, k, 0, current, count);
    
    cout << count << endl;

    return 0;
}
