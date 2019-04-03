#include <iostream>
using namespace std;

long long int dp[101];
long long int n_func(int);



long long int kimchi(int n){
	//cout << n << endl;
	if (n <= 3)	return 1;
	else if (n % 3 == 0) return 3 * n_func(n-1) - 2 * n_func(n-2) - n_func(n-3);
	else if (n % 3 == 1) return 3 * n_func(n-1) - 2 * n_func(n-2) + n_func(n-3);
	else return 2 * n_func(n-1) - 2 * n_func(n-2) + n_func(n-3);
	
}
long long int n_func(int k){
	long long int nm;
	if(dp[k]!=-1) nm = dp[k];
	else nm = dp[k] = kimchi(k);
	return nm;
}

void init(){
	int i=100;
	while(i--){
		dp[i]=-1;
	}
}

int main(void){
	int T;
	cin >> T;
	init();
	cout << kimchi(T);
	return 0;
}