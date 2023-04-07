#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;
double rounding (double i){
    double a ;
    if (i<0 && i>=-0.004){
        return 0;
    }
    i=i*100;
    a= round(i);
    return a/100;
}

int main(){
    double t;
    double ans;
    cin >> t;
    ans =rounding(t);
    printf ("t = %.2lf",t);
    printf("\n%.2lf",ans)  ;
}