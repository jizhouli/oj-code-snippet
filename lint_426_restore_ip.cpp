#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

bool parse_domain(string &ip_str, string &domain, int len) {
    if (len==0 || len>3 || ip_str.length() < len)
        return false;

    string s = ip_str;
    string d = s.substr(0, len);

    if (s.length() == len)
        s.clear();
    else {
        s = s.substr(len, s.length()-len);
    }

    int id = stoi(d);
    if (id < 0 || id > 255) {
        return false;
    }
    if (len > 1 and id < pow(10, (len-1)))
        return false;

    ip_str = s;
    domain = d;//to_string(id);
    return true;
}

void restore_ip(vector<string> &ips, string ip, int k, string ip_str) {
    if (0 == k) {
        if (ip_str.length() == 0)
            ips.push_back(ip);
        return;
    }

    for (int i=1; i<=3; i++) {
        string domain;
        string s = ip_str;
        if (parse_domain(s, domain, i)) {
            if (ip.length() == 0)
                restore_ip(ips, domain, k-1, s);
            else
                restore_ip(ips, ip+"."+domain, k-1, s);
        }
    }
}

int main(int argc, char* argv[]) {
    string s = "25525511135";
    s = "010010";
    vector<string> ips;
    string ip;
    restore_ip(ips, ip, 4, s);
    for (vector<string>::iterator it=ips.begin(); it != ips.end(); it++)
        cout << *it << endl;
    cout << "total ip count " << ips.size() << endl;

    /*
    // no change
    static const int arr[] = {16,2,77,29};
    vector<int> vec(arr, arr+sizeof(arr)/sizeof(arr[0]));
    vector<int> vec2(vec);
    vec2.push_back(100);
    for (vector<int>::iterator it=vec.begin();it != vec.end(); ++it) {
        cout << *it << endl;
    }
    */
    return 0;
}
