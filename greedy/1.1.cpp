#include <iostream>
using namespace std;

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void countingSort(char arr[], int n) {
    char output[n+1];
    int count[256] = {0};

    for (int i = 1; i <= n; i++) {
        count[arr[i]]++;
    }

    for (int i = 1; i < 256; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n; i >= 1; i--) {
        output[count[arr[i]]] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 1; i <= n; i++) {
        arr[i] = output[i];
    }
}

void permute(char X[], int start, int end) {
    if (start == end) {
        for (int i = 1; i <= end; i++) {
            cout << X[i];
        }
        cout << endl;
        return;
    }
    
    countingSort(X + start - 1, end - start + 1);
    
    for (int i = start; i <= end; i++) {
        swap(&X[start], &X[i]);
        permute(X, start + 1, end);
        swap(&X[start], &X[i]);
    }
}

int main() {
    int n;
    cin >> n;
    char *X = new char[n + 1];
    X[0] = ' '; 
    
    for(int i = 1; i <= n; i++) {
        cin >> X[i];
    }
    
    countingSort(X,n);
    
    permute(X, 1, n);
    
    delete[] X;
    return 0;
}