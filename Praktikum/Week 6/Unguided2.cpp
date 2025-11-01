#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Hello World!" << endl;
    Stack S;

    CreateStack(S);
    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);
    printInfo(S);

    cout << "balik stack" << endl;
    
    balikStack(S);
    printInfo(S);

    return 0;
}