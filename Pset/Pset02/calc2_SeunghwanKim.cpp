// 아너코드: On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment. 
// Signed: Kim Seunghwan  분반: ECE20010  Student Number: 22000116

// no magic number
// do nor repeat yourself
// 나머지% or ^, 연산자를 추가하기 최대한 쉽도록 만듭니다.
// 두 개의 연산자 + - * / 를 입력받는 간단한 프로그램을 작성하기
#include <iostream>
#include <sstream>
using namespace std;

int add(int a, int b) { return a + b; }
int mul(int a, int b) { return a * b; }
int sub(int a, int b) { return a - b; }
int dvd(int a, int b) { if (b != 0) return a / b;  else return 0; }

int get_int() {
    int x;
    do {
        cout << "Enter an integer: ";
        string str;
        getline(cin, str);
        try {
            x = stoi(str);
            break;
        }
        catch (invalid_argument& e) {
            cerr << e.what() << " error ouccurred. Retry~" << endl;
        }
    } while (true);
    return x;
}

pair<char, int> get_op(string opstr) {
    char op;
    size_t x;
    do {
        stringstream ss;
        string str;
        cout << "Enter an operator( " << opstr << " ): ";
        getline(cin, str);
        ss << str;
        ss >> op;
        x = opstr.find(op);
    } while (opstr.find(op) == string::npos);
    return make_pair(op, x);
}


int main() {
    // {} 로 선언해서 초기화 하는 것은 매우 일반적입니다.
    // 연산에 사용될 int (*pf)(int,int)를 선언합니다.
    // switch()를 사용해 op을 각 연산과정으로 분류되도록 합니다.
    // 결과와 함께 연산식도 출력합니다.

    int (*pf[])(int, int) = { add,sub,mul,dvd };
    string opstr{ "+-*/" };

    int a{ get_int() }; // 더할 값 1
    pair<char,int> op{ get_op(opstr) }; // 부호
    int b{ get_int() }; // 더할 값 2

    cout << a << " " << op.first << " " << b << " = " << (*pf[op.second])(a, b) << endl;
    return 0;
}