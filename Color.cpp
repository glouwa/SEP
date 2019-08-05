//------------------------------------------------------------------------------
// Color.cpp
//
// Group: Group 4015, study assistant Manuel Weber
//
// Authors: Glatzhofer Michael (0230699)
// Hampersberger Aron (0512772)
// Ilic Filip (1130748)
//------------------------------------------------------------------------------
//
#include <sstream>

#include "Color.h"
#include "Localization.h"

using std::string;
using std::ostringstream;

const char* Tools::COLORS[] =
{
  Localization::COLOR_BLACK,
  Localization::COLOR_WHITE,
  Localization::COLOR_RED,
  Localization::COLOR_GREEN,
  Localization::COLOR_BLUE,
  Localization::COLOR_YELLOW,
  Localization::COLOR_ORANGE,
  Localization::COLOR_BROWN
};

//------------------------------------------------------------------------------
std::string Tools::getColorName(Color const& color)
{
  return COLORS[color];
}

//------------------------------------------------------------------------------
std::string Tools::toLower(std::string const& input)
{
  ostringstream oss;
  for (string::const_iterator i = input.begin(); i != input.end(); i++)
  {
    oss << tolower(*i);
  }
  return oss.str();
}

