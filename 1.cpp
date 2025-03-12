#include <iostream>
#include <vector>

using namespace std;

void divideAndConquer(vector<int>& items, int start, int end) {
    if (start == end) {
        cout << items[start] << " ";
        return;
    }
    
    int mid = (start + end) / 2;
    divideAndConquer(items, start, mid);
    divideAndConquer(items, mid + 1, end);
}

int main() {
    return 0;
}