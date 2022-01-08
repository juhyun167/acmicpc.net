#include <iostream>
#include <sstream>
#include <cctype>
#include <cstdint>
#include <locale>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <climits>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <stack>
#include <queue>
#include <list>
#include <iomanip>
using namespace std;

#define MAX		(10000 + 1)

int m, n, t, k, v;

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

#define FLOOR_SQRT_LLONG_MAX    3037000499

/* bigint class */
class bigint {
    string value;
    char sign;

public:
    // constructors
    bigint();
    bigint(const bigint&);
    bigint(const long long&);
    bigint(const string&);

    // assignment
    bigint& operator=(const bigint&);
    bigint& operator=(const long long&);
    bigint& operator=(const string&);

    // unary arithmetic
    bigint operator+() const;
    bigint operator-() const;

    // binary arithmetic
    bigint operator+(const bigint&) const;
    bigint operator-(const bigint&) const;
    bigint operator*(const bigint&) const;
    bigint operator/(const bigint&) const;
    bigint operator%(const bigint&) const;
    bigint operator+(const long long&) const;
    bigint operator-(const long long&) const;
    bigint operator*(const long long&) const;
    bigint operator/(const long long&) const;
    bigint operator%(const long long&) const;
    bigint operator+(const string&) const;
    bigint operator-(const string&) const;
    bigint operator*(const string&) const;
    bigint operator/(const string&) const;
    bigint operator%(const string&) const;

    // arithmetic assignment
    bigint& operator+=(const bigint&);
    bigint& operator-=(const bigint&);
    bigint& operator*=(const bigint&);
    bigint& operator/=(const bigint&);
    bigint& operator%=(const bigint&);
    bigint& operator+=(const long long&);
    bigint& operator-=(const long long&);
    bigint& operator*=(const long long&);
    bigint& operator/=(const long long&);
    bigint& operator%=(const long long&);
    bigint& operator+=(const string&);
    bigint& operator-=(const string&);
    bigint& operator*=(const string&);
    bigint& operator/=(const string&);
    bigint& operator%=(const string&);

    // increment and decrement
    bigint& operator++();
    bigint& operator--();
    bigint operator++(int);
    bigint operator--(int);

    // relational
    bool operator==(const bigint&) const;
    bool operator!=(const bigint&) const;
    bool operator<(const bigint&) const;
    bool operator>(const bigint&) const;
    bool operator<=(const bigint&) const;
    bool operator>=(const bigint&) const;
    bool operator==(const long long&) const;
    bool operator!=(const long long&) const;
    bool operator<(const long long&) const;
    bool operator>(const long long&) const;
    bool operator<=(const long long&) const;
    bool operator>=(const long long&) const;
    bool operator==(const string&) const;
    bool operator!=(const string&) const;
    bool operator<(const string&) const;
    bool operator>(const string&) const;
    bool operator<=(const string&) const;
    bool operator>=(const string&) const;

    // stream
    friend istream& operator>>(istream&, bigint&);
    friend ostream& operator<<(ostream&, const bigint&);

    // conversion
    string to_string() const;
    int to_int() const;
    long to_long() const;
    long long to_long_long() const;
};

/* utility functions */
bool is_valid_number(const string& num) {
    for (const char digit : num) {
        if (digit < '0' or digit > '9') {
            return false;
        }
    }
    return true;
}

void strip_leading_zeroes(string& num) {
    size_t i;

    for (i = 0; i < num.size(); i++) {
        if (num[i] != '0') {
            break;
        }
    }
    num = (i == num.size()) ? "0" : num.substr(i);
}

void add_leading_zeroes(string& num, size_t num_zeroes) {
    num = string(num_zeroes, '0') + num;
}

void add_trailing_zeroes(string& num, size_t num_zeroes) {
    num += string(num_zeroes, '0');
}

tuple<string, string> get_larger_and_smaller(string num1, string num2) {
    string larger, smaller;

    if (num1.size() > num2.size() or
            (num1.size() == num2.size() and num1 > num2)) {
        larger = num1;
        smaller = num2;
    } else {
        larger = num2;
        smaller = num1;
    }
    add_leading_zeroes(smaller, larger.size() - smaller.size());

    return make_tuple(larger, smaller);
}

