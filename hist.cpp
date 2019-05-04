#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

const int N = 1000;
const double mi = 0;
const double ma = 10;
const int del = 10;
const int k = 20;

int main(){
	vector<int> counter(del, 0);

	double tmp;
	for(int i = 0; i < N; i++) {
		cin>>tmp;
		counter[min(max(int((tmp - mi) * del / (ma - mi)), 0), del - 1)]++;
	}

	int height = 0;
	for(int& i: counter) {
		i = i / k + int(i % k > 0);
		if(i > height) height = i;
	}

	for(int i = height; i > 0; i--) {
		string tmp(del, ' ');
		for(int j = 0; j < del; j++)
			if(counter[j] >= i)
				tmp[j] = '*';
		cout<<tmp<<endl;
	}
}