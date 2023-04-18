#include <iostream>

class Complex {
   private:
    double real;
    double imag;

   public:
    Complex(double real = 0.0, double imag = 0.0) {
        this->real = real;
        this->imag = imag;
    }

    // TODO (hint: "friend")
    friend Complex operator+(const Complex& c1, const Complex& c2);
    friend Complex operator-(const Complex& c1, const Complex& c2);
    friend Complex operator*(const Complex& c1, const Complex& c2);
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
};

Complex operator+(const Complex& c1, const Complex& c2) {
    // TODO
    Complex plus(c1.real + c2.real , c1.imag + c2.imag);
    return plus;
}

Complex operator-(const Complex& c1, const Complex& c2) {
    Complex m(c1.real - c2.real , c1.imag - c2.imag);
    return m;
}

Complex operator*(const Complex& c1, const Complex& c2) {
    //(a+bi)(c+di)=(ac-bd)+(ad+bc)i
    // TODO
    Complex mul(c1.real * c2.real - c1.imag * c2.imag , c1.real * c2.imag + c1.imag * c2.real);
    return mul;
}

std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << "(" << c.real << ", " << c.imag << ")";
    return os;
}

int main() {
    Complex c1(1.0, 2.0);
    Complex c2(3.0, 4.0);

    std::cout << "c1 = " << c1 << std::endl;
    std::cout << "c2 = " << c2 << std::endl;

    Complex c3 = c1 + c2;
    std::cout << "c1 + c2 = " << c3 << std::endl;

    Complex c4 = c1 - c2;
    std::cout << "c1 - c2 = " << c4 << std::endl;

    Complex c5 = c1 * c2;
    std::cout << "c1 * c2 = " << c5 << std::endl;

    return 0;
}