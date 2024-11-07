#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 10000; // Assume an upper limit for N
const int MAX_EDGES = 2 * MAX_N; // Since each edge is stored twice in adjacency list

int estrelas[MAX_N];
int adj[MAX_EDGES];
int head[MAX_N + 1], next_adj[MAX_EDGES];
bool visitado[MAX_N + 1];

int max_count = 0;

void add_edge(int u, int v, int& edge_count) {
    adj[edge_count] = v;
    next_adj[edge_count] = head[u];
    head[u] = edge_count++;
}

void dfs(int cidade, int ultima_estrela, int msc_atual) {
    max_count = max(max_count, msc_atual);
    visitado[cidade] = true;

    for (int i = head[cidade]; i != -1; i = next_adj[i]) {
        int vizinha = adj[i];
        if (!visitado[vizinha]) {
            dfs(vizinha, ultima_estrela, msc_atual);
            if (estrelas[vizinha - 1] > ultima_estrela) {
                dfs(vizinha, estrelas[vizinha - 1], msc_atual + 1);
            }
        }
    }

    visitado[cidade] = false;
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> estrelas[i];
    }

    fill(head, head + N + 1, -1);  // Initialize head array
    int edge_count = 0;

    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v, edge_count);
        add_edge(v, u, edge_count);
    }

    for (int inicio = 1; inicio <= N; ++inicio) {
        fill(visitado, visitado + N + 1, false);
        dfs(inicio, estrelas[inicio - 1], 1);
    }

    cout << max_count << endl;

    return 0;
}
