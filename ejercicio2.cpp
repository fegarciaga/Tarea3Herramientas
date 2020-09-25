#include <cmath>
#include <cstdlib>
#include <iostream>

double myatan(double x, int n);

int main(int argc, char **argv)
{
    std::cout.precision(15); std::cout.setf(std::ios::scientific);
    const int NSTEPS = std::atoi(argv[1]);// 53
    const double x = std::atof(argv[2]); // 4.2
    const double exact = std::atan(x);
    double my= myatan(x, NSTEPS);
    double diff = std::fabs(my-exact)/exact;
    std::cout << diff << std::endl;
    
    return 0;
}

double myatan(double x, int n)
{
    double x1= x, f=0, sign=1.0, sign1=1.0;
    double a=std::pow(2.0, -(1.0*n)/2), b=x1/(1+std::sqrt(1+x1*x1)), c=1.0, d=1.0;
    while(1-a>std::pow(2.0, -1.0*n))
    {
        c=2.0*c/(1+a);
        d=2.0*a*b/(1+b*b);
        d=(1.0*d)/(1+std::sqrt(1-d*d));
        d=(b+d)/(1-b*d);
        b=d/(1+std::sqrt(1+d*d));
        a=2.0*std::sqrt(a)/(1+a);
    }
    return sign1*c*std::log((1+b)/(1-b))+f*sign*M_PI/2.0;
    
}
