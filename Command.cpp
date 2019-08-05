//------------------------------------------------------------------------------
// Command.cpp
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

#include "Command.h"

using std::string;

//------------------------------------------------------------------------------
Command::Command(string name) : command_name_(name)
{
}

//------------------------------------------------------------------------------
Command::~Command()
{
}

//------------------------------------------------------------------------------
const string& Command::getName ()
{
  return command_name_;
}
