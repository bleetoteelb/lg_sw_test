#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;//제품 수
struct st{
	int X, ID;//위치, 아이디
	int newid;
    st(int x,int id,int ni):X(x),ID(id),newid(ni){}
};
//st A[50010];

bool compare(st a, st b){
    return a.X < b.X;
}

//priority_queue<st,vector<st>,compare> A;
vector<st> A;

int check[50010]={0,};
int check_cnt=1;

void InputData(){
	cin >> N;
    int x, id,tmp;

	for (int i = 0; i < N; i++){
        scanf("%d %d",&x,&id);
		tmp = id % 50000;
		for(int j=0;j<50000;j++){
			if(check[tmp]==0){
				check[tmp] = id;
				A.push_back(st(x,id,tmp));
				break;
			}else if(check[tmp]==id){
				A.push_back(st(x,id,tmp));
				break;
			}
			tmp = (tmp+1) % 50000;
		}
        A.push_back(st(x,id,tmp));
		//cin >> A[i].X >> A[i].ID;
	}
    sort(A.begin(),A.end(),compare);
}

int main(){
	int ans = -1;

	InputData();			//	입력 함수

	//	코드를 작성하세요
    int size=A.size();
	for(int i=0;i<size;i++) printf("%d %d %d\n",A[i].X,A[i].ID,A[i].newid);
	
	cout << ans << endl;	//	정답 출력
	return 0;
}
