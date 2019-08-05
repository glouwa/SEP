#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include <sstream>

class Point
{
  private:
    int x_;
    int y_;

  protected:

  public:

    Point();
    Point(int x, int y);

    virtual ~Point();

    Point(const Point& other);
    Point& operator=(const Point& other);

    inline int getX() const { return x_; }
    inline int getY() const { return y_; }

    bool isValid() const;

    friend Point operator + (Point const& op1, Point const& op2);
    friend Point operator - (Point const& op1, Point const& op2);
    friend Point operator * (Point const& op1, int multiplier);
    friend Point operator / (Point const& op1, int divisor);
    Point& operator+= (Point const& op2);
    Point& operator-= (Point const& op2);

    friend std::ostream& operator << (std::ostream& oss, Point const& point);
    friend std::istream& operator >> (std::istream& is, Point& point);
};

#endif // POINT_H_INCLUDED
