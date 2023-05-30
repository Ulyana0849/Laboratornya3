/*!
    @file
    @brief Заголовочный файл класса Complex
*/

#ifndef _MY_COMPLEX_H_
#define _MY_COMPLEX_H_
#include <iostream>

using namespace std;

/*!
    @brief Класс комплексного числа
*/
class Complex{
    /*!
        @brief Действительная составляющая
    */
    double Re;

    /*!
        @brief Мнимая составляющая
    */
    double Im;

public:
    Complex(double aRe = 0, double aIm = 0);
    Complex(const Complex&);
    ~Complex();

    operator double();

    double abs();

    Complex operator+ (const Complex&);
    Complex operator+ (const double&);

    Complex operator* (const Complex&);
    Complex operator* (const double&);

    Complex operator- (const double&);
    Complex operator- (const Complex&);

    Complex& operator+= (const Complex&);
    Complex& operator+= (const double&);

    Complex& operator*= (const Complex&);
    Complex& operator*= (const double&);

    Complex& operator-= (const Complex&);
    Complex& operator-= (const double&);

    Complex& operator/= (const Complex&);
    Complex& operator/= (const double&);

    Complex& operator= (const Complex&);
    Complex& operator= (const double&);

    friend istream& operator>> (istream&, Complex&);
    friend ostream& operator<< (ostream&, Complex&);
    friend Complex operator+ (const double&, const Complex&);
    friend Complex operator* (const double&, const Complex&);
    friend Complex operator- (const double&, const Complex&);
    };
#endif
