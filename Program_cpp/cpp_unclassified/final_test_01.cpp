/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
class shape
{
public:
    shape()
    {
    }
    ~shape()
    {
    }
    virtual double getarea() //計算面積
    {
        return 0;
    }
    virtual double getperimeter()
    {
        return 0;
        //計算周長
    }
    virtual void printpoint()
    {
        cout << "列印圖形的點的座標" << endl;
    }
};

class point
{
public:
    double x;
    double y;
    point() /*若不輸入引數則預設point為0 0*/
    {
        x = 0;
        y = 0;
    }
    point(double a, double b)
    {
        x = a;
        y = b;
    }
};

class triangle : public shape
{
private:
    point a, b, c;

public:
    triangle()
    {
        a = point();
        b = point();
        c = point();
    }
    triangle(point inputa, point inputb, point inputc);
    void setvalue(point inputa, point inputb, point inputc);
    void printpoint() override
    {
        cout << fixed << setprecision(2) << a.x << " " << fixed << setprecision(2) << a.y << endl;
        cout << fixed << setprecision(2) << b.x << " " << fixed << setprecision(2) << b.y << endl;
        cout << fixed << setprecision(2) << c.x << " " << fixed << setprecision(2) << c.y << endl;
    }
    double getarea() override;
    double getperimeter() override;
};
class rectangle : public shape
{
private:
    point a, b, c, d;

public:
    rectangle()
    {
        a = point();
        b = point();
        c = point();
        d = point();
    }
    rectangle(point inputa, point inputb, point inputc, point inputd);
    void setvalue(point inputa, point inputb, point inputc, point inputd);
    double getarea() override;
    double getperimeter() override;
    void printpoint() override
    {
        cout << fixed << setprecision(2) << a.x << " " << fixed << setprecision(2) << a.y << endl;
        cout << fixed << setprecision(2) << b.x << " " << fixed << setprecision(2) << b.y << endl;
        cout << fixed << setprecision(2) << c.x << " " << fixed << setprecision(2) << c.y << endl;
        cout << fixed << setprecision(2) << d.x << " " << fixed << setprecision(2) << d.y << endl;
    }
};
class circle : public shape
{
private:
    point center;
    double r;

public:
    circle()
    {
        center = point();
        r = 0;
    }
    circle(point x, double R);
    void setvalue(point x, double R);
    double getarea() override;
    double getperimeter() override;
    void printpoint() override
    {
        cout << fixed << setprecision(2) << center.x << " " << fixed << setprecision(2) << center.y << endl;
        cout << fixed << setprecision(2) << r << endl;
    }
};
int main()
{
    //cout<<fixed<<setprecision(2)<<3*3*M_PI<<endl;
    double x1, x2, x3, x4, y1, y2, y3, y4, r;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    point tri1(x1, y1), tri2(x2, y2), tri3(x3, y3); //設定座標的值

    triangle triangle1(tri1, tri2, tri3);                                 //初始化三角形
    triangle1.printpoint();                                               //印出點
    cout << fixed << setprecision(2) << triangle1.getperimeter() << endl; //印出周長(註記:周長=每個邊相加)
    cout << fixed << setprecision(2) << triangle1.getarea() << endl;      //印出面積(可參考三角形類別的異常處理)

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    point rec1(x1, y1), rec2(x2, y2), rec3(x3, y3), rec4(x4, y4);          //設定座標的值
    rectangle rectangle1(rec1, rec2, rec3, rec4);                          //初始化四邊形
    rectangle1.printpoint();                                               //印出點
    cout << fixed << setprecision(2) << rectangle1.getperimeter() << endl; //印出周長(註記:周長=每個邊相加)
    cout << fixed << setprecision(2) << rectangle1.getarea() << endl;      //印出面積

    cin >> x1 >> y1 >> r;
    point circlepoint1(x1, y1);                                         //設定座標的值
    circle circle1(circlepoint1, r);                                    //初始化圓形
    circle1.printpoint();                                               //印出點 半徑
    cout << fixed << setprecision(2) << circle1.getperimeter() << endl; //印出周長(註記:周長=直徑*pi)
    cout << fixed << setprecision(2) << circle1.getarea() << endl;      //印出面積 半徑*半徑*pi

    return 0;
}
/*
範例:
triangle::triangle(point inputa, point inputb, point inputc)
{
    a = inputa;
    b = inputb;
    c = inputc;
}

*/

/* PRESET CODE END - NEVER TOUCH CODE ABOVE*/
double triangle::getarea()
{
    double vector_AB_x = b.x - a.x;
    double vector_AB_y = b.y - a.y;

    double vector_AC_x = c.x - a.x;
    double vector_AC_y = c.y - a.y;
    double area;
    area = (sqrt((pow(vector_AB_x, 2) + pow(vector_AB_y, 2)) * (pow(vector_AC_x, 2) + pow(vector_AC_y, 2)) - (pow(vector_AB_x * vector_AC_x + vector_AB_y * vector_AC_y, 2)))) / 2;
    return area;
}
double triangle::getperimeter()
{
    double vector_AB_x = b.x - a.x;
    double vector_AB_y = b.y - a.y;
    double AB_length = sqrt(pow(vector_AB_x, 2) + pow(vector_AB_y, 2));

    double vector_AC_x = c.x - a.x;
    double vector_AC_y = c.y - a.y;
    double AC_length = sqrt(pow(vector_AC_x, 2) + pow(vector_AC_y, 2));

    double vector_BC_x = c.x - b.x;
    double vector_BC_y = c.y - b.y;
    double BC_length = sqrt(pow(vector_BC_x, 2) + pow(vector_BC_y, 2));

    return AB_length + AC_length + BC_length;
}

triangle::triangle(point inputa, point inputb, point inputc)
{
    a = inputa;
    b = inputb;
    c = inputc;
};
void setvalue(point inputa, point inputb, point inputc){
    //
};

double rectangle::getarea()
{
    double vector_AB_x = b.x - a.x;
    double vector_AB_y = b.y - a.y;
    double vector_AB_length;
    vector_AB_length = sqrt(pow(vector_AB_x, 2) + pow(vector_AB_y, 2));
    double vector_BC_x = c.x - b.x;
    double vector_BC_y = c.y - c.y;
    double vector_BC_length;
    vector_BC_length = sqrt(pow(vector_BC_x, 2) + pow(vector_BC_y, 2));

    return vector_AB_length * vector_BC_length;
}

double rectangle::getperimeter()
{
    double vector_AB_x = b.x - a.x;
    double vector_AB_y = b.y - a.y;
    double vector_AB_length;
    vector_AB_length = sqrt(pow(vector_AB_x, 2) + pow(vector_AB_y, 2));
    double vector_BC_x = c.x - b.x;
    double vector_BC_y = c.y - c.y;
    double vector_BC_length;
    vector_BC_length = sqrt(pow(vector_BC_x, 2) + pow(vector_BC_y, 2));
    return (vector_AB_length + vector_BC_length) * 2;
}

rectangle::rectangle(point inputa, point inputb, point inputc, point inputd)
{
    a = inputa;
    b = inputb;
    c = inputc;
    d = inputd;
}

circle::circle(point x, double R)
{
    center = x;
    r = R;
}

double circle::getarea()
{
    return r * r * 3.141592653;
}

double circle::getperimeter()
{
    return 2 * r * 3.141592653;
}