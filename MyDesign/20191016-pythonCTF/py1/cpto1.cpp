#include <bits/stdc++.h> 
using namespace std;

int main(){
	int result[10];
	bool check[10];
	int cnt = 0;
	string owo = "D0THeR1ghT1ng0w0";
	srand(time(NULL));
	for (int i=0; i<10; i++){
		int a, b;
		a = rand() % 10000;
		b = rand() % 10000;
		cout << a << " * " << b << " = ?\n";
		result[i] = a * b;
	}
	int rst;
	string str2 = "PA";
	for (int i=0; i<10; i++){
		time_t start_t = time(NULL);

		cin >> rst;
		if(rst != result[i]){
			cout <<"Wrong Answer!\n";
			return 0;
		}
		else{
			cnt++;
		}

		time_t current_t = time(NULL);

		if(difftime(current_t, start_t) >= 2){

			cout <<"T";
			for(int i=0; i<14; i++) cout << "o";
			cout <<" sl";
			for(int i=0; i<10; i++) cout << "o";
			for(int i=0; i<10; i++) cout << "w";
			cout << endl;
			cout << char(66) << char(121) << char(101) << char(126) <<"\n";
			return 0;
		}
	}
	string str = "CD";
	if(cnt == 10){
		cout << str << str2;
		cout <<"{";
		cout << owo;
		cout <<"}\n";
	}
	return 0;
}