bool is_power_of_10(const string& num) {
    if (num[0] != '1') {
        return false;
    }
    for (size_t i = 1; i < num.size(); i++) {
        if (num[i] != '0') {
            return false;
        }
    }
    return true;
}

/* math functions */
bigint abs(const bigint& num) {
    return (num < 0) ? -num : num;
}

bigint pow(const bigint& base, int exp) {
    bigint result = base, result_odd = 1;

    if (exp < 0) {
        if (base == 0) {
            throw logic_error("Attempted division by zero");
        }
        return (abs(base) == 1) ? base : 0;
    } else if (exp == 0) {
        if (base == 0) {
            throw logic_error("Zero cannot be raised to zero");
        }
        return 1;
    }

    while (exp > 1) {
        if (exp % 2) {
            result_odd *= result;
        }
        result *= result;
        exp /= 2;
    }

    return result * result_odd;
}

bigint pow(const long long& base, int exp) {
    return pow(bigint(base), exp);
}

bigint pow(const string& base, int exp) {
    return pow(bigint(base), exp);
}

bigint gcd(const bigint& num1, const bigint& num2) {
    bigint abs_num1 = abs(num1);
    bigint abs_num2 = abs(num2);
    bigint remainder = abs_num2;

    if (abs_num2 == 0) {
        return abs_num1;
    } else if (abs_num1 == 0) {
        return abs_num2;
    }

    if (abs_num1 < abs_num2) {
        swap(abs_num1, abs_num2);
    }
    while (remainder != 0) {
        remainder = abs_num1 % abs_num2;
        abs_num1 = abs_num2;
        abs_num2 = remainder;
    }

    return abs_num1;
}

bigint gcd(const bigint& num1, const long long& num2) {
    return gcd(num1, bigint(num2));
}

bigint gcd(const bigint& num1, const string& num2) {
    return gcd(num1, bigint(num2));
}

bigint gcd(const long long& num1, const bigint& num2) {
    return gcd(bigint(num1), num2);
}

bigint gcd(const string& num1, const bigint& num2) {
    return gcd(bigint(num1), num2);
}

/* constructors */
bigint::bigint() : value("0"), sign('+') {}

bigint::bigint(const bigint& num) : value(num.value), sign(num.sign) {}

bigint::bigint(const long long& num) {
    value = std::to_string(abs(num));
    sign = (num < 0) ? '-' : '+';
}

bigint::bigint(const string& num) {
    if (num[0] == '+' or num[0] == '-') {
        string magnitude = num.substr(1);
        if (is_valid_number(magnitude)) {
            value = num.substr(1);
            sign = num[0];
        } else {
            throw invalid_argument("Expected an integer, got \'" + num + "\'");
        }
    } else {
        if (is_valid_number(num)) {
            value = num;
            sign = '+';
        } else {
            throw invalid_argument("Expected an integer, got \'" + num + "\'");
        }
    }
    strip_leading_zeroes(value);
}

/* assignment */
bigint& bigint::operator=(const bigint& num) {
    value = num.value;
    sign = num.sign;

    return *this;
}

bigint& bigint::operator=(const long long& num) {
    bigint temp(num);

    value = temp.value;
    sign = temp.sign;

    return *this;
}

bigint& bigint::operator=(const string& num) {
    bigint temp(num);

    value = temp.value;
    sign = temp.sign;

    return *this;
}

/* unary arithmetic */
bigint bigint::operator+() const {
    return *this;
}

bigint bigint::operator-() const {
    bigint temp(value);

    if (value != "0") {
        temp.sign = (sign == '+') ? '-' : '+';
    }

    return temp;
}

