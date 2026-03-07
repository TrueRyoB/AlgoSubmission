#ifndef LIB_GEO
#define LIB_GEO

#ifdef LOCAL
#include "std.hpp"
#endif

//more at this link: 
//https://github.com/E869120/kyopro_educational_90/blob/main/sol/041-03.cpp

struct Point {
	long long px, py;
};

Point operator+(const Point& a1, const Point& a2) {
	return Point{ a1.px + a2.px, a1.py + a2.py };
}

Point operator-(const Point& a1, const Point& a2) {
	return Point{ a1.px - a2.px, a1.py - a2.py };
}

bool operator<(const Point& a1, const Point& a2) {
	if (a1.px < a2.px) return true;
	if (a1.px > a2.px) return false;
	if (a1.py < a2.py) return true;
	return false;
}

inline long long cross_product(const Point& p1, const Point& p2) {
	return p1.px * p2.py - p1.py * p2.px;
}

inline long long manhattan(const Point& p1, const Point& p2) {
	return abs(p1.px-p2.px)+abs(p1.py-p2.py);
}

inline long long euclidean(const Point& p1, const Point& p2) {
	ll diffx=p1.px-p2.px, diffy=p1.py-p2.py;
	return diffx*diffx+diffy*diffy;
}


#endif