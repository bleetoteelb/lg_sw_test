// <done>
#include <iostream>
using namespace std;

int N;//직원 수
int S;//시작 직원 번호
int M;

struct _staff{
	int pre,next;
	void setting(int a,int b){
		pre = a; next = b;
	}
};

_staff* staff;

void InputData(){
	cin >> N >> S >> M;
	staff = new _staff[N+1];
	for(int i=1;i<N+1;i++) staff[i].setting(i-1,i+1);
	staff[1].setting(N,2);
	staff[N].setting(N-1,1);
}



int main(){

	InputData();//	입력 함수

	//	코드를 작성하세요
	int cnt=0;
	int done=0;

	int nxt = S;
	while(done!=N){
		cnt++;
		if(cnt==M){
			printf("%d ",nxt);
			staff[staff[nxt].pre].next = staff[nxt].next;
			staff[staff[nxt].next].pre = staff[nxt].pre;
			nxt = staff[nxt].next;
			cnt=0;
			done++;
		}else{
			nxt = staff[nxt].next;
		}
	}

	return 0;
}