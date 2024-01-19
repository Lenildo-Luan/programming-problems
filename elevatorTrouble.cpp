/*

==========  LENILDO LUAN CARLOS  ==========
========== LENILDOLUAN@GMAIL.COM ==========

Question: https://www.beecrowd.com.br/judge/en/runs/code/37286827

Process:

1. Trying a recursive approach
2. Recursive approach is slow, change to iterative

Obs: variable names is from the question

*/

#include <stdio.h>
#include <iostream>
#include <cstdarg>
#include <vector>

using namespace std;

void getData(const char* format...) {
    // Variadic functions: https://en.cppreference.com/w/cpp/utility/variadic
    
    double* doubleArg;
    int* intArg;
    va_list args;
    va_start(args, format);
 
    while (*format != '\0') {  
        switch(*format) {
          case 'f':
            doubleArg = va_arg(args, double*);
            cin >> *doubleArg;
            break;
          case 'd':
            intArg = va_arg(args, int*);
            cin >> *intArg;
            break;
          default:
            cout << "Format \"" << *format << "\" don't exist" << endl;
            break;
        }

        ++format;
    }
 
    va_end(args);
}

int calcDistAfterPush(int s, int p, int g) {
    int distance = g - (s + p);
    if(distance < 0) distance *= -1;
    return distance;
}

int main() {
    int pushes = 0;
    int f, s, g, u, d;
    
    getData("ddddd", &f, &s, &g, &u, &d);
    
    vector<bool> floorIsPushed(f, false);
    
    while(1) {
        if(s == g){
            break;
        } else if (floorIsPushed[s-1]) {
            pushes = -1;
            break;
        } else if(calcDistAfterPush(s, u, g) < calcDistAfterPush(s, -d, g) && s + u <= f) {
            pushes++;
            floorIsPushed[s-1] = true;
            s += u;
        } else if(s - d >= 1) {
            pushes++;
            floorIsPushed[s-1] = true;
            s -= d;
        }
    }    
    
    if(pushes == -1) cout << "use the stairs" << endl;
    else cout << pushes << endl;
    
    return 0;
}
