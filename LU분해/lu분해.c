#include <stdio.h>

int x;
int y;
int z;

int main(void) {
	
	int i;
	int j;
	
	printf("\n\t���� ��������� �� ������ �����ּ���.\n\t");
	scanf("%d", &x);
	y= x;
	z= x;
	
	float Amatrix[x][z];
    float L[x][y];
    float U[y][z];
    
    printf("\n\t");
	for (i=0; i<x; i++) {
		printf("%d���� �ϳ��� �����ּ���.\n\t", i+1);
		for(j=0; j<z; j++) {
			scanf("%f", &Amatrix[i][j]);
			printf("\t");
		}
		printf("\n\t");
	}
	
	zero(L, U); //���� �ϻﰢ��İ� ��ﰢ����� ���� �� 0���� ������.  
	
	for (i=0; i<y; i++) { //���� U����� ���� ���ϰ�  
		Umatrix(i, Amatrix, L, U);
		if (i<y-1)
		    Lmatrix(i, Amatrix, L, U); //�״��� l����� ���� ���ϱ⸦ �ݺ�  
	}

    printf("\n\n\n\t��� A\n\t"); //��� A ���  
	for (i=0; i<x; i++) {
		for (j=0; j<z; j++) {
			printf("%.2f\t", Amatrix[i][j]);
		}
		printf("\n\t");
	}
	
	printf("\n\n");
	printf("\t�ϻﰢ��� L\n\t"); //�ϻﰢ��� ���  
	for (i=0; i<x; i++) {
		for (j=0; j<y; j++) {
			printf("%.2f\t", L[i][j]);
		}
		printf("\n\t");
	}
	
	printf("\n\n");
	printf("\t��ﰢ��� U\n\t"); //��ﰢ��� ���  
	for (i=0; i<y; i++) {
		for (j=0; j<z; j++) {
			printf("%.2f\t", U[i][j]);
		}
		printf("\n\t");
	}	
	return 0;
}

void zero(float L[x][y], float U[y][z]) { //�ϻﰢ��İ� ��ﰢ����� ���� �� 0���� ����  
	
	int i;
	int j;
	for ( i=0; i<x; i++) {
		for (j=0; j<y; j++) {
			L[i][j]= 0;
		}
		L[i][i]= 1; //�ϻﰢ����� �밢����� 1�� ����  
	}
	
	for ( i=0; i<y; i++) {
		for (j=0; j<z; j++) {
			U[y][z]= 0;
		}
	}
}

void Umatrix(int a, float Amatrix[x][z], float L[x][y], float U[y][z]) { //�ϻﰢ����� ���� ����  
	
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

void Lmatrix(int a, float Amatrix[x][z], float L[x][y], float U[y][z]) { //��ﰢ����� ���� ����  
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

