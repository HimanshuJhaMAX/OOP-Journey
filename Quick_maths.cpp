#include<iostream>
#include<cmath>
using namespace std ;

class MathOperations
{
public:

    int addition (int a ,int b)
    {
        return a+b;
    }

    int subtract (int a , int b)
    {
        return a - b;
    }

    int multiply (int a , int b)
    {
        return a * b;
    }

    int power (int a ,int b)
    {
        return static_cast<double>(pow(a , b));
    }

    int division (int a , int b)
    {
        return static_cast<double>( a / b);
    }

};

int main ()
{
    MathOperations mathop;
    int num1 , num2 ,result = 0 ;
    char sign;
    cout<<"Enter first number:\n";
    cin>> num1;
    cout<<"Enter second number:\n";
    cin>> num2;
    cout<<"Which mathematical operations you want to perform:";
    cin>> sign;
    if(sign == '+')
    {
        result = mathop.addition(num1, num2);
    }
    else if(sign == '-')
    {
        result = mathop.subtract(num1, num2);
    }
    else if (sign == '*')
    {
        result = mathop.multiply(num1 , num2);
    }
    else if (sign == '^')
    {
        result = mathop.power(num1 , num2);
    }
    else if (sign == '/')
    {
        result = mathop.division(num1 , num2);
    }
    else
    {
        cout << "Please enter the mathematical sign for the operation ";
        return 1;
    }
    cout << "The result for "<<num1 <<" "<<sign<<" "<<num2<<" is "<<result;
    return 0; 
}