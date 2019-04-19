// <done>
#include <algorithm>
#include <iostream>
using namespace std;

int N; //일
int S; //보관비용
int C[50010]; //가격
int Y[50010]; //용량
int dp[50010] = {0,};

void Input_Data(void){
	int i;
	cin >> N >> S;
	for (int i = 0; i < N; i++){
		cin >> C[i] >> Y[i];
		dp[i] = 2147483647;
	}
}

int main(){
	long long ans = 0;
	Input_Data();		// 입력 함수

	
	// TODO : 코드를 작성하세요
	for(int i=0;i<N;i++){
		for(int ii=i;ii<N;ii++){
			if((ii-i)*S >= 5000) break;
			dp[ii] = min(C[i]*Y[ii]+(ii-i)*S*Y[ii] , dp[ii]);
		}
	}
	
	for(int i=0;i<N;i++) ans+=dp[i];
	
	cout << ans << endl;	// 정답 출력
	return 0;
}
