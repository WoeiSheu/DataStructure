#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

int const MAXSIZE = 100;

void mergeTwoArray(int* r, int* r1, int s, int m, int t);
void mergePass(int* r, int* r1, int n, int h);
void mergeSort(int* r, int* r1, int n);             // Not recursive.
void mergeSort(int* r, int* r1, int s, int n);      // Recursive.

int main(int argc, char** argv) {
    srand(time(NULL));
    int n = 6;
    int x[n];
    for(int i = 0; i < n; i++) {
        x[i] = rand() % n;
    }
    for(int i = 0; i < n; i++) {
        cout << x[i] << ' ';
    }
    cout << endl;

    int x1[n];
    mergeSort(x,x1,0,n-1);

    for(int i = 0; i < n; i++) {
        cout << x1[i] << ' ';
    }
    cout << endl;

    return 0;
}

void mergeTwoArray(int* r, int* r1,int s, int m, int t) {
    int i = s;      // i point to r[s~m]
    int j = m+1;    // j point to r[m+1,t]
    int k = s;

    while( i <= m && j <= t ) {
        if(r[i] <= r[j]) {
            r1[k++] = r[i++];
        } else {
            r1[k++] = r[j++];
        }
    }

    while( i <= m ) {
        r1[k++] = r[i++];
    }
    while( j <= t ) {
        r1[k++] = r[j++];
    }
}
void mergePass(int* r, int* r1, int n, int h) {
    int i = 1;
    while(i <= n-2*h+1) {
        mergeTwoArray(r, r1, i, i+h-1, i+2*h-1);
        i += 2*h;
    }
    if(i < n-h+1) {
        mergeTwoArray(r, r1, i, i+h-1, n);
    } else {
        for(; i <= n; i++) {
            r1[i] = r[i];
        }
    }
}
void mergeSort(int* r, int* r1, int n) {
    int h = 1;
    while(h < n) {
        mergePass(r, r1, n ,h);
        h = 2*h;
        mergePass(r1, r, n, h);
        h = 2*h;
    }
}
void mergeSort(int* r, int* r1, int s, int t) {
    int r2[MAXSIZE];
    if(s == t) {
        r1[s] = r[s];
    } else {
        int m = (s+t)/2;
        mergeSort(r, r2, s, m);
        mergeSort(r, r2, m+1, t);

        mergeTwoArray(r2, r1, s, m, t);
    }
}