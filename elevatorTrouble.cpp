// Progress

#include <stdio.h>
#include <iostream>
#include <cstdarg>

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
z'  
int push(int f, int s, int g, int u, int d, int pushes) {
    
    if(u == 0 || d == 0) return -1;
        
    if(s == g){
        return pushes;
    } else if((s + u) - g < g - (s - d) && s + u <= f) {
        pushes++;
        s += u;
        return push(f, s, g, u, d, pushes);
    } else if(s - d >= 1) {
        pushes++;
        s -= d;
        return push(f, s, g, u, d, pushes);
    }
    
    return -1;
}

int main() {
    int pushes = 0;
    int f, s, g, u, d;
    
    getData("ddddd", &f, &s, &g, &u, &d);
    pushes = push(f, s, g, u, d, pushes);
    
    if(pushes == -1) cout << "use the stairs" << endl;
    else cout << pushes;
    
    return 0;
}
