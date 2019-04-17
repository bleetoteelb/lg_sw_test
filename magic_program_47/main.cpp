// <done>
#include <iostream>
using namespace std;

#define MAX_N (95)
int matrix[MAX_N][MAX_N];

// 작성할 함수
void Make_Magic_Square(int N)
{
	int row=0,col=N/2;
	matrix[row][col] = 1;
	


	for(int i=2;i<=N*N;i++){
		if((i-1)%N==0){
			row=(row==N-1)?0:row+1;
			matrix[row][col]=i;
		}else{
			row=(row==0)?N-1:row-1;
			col=(col==0)?N-1:col-1;
			matrix[row][col]=i;
		}
	}
}

void Print_Complete_Matrix(int N)
{
	int r, c;
	for (r=0;r<N;r++)
	{
		for (c=0;c<N;c++)
		{
			cout << matrix[r][c] << " ";
		}
		cout << endl;
	}
}

int main(void)
{
	int N;
	
	// 입력 받는 부분
	cin >> N;

	// 마방진 완성 코드
	Make_Magic_Square(N);

	// 마방진 출력
	Print_Complete_Matrix(N);
	
	return 0;
}