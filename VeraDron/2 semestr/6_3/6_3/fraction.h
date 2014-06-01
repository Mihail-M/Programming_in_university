#pragma once
#include <iostream>
#include <cmath>
#include <algorithm>

using  namespace std;
class Fraction {
private:
	int nominator;
	int denominator;
	void simplify() {
		if (denominator < 0) {
			nominator *= -1;
			denominator *= -1;
		}
		if (abs(nominator) < 2) return;
		int gcd = getGCD(std::abs(nominator), denominator);
		nominator /= gcd;
		denominator /= gcd;
	}
public:
	Fraction(int nominator, int denominator) : nominator(nominator), denominator(denominator) {
		simplify();
	}
	Fraction() : nominator(0), denominator(1) {}
	Fraction(const Fraction &other) : nominator(other.getNominator()), denominator(other.getDenominator()) {}
	Fraction(int value) : nominator(value), denominator(1) {}
	int getNominator() const {
		return nominator;
	}
	int getDenominator() const {
		return denominator;
	}
	double getValue() const {
		return static_cast<double>(getNominator()) / static_cast<double>(getDenominator());
	}
	int compareTo(const Fraction &other) const {
		return getNominator() * other.getDenominator() - getDenominator() * other.getNominator();
	}
	static int getGCD(int a, int b) {
		while (a != b)
		if (a > b) a -= b; 
		else b -= a;
		return a;
	}
};

std::ostream &operator<<(std::ostream &stream, const Fraction &Fraction) {
	return stream << Fraction.getNominator() << "/" << Fraction.getDenominator();
}

Fraction operator-(const Fraction &a) {
	return Fraction(-a.getNominator(), a.getDenominator());
}

Fraction operator+(const Fraction &a, const Fraction &b) {
	int commonDenominator = a.getDenominator() * b.getDenominator();
	int commonNominator = a.getNominator() * b.getDenominator() + b.getNominator() * a.getDenominator();
	return Fraction(commonNominator, commonDenominator);
}

Fraction operator-(const Fraction &a, const Fraction &b) {
	return a + -b;
}

Fraction operator*(const Fraction &a, const Fraction &b) {
	return Fraction(a.getNominator() * b.getNominator(), a.getDenominator() * b.getDenominator());
}

Fraction operator/(const Fraction &a, const Fraction &b) {
	return Fraction(a.getNominator() * b.getDenominator(), a.getDenominator() * b.getNominator());
}

bool operator==(const Fraction &a, const Fraction &b) { return a.compareTo(b) == 0; }
bool operator!=(const Fraction &a, const Fraction &b) { return a.compareTo(b) != 0; }

bool operator<(const Fraction &a, const Fraction &b) { return a.compareTo(b) < 0; }
bool operator>(const Fraction &a, const Fraction &b) { return a.compareTo(b) > 0; }
bool operator<=(const Fraction &a, const Fraction &b) { return a.compareTo(b) <= 0; }
bool operator>=(const Fraction &a, const Fraction &b) { return a.compareTo(b) >= 0; }


Fraction abs(Fraction a){
	return Fraction(abs(a.getNominator()), a.getDenominator());
}