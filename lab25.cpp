#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		bool operator==(const ComplexNumber &);
		double abs();
		double angle();
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}

//Write your code here
ComplexNumber ComplexNumber::operator*(const ComplexNumber &c){
    ComplexNumber z;
    z.real = real*c.real - imag*c.imag;
    z.imag = c.real*imag + real*c.imag;
	return z;
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c){
    ComplexNumber z;
    double s = pow(c.real,2) + pow(c.imag,2);
    z.real = (real*c.real + imag*c.imag)/s;
    z.imag = (c.real*imag - real*c.imag)/s;
	return z;
}

bool ComplexNumber::operator==(const ComplexNumber &c){
    if(c.real == real && c.imag == imag){
        return true;
    }
    else{
        return false;
    }
}

double ComplexNumber::abs(){
    double s = pow(real,2) + pow(imag,2);
    return sqrt(s);
}

double ComplexNumber::angle(){
    double k = atan2(imag,real) * 180 / M_PI;
    return k;
}

ComplexNumber operator+(double p,const ComplexNumber &c){
	return ComplexNumber(p+c.real,c.imag);
}

ComplexNumber operator-(double p,const ComplexNumber &c){
	return ComplexNumber(p-c.real,-c.imag);
}

ComplexNumber operator*(double p,const ComplexNumber &c){
    ComplexNumber z;
    z.real = p*c.real;
    z.imag = p*c.imag;
	return z;
}

ComplexNumber operator/(double p,const ComplexNumber &c){
    ComplexNumber z;
    double s = pow(c.real,2) + pow(c.imag,2);
    z.real = (p*c.real)/s;
    z.imag = (p*-c.imag)/s;
	return z;
}

bool operator==(double p,const ComplexNumber &c){
    if(c.real == p && c.imag == p){
        return true;
    }
    else{
        return false;
    }
}

ostream & operator<<(ostream &gtfo, const ComplexNumber &c){ //imag is 1 become only i 
    if(c.imag > 0){
        if(c.real == 0) return gtfo << c.imag << "i";
        else return gtfo << c.real << "+" << c.imag << "i";
    }
    else if(c.imag == 0){
        return gtfo << c.real;
    }
    else{
        if(c.real == 0) return gtfo << c.imag << "i";
        else return gtfo << c.real << c.imag << "i";
    }
}

int main(){
	ComplexNumber a(1.5,2),b(3.2,-2.5),c(-1,1.2);	
	cout << a << "\n";
	cout << b << "\n";
	cout << c << "\n";
	cout << a+2.5 << "\n";
	cout << 2.5+a << "\n";
	cout << a-1.5 << "\n";
	cout << 1.5-a << "\n";
	cout << b+ComplexNumber(0,2.5) << "\n";
	cout << c-c << "\n";
	cout << "-----------------------------------\n";
	
	ComplexNumber d = (a+b)/c;
	ComplexNumber e = b/(a-c);
	cout << d << "\n";
	cout << e << "\n";
	cout << c*2 << "\n";
	cout << 0.5*c << "\n";
	cout << 1/c << "\n";
	cout << "-----------------------------------\n";
	
	cout << ComplexNumber(1,1).abs() << "\n";
	cout << ComplexNumber(-1,1).abs() << "\n";
	cout << ComplexNumber(1.5,2.4).abs() << "\n";
	cout << ComplexNumber(3,4).abs() << "\n";
	cout << ComplexNumber(69,-9).abs() << "\n";		
	cout << "-----------------------------------\n";	
	
	cout << ComplexNumber(1,1).angle() << "\n";
	cout << ComplexNumber(-1,1).angle() << "\n";
	cout << ComplexNumber(-1,-1).angle() << "\n";
	cout << ComplexNumber(1,-1).angle() << "\n";
	cout << ComplexNumber(5,2).angle() << "\n";
	cout << "-----------------------------------\n";
	
	cout << (ComplexNumber(1,1) == ComplexNumber(1,2)) << "\n";
	cout << (ComplexNumber(1,1) == 1) << "\n";
	cout << (0 == ComplexNumber()) << "\n";
}





