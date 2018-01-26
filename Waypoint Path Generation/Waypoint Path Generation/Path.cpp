//#include "Path.h"
//
//void Path::GenerateSpline() {
//const int n = mainPath.size - 1, // number of segments
//result = new Float64Array(points.length * 3 - 2);
//
//if (n == = 0) {
//	result[0] = points[0];
//	return result;
//}
//else if (n == = 1) {
//	result[0] = result[1] = points[0];
//	result[2] = result[3] = points[1];
//	return result;
//}
//
//int a[n] = {}, 
//int b[n] = {}, 
//int c[n] = {}, 
//int d[n] = {}, 
//int p2[n] = {},
//i, k, p1;
//
//for (i = 0; i < n; i++) {
//	a[i] = 1;
//	b[i] = 4;
//	c[i] = 1;
//	// The NaN values will never be used, we just mark them here explicitly.
//	if (i == 0) {
//		a[i] = nullptr;
//		b[i] = 2;
//		d[i] = points[i] + 2 * points[i + 1];
//	}
//	else if (i == n - 1) {
//		a[i] = 2;
//		b[i] = 7;
//		c[i] = nullptr;
//		d[i] = 8 * points[i] + points[i + 1];
//	}
//	else {
//		d[i] = 4 * points[i] + 2 * points[i + 1];
//	}
//}
//
//p1 = DoStuff(a, b, c, d);
//
//for (i = 0; i < n - 1; i++) {
//	p2[i] = 2 * points[i + 1] - p1[i + 1];
//}
//p2[n - 1] = (points[n] + p1[n - 1]) / 2;
//
//result[0] = points[0];
//for (i = 0; i < n; i++) {
//	k = i * 3;
//	result[k + 1] = p1[i];
//	result[k + 2] = p2[i];
//	result[k + 3] = points[i + 1];
//}
//
//return result;
//}
//
//int Path::DoStuff(int a[5], int b[5], int c[5], int d[5]) {
//	var n = a.length,
//		cp = new Float64Array(n), // c prime
//		dp = new Float64Array(n), // d prime
//		x = new Float64Array(n),  // solution
//		i;
//
//
//	for (i = 0; i < n - 1; i++) {
//		if (i == = 0) {
//			cp[i] = c[i] / b[i];
//			dp[i] = d[i] / b[i];
//		}
//		else {
//			cp[i] = c[i] / (b[i] - a[i] * cp[i - 1]);
//			dp[i] = (d[i] - a[i] * dp[i - 1]) / (b[i] - a[i] * cp[i - 1]);
//		}
//	}
//	x[i] = dp[i] = (d[i] - a[i] * dp[i - 1]) / (b[i] - a[i] * cp[i - 1]); // i === n - 1
//
//	for (i = n - 2; i >= 0; i--) {
//		x[i] = dp[i] - cp[i] * x[i + 1];
//	}
//
//	return x;
//}