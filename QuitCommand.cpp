//------------------------------------------------------------------------------
// QuitCommand.cpp
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

#include "QuitCommand.h"
#include "Game.h"
#include "Localization.h"

using std::string;
using std::endl;
using std::cout;
using std::endl;
using std::vector;

const string QuitCommand::NAME = "quit";

//------------------------------------------------------------------------------
QuitCommand::QuitCommand() : Command(NAME) 
{
}

//------------------------------------------------------------------------------
bool QuitCommand::execute(Game& board, vector<string> const& params)
{
  if (params.size() > 0)
  {
    cout << Localization::ERROR_WRONG_USAGE << endl;
    return true;
  }
  else
  {
    cout << Localization::BYE << endl;
    return false;
  }
}

