// 아너코드: On my honor, I pledge that I have neither received nor provided 
// improper assistance in the completion of this assignment. 
// Signed: Kim Seunghwan Student Number: 22000116

#include<iostream>
#include<vector>
using namespace std;
// 위 아래 둘 다 range-for 사용해야하는지?
// #if 에 0 / 1 지정이 안 되어 있는 경우, 그냥 아무거나 적어서 제출 가능한가?
#if 0
// mulitply even number elements in the list by 10
// without using reference variable.
int main(int argc, char* argv[]) {
	vector<int> list = { 0, 1, 2, 2, 4, 5, 6, 7, 8, 8, 10 };
	//cout << "your code here\n";
	for (size_t i = 0; i < list.size(); i++) {
		if (list[i] % 2 == 0)	list[i] *= 10;
	}
	for (auto x : list) cout << x << " ";
	return 0;
}
#else
// mulitply even number elements in the list by 10
// using reference variable.
int main(int argc, char* argv[]) {
	vector<int> list = { 0, 1, 2, 2, 4, 5, 6, 7, 8, 8, 10 };
	//cout << "your code here\n";
	// 이거 range-for + 참조변수 사용해야함.
	// for (int i = 0; i < list.size(); i++) {
	for (auto& i : list) {	// auto 
		int& tmp = i;
		if (tmp % 2 == 0)	tmp *= 10;
	// cout << i << " ";	 // 
	}
	for (auto x : list) cout << x << " ";

	return 0;
}
#endif