long long MOD = 1e9 + 7;

long long modInverse(long long a) {
    long long res = 1, p = MOD - 2;
    while (p) {
        if (p & 1) res = res * a % MOD;
        a = a * a % MOD;
        p >>= 1;
    }
    return res;
}

class Fancy {
public:
    vector<long long> seq;
    long long mul = 1;
    long long add = 0;

    Fancy(){}

    void append(int val) {
        long long x = (val - add + MOD) % MOD;
        x = x * modInverse(mul) % MOD;
        seq.push_back(x);
    }

    void addAll(int inc) {
        add = (add + inc) % MOD;
    }

    void multAll(int m) {
        mul = mul * m % MOD;
        add = add * m % MOD;
    }

    int getIndex(int idx) {
        if (idx >= seq.size()) return -1;
        return (seq[idx] * mul + add) % MOD;
    }
};
