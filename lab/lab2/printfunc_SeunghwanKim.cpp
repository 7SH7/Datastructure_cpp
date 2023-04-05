// 아너코드: On my honor, I pledge that I have neither received nor provided improper 
// assistance in the completion of this assignment. Signed: Kim SeungHwan Student Number: 22000116

// C++ for C Coders & Data Structures
// Lecture note by idebtor@gmail.com
#include <iostream>
#include <vector>
using namespace std;

void printfunc(int n, char *names[]) {
	for (int i = 0; i < n; i++){      // do not change i = 0 to i = 1.
		cout << "Hello " << names[i] << "!" << endl;
	}	
}

// Add another printfunc() for function overloading 
void printfunc(vector<string>names){
	for(auto i : names ){	
		cout << "Hello " << i << "!" << endl;
	}
}
