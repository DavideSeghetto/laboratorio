#include <iostream>

using namespace std;

class Rational {
	
	private:
		int num;
		int den;
	
	public:
		Rational(int num, int den);
		int get_num();
		int get_den();
		void assignment(int a, int b);
};

Rational::Rational(int num, int den) {
	this->num = num;
	this->den = den;
}
	
int Rational::get_num() {
	return num;
}

int Rational::get_den() {
	return den;
}

void Rational::assignment(int num_, int den_) {
	num = num_;
	den = den_;
}

double conversion(Rational r) {
	return r.get_num() / r.get_den();
}

int mcm(int x, int y) {
	int s = x;
	int j = y;
	while(j != 0) {
		int z = s % j;
		s = j;
		j = z;
	}
	return x*y/s;
}
	
Rational operator+(Rational r1, Rational r2) {
	int n1 = r1.get_num();
	int n2 = r2.get_num();
	int d1 = r1.get_den();
	int d2 = r2.get_den();

	int mcm_ = mcm(d1, d2);
	int new_num = (mcm_ / d1 * n1) + (mcm_ / d2 * n2);
	
    return Rational(new_num, mcm_);
}

Rational operator-(Rational r1, Rational r2) {
	int n1 = r1.get_num();
	int n2 = r2.get_num();
	int d1 = r1.get_den();
	int d2 = r2.get_den();

	int mcm_ = mcm(d1, d2);
	int new_num = (mcm_ / d1 * n1) - (mcm_ / d2 * n2);
	
    return Rational(new_num, mcm_);
}

Rational operator*(Rational r1, Rational r2) {
	int n1 = r1.get_num();
	int n2 = r2.get_num();
	int d1 = r1.get_den();
	int d2 = r2.get_den();

	int new_num = n1 * n2;
	int new_den = d1 * d2;
	int mcm_ = mcm(new_num, new_den);
	
    return Rational(new_num, new_den);
}

Rational operator/(Rational r1, Rational r2) {
	int new_num;
	int new_den;

	if(r1.get_num() % r2.get_num() == 0 && r1.get_den() % r2.get_den() == 0) {
		new_num = r1.get_num() / r2.get_num();
		new_den = r1.get_den() / r2.get_den();
	}
    return Rational(new_num, new_den);
}

bool operator==(Rational r1, Rational r2) {
	if(r1.get_num() == r2.get_num() && r1.get_den() == r2.get_den()) return true;
	return false;
}

ostream& operator <<(ostream& os, Rational& r) {   
    os << r.get_num() << "/" << r.get_den();                   
    return os;
} 

int main(void) {
	Rational r1 = Rational(6, 10);
    Rational r2 = Rational(3, 2);
    Rational r3 = r1 + r2;
	Rational r4 = r1 - r2;
	Rational r5 = r1 * r2;
	Rational r6 = r1 / r2;
    cout << r3 << endl;
	cout << r4 << endl;
	cout << r5 << endl;
	cout << r6 << endl;
}