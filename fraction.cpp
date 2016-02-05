#include <iostream>
#include <vector>

using namespace std;

class Fraction {
public:
    int _num; //numerator
    int _den; //denominator

    Fraction() : _num(0), _den(1) {}
    Fraction(int x, int y) {
        int z = gcd(x, y);
        if (z != 1) {
            x /= z;
            y /= z;
        }

        _num = x;
        _den = y;
    }

    int num() const {return _num;}
    int den() const {return _den;}

    /* Greatest Common Divisor */
    int gcd(int a, int b) {
        int c;
        while (a != 0) {
            c = a;
            a = b%a;
            b = c;
        }
        return b;
    }
};

inline bool operator==(const Fraction& a, const Fraction& b) {
    if (a.num() == b.num() && a.den() == b.den())
        return true;
    else
        return false;
}

inline bool operator!=(const Fraction& a, const Fraction& b) {
    return !(a==b);
}

ostream& operator<<(ostream& out, const Fraction& a) {
    return out << a.num() << "/" << a.den();
}

int main(int argc, char* argv[]) {
    Fraction frac1(4, 10);
    cout << frac1 << endl;
    Fraction frac2(32, 80);
    cout << frac2 << endl;

    if (frac1 != frac2)
        cout << "not equal" << endl;
    else
        cout << "equal" << endl;

    return 0;
}