/* binary arithmetic */
bigint bigint::operator+(const bigint& num) const {
    bigint result;
    string larger, smaller;
    char sum, carry = 0;

    if (sign == '+' and num.sign == '-') {
        bigint rhs = num;
        rhs.sign = '+';
        return *this - rhs;
    } else if (sign == '-' and num.sign == '+') {
        bigint lhs = *this;
        lhs.sign = '+';
        return -(lhs - num);
    }

    result.value = "";
    tie(larger, smaller) = get_larger_and_smaller(value, num.value);
    for (long long i = larger.size() - 1; i >= 0; i--) {
        sum = larger[i] - '0' + smaller[i] - '0' + carry;
        result.value = std::to_string(sum % 10) + result.value;
        carry = sum / (char) 10;
    }
    result.value = (carry) ?
        std::to_string(carry) + result.value : result.value;
    result.sign = (sign == '-' and result.value != "0") ?
        '-' : result.sign;

    return result;
}

bigint bigint::operator-(const bigint& num) const {
    bigint result;
    string larger, smaller;
    short difference;
    long long i, j;

    if (sign == '+' and num.sign == '-') {
        bigint rhs = num;
        rhs.sign = '+';
        return *this + rhs;
    } else if (sign == '-' and num.sign == '+') {
        bigint lhs = *this;
        lhs.sign = '+';
        return -(lhs + num);
    }

    if (abs(*this) > abs(num)) {
        larger = value;
        smaller = num.value;
        result.sign = (sign == '-') ? '-' : result.sign;
    } else {
        larger = num.value;
        smaller = value;
        result.sign = (num.sign == '+') ? '-' : result.sign;
    }
    add_leading_zeroes(smaller, larger.size() - smaller.size());

    result.value = "";
    for (i = larger.size() - 1; i >= 0; i--) {
        difference = larger[i] - smaller[i];
        if (difference < 0) {
            for (j = i - 1; j >= 0; j--) {
                if (larger[j] != '0') {
                    larger[j]--;
                    break;
                }
            }
            j++;
            while (j != i) {
                larger[j++] = '9';
            }
            difference += 10;
        }
        result.value = std::to_string(difference) + result.value;
    }
    strip_leading_zeroes(result.value);
    result.sign = (result.value == "0") ? '+' : result.sign;

    return result;
}

bigint bigint::operator*(const bigint& num) const {
    bigint product;

    if (*this == 0 or num == 0) {
        return bigint(0);
    } else if (*this == 1) {
        return num;
    } else if (num == 1) {
        return *this;
    }

    if (abs(*this) <= FLOOR_SQRT_LLONG_MAX and
            abs(num) <= FLOOR_SQRT_LLONG_MAX) {
        product = stoll(value) * stoll(num.value);
    } else if (is_power_of_10(value)) {
        product.value = num.value;
        product.value.append(value.begin() + 1, value.end());
    } else if (is_power_of_10(num.value)) {
        product.value = value;
        product.value.append(num.value.begin() + 1, num.value.end());
    } else {
        string larger, smaller;
        size_t half_length;
        bigint num1_high, num1_low, num2_high, num2_low;
        bigint prod_high, prod_mid, prod_low;

        tie(larger, smaller) = get_larger_and_smaller(value, num.value);
        half_length = larger.size() / 2;
        auto half_length_ceil = (size_t) ceil(larger.size() / 2.0);

        num1_high = larger.substr(0, half_length);
        num1_low = larger.substr(half_length);
        num2_high = smaller.substr(0, half_length);
        num2_low = smaller.substr(half_length);

        strip_leading_zeroes(num1_high.value);
        strip_leading_zeroes(num1_low.value);
        strip_leading_zeroes(num2_high.value);
        strip_leading_zeroes(num2_low.value);

        prod_high = num1_high * num2_high;
        prod_low = num1_low * num2_low;
        prod_mid = (num1_high + num1_low) * (num2_high + num2_low)
                    - prod_high - prod_low;

        add_trailing_zeroes(prod_high.value, 2 * half_length_ceil);
        add_trailing_zeroes(prod_mid.value, half_length_ceil);

        strip_leading_zeroes(prod_high.value);
        strip_leading_zeroes(prod_mid.value);
        strip_leading_zeroes(prod_low.value);

        product = prod_high + prod_mid + prod_low;
    }
    strip_leading_zeroes(product.value);
    product.sign = (sign == num.sign) ? '+' : '-';

    return product;
}

