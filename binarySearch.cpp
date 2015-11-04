#include <iostream>

using namespace std;

int binarySearch(int a[], int n, int key) {     //a[0]不用,a[1]~a[n]存储数据
    int low = 1;
    int high = n;
    while(low <= high) {
        int mid = (low+high) / 2;
        if(key == a[mid]) {
            return mid;
        } else if(key < a[mid]) {
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    return 0;
}

int main(int argc, char** argv) {
    int x[11] = {0,1,5,8,10,16,17,20,39,46,66};
    int index = binarySearch(x,10,20);
    cout << index;
    return 0;
}
