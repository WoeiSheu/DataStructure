// Version 1
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int partion(int r[], int first, int end) {
    int i = first;
    int j = end;
    int pivot = r[i];
    while(i < j) {
        while( (i < j) && (r[j] >= pivot) ) {   //右侧扫描,寻找小于pivot的元素前移
            j--;
        }
        r[i] = r[j];
        while( (i < j) && (r[i] <= pivot) ) {
            i++;
        }
        r[j] = r[i];
    }

    r[i] = pivot;
    return i;
}
void quickSort(int r[], int i, int j) {
    if(i < j) {
        int pivotLoc = partion(r,i,j);
        quickSort(r,i,pivotLoc-1);
        quickSort(r,pivotLoc+1,j);
    }
}

int main(int argc, char** argv) {
    srand(time(NULL));
    int n = 100;
    int x[n];
    for(int i = 0; i < n; i++) {
        x[i] = rand() % n;
        //int x[10] = {12,5764,312,233,455,132,2123,1232,123,24};
    }
    for(int i = 0; i < n; i++) {
        cout << x[i] << ' ';
    }
    cout << endl;

    quickSort(x,0,n-1);
    for(int i = 0; i < n; i++) {
        cout << x[i] << ' ';
    }
    return 0;
}

// Version 2
/*
#include<iostream>
#include<vector>

using namespace std;

void quickSort(std::vector<int>&, int left, int right);

int main(int argc, char** argv) {
    int input;
    std::vector<int> s;
    cin >> input;
    while(input != -1) {
        s.push_back(input);
        cin >> input;
    }
    for(int i = 0; i < s.size(); i++) {
        cout << s.at(i) << ' ';
    }
    cout << endl;

    quickSort(s, 0, s.size()-1);

    for(int i = 0; i < s.size(); i++) {
        cout << s.at(i) << ' ';
    }
    cout << endl;
}

void quickSort(std::vector<int>& s, int left, int right) {
    if( left >= right ) {
        return;
    }
    int i = left, j = right;
    int dummy = s.at(j);

    while(i < j) {
        while( (i < j) && (s.at(i) <= dummy) ) {
            i++;
        }
        if(i < j) {
            s.at(j--) = s.at(i);
        }

        while( (i < j) && (s.at(j) > dummy) ) {
            j--;
        }
        if(i < j) {
            s.at(i++) = s.at(j);
        }
    }

    s[i] = dummy;
    quickSort(s, left, i-1);
    quickSort(s, i+1, right);
}
*/
