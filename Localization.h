//------------------------------------------------------------------------------
// Localization.h
//
// Group: Group 4015, study assistant Manuel Weber
//
// Authors: Glatzhofer Michael (0230699)
// Hampersberger Aron (0512772)
// Ilic Filip (1130748)
//------------------------------------------------------------------------------
//
#ifndef LOCALIZATION_H_INCLUDED
#define LOCALIZATION_H_INCLUDED

//------------------------------------------------------------------------------
// All output strings will be placed here.
// Can be used to localize the application later on.
//
class Localization
{
  public:

    static const char* PROMPT;
    static const char* CURRENT_PLAYER;
    static const char* BYE;

    static const char* COLOR_BLACK;
    static const char* COLOR_WHITE;
    static const char* COLOR_RED;
    static const char* COLOR_GREEN;
    static const char* COLOR_BLUE;
    static const char* COLOR_YELLOW;
    static const char* COLOR_ORANGE;
    static const char* COLOR_BROWN;

    static const char* ERROR_INVALID_PARAMTER_COUNT;
    static const char* ERROR_OUT_OF_MEMORY;
    static const char* ERROR_SETUP_STRING_INVALID;
    static const char* ERROR_SETUP_STRING_CORRUPT;

    static const char* ERROR_MOVE_USAGE;
    static const char* ERROR_INCORRECT_STARTING_LOCATION;
    static const char* ERROR_INCORRECT_TARGET_LOCATION;
    static const char* ERROR_NO_PIECE_AT_THIS_LOCATION;
    static const char* ERROR_NO_OWN_PIECE_AT_THIS_LOCATION;
    static const char* ERROR_TARGET_LOCATION_NOT_REACHABLE;
    static const char* ERROR_PIECE_ON_THE_WAY;
    static const char* ERROR_OWN_PIECE_ON_TARGET_LOCATION;
    static const char* ERROR_NO_SACRIFICE_ALLOWED;

    static const char* ERROR_UNKNOWN_COMMAND;
    static const char* ERROR_WRONG_USAGE;
};

#endif //LOCALIZATION_H_INCLUDED
