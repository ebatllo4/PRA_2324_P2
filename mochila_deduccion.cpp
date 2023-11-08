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

int* mochila_sol(int W, int N, int*  v, int* w, int** c){
        int* x = new int[N];
        for(int i = 0; i < N; i++){
                x[i] = 0;
        }
        int i = N-1;
        int j = W;
        while(i > 0 && j > 0){
                if(i == 1 && c[i][j] == v[i]){
			x[i] = 1;
		}else{
			if(c[i][j] == (v[i] + c[i-1][j-w[i]])){
                        	x[i] = 1;
				j = j - w[i];
			}
                }
		i--;
        }
        return x;
}

int mochila(int* w, int* v, int N, int W){

        int** matrix = new int*[N];

        for( int i = 0; i < N; i++){
                matrix[i] = new int[W+1];
                for(int j = 0; j<=W; j++){
                        if(j == 0){
                                matrix[i][j] = 0;
                        }
                        if (i == 0){
				 if(w[i] > j){
                                        matrix[i][j] = 0;
                                } else{
                                        matrix[i][j] = v[i];
                                }
                        } else {
                                if(w[i] > j){
                                        matrix[i][j] = matrix[i-1][j];
                                }else{
                                        if ((matrix[i-1][j]) > (v[i] + matrix[i-1][j - w[i]])){
                                                matrix[i][j] = matrix[i-1][j];
                                        }else{
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
 	
	int* solucion = mochila_sol(W, N, v, w, matrix);
        cout<<"La solucion es: ";
        for(int i = 0; i < N; i++){
                cout<< solucion[i]<< " ";
        }
        cout<<endl;

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

