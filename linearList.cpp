#include <iostream>

using namespace std;

const int MAXSIZE = 1000;
template<class T>
class LinearList {
private:
    int length;
    T data[MAXSIZE];
public:
    LinearList() {
        length = 0;
    }
    LinearList(T a[], int n) {
        if(n > MAXSIZE) throw "Exceed the max length.";
        for(int i = 0; i < n; i++) {
            data[i] = a[i];
        }
        length = n;
    }

    int getLength() {
        return length;
    }
    void printList();
    void insertItem(int index, T x);
    T deleteItem(int i);
    T getItem(int i);
    int locateItem(T x);
};
template<class T>
void LinearList<T>::printList() {
    for(int i = 0; i < length; i++) {
        cout << data[i] << ' ';
    }
    cout << endl;
}
template<class T>
void LinearList<T>::insertItem(int index, T x) {
    if(index > MAXSIZE) throw "Exceed the max length.";

    if(index > length || index < 1) throw "Wrong location.";

    for(int i = length; i >= index; i--) {
        data[i] = data[i-1];
    }
    data[index-1] = x;
    length++;
}
template<class T>
T LinearList<T>::deleteItem(int index) {
    if(0 == length) throw "Null List.";
    if(index > length || index < 1) throw "Wrong location.";

    T deleteReserve = data[index-1];
    for(int i = index; i < length; i++) {
        data[i-1] = data[i];
    }
    length--;
    return deleteReserve;
}
template<class T>
T LinearList<T>::getItem(int index) {
    if(index > length || index < 1) throw "Wrong location.";

    return data[index-1];
}
template<class T>
int LinearList<T>::locateItem(const T x) {         //const–ﬁ Œ∑¿÷πx±ª–ﬁ∏ƒ
    for(int i = 0; i < length; i++) {
        if(x == data[i]) {
            return i;
        }
    }
    return -1;
}

int main(int argc, char** argv) {
    int example[7] = {1,2,3,4,5,6,7};
    LinearList<int> linearList(example,7);

    linearList.printList();
    linearList.insertItem(linearList.getLength(),8);
    linearList.printList();
    linearList.deleteItem(8);
    linearList.printList();
    linearList.insertItem(7,7);
    linearList.printList();
    return 0;
}
