//------------------------------------------------------------------------------
// MoveCommand.cpp
//
// Group: Group 4015, study assistant Manuel Weber
//
// Authors: Glatzhofer Michael (0230699)
// Hampersberger Aron (0512772)
// Ilic Filip (1130748)
//------------------------------------------------------------------------------
//
#include <iostream>
#include <sstream>
#include <vector>

#include "MoveCommand.h"
#include "Chess.h"
#include "Localization.h"
#include "SetupStringInvalidException.h"
#include "SetupStringCorruptException.h"

using std::string;
using std::endl;
using std::cout;
using std::endl;
using std::vector;
using std::istringstream;

const string MoveCommand::NAME = "move";

//------------------------------------------------------------------------------
MoveCommand::MoveCommand() : Command(NAME)
{
}

//------------------------------------------------------------------------------
bool MoveCommand::execute(Game& board, vector<string> const& params)
{
  if (params.size() != 2)
  {
    cout << Localization::ERROR_MOVE_USAGE << endl;
  }
  else
  {
    Point start_location, end_location;

    if (parseLocation(start_location, params[0], Localization::ERROR_INCORRECT_STARTING_LOCATION) &&
        parseLocation(end_location, params[1], Localization::ERROR_INCORRECT_TARGET_LOCATION))
    {
      try
      {
        return !board.move(start_location, end_location);
      }
      catch(MoveException const& e)
      {
        cout << e.message() << endl;
      }
    }
  }
  return true;
}

bool MoveCommand::parseLocation(Point & result, string const& param, string const& error_message) const
{
  try
  {
    istringstream iss(param);
    iss >> result;
    return true;
  }
  catch(EofException)
  {
    cout << Localization::ERROR_MOVE_USAGE << endl;
  }
  catch(FormatException)
  {
    cout << Localization::ERROR_MOVE_USAGE << endl;
  }
  catch(InvalidArgumentException)
  {
    cout << error_message << endl;
  }
  return false;
}
