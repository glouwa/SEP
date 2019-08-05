//------------------------------------------------------------------------------
// Color.h
//
// Group: Group 4015, study assistant Manuel Weber
//
// Authors: Glatzhofer Michael (0230699)
// Hampersberger Aron (0512772)
// Ilic Filip (1130748)
//------------------------------------------------------------------------------
//
#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

#include <string>

//------------------------------------------------------------------------------
// Color enumeration
// Listing of all available colors
//
enum Color
{
  BLACK,
  WHITE,
  RED,
  GREEN,
  BLUE,
  YELLOW,
  ORANGE,
  BROWN
};

//------------------------------------------------------------------------------
// ColorToStringTool Class
// Toolclass for string representations constants of colors,
// and conversion functions.
//
// This is bad OOP design,
// but it would be also bad OOP design to put them into the 'Player' class.
//
// Unfortunately it's not possible to create a proper color class,
// because the enum is part of the specification.
//
class Tools
{
  public:

    static const char* COLORS[];

    //--------------------------------------------------------------------------
    // Returns a human readable string representation of the given
    // argument 'color'
    //
    // @param  color The color enum which should be converted in a string.
    // @return Returns human readable string representation of the given
    //         argument 'color'. If color has an invalid value
    //         ColorToStringTool::INVALID_STRING will be returned.
    //
    static std::string getColorName(Color const& color);

    static std::string toLower(std::string const& input);
};

#endif // COLOR_H_INCLUDED
