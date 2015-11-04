#include<iostream>
#include<vector>

using namespace std;

void mergeTwoArray(int* r, int s, int m, int t);
void mergeSort(int* r, int* r1, int n);

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
