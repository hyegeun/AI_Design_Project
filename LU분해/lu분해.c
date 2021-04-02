#include <stdio.h>

int x;
int y;
int z;

int main(void) {
	
	int i;
	int j;
	
	printf("\n\t몇차 정방행렬을 할 것인지 적어주세요.\n\t");
	scanf("%d", &x);
	y= x;
	z= x;
	
	float Amatrix[x][z];
    float L[x][y];
    float U[y][z];
    
    printf("\n\t");
	for (i=0; i<x; i++) {
		printf("%d행을 하나씩 적어주세요.\n\t", i+1);
		for(j=0; j<z; j++) {
			scanf("%f", &Amatrix[i][j]);
			printf("\t");
		}
		printf("\n\t");
	}
	
	zero(L, U); //먼저 하삼각행렬과 상삼각행렬의 값을 다 0으로 맞춰줌.  
	
	for (i=0; i<y; i++) { //먼저 U행렬의 행을 구하고  
		Umatrix(i, Amatrix, L, U);
		if (i<y-1)
		    Lmatrix(i, Amatrix, L, U); //그다음 l행렬의 열을 구하기를 반복  
	}

    printf("\n\n\n\t행렬 A\n\t"); //행렬 A 출력  
	for (i=0; i<x; i++) {
		for (j=0; j<z; j++) {
			printf("%.2f\t", Amatrix[i][j]);
		}
		printf("\n\t");
	}
	
	printf("\n\n");
	printf("\t하삼각행렬 L\n\t"); //하삼각행렬 출력  
	for (i=0; i<x; i++) {
		for (j=0; j<y; j++) {
			printf("%.2f\t", L[i][j]);
		}
		printf("\n\t");
	}
	
	printf("\n\n");
	printf("\t상삼각행렬 U\n\t"); //상삼각행렬 출력  
	for (i=0; i<y; i++) {
		for (j=0; j<z; j++) {
			printf("%.2f\t", U[i][j]);
		}
		printf("\n\t");
	}	
	return 0;
}

void zero(float L[x][y], float U[y][z]) { //하삼각행렬과 상삼각행렬의 값을 다 0으로 맞춤  
	
	int i;
	int j;
	for ( i=0; i<x; i++) {
		for (j=0; j<y; j++) {
			L[i][j]= 0;
		}
		L[i][i]= 1; //하삼각행렬의 대각행렬을 1로 맞춤  
	}
	
	for ( i=0; i<y; i++) {
		for (j=0; j<z; j++) {
			U[y][z]= 0;
		}
	}
}

void Umatrix(int a, float Amatrix[x][z], float L[x][y], float U[y][z]) { //하삼각행렬의 행을 구함  
	
	int i;
	int j;
	for (i=a; i<z; i++) {
		U[a][i] = Amatrix[a][i];
		for (j=0; j<y; j++) {
			if (a !=j)
			    U[a][i] -= L[a][j]*U[j][i];
		}
	}
	
}

void Lmatrix(int a, float Amatrix[x][z], float L[x][y], float U[y][z]) { //상삼각행렬의 행을 구함  
	int i;
	int j;
	for (i=a+1; i<y; i++) {
		L[i][a] = Amatrix[i][a];
		for (j=0; j<y; j++) {
			if (a !=j)
			    L[i][a] -= L[i][j]*U[j][a];
		}
		L[i][a] /= U[a][a];
	}
}

