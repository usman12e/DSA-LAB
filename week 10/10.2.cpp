#include <iostream>
using namespace std;

//Weighted Graph using Adjacency List


class Edge {
public:
    int weight;
    class Vertex* destination;
    Edge* next;

    Edge(Vertex* dest, int w) {
        destination = dest;
        weight = w;
        next = nullptr;
    }
};

class Vertex {
public:
    char data;
    Edge* edgeList;
    Vertex* next;

    Vertex(char d) {
        data = d;
        edgeList = nullptr;
        next = nullptr;
    }

    void connectTo(Vertex* dest, int weight) {
        Edge* newEdge = new Edge(dest, weight);
        newEdge->next = edgeList;
        edgeList = newEdge;
    }

    void printEdges() {
        Edge* e = edgeList;
        while (e) {
            cout << data << " -> " << e->destination->data << " (w:" << e->weight << ")\n";
            e = e->next;
        }
    }

    void printGraph() {
        printEdges();
        if (next) next->printGraph();
    }
};

class Graph {
    Vertex* head;

public:
    Graph() {
        head = nullptr;
    }

    Vertex* find(char val) {
        Vertex* temp = head;
        while (temp) {
            if (temp->data == val) return temp;
            temp = temp->next;
        }
        return nullptr;
    }

    bool addVertex(char val) {
        if (find(val)) return false;
        Vertex* newVertex = new Vertex(val);
        newVertex->next = head;
        head = newVertex;
        return true;
    }

    bool addEdge(char from, char to, int weight) {
        Vertex* v1 = find(from);
        Vertex* v2 = find(to);
        if (!v1 || !v2) return false;
        v1->connectTo(v2, weight);
        return true;
    }

    void print() {
        if (head) head->printGraph();
    }
};

int main() {
    // Using adjacency list
    Graph g;
    g.addVertex('A');
    g.addVertex('B');
    g.addVertex('C');
    g.addEdge('A', 'B', 5);
    g.addEdge('A', 'C', 10);
    g.addEdge('B', 'C', 2);
    g.print();

    return 0;
}
