#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

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

class Solution {
public:
    /**
     * @param points an array of point
     * @return an integer
     */
    int maxPoints(vector<Point>& points) {
        int size = points.size();
        int* max_points = (int *)malloc(sizeof(int)*size);
        memset(max_points, 0, sizeof(int)*size);

        /*
        Fraction frac1(4, 10);
        cout << frac1 << endl;
        Fraction frac2(32, 80);
        cout << frac2 << endl;

        if (frac1 != frac2)
            cout << "not equal" << endl;
        else
            cout << "equal" << endl;
        */

        free(max_points);
        return 0;
    }
};

int main(int argc, char* argv[]) {
    Point p1(1, 2);
    Point p2(3, 6);
    Point p3(0, 0);
    Point p4(1, 3);

    vector<Point> vp;
    vp.push_back(p1);
    vp.push_back(p2);
    vp.push_back(p3);
    vp.push_back(p4);

    Solution sol;
    int maxp = sol.maxPoints(vp);
    cout << "max points count " << maxp << endl;

    return 0;
}
