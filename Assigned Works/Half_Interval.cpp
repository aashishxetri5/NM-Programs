#include <iostream>
#include <cmath>

float calc(float value) {
    return ( pow(value, 3) - value - 3);
}

void display(float *xl, float *fxl, float *xu, float *fxu, float *xm, float *fxm, float *err){
    
    std::cout << *xl << "\t" << *fxl << "\t";
    std::cout << *xu << "\t" << *fxu << "\t";
    std::cout << *xm << "\t" << *fxm << "\t";
    std::cout << *err << "\n";
}

float halfInterval(float *xl, float *fxl, float *xu, float *fxu, float *xm, float *fxm, float *err) {
    
    display(xl, fxl, xu, fxu, xm, fxm, err);
    
    if(*fxm < 0){
        *xl = *xm;
        *fxl = *fxm;
    } else {
        *xu = *xm;
        *fxu = *fxm;
    }
    
    float oldxm = *xm;
    
    *xm = (*xu + *xl)/2;
    *fxm = calc(*xm);
    *err = std::abs( (*xm - oldxm) / *xm );
    
    if(*err > 0.005f){
        return halfInterval(xl, fxl, xu, fxu, xm, fxm, err);
    } else {
        display(xl, fxl, xu, fxu, xm, fxm, err);
        return *xm;
    }
    
}

int main() {
    float xl, fxl, xu, fxu, xm, fxm, err;
    
    xl = 1;
    fxl = calc(xl);
    xu = 2;
    fxu = calc(xu);
    xm = (xl+xu)/2;
    fxm = calc(xm);
    err = (xu - xl)/xu;
    
    float x = halfInterval(&xl, &fxl, &xu, &fxu, &xm, &fxm, &err);

    std::cout << "\nRoot is:" << x;

    return 0;
}