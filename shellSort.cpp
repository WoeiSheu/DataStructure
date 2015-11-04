#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void shellSort(int r[], int n) {
    for(int d = n/2; d >= 1; d = d/2) {
        for(int i = d+1; i <= n; i++) {
            if(r[i] < r[i-d]) {
                r[0] = r[i];
                int j;
                for(j = i-d; j > 0 && r[0] < r[j]; j = j-d) {
                    r[j+d] = r[j];
                }
                r[j+d] = r[0];
            }
        }
    }
}

int main(int argc, char** argv) {
    srand(time(NULL));
    int n = 10;
    int x[n+1];
    for(int i = 1; i < n+1; i++) {
        x[i] = rand() % n;
    }
    for(int i = 1; i < n+1; i++) {
        cout << x[i] << ' ';
    }
    cout << endl;

    shellSort(x,n);
    for(int i = 1; i < n+1; i++) {
        cout << x[i] << ' ';
    }
    return 0;
}
