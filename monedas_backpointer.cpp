#include <iostream>
#include <limits>
#include <algorithm>
using namespace std;

int* coin_change_solution_b(int** p, int W, int N) {
    int* x = new int[N];
    for (int i = 0; i < N; i++) {
        x[i] = 0;
    }
    int i = N - 1;
    int j = W;
    while (i >= 0 && j > 0) {
        if (p[i][j] == j) {
            i = i - 1;
        } else {
            x[i] = x[i] + 1;
            j = p[i][j];
        }
    }
    return x;
}

int cambio(int N, int* w, int W) {
    int** matrix = new int*[N];
    int** p = new int*[N];
    for (int i = 0; i < N; i++) {
        matrix[i] = new int[W + 1];
        p[i] = new int[W + 1];
        for (int j = 0; j <= W; j++) {
            if (j == 0) {
                matrix[i][j] = 0;
                p[i][j] = j; // Inicializar p[i][j] correctamente
            } else {
                matrix[i][j] = numeric_limits<int>::max();
                p[i][j] = -1;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0) {
                if (w[i] > j) {
                    matrix[i][j] = 0;//numeric_limits<int>::max();
                } else {
                    matrix[i][j] = 1 + matrix[i][j - w[i]];
                }
            } else {
                if (w[i] > j) {
                    matrix[i][j] = matrix[i - 1][j];
                } else {
                    matrix[i][j] = min(matrix[i - 1][j], 1 + matrix[i][j - w[i]]);
                    if (matrix[i - 1][j] <= 1 + matrix[i][j - w[i]]) {
                        p[i][j] = j;
                    } else {
                        p[i][j] = j - w[i];
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= W; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    int* sol = coin_change_solution_b(p, W, N);
    for (int i = 0; i < N; i++) {
        cout << sol[i] << " ";
    }
    cout << endl;

    return matrix[N - 1][W];
}

int main() {
    int N = 3;
    int w[N];
    w[0] = 1;
    w[1] = 4;
    w[2] = 6;
    int W = 8;
    int result = cambio(N, w, W);
    cout << "Cantidad mínima de monedas: " << result << endl;
    return 0;
}

