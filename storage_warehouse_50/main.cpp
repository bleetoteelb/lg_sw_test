// <done>
#include <iostream>
using namespace std;

int N, M;//공장 수, 도로 정보 수

int table[101][101];
int A[5000], B[5000], D[5000];//공장 A, 공장 B, 거리 D

void InputData(){
	int i;
	cin >> N >> M;
	for(i=0;i<101;i++){
		for(int ii=0;ii<101;ii++) table[i][ii] = 1000;
	}
	for (i = 0; i < M; i++){
		cin >> A[i] >> B[i] >> D[i];
	}
}

void get_dis(int start){
	bool finish = true;
	table[start][start] = 0;
	for(int i=0;i<N;i++){
		finish = true;
		for(int ii=0;ii<M;ii++){
			if(table[start][A[ii]] != 1000 && table[start][A[ii]] + D[ii] < table[start][B[ii]]){
				table[start][B[ii]] = table[B[ii]][start] = table[start][A[ii]] + D[ii];
				finish = false;
			}
			if(table[start][B[ii]] != 1000 && table[start][B[ii]] + D[ii] < table[start][A[ii]]){
				table[start][A[ii]] = table[A[ii]][start] = table[start][B[ii]] + D[ii];
				finish = false;
			}
		}
		if(finish) break;
	}

}

int main(){
	int ans = 1000;
	int highest = 0;
	InputData();//	입력 함수

	//	코드를 작성하세요
	for(int i=1;i<N+1;i++) get_dis(i);

	for(int i=1;i<N+1;i++){
		highest = 0;
		for(int ii=1;ii<N+1;ii++){
			if(highest < table[i][ii]){
				highest = table[i][ii];
			}
		}
		if(highest < ans) ans = highest;
	}


	cout << ans << endl;//	정답 출력
	return 0;
}