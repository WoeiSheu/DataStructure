#include <iostream>

using namespace std;

const int MAXSIZE = 12;
template<class T>
class MatrixGraph {
private:
    T vertex[MAXSIZE];
    int arc[MAXSIZE][MAXSIZE];
    int vertexNum, arcNum;
public:
    MatrixGraph(T a[], int n, int e);
    void DFS(int v);
    void BFS(int v);
};
template<class T>
MatrixGraph<T>::MatrixGraph(T a[], int n, int e) {
    int i,j,k;
    vertexNum = n;
    arcNum = e;
    for(k = 0; k < n; k++) {
        vertex[k] = a[k];
    }
    for(k = 0; k < n; k++) {
        for(j = 0; j < n; j++) {
            arc[k][j] = 0;
        }
    }
    for(k = 0; k < e; k++) {
        cin >> i >> j;
        arc[i][j] = 1;
        arc[j][i] = arc[i][j];
    }
}

bool visited[MAXSIZE] = {false};
template<class T>
void MatrixGraph<T>::DFS(int v) {
    cout << vertex[v] << ' ';
    visited[v] = true;
    for(int j = 0; j < vertexNum; j++) {
        if(arc[v][j] == 1 && !visited[j]) {
            DFS(j);
        }
    }
}

template<class T>
void MatrixGraph<T>::BFS(int v) {
    int q[MAXSIZE];
    int f = 0, r = 0;
    cout << vertex[v] << ' ';
    visited[v] = true;
    q[++r] = v;

    while(f != r) {
        v = q[++f];
        for(int j = 0; j < vertexNum; j++) {
            if(arc[v][j] == 1 && !visited[j]) {
                cout << vertex[j] << ' ';
                visited[j] = true;
                q[++r] = j;
            }
        }
    }
}

int main(int argc, char** argv) {

    return 0;
}
