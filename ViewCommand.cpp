//------------------------------------------------------------------------------
// ViewCommand.cpp
//
// Group: Group 4015, study assistant Manuel Weber
//
// Authors: Glatzhofer Michael (0230699)
// Hampersberger Aron (0512772)
// Ilic Filip (1130748)
//------------------------------------------------------------------------------
//
#include <iostream>
#include <vector>

#include "ViewCommand.h"
#include "Game.h"
#include "Player.h"
#include "Localization.h"

using std::string;
using std::endl;
using std::cout;
using std::endl;
using std::vector;

const string ViewCommand::NAME = "view";

//------------------------------------------------------------------------------
ViewCommand::ViewCommand() : Command(NAME)
{
}

//------------------------------------------------------------------------------
bool ViewCommand::execute(Game& board, vector<string> const& params)
{
  if(params.size() > 0)
  {
    cout << Localization::ERROR_WRONG_USAGE << endl;
  }
  else
  {
    cout << board.toString() << endl;
  }

  return true;
}
