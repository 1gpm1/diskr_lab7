#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>

class Graph {
private:
    std::vector<std::vector<int>> adjacencyMatrix;
    int vertices;

public:
    Graph(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Файл не знайдено" << std::endl;
            return;
        }

        file >> vertices;
        adjacencyMatrix.resize(vertices, std::vector<int>(vertices));

        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                file >> adjacencyMatrix[i][j];
            }
        }

        file.close();
    }

    void printDegrees() {
        for (int i = 0; i < vertices; ++i) {
            int degree = 0;
            for (int j = 0; j < vertices; ++j) {
                degree += adjacencyMatrix[i][j];
            }
            std::cout << "Степінь вершини " << (i + 1) << ": " << degree << std::endl;
        }
    }

    void printIsolatedAndPendantVertices() {
        for (int i = 0; i < vertices; ++i) {
            int degree = 0;
            for (int j = 0; j < vertices; ++j) {
                degree += adjacencyMatrix[i][j];
            }
            if (degree == 0) {
                std::cout << "Ізольована вершина: " << (i + 1) << std::endl;
            }
            else if (degree == 1) {
                std::cout << "Висяча вершина: " << (i + 1) << std::endl;
            }
        }
    }

    int getDegree(int vertex) {
        int degree = 0;
        for (int j = 0; j < vertices; ++j) {
            degree += adjacencyMatrix[vertex][j];
        }
        return degree;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    try {
        Graph graph("graph.txt");
        graph.printDegrees();
        graph.printIsolatedAndPendantVertices();
    }
    catch (...) {
        std::cerr << "Файл не знайдено" << std::endl;
    }

    return 0;
}
