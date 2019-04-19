// <done>
#include <iostream>
using namespace std;

int N;			//	시험 일수
int h[31];	//	시험 시간
int sol = 0 ;	

void InputData(){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> h[i];
	}
}

int main(){
	
	InputData();						//	입력 함수

	//	최종 계산값이 sol 에 저장될 수 있도록 완성하세요
	for (int i = 0; i < N; i++){
		if(h[i]<3) ;
		else if(h[i]>=3 && h[i]<=6) sol += 100;
		else if(h[i]>6) sol += ((h[i]-6)*50 > 400) ? 500 : (50*(h[i]-6)+100);
	}

	if(sol >= 10000) sol *= 0.9;

	
	cout << sol << endl; 		// 정답 출력
	return 0;
}