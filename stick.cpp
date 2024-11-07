#include <iostream>
using namespace std;

long long area(int N, int K, int L) {
    long long quadrado = 4LL * L * L;
    long long total = quadrado * N; 
    
    int direita = (N - 1) * K + L; 
    int esquerda = 0 - L; 

    if (K >= 2 * L) {
        return total;
    } else {
        long long largura = direita - esquerda;
        return largura * largura;
    }
}

int main() {
    int N, K, L;
    cin >> N >> K >> L;

    cout << area(N, K, L) << endl;
    return 0;
}
