// 부동소수점 수 Floating Point Numbers

#include<iostream>
#include <iomanip>
#include <limits>
#include <cmath>

int main()
{
	using namespace std;


	cout << sizeof(float) << numeric_limits<float>::max() << endl;
	cout << numeric_limits<float>::lowest() << endl;

	// double 을 가장 많이 사용하는 추세
	// double 과 long double 이 시스템에서 구현되어있는 범위는 같다
	cout << sizeof(double) << numeric_limits<double>::max() << endl;
	cout << numeric_limits<double>::lowest() << endl;

	cout << sizeof(long double) << numeric_limits<long double>::max() << endl;
	cout << numeric_limits<long double>::lowest() << endl;


	//3.14 = 31.4 * 0.1

	cout << 3.14 << endl;
	cout << 31.4e-1 << endl;
	cout << 31.4e-1 << endl;
	cout << 31.4e1 << endl;
	cout << 31.4e2 << endl;

	float f(123456789.0f); // 10 significant digits

	cout << std::setprecision(9);
	cout << f << endl;

	double d(0.1);

	cout << d << endl;
	cout << std::setprecision(15);
	cout << d << endl;

	double d1(1.0);
	double d2(0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1);
	
	cout << d1 << endl;
	cout << d2 << endl;

	cout << setprecision(17);

	cout << d1 << endl;
	cout << d2 << endl;


	double zero = 0.0;
	double posinf = 5.0 / zero;
	double neginf = -5.0 / zero;
	double nan = zero / zero;

	cout << posinf << endl;
	cout << neginf << endl;
	cout << nan << endl;

	//std::isnan inf지 아닌지 부으로 알려줌, <cmath> 필요

	cout << posinf << " " << std::isnan(posinf) << std::isinf(posinf) << endl;
	cout << neginf << " " << std::isnan(neginf) << std::isinf(neginf) << endl;
	cout << nan << " " << std::isnan(nan) << std::isinf(nan) << endl;
	cout << 1.0 << " " << std::isnan(1.0) << endl;

	return 0;
}
