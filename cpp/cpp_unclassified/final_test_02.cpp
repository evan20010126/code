/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

//請完成兩個運算子覆載,err_detection和find_intersection函式
#include <iostream>
#include <cmath>
using namespace std;
const double TOL = 1.e-13;
//異常處理類別
class Err
{
private:
    int kind; //可用來判斷異常的種類，如兩點重疊(目前設定的值為1)、沒有交點、兩線重疊
public:
    Err(int i) : kind(i) {}
    //完成運算子覆載功能，透過kind的值將不同種類的異常狀態回傳
    friend ostream &operator<<(ostream &out, const Err &foo);
};
//生成點座標的類別
class Point
{
private:
    double x, y;

public:
    Point(double a = 0., double b = 0.) : x(a), y(b) {}
    //將交於一點的該點根據題意輸出
    friend ostream &operator<<(ostream &out, const Point &pt)
    {
        return out << "(" << (abs(pt.x) < TOL ? 0. : pt.x)
                   << "," << (abs(pt.y) < TOL ? 0. : pt.y)
                   << ")";
    }

    friend istream &operator>>(istream &in, Point &pt)
    {
        return in >> pt.x >> pt.y;
    }
    //完成運算子覆載功能，透過該函式比較兩點座標是否相等，相等回傳true
    friend bool operator==(const Point &a, const Point &b);
    friend class Line;
};
//透過兩點(Point物件)構成一線
class Line
{
private:
    Point pt1, pt2;
    double a, b, c; //直線方程式為ax+by=c

public:
    Line(const Point &m, const Point &n) : pt1(m), pt2(n)
    {
        if (m == n)
        {                  //透過運算子覆載功能比較兩點座標
            throw(Err(1)); //若無法構成線(兩點重疊)的情況，擲出Err物件
        }
        if (pt1.x == pt2.x)
        {
            a = 1;
            b = 0;
            c = pt1.x;
        }
        else
        {
            a = (pt2.y - pt1.y) / (pt2.x - pt1.x);
            b = -1;
            c = a * pt1.x - pt1.y;
        }
    }

    friend Point intersection(const Line &line1, const Line &line2);

    //待完成的函式，功能主要是回傳異常的種類("沒有交點"或"兩線重疊")，沒有異常回傳0
    friend int err_detection(const Line &line1, const Line &line2);
    //待完成的函式，計算出兩線交於一點的點座標，可透過x,y儲存計算出的xy座標
    friend void find_intersection(const Line &line1, const Line &line2, double *x, double *y);
};
//先透過err_detection()判斷line1, line2是否有異常，之後再透過find_intersection()找出交於一點的點座標
Point intersection(const Line &line1, const Line &line2)
{
    double point_x, point_y;                  //交點的點座標
    int errlog = err_detection(line1, line2); //先找出是否有異常
    if (errlog != 0)
        throw(Err(errlog));
    else
    {
        find_intersection(line1, line2, &point_x, &point_y); //計算出交於一點的點座標
        return Point(point_x, point_y);
    }
}

int main()
{
    Point pt1, pt2, pt3, pt4;
    while (cin >> pt1 >> pt2 >> pt3 >> pt4)
    {
        try
        {
            Line line1(pt1, pt2);
            Line line2(pt3, pt4);
            cout << intersection(line1, line2) << endl;
        }
        catch (const Err &err)
        {
            cout << err << endl;
        }
    }
    return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE*/

int err_detection(const Line &line1, const Line &line2)
{
    if (((line1.b == 0) && (line2.b == 0) && (line1.c == line2.c)))
    {
        return 2;
    }
    else if (((line1.b == 0) && (line2.b == 0) && (line1.c != line2.c)))
    {
        return 3;
    }

    double deltax1 = line1.c * line2.b - line1.b * line2.c;
    double dletax2 = line1.a * line2.c - line1.c * line2.a;
    double delta = line1.a * line2.b - line2.a * line1.b;
    if (delta != 0)
    {
        return 0; //沒問題
    }
    else if (deltax1 == 0 && dletax2 == 0)
    {
        return 2; //兩線重疊
    }
    else
    {
        return 3; //沒有交點
    }
};

void find_intersection(const Line &line1, const Line &line2, double *x, double *y)
{
    double deltax1 = line1.c * line2.b - line1.b * line2.c;
    double dletax2 = line1.a * line2.c - line1.c * line2.a;
    double delta = line1.a * line2.b - line2.a * line1.b;
    *x = deltax1 / delta;
    *y = dletax2 / delta;
}

ostream &operator<<(ostream &out, const Err &foo)
{
    if (foo.kind == 1)
    {
        out << "兩點重疊";
    }
    else if (foo.kind == 2)
    {
        out << "兩線重疊";
    }
    else if (foo.kind == 3)
    {
        out << "沒有交點";
    }
    return out;
}

bool operator==(const Point &a, const Point &b)
{
    if ((a.x == b.x) && (a.y == b.y))
    {
        return true;
    }
    else
    {
        return false;
    }
};