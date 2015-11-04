#include <iostream>

using namespace std;

const int RECURSION = 0;

template<class T>
struct BinaryNode {
    T value;
    BinaryNode<T> * leftChild;
    BinaryNode<T> * rightChild;
};

template<class T>
class BinaryTree {
private:
    void createBinaryTree(BinaryNode<T> * &R, T data[], int i, int n);
    void releaseBinaryTree(BinaryNode<T> * R);
public:
    BinaryNode<T> * root;
    BinaryTree(T data[], int n);
    void preOrder(BinaryNode<T> * R);
    void inOrder(BinaryNode<T> * R);
    void postOrder(BinaryNode<T> * R);
    void levelOrder(BinaryNode<T> * R);
    ~BinaryTree();
};
template<class T>
void BinaryTree<T>::createBinaryTree(BinaryNode<T> * &R, T data[], int i, int n) {
    if(i <= n ) {
        R = new BinaryNode<T>;
        R->value = data[i-1];
        createBinaryTree(R->leftChild, data, 2*i, n);
        createBinaryTree(R->rightChild, data, 2*i+1, n);
    } else {
        R = NULL;
    }
}
template<class T>
BinaryTree<T>::BinaryTree(T data[], int n) {
    createBinaryTree(root,data,1,n);
}
template<class T>
void BinaryTree<T>::preOrder(BinaryNode<T> * R) {
    if(RECURSION == 1) {
        if(R != NULL) {
            cout << R->value << ' ';
            preOrder(R->leftChild);
            preOrder(R->rightChild);
        }
    } else {
        BinaryNode<T> * s[100]; //ջ
        int top = -1;
        while(top != -1 || R != NULL) {
            if(R != NULL) {
                cout << R->value << ' ';
                s[++top] = R;
                R = R->leftChild;
            } else {
                R = s[top--];
                R = R->rightChild;
            }
        }
    }
}
template<class T>
void BinaryTree<T>::inOrder(BinaryNode<T> * R) {
    if(RECURSION == 1) {
        if(R != NULL) {
            inOrder(R->leftChild);
            cout << R->value << ' ';
            inOrder(R->rightChild);
        }
    } else {
        BinaryNode<T> * s[100];
        int top = -1;
        while(top != -1 || R != NULL) {
            if(R != NULL) {
                s[++top] = R;
                R = R->leftChild;
            } else {
                R = s[top--];
                cout << R->value << ' ';
                R = R->rightChild;
            }
        }

    }
}
template<class T>
void BinaryTree<T>::postOrder(BinaryNode<T> * R) {
    if(RECURSION == 1) {
        if(R != NULL) {
            postOrder(R->leftChild);
            postOrder(R->rightChild);
            cout << R->value << ' ';
        }
    } else {
        BinaryNode<T> * s[100];
        int tag[100];
        int top = -1;
        while(R != NULL || top != -1) {
            while(R != NULL) {
                s[++top] = R;
                tag[top] = 0;
                R = R->leftChild;
            }
            while(top != -1 && tag[top]==1) {
                R = s[top--];
                cout << R->value << ' ';
            }

            if(top != -1) {
                tag[top] = 1;
                R = s[top];
                R = R->rightChild;
            } else {
                break;
            }
        }
    }
}
template<class T>
void BinaryTree<T>::levelOrder(BinaryNode<T> * R) {
    BinaryNode<T> * s[100];
    int frontIndex = 0, rearIndex = 0;
    if(R != NULL) {
        s[++rearIndex] = R;
    }

    while(frontIndex != rearIndex) {
        BinaryNode<T> * p = s[++frontIndex];
        cout << p->value << ' ';
        if(p->leftChild != NULL) {
            s[++rearIndex] = p->leftChild;
        }
        if(p->rightChild != NULL) {
            s[++rearIndex] = p->rightChild;
        }
    }
}
template<class T>
void BinaryTree<T>::releaseBinaryTree(BinaryNode<T> * R) {
    if(R != NULL) {
        releaseBinaryTree(R->leftChild);
        releaseBinaryTree(R->rightChild);
        delete R;
    }
}
template<class T>
BinaryTree<T>::~BinaryTree() {
    releaseBinaryTree(root);
}

int main(int argc, char** argv) {
    int data[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
    BinaryTree<int> binaryTree(data,12);
    binaryTree.postOrder(binaryTree.root);

    return 0;
}