/* divide helper function */
tuple<bigint, bigint> divide(const bigint& dividend, const bigint& divisor) {
    bigint quotient = 1, remainder, temp = divisor;

    while (temp < dividend) {
        quotient++;
        temp += divisor;
    }
    if (temp > dividend) {
        quotient--;
        remainder = dividend - (temp - divisor);
    }

    return make_tuple(quotient, remainder);
}

bigint bigint::operator/(const bigint& num) const {
    bigint abs_dividend = abs(*this);
    bigint abs_divisor = abs(num);
    bigint quotient;

    if (num == 0) {
        throw logic_error("Attempted division by zero");
    } else if (abs_dividend < abs_divisor) {
        return bigint(0);
    } else if (num == 1) {
        return *this;
    } else if (num == -1) {
        return -(*this);
    }

    if (abs_dividend <= LLONG_MAX and abs_divisor <= LLONG_MAX) {
        quotient = stoll(abs_dividend.value) / stoll(abs_divisor.value);
    } else if (abs_dividend == abs_divisor) {
        quotient = 1;
    } else if (is_power_of_10(abs_divisor.value)) {
        size_t digits_in_quotient = abs_dividend.value.size()
                                    - abs_divisor.value.size() + 1;
        quotient.value = abs_dividend.value.substr(0, digits_in_quotient);
    } else {
        bigint chunk, chunk_quotient, chunk_remainder;
        size_t chunk_index = 0;

        quotient.value = "";
        chunk_remainder.value = abs_dividend.value.substr(chunk_index,
                                                abs_divisor.value.size() - 1);
        chunk_index = abs_divisor.value.size() - 1;
        while (chunk_index < abs_dividend.value.size()) {
            chunk.value = chunk_remainder.value.append(1,
                                                abs_dividend.value[chunk_index++]);
            while (chunk < abs_divisor) {
                quotient.value += "0";
                if (chunk_index < abs_dividend.value.size()) {
                    chunk.value.append(1, abs_dividend.value[chunk_index]);
                    chunk_index++;
                } else {
                    break;
                }
            }
            if (chunk == abs_divisor) {
                quotient.value += "1";
                chunk_remainder = 0;
            } else if (chunk > abs_divisor) {
                strip_leading_zeroes(chunk.value);
                tie(chunk_quotient, chunk_remainder) = divide(chunk, abs_divisor);
                quotient.value += chunk_quotient.value;
            }
        }
    }
    strip_leading_zeroes(quotient.value);
    quotient.sign = (sign == num.sign) ? '+' : '-';

    return quotient;
}

bigint bigint::operator%(const bigint& num) const {
    bigint abs_dividend = abs(*this);
    bigint abs_divisor = abs(num);
    bigint remainder;

    if (abs_divisor == 0) {
        throw logic_error("Attempted division by zero");
    } else if (abs_divisor == 1 or abs_divisor == abs_dividend) {
        return bigint(0);
    }

    if (abs_dividend <= LLONG_MAX and abs_divisor <= LLONG_MAX) {
        remainder = stoll(abs_dividend.value) % stoll(abs_divisor.value);
    } else if (abs_dividend < abs_divisor) {
        remainder = abs_divisor;
    } else if (is_power_of_10(num.value)) {
        size_t num_zeroes = num.value.size() - 1;
        remainder.value = abs_dividend.value.substr(abs_dividend.value.size()
                                                    - num_zeroes);
    } else {
        bigint quotient = abs_dividend / abs_divisor;
        remainder = abs_dividend - quotient * abs_divisor;
    }
    strip_leading_zeroes(remainder.value);
    remainder.sign = (remainder.value == "0") ? '+' : sign;

    return remainder;
}

bigint bigint::operator+(const long long& num) const {
    return *this + bigint(num);
}

bigint operator+(const long long& lhs, const bigint& rhs) {
    return bigint(lhs) + rhs;
}

bigint bigint::operator-(const long long& num) const {
    return *this - bigint(num);
}

bigint operator-(const long long& lhs, const bigint& rhs) {
    return bigint(lhs) - rhs;
}

bigint bigint::operator*(const long long& num) const {
    return *this * bigint(num);
}

bigint operator*(const long long& lhs, const bigint& rhs) {
    return bigint(lhs) * rhs;
}

