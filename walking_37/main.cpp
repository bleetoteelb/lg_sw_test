#include <iostream>
using namespace std;

int N;//직원 수
int T;//산책 시간(분단위)
// int P[100000 + 10];//직원 출발 위치
// int S[100000 + 10];//직원 산책 속도(분당)


struct _staff{
	int pos,speed;
	int pre,next;
	bool first,last;
	_staff():first(false),last(false){}
	void setting(int a,int b,int c,int d){
		pos = a;
		speed = b;
		pre = c;
		next = d;
	}
};
_staff *staff;
void InputData(){
	cin >> N >> T;
	int tmp1, tmp2;
	staff = new _staff[N];
	for (int i = 0; i < N; i++){
		cin >> tmp1 >> tmp2;
		staff[i].setting(tmp1,tmp2,i-1,i+1);
	}
	staff[0].first = true;
	staff[N-1].last = true;
}

void pop_staff(int a){
	if(staff[a].first){
		staff[staff[a].next].first = true;
	}else{
		staff[staff[a].pre].next = staff[a].next;
		staff[staff[a].next].pre = staff[a].pre;
	}
	return;
}

int main(){
	int ans;

	InputData();			//	입력 함수
	ans = N;
	//	코드를 작성하세요
	for(int i=0;i<T;i++){
		for(int ii=N-1;ii>=0;){
			//cout << "start ii: " << ii << endl;
			staff[ii].pos = staff[ii].pos + staff[ii].speed;
			if(staff[ii].last){
				ii = staff[ii].pre;
				continue;
			}

			if(staff[ii].pos >= staff[staff[ii].next].pos) {
				pop_staff(ii);
				//cout << ii << endl;
				ans--;
			}
			
			if(staff[ii].first){
				break;
			}else{
				ii = staff[ii].pre;
			}
		}
	}
	
	cout << ans << endl;	//	정답 출력
	return 0;
}
