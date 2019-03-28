#include <iostream>
using namespace std;

int N;//LED 수
int S[100000 + 10];//LED 상태

void InputData(){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> S[i];
	}
}

int main(){
	int ans = -1;

	InputData();			//	입력 함수

	//	코드를 작성하세요
	
	
	cout << ans << endl;	//	정답 출력
	return 0;
}
