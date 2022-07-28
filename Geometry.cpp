#include <bits/stdc++.h>
using namespace std;
#define Charpoka ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cin.exceptions(ios::badbit | ios::failbit)
#define endl '\n'
#define pb push_back
#define ll long long int
#define infinity 1 << 30
typedef long double Tf;
const Tf EPS = 1e-9;

/* COMPARISON BETWEEN TWO FLOATING VALUES IF THEY ARE EQUAL OR NOT BY APPLYING SOME CONDITIONS */
int dcmp(Tf x, Tf y = 0)
{
    if (fabs(x - y) < EPS)
    {
        return 0;
    }
    return x < y ? -1 : 1;
}

/* OPERATIONS ON POINTS */
struct Point
{
    Tf x, y;
    Point()
    {
    }

    Point(Tf x, Tf y) : x(x), y(y)
    {
    }

    Point operator+(const Point &p)
    {
        return Point(x + p.x, y + p.y);
    }

    Point operator-(const Point &p)
    {
        return Point(x - p.x, y - p.y);
    }

    Point operator*(const Tf v)
    {
        return Point(x * v, y * v);
    }

    Point operator/(const Tf v)
    {
        return Point(x / v, y / v);
    }

    bool operator==(const Point &p)
    {
        return dcmp(x, p.x) == 0 and dcmp(y, p.y) == 0;
    }

    bool operator!=(const Point &p)
    {
        return !(*this == p);
    }

    friend ostream &operator<<(ostream &os, const Point &p)
    {
        return os << "( " << p.x << " , " << p.y << " )";
    }
};

typedef Point Vector;

/* DOT PRODUCT */
Tf dot(Vector a, Vector b)
{
    return a.x * b.x + a.y * b.y;
}

/* CROSS PRODUCT */
Tf cross(Vector a, Vector b)
{
    return a.x * b.y + a.y * b.x;
}

Tf length(Vector a)
{
    return sqrt(dot(a, a));
}

Vector rotate(Vector a, Tf ang)
{
    return Vector(a.x * cos(ang) - a.y * sin(ang), a.x * sin(ang) + a.y * cos(ang));
}

Vector rotate_ccw90(Vector a)
{
    return Vector(-a.y, a.x);
}

Vector unit(Vector a)
{
    return a / length(a);
}

///-1 if c is left turn from a-b
/// 1 if c is right turn from a-b
/// 0 if c is on a-b

/* CCW CONCEPT */
int ccw(Point a, Point b, Point c)
{
    Tf k = cross(b - a, c - a);
    return dcmp(k);
}

/* SEGEMENT OPERATIONS */
struct Segment
{
    Point a, b;

    Segment()
    {
    }

    Segment(Point a, Point b) : a(a), b(b)
    {
    }
};

// RETURNS TRUE IF P IS ON SEGMENT S
bool is_point_on_segment(Point p, Segment s)
{
    return dcmp(cross(p - s.a, p - s.b)) == 0 and dcmp(dot(p - s.a, p - s.b)) <= 0;
}

// RETURNS TRUE IF SEGMENTS P AND Q INTERSECTS (PROPER OR IMPROPER)
bool do_segments_intersect(Segment p, Segment q)
{
    if (is_point_on_segment(p.a, q) or is_point_on_segment(p.b, q) or is_point_on_segment(q.a, p) or is_point_on_segment(q.b, p))
        return true; /// IMPROPER INTERSECTION
    return ccw(p.a, p.b, q.a) != ccw(p.a, p.b, q.b) and ccw(q.a, q.b, p.a) != ccw(q.a, q.b, p.b);
}

struct Line
{
    Point p;  // ANY POINT ON THE LINE
    Vector v; // NON-ZERO VECTOR ON THE LINE

    Line() {}
    Line(Point a, Point b) : p(a), v(b - a) {}
};

// DISTANCE FROM POINT P ON LINE L
Tf distance_point_line(Point p, Line l)
{
    Vector w = p - l.p;
    return abs(cross(l.v, w)) / length(l.v);
}

// PROJECTION OF POINT P ON LINE L
Point project_point_line(Point p, Line l)
{
    Vector w = p - l.p;
    Tf k = dot(l.v, w) / dot(l.v, l.v);
    return l.p + l.v * k;
}

bool is_parallel_line(Line l1, Line l2)
{
    return dcmp(cross(l1.v, l2.v)) == 0;
}

// RETURNS THE INTERSECTION POINT OF LINE L! AND L2
Point line_line_intersection(Line l1, Line l2)
{
    Vector u = l2.p - l1.p, v = l1.v, w = l2.v;
    return l1.p + l1.v * cross(w, u) / cross(w, v);
}

Tf area_of_triangle(Point a, Point b, Point c)
{
    Vector ab = b - a;
    Vector ac = c - a;
    Tf k = cross(ab, ac);
    return abs(k) / 2;
}

Line perpendicular_line(Line l1)
{
    return Line(l1.p, rotate_ccw90(l1.v));
}

typedef vector<Point> Polygon;

Tf area_of_polygon(Polygon p)
{
    Tf ret = 0;
    for (int i = 0; i + 1 < (int)p.size(); ++i)
    {
        ret += cross(p[i] - p[0], p[i + 1] - p[0]);
    }
    return abs(ret) / 2;
}

int main()
{
    Charpoka;
    // Point a={0,0},b={4,0},c={0,5};
    // cout<<area_of_triangle(a,b,c)<<endl;

    cout << boolalpha << do_segments_intersect(Segment({0, 0}, {10, 0}), Segment({2, 0}, {5, 0}));
    return 0;
}