bigint bigint::operator/(const long long& num) const {
    return *this / bigint(num);
}

bigint operator/(const long long& lhs, const bigint& rhs) {
    return bigint(lhs) / rhs;
}

bigint bigint::operator%(const long long& num) const {
    return *this % bigint(num);
}

bigint operator%(const long long& lhs, const bigint& rhs) {
    return bigint(lhs) % rhs;
}

bigint bigint::operator+(const string& num) const {
    return *this + bigint(num);
}

bigint operator+(const string& lhs, const bigint& rhs) {
    return bigint(lhs) + rhs;
}

bigint bigint::operator-(const string& num) const {
    return *this - bigint(num);
}

bigint operator-(const string& lhs, const bigint& rhs) {
    return bigint(lhs) - rhs;
}

bigint bigint::operator*(const string& num) const {
    return *this * bigint(num);
}

bigint operator*(const string& lhs, const bigint& rhs) {
    return bigint(lhs) * rhs;
}

bigint bigint::operator/(const string& num) const {
    return *this / bigint(num);
}

bigint operator/(const string& lhs, const bigint& rhs) {
    return bigint(lhs) / rhs;
}

bigint bigint::operator%(const string& num) const {
    return *this % bigint(num);
}

bigint operator%(const string& lhs, const bigint& rhs) {
    return bigint(lhs) % rhs;
}

/* arithmetic assignment */
bigint& bigint::operator+=(const bigint& num) {
    *this = *this + num;

    return *this;
}

bigint& bigint::operator-=(const bigint& num) {
    *this = *this - num;

    return *this;
}

bigint& bigint::operator*=(const bigint& num) {
    *this = *this * num;

    return *this;
}

bigint& bigint::operator/=(const bigint& num) {
    *this = *this / num;

    return *this;
}

bigint& bigint::operator%=(const bigint& num) {
    *this = *this % num;

    return *this;
}

bigint& bigint::operator+=(const long long& num) {
    *this = *this + bigint(num);

    return *this;
}

bigint& bigint::operator-=(const long long& num) {
    *this = *this - bigint(num);

    return *this;
}

bigint& bigint::operator*=(const long long& num) {
    *this = *this * bigint(num);

    return *this;
}

bigint& bigint::operator/=(const long long& num) {
    *this = *this / bigint(num);

    return *this;
}

bigint& bigint::operator%=(const long long& num) {
    *this = *this % bigint(num);

    return *this;
}

bigint& bigint::operator+=(const string& num) {
    *this = *this + bigint(num);

    return *this;
}

bigint& bigint::operator-=(const string& num) {
    *this = *this - bigint(num);

    return *this;
}

bigint& bigint::operator*=(const string& num) {
    *this = *this * bigint(num);

    return *this;
}

bigint& bigint::operator/=(const string& num) {
    *this = *this / bigint(num);

    return *this;
}

bigint& bigint::operator%=(const string& num) {
    *this = *this % bigint(num);

    return *this;
}

/* increment and decrement */
bigint& bigint::operator++() {
    *this += 1;

    return *this;
}

bigint& bigint::operator--() {
    *this -= 1;

    return *this;
}

bigint bigint::operator++(int) {
    bigint temp = *this;
    *this += 1;

    return temp;
}

bigint bigint::operator--(int) {
    bigint temp = *this;
    *this -= 1;

    return temp;
}

/* relational */
bool bigint::operator==(const bigint& num) const {
    return sign == num.sign and value == num.value;
}

bool bigint::operator!=(const bigint& num) const {
    return !(*this == num);
}

bool bigint::operator<(const bigint& num) const {
    if (sign == num.sign) {
        if (sign == '+') {
            return (value.length() == num.value.length()) ?
                value < num.value :
                value.length() < num.value.length();
        } else {
            return -(*this) > -num;
        }
    } else {
        return sign == '-';
    }
}

bool bigint::operator>(const bigint& num) const {
    return !((*this < num) or (*this == num));
}

bool bigint::operator<=(const bigint& num) const {
    return *this < num or *this == num;
}

bool bigint::operator>=(const bigint& num) const {
    return !(*this < num);
}

