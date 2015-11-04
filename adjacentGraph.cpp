#include <iostream>

using namespace std;

struct ArcNode {
    int adjVex;
    ArcNode * nextArc;
};
struct VertexNode {
    char vertex;
    ArcNode * firstArc;
};

const int MAXSIZE = 10;
template<class T> class AdjacentGraph {
private:
    VertexNode adjList[MAXSIZE];
    int vertexNum, arcNum;
public:
    AdjacentGraph(T a[], int n, int e);
    ~AdjacentGraph();
    void DFS(int v);
    void BFS(int v);
};
template<class T>
AdjacentGraph<T>::AdjacentGraph(T a[], int n, int e) {
    int i,j,k;
    vertexNum = n;
    arcNum = e;
    for(k = 0; k < n; k++) {
        adjList[i].vertex = a[k];
        adjList[i].firstArc = NULL;
    }

    for(k = 0; k < e; k++) {
        cin >> i >> j;
        ArcNode * s = new ArcNode;
        s->adjVex = j;
        s->nextArc = adjList[i].firstArc;
        adjList[i].firstArc = s;
    }
}

bool visited[MAXSIZE] = {false};
template<class T>
void AdjacentGraph<T>::DFS(int v) {
    cout << adjList[v].vertex;
    visited[v] = true;
    ArcNode* p = adjList[v].firstArc;
    while(p) {
        int j = p->adjVex;
        if(!visited[j]) {
            DFS(j);
        }
        p = p->nextArc;
    }
}

template<class T>
void AdjacentGraph<T>::BFS(int v) {
    int q[MAXSIZE];
    int f = 0, r = 0;
    cout << adjList[v].vertex << ' ';
    visited[v] = true;
    q[++r] = v;
    while(f != r) {
        v = q[++f];
        ArcNode* p = adjList[v].firstArc;
        while(p) {
            int j = p->adjVex;
            if(!visited[j]) {
                cout << adjList[j].vertex << ' ';
                visited[j] = true;
                q[++r] = j;
            }
            p = p->nextArc;
        }
    }
};

int main(int argc, char** argv) {
    return 0;
}
