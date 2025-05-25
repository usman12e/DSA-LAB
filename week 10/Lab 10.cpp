#include <iostream>
using namespace std;


// Weighted Graph using Adjacency Matrix

template<int MAX_VERTICES>
class WeightedGraphMatrix {
    int matrix[MAX_VERTICES][MAX_VERTICES];
    char vertices[MAX_VERTICES];
    int vertexCount;

public:
    WeightedGraphMatrix() {
        vertexCount = 0;
        for (int i = 0; i < MAX_VERTICES; ++i)
            for (int j = 0; j < MAX_VERTICES; ++j)
                matrix[i][j] = 0;
    }

    bool addVertex(char label) {
        if (vertexCount >= MAX_VERTICES) return false;
        vertices[vertexCount++] = label;
        return true;
    }

    int getIndex(char label) {
        for (int i = 0; i < vertexCount; ++i)
            if (vertices[i] == label)
                return i;
        return -1;
    }

    bool addEdge(char from, char to, int weight) {
        int i = getIndex(from), j = getIndex(to);
        if (i == -1 || j == -1) return false;
        matrix[i][j] = weight;
        return true;
    }

    void print() {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < vertexCount; ++i) {
            cout << vertices[i] << ": ";
            for (int j = 0; j < vertexCount; ++j)
                cout << matrix[i][j] << " ";
            cout << endl;
        }
    }
};

int main(){
WeightedGraphMatrix<5> g2;
g2.addVertex('A');
g2.addVertex('B');
g2.addVertex('C');
g2.addEdge('A', 'B', 5);
g2.addEdge('A', 'C', 10);
g2.addEdge('B', 'C', 2);
g2.print();

return 0;
}