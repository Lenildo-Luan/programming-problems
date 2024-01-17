/*

==========  LENILDO LUAN CARLOS  ==========
========== LENILDOLUAN@GMAIL.COM ==========

Question: https://www.beecrowd.com.br/judge/en/runs/code/37266833

*/

#include <stdio.h>
#include <iostream> 
#include <cstdarg>
#include <cmath>

using namespace std;

int main() {
    int wins = 0;
    int testCasesQtd, testCase, carDoor;
    
    cin >> testCasesQtd;
    
    for(testCase = 0; testCase < testCasesQtd; testCase++) {
        cin >> carDoor;
        if(carDoor != 1) wins++;
    }
    
    cout << wins << endl;  
    
    return 0;
}
