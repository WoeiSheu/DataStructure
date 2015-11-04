#include <iostream>

using namespace std;

void sift(int r[], int k, int m) {
    int i = k, j = 2*i;
    while(j <= m) {
        if(j < m && r[j] < r[j+1]) {
            j++;
        }
        if(r[i] >= r[j]) {
            break;
        } else {
            r[0] = r[i];
            r[i] = r[j];
            r[j] = r[0];
            i = j;
        }
    }
}

void heapSort(int r[], int n) {
    for(int i = n/2; i >= 1; i--) {     //建堆
        sift(r,i,n);
    }
    for(int i = n; i > 1; i--) {
        //输出堆顶元素
        r[0] = r[1];
        r[1] = r[i];
        r[i] = r[0];

        sift(r, 1, i-1);    //重新建堆
    }
}

int main(int argc, char** argv) {
    int x[11] = {0,234,245,21,433,53,344,98,109,453,311};
    heapSort(x,10);
    for(int i = 1; i < 11; i++) {
        cout << x[i] << ' ';
    }
    return 0;
}
