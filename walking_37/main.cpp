// <done>
#include <iostream>
using namespace std;

int N;//직원 수
int T;//산책 시간(분단위)
int P[100000 + 10];//직원 출발 위치
int S[100000 + 10];//직원 산책 속도(분당)

void InputData(){
	cin >> N >> T;
	for (int i = 0; i < N; i++){
		cin >> P[i] >> S[i];
	}
}

int main(){
	int ans = 1;
	long long after_t_pos=0;
	long long cur;
	InputData();			//	입력 함수

	//	코드를 작성하세요
	after_t_pos = (long long)P[N-1] + (long long)T * (long long)S[N-1];
	for(int i=N-2;i>=0;i--){
		cur = (long long)P[i] + (long long)T * (long long)S[i];
		//printf("%lli\n",cur);
		if(after_t_pos > cur) {
			after_t_pos = cur;
			ans++;
		}
	}

	printf("%d\n",ans);
	
	

	return 0;
}
