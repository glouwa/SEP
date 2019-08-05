//------------------------------------------------------------------------------
// EchoCommand.cpp
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

#include "EchoCommand.h"
#include "Game.h"
#include "Localization.h"

using std::string;
using std::endl;
using std::cout;
using std::endl;
using std::vector;

const string EchoCommand::NAME = "echo";

//------------------------------------------------------------------------------
EchoCommand::EchoCommand() : Command(NAME)
{ 
}

//------------------------------------------------------------------------------
bool EchoCommand::execute(Game& board, vector<string> const& params)
{
  if (params.size() == 0 || params.size() > 1)
  {
    cout << Localization::ERROR_WRONG_USAGE << endl;
  }
  else
  {
    cout << params[0] << endl;
  }
  return true;
}
