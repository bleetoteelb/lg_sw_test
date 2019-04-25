// <done>
#include <iostream>
#include <vector>
#include <algorithm>

#include <stdio.h>
using namespace std;

int N;//제품 수
struct st{
	int X, ID;//위치, 아이디
	int newid;
    st(int x,int id,int ni):X(x),ID(id),newid(ni){}
};


bool compare(st a, st b){
    return a.X < b.X;
}

vector<st> A;

int check[50010];
int check_cnt=0;

void InputData(){
	cin >> N;
    int x, id,tmp;

	for (int i = 0; i < N; i++){
        scanf("%d %d",&x,&id);
		tmp = id % 50000;
		for(int j=0;j<50000;j++){
			if(check[tmp]==-1){
				check[tmp] = id;
				A.push_back(st(x,id,tmp));
				check_cnt++;
				break;
			}else if(check[tmp]==id){
				A.push_back(st(x,id,tmp));
				break;
			}
			tmp = (tmp+1) % 50000;
		}
	}
    sort(A.begin(),A.end(),compare);
}

int main(){
	long long ans = 1000000001, sample_cnt = 0;

	for(int i=0;i<50010;i++) check[i] = -1;
	InputData();			//	입력 함수
	int start=0,last=0;
	int exist[50010]= {0,};
	int adsf = 6;
	
	exist[A[last].newid]++;
	sample_cnt++;
	while(1){
		
		if(sample_cnt==check_cnt){
			ans <= (A[last].X - A[start].X) ? ans : ans = A[last].X - A[start].X;
						
			if(exist[A[start].newid] >= 2){
				exist[A[start++].newid] -= 1;
			}else{
				if(last==N-1) break;
				exist[A[++last].newid] += 1;
			}
			
		}else{
			if(last==N-1) break;
						
			if(exist[A[++last].newid]==0){
				sample_cnt++;
			}
			exist[A[last].newid] += 1;
			
		}
	}   
	
	cout << ans << endl;	//	정답 출력
	return 0;
}
