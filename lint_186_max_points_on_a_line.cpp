#include <iostream>
#include <vector>
#include <map>

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

class Solution {
public:
    /**
     * @param points an array of point
     * @return an integer
     */
    int maxPoints(vector<Point>& points) {
        int size = points.size();
        if (size==0 || size==1)
            return size;

        int max = 0;

        vector<vector<Fraction> > slope_table(
            size,
            vector<Fraction>(size, Fraction())
        );

        //DO THE JOB
        map<Fraction, int> line_sum;
        for (int i=0; i<size; i++) {
            line_sum.clear();

            for (int j=0; j<size; j++) {
                if (i == j)
                    continue;

                if (i > j)
                    slope_table[i][j] = slope_table[j][i];
                else {
                    // calc slope
                    Point p1 = points[i];
                    Point p2 = points[j];
                    Fraction slope(p2.x-p1.x, p2.y-p1.y);
                    slope_table[i][j] = slope;
                }
                /*
                if (slope_table[i][j].is_null())
                    continue;
                */

                map<Fraction, int>::iterator it = line_sum.find(slope_table[i][j]);
                if (it == line_sum.end())
                    line_sum[slope_table[i][j]] = 1;
                else
                    it->second += 1;

            }

            int line_max = 0;
            for (map<Fraction, int>::iterator it=line_sum.begin(); it!=line_sum.end(); ++it) {
                if (it->second>line_max) {
                    /*
                    if (it->first.is_null())
                        line_max = it->second;
                    else
                    */
                        line_max = it->second + 1;
                }
            }
            if (line_max > max)
                max = line_max;
        }

        for (int i=0; i<size; i++)
            for (int j=0; j<size; j++) {
                cout << slope_table[i][j] << " ";
                if (j == size-1)
                    cout << endl;
            }

        return max;
    }
};

int main(int argc, char* argv[]) {
    vector<Point> vp;

    vp.push_back(Point(-54,-297));
    vp.push_back(Point(-36,-222));
    vp.push_back(Point(3,-2));
    vp.push_back(Point(30,53));
    vp.push_back(Point(-5,1));
    vp.push_back(Point(-36,-222));
    vp.push_back(Point(0,2));
    vp.push_back(Point(1,3));
    vp.push_back(Point(6,-47));
    vp.push_back(Point(0,4));
    vp.push_back(Point(2,3));
    vp.push_back(Point(5,0));
    vp.push_back(Point(48,128));
    vp.push_back(Point(24,28));
    vp.push_back(Point(0,-5));
    vp.push_back(Point(48,128));
    vp.push_back(Point(-12,-122));
    vp.push_back(Point(-54,-297));
    vp.push_back(Point(-42,-247));
    vp.push_back(Point(-5,0));
    vp.push_back(Point(2,4));
    vp.push_back(Point(0,0));
    vp.push_back(Point(54,153));
    vp.push_back(Point(-30,-197));
    vp.push_back(Point(4,5));
    vp.push_back(Point(4,3));
    vp.push_back(Point(-42,-247));
    vp.push_back(Point(6,-47));
    vp.push_back(Point(-60,-322));
    vp.push_back(Point(-4,-2));
    vp.push_back(Point(-18,-147));
    vp.push_back(Point(6,-47));
    vp.push_back(Point(60,178));
    vp.push_back(Point(30,53));
    vp.push_back(Point(-5,3));
    vp.push_back(Point(-42,-247));
    vp.push_back(Point(2,-2));
    vp.push_back(Point(12,-22));
    vp.push_back(Point(24,28));
    vp.push_back(Point(0,-72));
    vp.push_back(Point(3,-4));
    vp.push_back(Point(-60,-322));
    vp.push_back(Point(48,128));
    vp.push_back(Point(0,-72));
    vp.push_back(Point(-5,3));
    vp.push_back(Point(5,5));
    vp.push_back(Point(-24,-172));
    vp.push_back(Point(-48,-272));
    vp.push_back(Point(36,78));
    vp.push_back(Point(-3,3));

    vp.clear();
    vp.push_back(Point(0,0));
    vp.push_back(Point(0,0));

    vp.clear();
    vp.push_back(Point(1,2));
    vp.push_back(Point(3,6));
    vp.push_back(Point(0,0));
    vp.push_back(Point(1,3));

    Solution sol;
    int maxp = sol.maxPoints(vp);
    cout << "max points count " << maxp << endl;

    return 0;
}
