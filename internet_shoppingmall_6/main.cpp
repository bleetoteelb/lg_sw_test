// <done>
#include <iostream>
using namespace std;

int N;               // 제품의 개수
int ID[10000 + 10];  // 아이디
int S[10000 + 10];   // 판매수량
int R[10000 + 10];   // 조회회수

// 두 위치의 값을 교환하는 함수
void swap(int x1, int x2)
{
	int temp;

	temp = S[x2];
	S[x2] = S[x1];
	S[x1] = temp;

	temp = R[x2];
	R[x2] = R[x1];
	R[x1] = temp;

	temp = ID[x2];
	ID[x2] = ID[x1];
	ID[x1] = temp;
}

int main(void)
{
	int i, j;
	bool change = true;

	// 입력 읽기
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> ID[i] >> S[i] >> R[i];
	}
	// 선호도 순으로 정렬
	while(change){
		change = false;
		//cout << "in\n";
		for(int i=0;i<N-1;i++){
			if(S[i] < S[i+1]) {
				swap(i,i+1);
				change=true;
				//cout << "in_S\n";
			}else if(S[i]==S[i+1]){
				if(R[i] < R[i+1]){
					swap(i,i+1);
					change = true;
					//cout << "in_R\n";
				}else if(R[i]==R[i+1]){
					if(ID[i] < ID[i+1]){
						swap(i,i+1);
						change = true;
						//cout << "in_ID\n";
					}
				}
			}
		}
	}
	
	// 결과 출력
	for (i = 0; i < N; i++) {
		cout << ID[i] << " ";
	}

	return 0;
}
