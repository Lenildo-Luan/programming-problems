/*

==========  LENILDO LUAN CARLOS  ==========
========== LENILDOLUAN@GMAIL.COM ==========

Question: https://www.beecrowd.com.br/judge/en/problems/view/1160

Process:

1. Try to find an equation to solve this problem in o(1)
2. Compound interest can resolve this
3. Dont't work because the problem require the numbers being
   truncate every multiplication
4. Create a loop to made this
5. Organize code in functions

*/

#include <stdio.h>
#include <iostream> 
#include <cstdarg>
#include <cmath>

using namespace std;

void getData(const char* format...) {
    // Variadic functions: https://en.cppreference.com/w/cpp/utility/variadic
    
    double* doubleArg;
    va_list args;
    va_start(args, format);
 
    while (*format != '\0') {  
        switch(*format) {
          case 'f':
            doubleArg = va_arg(args, double*);
            cin >> *doubleArg;
            break;
          default:
            cout << "Format \"" << *format << "\" don't exist" << endl;
            break;
        }

        ++format;
    }
 
    va_end(args);
}
void transformGrowthCityToPercent(double &growthCity1, double &growthCity2) {
    growthCity1 = 1 + (growthCity1 / 100);
    growthCity2 = 1 + (growthCity2 / 100);  
}
void showResult(int years) {    
    if(years > 100) {
        cout << "Mais de 1 seculo." << endl; 
    } else {
        cout << years << " anos." << endl; 
    }
}
int calculateYears(double populationCity1, double populationCity2, double growthCity1, double growthCity2) {
    int years = 0;
    
    while(populationCity1 <= populationCity2) {
        populationCity1 *= growthCity1;
        populationCity2 *= growthCity2;
    
        populationCity1 = trunc(populationCity1);
        populationCity2 = trunc(populationCity2);
        
        years++;
        if(years > 100) break;
    }
    
    return years;
}

int main() {
 
    int testCasesQtd, testCase, years;
    double populationCity1 = 0, populationCity2 = 0, growthCity1 = 0, growthCity2 = 0;
    
    cin >> testCasesQtd;
    
    for(testCase = 0; testCase < testCasesQtd; testCase++) {
        
        years = 0;
        
        getData("ffff", &populationCity1, &populationCity2, &growthCity1, &growthCity2);
        transformGrowthCityToPercent(growthCity1, growthCity2);
        years = calculateYears(populationCity1, populationCity2, growthCity1, growthCity2);
        showResult(years);
        
    }
    
    return 0;
}
