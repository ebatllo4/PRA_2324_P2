#include <iostream>
#include <limits>
#include <algorithm>
using namespace std;

//N = numero d'objectes

//v = array amb el valor de cada objecte en la possició corresponent

//w = array amb el pes de cada objecte en la possició corresponent
//W = pes maxim

//i = possició de moneda

//j = pes restant

int* mochila_sol_b(int** p, int W, int N) {
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

int mochila(int* w, int* v, int N, int W){
        int** matrix = new int*[N];
        int** p = new int*[N];
	for( int i = 0; i < N; i++){
                matrix[i] = new int[W+1];
                p[i] = new int[W + 1];
		for(int j = 0; j<=W; j++){
                        if(j == 0){
                                p[i][j] = -1;
				matrix[i][j] = 0;
                        }
                        if (i == 0){
                                if(w[i] > j){
                                        p[i][j] = -1;
					matrix[i][j] = 0;
                                } else{
                                        p[i][j] = 0;
					matrix[i][j] = v[i];
                                }
                        } else {
                                if(w[i] > j){
					p[i][j] = j;
                                        matrix[i][j] = matrix[i-1][j];
                                }else{
					 if ((matrix[i-1][j]) > (v[i] + matrix[i-1][j - w[i]])){
                                                p[i][j] = j;
						matrix[i][j] = matrix[i-1][j];
                                        }else{
                                                p[i][j] = j-w[i];
						matrix[i][j] = v[i] + matrix[i-1][j - w[i]];
                                        }
                                        //matrix[i][j] = max(matrix[i-1][j], v[i] + matrix[i-1][j - w[i]]);
                                }

                        }
                }
        }

        for(int i= 0; i < N; i++){
                for(int j = 0; j<=W; j++){
                        cout<<matrix[i][j] << " ";
                }
                cout<< endl;
        }

	int* sol = mochila_sol_b(p, W, N);
    	for (int i = 0; i < N; i++) {
        	cout << sol[i] << " ";
    	}
    	cout << endl;

        return matrix[N -1][W];
}


int main(){
        int N = 5;
        int w[N];
        w[0] = 1;
        w[1] = 2;
        w[2] = 5;
        w[3] = 6;
        w[4] = 7;
        int v[N];
        v[0] = 1;
        v[1] = 6;
        v[2] = 18;
	v[3] = 22;
        v[4] = 28;
        int W = 11;
        int result = mochila(w, v, N, W);
        cout << "Valor maximo: " << result << endl;
        return 0;
}
                  
