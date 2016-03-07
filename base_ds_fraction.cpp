#include <iostream>
#include <vector>

using namespace std;

class Fraction {
public:
    int _num; //numerator
    int _den; //denominator
    
    Fraction() : _num(0), _den(0) {}
    Fraction(int x, int y) {
        if (x==0 && y==0) {
            _num = 0;
            _den = 0;
        }
        else if (x!=0 && y==0) {
            _num = 1;
            _den = 0;
        }
        else {
            int z = gcd(x, y);
            if (z != 1) {
                x /= z;
                y /= z;
            }
            _num = x;
            _den = y;
            
            int sign = 1;
            if (x*y < 0)
                sign = -1;
            _num = abs(x);
            _den = sign*abs(y);
        }
    }
    
    int num() const {return _num;}
    int den() const {return _den;}
    bool is_null() const {
        if (den()==0 && num()==0)
            return true;
        return false;
    }
    
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
    
    /* operator overload */
    bool operator<(const Fraction& a) const;
};

inline bool operator==(const Fraction& a, const Fraction& b) {
    /*
     if (a.is_null() || b.is_null())
     return false;
     */
    
    if (a.num() == b.num() && a.den() == b.den())
        return true;
    else
        return false;
}

inline bool operator!=(const Fraction& a, const Fraction& b) {
    return !(a==b);
}

bool Fraction::operator<(const Fraction& a) const {
    /*bug fix because of this code snippet*/
    if (is_null() && !a.is_null())
        return true;
    if (!is_null() && a.is_null())
        return false;
    /*end fix*/
    
    if (den()==0 && a.den()==0) {
        /*
         if (*this==a)
         return false;
         */
        return false;
    }
    else if (den()==0 || a.den()==0) {
        if (den() == 0)
            return false;
        else
            return true;
    }
    else {
        int l = num() * a.den();
        int r = a.num() * den();
        return l < r;
    }
    return false;
}

ostream& operator<<(ostream& out, const Fraction& a) {
    if (a.num()==0 && a.den()==0)
        return out << "NULL";
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
