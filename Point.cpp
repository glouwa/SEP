#include "Point.h"
#include "Chess.h"
#include "SetupStringInvalidException.h"
#include "SetupStringCorruptException.h"

Point::Point() : x_(-1), y_(-1)
{
}

Point::Point(int x, int y) : x_(x), y_(y)
{
}

Point::Point(Point const& src) : x_(src.x_), y_(src.y_)
{
}

Point::~Point()
{
}

Point& Point::operator= (Point const& src)
{
  if (this == &src) return *this;
  x_ = src.x_;
  y_ = src.y_;
  return *this;
}

bool Point::isValid() const
{
  if (x_ < 0 || x_ >= Chess::BOARD_SIZE ||
      y_ < 0 || y_ >= Chess::BOARD_SIZE )
  {
    return false;
  }
  else
  {
    return true;
  }
}

Point operator+ (Point const& op1, Point const& op2)
{
  return Point(op1.getX() + op2.getX(), op1.getY() + op2.getY());
}

Point operator- (Point const& op1, Point const& op2)
{
  return Point(op1.getX() - op2.getX(), op1.getY() - op2.getY());
}

Point operator* (Point const& op1, int multiplier)
{
  return Point(op1.getX() * multiplier, op1.getY() * multiplier);
}

Point operator/ (Point const& op1, int divisor)
{
  return Point(op1.getX() / divisor, op1.getY() / divisor);
}

Point& Point::operator+= (Point const& op2)
{
  x_ += op2.x_;
  y_ += op2.y_;
  return *this;
}

Point& Point::operator-= (Point const& op2)
{
  x_ -= op2.x_;
  y_ -= op2.y_;
  return *this;
}

std::ostream& operator<< (std::ostream& oss, Point const& point)
{
  oss << (char)(point.getX() + 'a') << (char)(point.getY() + '1');
  return oss;
}

std::istream& operator>> (std::istream& is, Point& point)
{
  char char_x;
  if (!(is >> char_x)) throw EofException();
  if (!isalpha(char_x)) throw FormatException();
  int x = tolower(char_x) - 'a';
  if (x < 0 || x >= Chess::BOARD_SIZE) throw InvalidArgumentException();

  char char_y;
  if (!(is >> char_y)) throw EofException();
  if (!isdigit(char_y)) throw FormatException();
  int y = char_y - '1';
  if (y < 0 || y >= Chess::BOARD_SIZE) throw InvalidArgumentException();

  point = Point(x, y);
  return is;
}
