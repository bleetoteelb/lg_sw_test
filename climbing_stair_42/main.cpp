// <done>
#include <iostream>
#include <algorithm>
using namespace std;

int N;				//	계단의 개수
int P[310];		//	P[i]: i 계단을 밟았을 때 얻는 점수

struct _dp{
	int val,pre_step;
	_dp():val(0),pre_step(0){}
	void setting(int a,int b){
		val = a;
		pre_step = b;
	}
} dp[301];

int Solve(){

	dp[1].val = P[1];
	dp[1].pre_step = 1;
	//	코드를 작성하세요
	for(int i=2;i<=N;i++){
		
		if(dp[i-1].pre_step==1) {
			if(dp[i-3].val + P[i-1] > dp[i-2].val) dp[i].setting(dp[i-3].val+P[i-1]+P[i],1);
			else dp[i].setting(dp[i-2].val+P[i],2);
		}
		else {
			if(dp[i-1].val <= dp[i-2].val){
				dp[i].setting(dp[i-2].val+P[i],2);
			}else dp[i].setting(dp[i-1].val+P[i],1);
		}
	}
	

	return dp[N].val;
}

void InputData(){
	cin >> N;
	for(int i=1 ; i<=N ; i++){
		cin >> P[i];
	}
}

int main(){
	
	InputData();					//	입력 함수

	int sol = Solve();

	cout << sol << endl;		//	정답 출력
	return 0;
}
