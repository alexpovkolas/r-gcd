#include <iostream>
#include <vector>

int gcd(int m, int n){
    if (n == 0) {
        return m;
    } else if (m == 0) {
        return n;
    } else if (n == 1 || m == 1) {
        return 1;
    } else if (n == m) {
        return n;
    }

    bool nEven = n % 2 == 0;
    bool mEven = m % 2 == 0;
    if (nEven && mEven) {
        return 2 * gcd(m/2, n/2);
    } else if (mEven && !nEven) {
        return gcd(m/2, n);
    } else if (!mEven && nEven) {
        return gcd(m, n/2);
    } else if (!mEven && !nEven && n > m) {
        return gcd((n-m) / 2, m);
    } else {
        return gcd((m-n) / 2, n);
    }
}

int gcd_v(std::vector<int> &args){
    int res = args[0];
    for (int i = 1; i < args.size(); ++i) {
        res = gcd(res, args[i]);
    }
    return res;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    std::vector<int> v = {1071, 462, 42, 84, 12};
    std::cout << gcd_v(v);
    return 0;
}