bool bigint::operator==(const long long& num) const {
    return *this == bigint(num);
}

bool operator==(const long long& lhs, const bigint& rhs) {
    return bigint(lhs) == rhs;
}

bool bigint::operator!=(const long long& num) const {
    return !(*this == bigint(num));
}

bool operator!=(const long long& lhs, const bigint& rhs) {
    return bigint(lhs) != rhs;
}

bool bigint::operator<(const long long& num) const {
    return *this < bigint(num);
}

bool operator<(const long long& lhs, const bigint& rhs) {
    return bigint(lhs) < rhs;
}

bool bigint::operator>(const long long& num) const {
    return *this > bigint(num);
}

bool operator>(const long long& lhs, const bigint& rhs) {
    return bigint(lhs) > rhs;
}

bool bigint::operator<=(const long long& num) const {
    return !(*this > bigint(num));
}

bool operator<=(const long long& lhs, const bigint& rhs) {
    return bigint(lhs) <= rhs;
}

bool bigint::operator>=(const long long& num) const {
    return !(*this < bigint(num));
}

bool operator>=(const long long& lhs, const bigint& rhs) {
    return bigint(lhs) < rhs;
}

bool bigint::operator==(const string& num) const {
    return *this == bigint(num);
}

bool operator==(const string& lhs, const bigint& rhs) {
    return bigint(lhs) == rhs;
}

bool bigint::operator!=(const string& num) const {
    return !(*this == bigint(num));
}

bool operator!=(const string& lhs, const bigint& rhs) {
    return bigint(lhs) != rhs;
}

bool bigint::operator<(const string& num) const {
    return *this < bigint(num);
}

bool operator<(const string& lhs, const bigint& rhs) {
    return bigint(lhs) < rhs;
}

bool bigint::operator>(const string& num) const {
    return *this > bigint(num);
}

bool operator>(const string& lhs, const bigint& rhs) {
    return bigint(lhs) > rhs;
}

bool bigint::operator<=(const string& num) const {
    return !(*this > bigint(num));
}

bool operator<=(const string& lhs, const bigint& rhs) {
    return bigint(lhs) <= rhs;
}

bool bigint::operator>=(const string& num) const {
    return !(*this < bigint(num));
}

bool operator>=(const string& lhs, const bigint& rhs) {
    return bigint(lhs) < rhs;
}

/* stream */
istream& operator>>(istream& in, bigint& num) {
    string input;

    in >> input;
    num = bigint(input);

    return in;
}

ostream& operator<<(ostream& out, const bigint& num) {
    if (num.sign == '-') {
        out << num.sign;
    }
    out << num.value;

    return out;
}

/* conversion */
string bigint::to_string() const {
    return (sign == '-') ? "-" + value : value;
}

int bigint::to_int() const {
    return stoi(to_string());
}

long bigint::to_long() const {
    return stol(to_string());
}

long long bigint::to_long_long() const {
    return stoll(to_string());
}

void mtimes(vector<vector<bigint>>& a, vector<vector<bigint>>& b,
				vector<vector<bigint>>& result) {
	vector<vector<bigint>> _a = a, _b = b;

	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result.size(); j++) {
			result[i][j] = 0;
		}
	}

	for (int i = 0; i < _a.size(); i++) {
		for (int j = 0; j < _b[0].size(); j++) {
			for (int t = 0; t < _b.size(); t++) {
				result[i][j] += _b[t][j] * _a[i][t];
			}
		}
	}
}

void mpower(vector<vector<bigint>>& base, int exp,
		vector<vector<bigint>>& result) {
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result.size(); j++) {
            result[i][j] = (i == j) ? 1 : 0;
        }
    }

    while (exp > 0) {
        if (exp & 1) {
            mtimes(result, base, result);
        }
        mtimes(base, base, base);
        exp >>= 1;
    }
}

int main() {
	vector<vector<bigint>> fibonacci { { 1, 1 }, { 1, 0 } };
	vector<vector<bigint>> result(2, vector<bigint>(2, 0));

	setup();
	cin >> n;
	mpower(fibonacci, n, result);
	cout << result[0][1] << "\n";

	return 0;
}
