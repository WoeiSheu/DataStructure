#include <iostream>

using namespace std;

struct HuffmanNode {
    int weight;
    int parent;
    int leftChild;
    int rightChild;
};
struct HuffmanCode {
    char data;
    char code[100];
};
class Huffman {
private:
    HuffmanNode* HuffmanTree;
    HuffmanNode* HuffmanCodeTable;
public:
    void createHuffmanTree(int a[], int n);
    void createCodeTable(char b[], int n);
    void Encode(char* s, char* d, int n);
    void Decode(char* s, char* d, int n);
    ~Huffman();
};

void selectMin(int x, int y, int k, int i) {

}
void Huffman::createHuffmanTree(int a[], int n) {
    HuffmanTree = new HuffmanNode[2*n-1];
    for(int i = 0; i < n; i++) {
        HuffmanTree[i].weight = a[i];
        HuffmanTree[i].leftChild = HuffmanTree[i].rightChild = HuffmanTree[i].parent = -1;
    }

    int x,y;
    for(int i = n; i < 2*n-1; i++) {
        selectMin(x,y,0,i);
        HuffmanTree[x].parent = HuffmanTree[y].parent;
        HuffmanTree[i].weight = HuffmanTree[x].weight + HuffmanTree[y].weight;
        HuffmanTree[i].leftChild = x;
        HuffmanTree[i].rightChild = y;
        HuffmanTree[i].parent = -1;
    }
}
void Huffman::createCodeTable(char b[], int n) {
    HuffmanCodeTable = new HuffmanCode[n];
    for(int i = 0; i < n; i++) {
        HuffmanCodeTable[i].data = b[i];
        int child = i;
        int parent = HuffmanTree[i].parent;
        int k = 0;
        while(parent != 1) {
            if(child == HuffmanTree[parent].leftChild) {
                HuffmanCodeTable[i].code[k] = '0';
            } else {
                HuffmanCodeTable[i].code[k] = '1';
            }
            k++;
            child = parent;
            parent = HuffmanTree[child].parent;
        }

        HuffmanCodeTable[i].code[k] = '\0';
        reverseChar(HuffmanCodeTable[i].code);
    }
}

void Huffman::Decode(char* s, char* d, int n) {
    while(*s != '\0') {
        int parent = 2*n - 2;
        while(HuffmanTree[parent].leftChild != -1) {
            if(*s == '0') {
                parent = HuffmanTree[parent].leftChild;
            } else {
                parent = HuffmanTree[parent].rightChild;
            }
            s++;
        }

        *d = HuffmanCodeTable[parent].data;
        d++;
    }
}

int main(int argc, char** argv) {
    return 0;
}
