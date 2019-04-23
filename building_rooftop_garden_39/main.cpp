// <done>
#include <iostream>
#include <stack>
using namespace std;

int N;//건물 수
int H[80010];//건물 높이

struct building{
	int h,idx;
	building(int a,int b):h(a),idx(b){}
};


void Input_Data(void){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> H[i];
	}
}

int main(){
	long long ans = 0;
	Input_Data();		//	입력 함수
	int count[80010] = {0,};
	stack<building> st;
	//	코드를 작성하세요

	for(int i=0;i<N;i++){
		if(st.empty()) {
			st.push(building(H[i],i));
		}
		else{
			while(!st.empty() && st.top().h <= H[i]){
				count[st.top().idx] = i - st.top().idx - 1;
				st.pop();
			}
			st.push(building(H[i],i));
		}
	}
	while(!st.empty()){
		count[st.top().idx] = N - st.top().idx - 1;
		st.pop();
	}
	for(int i=0;i<N;i++){
		ans += count[i];
	}
	
	cout << ans << endl;	//	정답 출력
	return 0;
}
