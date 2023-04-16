#include <iostream>
using namespace std;
class Fraction{
    private:
        int numerator;
        int denominator;

    public:
        Fraction(int numerator, int denominator){
            this -> numerator = numerator;
            this -> denominator = denominator;
        }

        void print(){
            cout<<numerator<<" / "<<denominator<<endl;
        }

        void simplify(){
            int gcd = 1;
            int j = min(numerator,denominator);
            for (int i =1; i <=j; i++){
                if(numerator % i == 0 && denominator % i == 0){
                    gcd = i;
                }
            }
            numerator /= gcd;
            denominator /= gcd;
        }
        Fraction add(Fraction const &f2){
            int lcm = denominator * f2.denominator;
            int x = lcm/denominator;
            int y = lcm/f2.denominator;
            int num = x * numerator + ( y * f2.numerator);
            Fraction fnew(num,lcm);
            fnew.simplify();
            return fnew;
        }
        Fraction operator+(Fraction const &f2) const{
            int lcm = denominator * f2.denominator;
            int x = lcm/denominator;
            int y = lcm/f2.denominator;
            int num = x * numerator + ( y * f2.numerator);
            Fraction fnew(num,lcm);
            fnew.simplify();
            return fnew;
        }

        Fraction operator*(Fraction const &f2) const{
            int n = numerator * f2.numerator;
            int d = denominator * f2.denominator;
            Fraction fnew(n, d);
            fnew.simplify();
            return fnew;
        }

        bool operator==(Fraction &f2){
            simplify();
            f2.simplify();
            return (numerator==f2.numerator && denominator==f2.denominator);
        }

        //Pre-increment
        Fraction& operator++(){
            numerator = numerator+denominator;
            simplify();

            return *this;
        }

        //Post-increment
        Fraction operator++(int) {
            Fraction fnew(numerator,denominator);
            numerator = numerator + denominator;
            simplify();
            fnew.simplify();
            return fnew;
        }

        Fraction& operator +=(Fraction const &f2){
            int lcm = denominator * f2.denominator;
            int x = lcm / denominator;
            int y = lcm / f2.denominator;
            int num = x * numerator + (y * f2.numerator);
            numerator = num;
            denominator = lcm;
            simplify();
            return *this;
        }
};

int main(){
    Fraction f1(10,2);
    Fraction f2(20,4);
    Fraction f3 = f1.add(f2);
    Fraction f4 = f1+f2;
    f1.print();
    f2.print();
    f3.print();
    f4.print();
    Fraction f5 =f1*f2;
    f5.print();
    ++f5;
    f5.print();
    Fraction f6 = ++(++f5);
    f6.print();
    f5.print();
    (f6+=f1)+=f1;
    f6.print();
    if(f1==f2){
        cout<<"The fractions are equal"<<endl;
    }
    else{
        cout<<"The fractions are not equal"<<endl;
    }
    return 0;
}
