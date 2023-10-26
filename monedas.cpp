#include <iostream>
#include <limits>
#include <algorithm>
using namespace std;

//N = numero de tipos de moneda
//w = array amb el valor de cada moneda en la possició corresponent
//W = numero total que deven tornar
//i = possició de valor de moneda
//j = possició de valor a tornar

int cambio(int N, int* w, int W){
	int** matrix = new int*[N];
	for(int i= 0; i < N; i++){
		matrix[i] = new int[W+1];
		for(int j = 0; j<= W; j++){
			if (j == 0){
				matrix[i][j] = 0;
			}else{
				matrix[i][j] = -1;
			}
		}
	}

	for( int i = 0; i < N; i++){
		for(int j = 0; j<=W; j++){
			if (j == 0){
				matrix[i][j] = 0;
			}
			if (i == 0){
				if(w[i] > j){
					matrix[i][j] = 0; //std::numeric_limits<int>::max(); Aço es lo que feia que ixqueren numeros que no son.
				} else{
					matrix[i][j] = 1 + matrix[i][j - w[i]];
				}
			} else {
			        if(w[i] > j){
					matrix[i][j] = matrix[i-1][j];
				}else{
					matrix[i][j] = min( matrix[i-1][j], 1 + matrix[i][j - w[i]]);
				}
						
			}
		}
	}
	

	 for(int i= 0; i < N; i++){
                for(int j = 0; j<W; j++){
			cout<<matrix[i][j] << " ";
		}
		cout<< endl;
	}
	return matrix[N -1][W];
}


int main(){
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
