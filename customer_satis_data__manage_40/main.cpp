// <done>
#include <iostream>
using namespace std;

int M;					// 반복 인정 회수
char S[100000 + 10];	// 조사 문자열

int get_len(){
	for(int i=0;i<100010;i++){
		if(S[i]=='\0') return i;
	}
}

void print_short(int idx,int cnt){
	cout << S[idx] <<"(" << cnt << ")";
	
}
void print_raw(int idx,int cnt){
	for(int i=0;i<cnt;i++){
		cout << S[idx];
	}
}

int main(void)
{
	int i;			// 문자열 S의 어떤 문자를 지시
	int len;		// 문자열 S의 길이
	char r_char;	// 반복되는 문자
	int r_cnt;		// 반복 회수

	// 데이터 읽기
	cin >> M;
	cin >> S;

	// 코드 구현 및 결과 출력
	len = get_len();
	r_char = S[0];
	r_cnt = 1;

	for(i=1;i<=len;i++){
		if(S[i] != r_char){
			if(r_cnt >= M){
				print_short(i-1,r_cnt);
			} else print_raw(i-1,r_cnt);
			r_char = S[i];
			r_cnt = 1;
		}else r_cnt++;
	}

	//cout << len << endl;

	return 0;
}
