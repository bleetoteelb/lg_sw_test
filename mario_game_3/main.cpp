#include <iostream>
using namespace std;

int N;//버섯 수
int P[150000 + 10];//버섯 값

void InputData(){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> P[i];
	}
}

int main(){

	InputData();			//	입력 함수

	int small=1000,large=0;
	int pm=1;
	int height = 0;
	for(int i=0;i<N;i++){
		if(pm==1){
			if(large<=P[i]){
				large = P[i];
				//cout << "switch to +"<<large <<"\n";
			}else{
				//cout << "eat +"<<large <<"\n";
				height += large;
				large = 0;
				small = P[i];
				pm = -1;

			}
		}else{
			if(small>=P[i]){
				small = P[i];
				//cout << "switch to +"<<small <<"\n";
			}else{
				//cout << "eat -"<<small<<"\n";
				height -= small;
				small = 1000;
				large = P[i];
				pm = 1;
			}
		}
	}

	if(pm==1) height += large;
	
	
	cout << height << endl;	//	정답 출력
	return 0;
}
