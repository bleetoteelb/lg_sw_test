#include <iostream>
using namespace std;

unsigned int Make_Data(unsigned int rcv);

// 작성할 함수
unsigned int Make_Data(unsigned int rcv)
{
	int sol = 0;
    int twobit[32] = {0,};
    int squre[32] = {0,};
	for(int i=0;i<32;i++){
        if(rcv==0) break;
        twobit[31-i] = rcv%2;

        rcv/=2;
    }

    squre[31] = 1;
    for(int i=1;i<32;i++) {
        squre[31-i] = squre[32-i]*2;
    }


    sol += twobit[28]*squre[0];
    sol += twobit[29]*squre[1];
    sol += twobit[30]*squre[2];
    sol += twobit[31]*squre[3];

    sol += twobit[13]*squre[4];
    sol += twobit[14]*squre[5];
    sol += twobit[15]*squre[6];
    sol += twobit[16]*squre[7];

    sol += twobit[0]*squre[8];
    sol += twobit[1]*squre[9];
    sol += twobit[2]*squre[10];
    sol += twobit[3]*squre[11];
    sol += twobit[4]*squre[12];
    sol += twobit[5]*squre[13];

    sol += twobit[21]*squre[14];
    sol += twobit[22]*squre[15];

    sol += twobit[6]*squre[16];
    sol += twobit[7]*squre[17];
    sol += twobit[8]*squre[18];

    sol += twobit[23]*squre[19];
    sol += twobit[24]*squre[20];
    sol += twobit[25]*squre[21];
    sol += twobit[26]*squre[22];
    sol += twobit[27]*squre[23];

    sol += twobit[17]*squre[24];
    sol += twobit[18]*squre[25];
    sol += twobit[19]*squre[26];
    sol += twobit[20]*squre[27];

    sol += twobit[9]*squre[28];
    sol += twobit[10]*squre[29];
    sol += twobit[11]*squre[30];
    sol += twobit[12]*squre[31];

    //cout << sol<<endl;
	return sol;
}

int main(void)
{
	unsigned int rcv=0,sol;
	
	// 입력 받는 부분
	cin >> hex >> uppercase >> rcv;

	sol = Make_Data(rcv);

	cout << hex << uppercase << sol;
}