#include <iostream>
#define endl '\n';
using namespace std;
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permute(int X[], int start, int end) {
    if (start == end) {
        cout << " | " << start << ": ";
        for (int i = 1; i <= end; i++) {
            printf("%d ", X[i]);
        }
        printf("\n");
        return;
    }

    for (int i = start; i <= end; i++) {
        cout << " | " << start << "."<< i << ": " <<  X[start] << " " << X[i] << " : ";
        swap(&X[start], &X[i]);
        for (int i = 1; i <= end; i++) {
            printf("%d ", X[i]);
        }
        cout << endl;
        permute(X, start + 1, end);
        swap(&X[start], &X[i]);
        cout << " | " << start << "."<< i  << ":2 " <<  X[start] << " " << X[i] << " : ";
        for (int i = 1; i <= end; i++) {
            printf("%d ", X[i]);
        }
    }
    cout << endl;
}

int main() {
    int n = 3;
    int X[] = {-1, 1, 2, 3};

    permute(X, 1, n);

    return 0;
}