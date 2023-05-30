/*!
    @file
    @brief Файл с описанием методов класса Complex
*/

#include <iostream>
#include <cmath>
#include "mycomplex.h"

using namespace std;

/*!
    @brief Конструктор класса
    @param aRe Действительная составляющая
    @param aIm Минимальная состовляющая
*/

Complex::Complex(double aRe, double aIm){
    Re = aRe;
    Im = aIm;
}

/*!
    @brief Конструктор класса
    @param complex_num Комплексное число
*/
Complex::Complex(const Complex& complex_num){
    Re = complex_num.Re;
    Im = complex_num.Im;
}

/*!
    @brief Деструктор класса
*/
Complex::~Complex(){
    Re = 0.0;
    Im = 0.0;
}

/*!
    @brief Возвращает модуль комплексного числа
    @param Модуль комплексного числа
*/
Complex::operator double(){
    return abs();
}

/*!
	@brief Возвращает модуль комплексного числа
*/
double Complex::abs()
{
	return sqrt(Re * Re + Im * Im);
}
/*!
	@brief Перегрузка арифметического оператора сложения
	@return Сумму обьектов комплексных чисел
*/
Complex Complex::operator+ (const Complex& aRval)
{
	Complex Result;
	Result.Re = Re + aRval.Re;
	Result.Im = Im + aRval.Im;
	return Result;
}
/*!
	@brief Перегрузка арифметического оператора вычитания
	@return Разность обьектов комплексных чисел
*/
Complex Complex::operator- (const Complex& aRval)
{
	Complex Result;
	Result.Re = Re - aRval.Re;
	Result.Im = Im - aRval.Im;
	return Result;
}
/*!
	@brief Перегрузка арифметического оператора сложения
	@return Сумму обьекта комплексного числа с числом
*/
Complex Complex::operator+ (const double& aval)
{
	Complex result;
	result.Re = Re + aval;
	result.Im = Im;
	return result;
}
/*!
	@brief Перегрузка арифметического оператора вычитания
	@return Разность обьекта комплексного числа с числом
*/
Complex Complex::operator- (const  double& aRval)
{
	Complex Result(*this);
	Result.Re = Re - aRval;
	return Result;
}
/*!
	@brief Перегрузка арифметического оператора умножения
	@return Произведение обьектов комплексных чисел
*/
Complex Complex::operator* (const Complex& aRval)
{
	Complex Result;
	Result.Re = Re * aRval.Re - Im * aRval.Im;
	Result.Im = Re * aRval.Im + Im * aRval.Re;
	return Result;
}
/*!
	@brief Перегрузка арифметического оператора умножения, перегруженная функция
	@return Произведение обьекта комплексного числа с числом
*/
Complex Complex::operator* (const double& aRval)
{
	Complex Result;
	Result.Re = Re * aRval;
	Result.Im = Im * aRval;
    return Result;
}
/*!
	@brief Перегрузка арифметического оператора деления
	@return Частное обьекта комплексного числа с числом
*/
Complex Complex::operator/ (const double& aRval)
{
	Complex Result;
	Result.Re = Re / aRval;
	Result.Im = Im / aRval;
	return Result;
}
/*!
	@brief Перегрузка арифметического оператора присваивания-сложения
	@return Сумму обьектов комплексных чисел
*/
Complex& Complex::operator+= (const Complex& arval)
{
	Re += arval.Re;
	Im += arval.Im;
	return *this;
}
/*!
	@brief Перегрузка арифметического оператора присваивания-вычитания
	@return Разность обьектов комплексных чисел
*/
Complex& Complex::operator-= (const Complex& aRval)
{
	Re -= aRval.Re;
	Im -= aRval.Im;
	return *this;
}
/*!
	@brief Перегрузка арифметического оператора присваивания-умножения
	@return Произведение обьектов комплексных чисел
*/
Complex& Complex::operator*= (const Complex& aRval)
{
	double tmpRe = Re;
	Re = Re * aRval.Re - Im * aRval.Im;
	Im = Im * aRval.Re + tmpRe * aRval.Im;
	return *this;
}
/*!
	@brief Перегрузка арифметического оператора присваивания-сложения, перегрузка функции
	@return Сумму обьекта комплексного числа с числом
*/
Complex& Complex::operator+= (const double& aRval)
{
	Re += aRval;
	return *this;
}
/*!
	@brief Перегрузка арифметического оператора присваивания-вычитания, перегрузка функции
	@return Разность обьекта и числа
*/
Complex& Complex::operator-= (const double& aRval)
{
	Re -= aRval;
	return *this;
}
/*!
	@brief Перегрузка арифметического оператора присваивания-умножения, перегрузка функции
	@return Произведение обьекта и числа
*/
Complex& Complex::operator*= (const double&  aRval)
{
	Re *= aRval;
	Im *= aRval;
	return *this;
}
/*!
	@brief Перегрузка арифметического оператора присваивания-деления, перегрузка функции
	@return Частное обьекта и числа
*/
Complex& Complex::operator/= (const double& aRval)
{
	Re /= aRval;
	Im /= aRval;
    return *this;
}
/*!
	@brief Перегрузка оператора присваивания
	@return Копия обьекта
*/
Complex& Complex::operator= (const Complex& aRval)
{
	Re = aRval.Re;
	Im = aRval.Im;
	return *this;
}
/*!
	@brief Перегрузка оператора присваивания, перегрузка функции
	@return Обьект комплексного числа
*/
Complex& Complex::operator= (const double& aRval)
{
	Re = aRval;
	Im = 0.0;
	return *this;
}
/*!
	@brief Перегрузка оператора ввода
	@return Поток ввода для комплексного числа
*/
istream& operator>> (istream& stream, Complex& a)
{
	char tmp[256];
	stream >> a.Re >> a.Im >> tmp;
	return stream;
}
/*!
	@brief Перегрузка оператора вывода
	@return Поток вывода для комплексного числа
*/
ostream& operator<< (ostream& stream, Complex& a)
{
	stream << a.Re;
	if(!(a.Im < 0))
		stream << '+';
	stream << a.Im << 'i';
	return stream;
}
/*!
	@brief Перегрузка арифметического оператора сложения
	@return Сумму обьекта комплексного числа с числом
*/
Complex operator+ (const double& aLval, const Complex& aRval)
{
	Complex Result;
	Result.Re = aLval + aRval.Re;
	Result.Im = aRval.Im;
	return Result;
}
/*!
	@brief Перегрузка арифметического оператора вычитания
	@return Разность обьекта комплексного числа с числом
*/

Complex operator- (const double& aLval, const Complex& aRval)
{
	Complex Result;
	Result.Re = aLval - aRval.Re;
	Result.Im =- aRval.Im;
	return Result;
}
/*!
	@brief Перегрузка арифметического оператора произведения
	@return Произведение обьекта комплексного числа с числом
*/
Complex operator* (const double& aLval, const Complex& a)
{
	Complex r;
	r.Re = aLval* a.Re;
	r.Im = aLval * a.Im;
	return r;
}

