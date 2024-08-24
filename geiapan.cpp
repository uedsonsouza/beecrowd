// Há muito tempo, em uma galáxia muito, muito distante, havia um planeta 
// chamado Geiapan. Ele era formado por um bloco único de terra, com 
// diversas cidades. Em certo dia, houve um terremoto gigantesco, que 
// dividiu o bloco de terra em várias ilhas, com algumas cidades dentro de 
// cada ilha. Em um acordo global, todas as ilhas se tornaram independentes,
//  e se tornaram países. Eles precisam de um levantamento histórico e 
//  contam com a tua ajuda para que isso aconteça. Dadas as cidades, e 
//  entre quais delas existe uma fronteira terrestre, informe quantos 
//  países foram formados, após o terremoto.

// Entrada
// A primeira linha da entrada contém 2 inteiros, C e F, sendo o número de 
 // cidades e o número de fronteiras entre as cidades, respectivamente.

// Depois há F linhas indicando as fronteiras terrestres entre as cidades, 
 // em que cada uma há dois inteiros X e Y, indicando que há uma fronteira 
 // terrestre que liga a cidade X à cidade Y.
 // Limites:
 // 1 ≤ C ≤ 105;
// 0 ≤ F ≤ min(105, (C*(C-1))/2);
// 1 ≤ X,Y ≤ C.

// Saída
 // Para cada caso de teste, informe a quantidade de países que foram 
 // formados após o terremoto.
#include <iostream>
#include <vector>

class UnionFind {
public:
    UnionFind(int n) : parent(n) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void union_sets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootY] = rootX;
        }
    }

private:
    std::vector<int> parent;
};

int main() {
    int C, F;
    std::cin >> C >> F;

    UnionFind uf(C);

    for (int i = 0; i < F; i++) {
        int X, Y;
        std::cin >> X >> Y;
        uf.union_sets(X - 1, Y - 1);
    }

    int countries = 0;
    for (int i = 0; i < C; i++) {
        if (uf.find(i) == i) {
            countries++;
        }
    }

    std::cout << countries << std::endl;

    return 0;
}