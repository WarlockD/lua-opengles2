#ifndef __LUAVECTORS_H_
#define __LUAVECTORS_H_

#include <cmath>
#include <unordered_map>

template<typename T> inline struct Point2D
{
	const Point2D<T> Zero = Point2D<T>();
	T x, y; 
	Point2D() : x(0),y(0) {}
	Point2D(const T x, const T y) : x(x),y(y) {}
	inline void* ptr() { return &x; }
	const T &operator[](unsigned int i) const { return *(&x+i); }

	bool operator==(const Point2D<T>&p) { return (x==v.x) && (y==v.y); }
	bool operator!=(const Point2D<T>&p) { return (x!=v.x) || (y!=v.y); }

	const Point2D<T>& operator= (const Point2D<T>& r) { x = r.x; y = r.y; return *this; }
	const Point2D<T> operator-(void) const { return Point2D<T>(-x,-y); }
	const Point2D<T> operator+(const Point2D<T> &r) { return Point2D<T>(x+r.x,y+r.y); }
	const Point2D<T> operator-(const Point2D<T> &r) { return Point2D<T>(x-r.x,y-r.y); }
	const Point2D<T> operator*(const T r) { Point2D<T> temp(*this); return temp*=r; }
	const Point2D<T> operator/(const T r) { Point2D<T> temp(*this); return temp/=r; }
	const Point2D<T> &operator=+(const Point2D<T> &r) { x+=r.x; y+=r.y; return *this }
	const Point2D<T> &operator=-(const Point2D<T> &r) { x-=r.x; y-=r.y; return *this }
	const Point2D<T> &operator=*(const T r) { x*=r; y*=r; return *this }
	const Point2D<T> &operator=/(const T r) { x/=r; y/=r; return *this }
	T operator*(const Point2D<T> &r) const { return x*r.x + y*r.y; }

	T lenSqr() const {	return (float)(*this * *this);   }
	T len() const   {  return (float)std::sqrt(*this * *this);   }
	void normalize() { *this/=length();	}
	Point2D<T> normalized() const { return  *this/length(); }

	//! reflects this vector about n
	void reflect(const vector2f &n) { vector2f orig(*this); project(n); *this= *this*2 - orig;}

	//! projects this vector onto v
	void project(const vector2f &v) {	*this= v * (*this * v)/(v*v);	}

	//! returns this vector projected onto v
	Point2D<T> projected(const vector2f &v) {   return v * (*this * v)/(v*v);	}

	//! computes the angle between 2 arbitrary vectors
	static inline float angle(const vector2f &v1, const vector2f &v2) {   return acosf((v1*v2) / (v1.length()*v2.length()));  }

	//! computes the angle between 2 normalized arbitrary vectors
	static inline float angle_normalized(const vector2f &v1, const vector2f &v2) {   return acosf(v1*v2);  }
};


template<typename T> class  Rect
{
private:
	Point2D<T> origin;
	Point2D<T>  size;

public:
	const Rect Zero = Rect();
	Rect() : origin(0,0), size(0,0) {}
	Rect(float x, float y, float width, float height): origin(x,y), size(width,height) {}
	T& x() { return &origin.x; }
	T& x() { return &origin.y; }
	T& width() { return &size.width; }
	T& height() { return &size.height; }
public:
	//! return the leftmost x-value of 'rect'
	static T CCRectGetMinX(const Rect<T>& rect);

	//! return the rightmost x-value of 'rect'
	static T CCRectGetMaxX(const Rect<T>& rect);

	//! return the midpoint x-value of 'rect'
	static T CCRectGetMidX(const Rect<T>& rect);

	//! Return the bottommost y-value of `rect'
	static T CCRectGetMinY(const Rect<T>& rect);

	//! Return the topmost y-value of `rect'
	static T CCRectGetMaxY(const Rect<T>& rect);

	//! Return the midpoint y-value of `rect'
	static T CCRectGetMidY(const Rect<T>& rect);

	static bool CCRectEqualToRect(const Rect<T>& rect1, const Rect<T>& rect2);

    static bool CCRectContainsPoint(const Rect<T>& rect, const Rect<T>& point);

	static bool CCRectIntersectsRect(const Rect<T>& rectA, const Rect<T>& rectB);
};

typedef Point2D<float> Point2Df;
typedef Rect<float> Rectf; 



#endif