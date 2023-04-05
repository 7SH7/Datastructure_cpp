// On my honor, I pledge that I have neither received nor provided improper assistance in the 
// completion of this assignment. 
// 서명: ______김승환_________ 학번: ____22000116_____

/*
* file: hellofunc.cpp
* It prints "Hello World!" or "Hello" with a given name.
* The completed code should work as shown below. “>” is a prompt of the console.
*
* To run the program without a command line argument:
* > ./hello
* > Enter a name: John Lee
* > Hello John Lee!
* > Enter a name: Peter Kim
* > Hello Peter Kim!
* > Enter a name:<Enter>
* > Hello World!
* >
*
* To run the program with a command line argument:
* > ./hello John "Dr. Lee" "Handong Global University" peter
* > Hello John!
* > Hello Dr. Lee!
* > Hello Handong Global University!
* > Hello peter!
* > Hello World!
* >
* To run the program through a pipe
* (names.txt contains a list of names as shown below:)
* > cat names.txt | ./hello
* > Enter a name: Hello john!
* > Enter a name: Hello Dr. Lee!
* > Enter a name: Hello Handong Global University!
* > Enter a name: Hello Peter!
* > Enter a name: Hello World!
*
*/
#include <iostream>
#include <string>
using namespace std;

void printfunc(int n, char *names[]);

int main(int argc, char* argv[]) {
    // if necessary, use setvbuf() to prevent the output from buffered on console.
    // setvbuf(stdout, NULL, _IONBF, 0);
    // cout << "Your code here" << endl;
    // cout << argc ;   // default가 1이네!
    // 아무것도 안 들어왔을 때!
    string str="";
    if (argc==1) {  // 첫번째는 주소값이니까,, default가 1 아닐까?
        do{
            cout << "Enter a name: ";
            getline(cin, str);
            if (str.empty()) {
                cout << "Hello World!\n";
                return 0;
            }
            cout << "Hello " << str << "!" << endl;
        } while (!str.empty());
    }

    char* tmp_argv[argc] = {};
    for(int i = 1 ; i < argc ; i++){
        tmp_argv[i-1]=argv[i];
    }

    if (argc > 1)
    {
        printfunc(argc-1,tmp_argv);
        cout << "Hello World!\n";
    }


    // if necessary use system("pause") to prevent the terminal from disappearing
    // as soon as the program terminates as in Visual Studio sometimes.
    // system("pause");    
    return EXIT_SUCCESS;
}

// names.txt만 만들면 끝나는데.. 다른 건 다 실행 잘 됨.
// names.txt를 임의로 만들고, 실행시켜도 작동 된다.