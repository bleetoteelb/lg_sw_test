#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>

using namespace std;

int N,size_long;
char full[50000 + 10];
char sus[1001][101];
int cnt[1001];

void Input_Data(){
	cin >> full;
	cin >> N; 
	for(int i=0;i<N;i++){
		cin >> sus[i];
	}
}
int get_size(char* a){
	int i=0;
	while(a[i]!='\0'){ i++; }

	return i;
}
int Count(int a){
	int size_short = get_size(sus[a]);
	vector<int> kmp(size_short,0);
	
	int j = 0, many=0;

	for(int i=1;i<size_short;i++){
		while(j > 0 && sus[a][i] != sus[a][j]){
			j = kmp[j-1];
		}
		if(sus[a][i]==sus[a][j])
			kmp[i] = ++j;
	}
	j = 0;
	for(int i=0;i<size_short;i++){
		cout << kmp[i] << " ";
	}
	cout << endl;
	for(int i=1;i<size_long;i++){
		while(j > 0 && full[i] != sus[a][j]){
			j = kmp[j-1];
		}
		if(full[i] == sus[a][j]){
			cout << "here is :" << i << endl;
			if(j == size_short-1){
				many++;
				j=kmp[j];
			} else {
				j++;
			}
		}
	}
	return many;
}

int main() {

	Input_Data();
	int many=0,idx=0,tmp;
	size_long =  get_size(full);
	for(int i=0;i<N;i++){
		cnt[i] = Count(i);
		cout << cnt[i] << endl;
		many < cnt[i] ? many = cnt[i] : many;
	}
	if(many == 0){
		cout << "null" << endl; 
		return 0;
	}
	for(int i=0;i<N;i++){
		if(many==cnt[i]){
			cout << sus[i] << endl;
			return 0;
		}
	}
	
	return 0;
}
