#include <iostream>
//#include <math.h>
#include <cmath>
using namespace std;

double f(double a, double b, double c, double x) {
	double ff = x*x*x + a*x*x + b*x + c;
	return ff;
}
double dichotomy(double a, double b, double c, double alpha, double beta) {
	double middle, left, right;
	(alpha < beta) ? (left = alpha, right = beta) : (left = beta, right = alpha);
	if (f(a, b, c, left) == 0)
		return left;
	if (f(a, b, c, right) == 0)
		return right;
	float left_sign = (f(a, b, c, left) > 0) ? 1 : -1;
	float right_sign = (f(a, b, c, right) > 0) ? 1 : -1;
	float mid_sign;
	double epsilon = 0.00001, n;
	n = log2((right - left) / epsilon);
	while (n > 0){
		middle = (left + right) / 2;
		mid_sign = (f(a, b, c, middle) > 0) ? 1 : -1;
		if (mid_sign == right_sign)
			right = middle;
		else
			left = middle;
		--n;
	}
	return middle;
}
double search(double a, double b, double c, double start, int direction) { //-1 - left, 1 - right
	float step = 1;
	double curr, pos = start;
	int funct_sign = (f(a, b, c, pos) > 0) ? 1 : -1;
	int curr_sign;
	while (true){
		curr = f(a, b, c, pos);
		curr_sign = (curr > 0) ? 1 : -1;
		if (!(funct_sign == curr_sign) || (curr == 0))
			break;
		pos += step*direction;
	}
	return pos;
}

int main(int argc, char* argv) {
	double a, b, c, D, root, epsilon = 0.00001;
	while (1) {
		cout << "Enter coefficients a, b and c" << endl;
		if (!(cin >> a) || !(cin >> b) || !(cin >> c)) {
			cout << "Wrong coefficients, try again" << endl;
			return 0;
		}
		else
			break;
	} 
	D = 4 * a*a - 12 * b;
	if (D <= 0) {
		if (c > 0) {
			root = dichotomy(a, b, c, search(a, b, c, 0, -1), 0);
			cout << "Root is " << root << endl;
		}
		else if (c < 0) {
			root = dichotomy(a, b, c, 0, search(a, b, c, 0, 1));
			cout << "Root is " << root << endl;
		}
		else {
			root = 0;
			cout << "Root is " << root << endl;
		}
	}
	else if (D > 0) {
		double x1 = ((-1 * 2 * a) + sqrt(D)) / 6;
		double x2 = ((-1 * 2 * a) - sqrt(D)) / 6;
		double alpha, beta;
		(x1 < x2) ? (alpha = x1, beta = x2) : (alpha = x2, beta = x1);
		double f1 = f(a, b, c, alpha);
		double f2 = f(a, b, c, beta);

		if ((f1 > 0) && (f2 > 0)) {
			root = dichotomy(a, b, c, search(a, b, c, alpha, -1), alpha);
			cout << "Root is " << root << endl;
		}
		else if ((f1 < 0) && (f2 < 0)) {
			root = dichotomy(a, b, c, search(a, b, c, beta, 1), beta);
			cout << "Root is " << root << endl;
		}
		else if (abs(f2) < epsilon) {
			root = dichotomy(a, b, c, search(a, b, c, alpha, -1), alpha);
			cout << beta << "is a multiple root 2nd degree, another root is" << root << endl;
		}
		else if (abs(f1) < epsilon) {
			root = dichotomy(a, b, c, search(a, b, c, beta, 1), beta);
			cout << alpha << "is a multiple root 2nd degree, another root is" << root << endl;
		}
		else if ((f1 > epsilon) && (f2 < -epsilon)) {
			root = dichotomy(a, b, c, alpha, beta);
			cout << "Root1 is " << root << endl;
			root = dichotomy(a, b, c, search(a, b, c, alpha, -1), alpha);
			cout << "Root2 is " << root << endl;
			root = dichotomy(a, b, c, search(a, b, c, beta, 1), beta);
			cout << "Root3 is " << root << endl;
		}
	}
	return 0;
}