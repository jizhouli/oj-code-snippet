#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>

using namespace std;

void gen_parenthesis_err1(string pre, string post, int k,
                     set<string> &result) {
    if (k == 0) {
        result.insert(pre + post);
    }
    else {
        gen_parenthesis_err1("()"+pre, post, k-1, result);
        gen_parenthesis_err1("("+pre+")", post, k-1, result);
        gen_parenthesis_err1("("+pre, post+")", k-1, result);
        gen_parenthesis_err1(pre, "("+post+")", k-1, result);
        gen_parenthesis_err1(pre, post+"()", k-1, result);
        gen_parenthesis_err1(pre+"()", post, k-1, result);
        gen_parenthesis_err1(pre, "()"+post, k-1, result);
        gen_parenthesis_err1(pre+"(", ")"+post, k-1, result);
    }
}

void gen_parenthesis_err2(string pre, string post, int k,
                     set<string> &result) {
    if (k == 0) {
        result.insert(pre + post);
    }
    else {
        gen_parenthesis_err2("()"+pre, post, k-1, result);
        gen_parenthesis_err2("("+pre+")", post, k-1, result);
        gen_parenthesis_err2(pre+"()", post, k-1, result);
    }
}

void gen_parenthesis(string s, int l, int r, vector<string> &result) {
    cout << s << " " << l << " " << r << endl;
    if (r <= 0) {
        result.push_back(s);
        return;
    }
    if (l == r)
        gen_parenthesis(s+"(", l-1, r, result);
    else if (l == 0) {
        gen_parenthesis(s+")", l, r-1, result);
    }
    else {
        gen_parenthesis(s+"(", l-1, r, result);
        gen_parenthesis(s+")", l, r-1, result);
    }
}

int main(int argc, char* argv[]) {
    int count = 6;
    vector<string> ret;

    string s;
    gen_parenthesis(s, count, count, ret);
    
    for (vector<string>::iterator it = ret.begin();
         it != ret.end(); ++it) {
        cout << *it << endl;
    }
    cout << count << " -> " << ret.size() << endl;
    return 0;
}
