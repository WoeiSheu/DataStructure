#include <iostream>

using namespace std;

const bool HEAD = true;
const bool TAIL = false;

template<class T>
struct Node {
    T value;
    struct Node<T> * next;  //T¿ÉÊ¡ÂÔ
};

template<class T>
class SingleLinkedList {
private:
    Node<T> * head;
public:
    SingleLinkedList() {
        head = new Node<T>;
        head->next = NULL;
    }
    SingleLinkedList(T a[], int n, bool type);
    ~SingleLinkedList();
    int getLength();
    void printList();
    Node<T> * getItem(int index);
    void insertItem(int index, T x);
    T deleteItem(int index);
    int locateItem(T x);
};
template<class T>
SingleLinkedList<T>::SingleLinkedList(T a[], int n, bool type) {
    if(type == HEAD) {
        head = new Node<T>;
        head->next = NULL;
        for(int i = n-1; i >= 0; i--) {
            Node<T> * s = new Node<T>;
            s->next = head->next;
            s->value = a[i];
            head->next = s;
        }
    }
    if(type == TAIL) {
        head = new Node<T>;
        Node<T> * tail = head;
        for(int i = 0; i < n; i++) {
            Node<T> * s = new Node<T>;
            s->value = a[i];
            tail->next = s;
            tail = s;
        }
        tail->next = NULL;
    }
}
template<class T>
SingleLinkedList<T>::~SingleLinkedList() {
    Node<T> * p = head;
    while(p) {
        head = p;
        p = p->next;
        delete head;
    }
}


int main(int argc, char** argv) {

    return 0;
}
