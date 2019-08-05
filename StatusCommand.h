//------------------------------------------------------------------------------
// StatusCommand.h
//
// Group: Group 4015, study assistant Manuel Weber
//
// Authors: Glatzhofer Michael (0230699)
// Hampersberger Aron (0512772)
// Ilic Filip (1130748)
//------------------------------------------------------------------------------
//
#ifndef STATUSCOMMAND_H_INCLUDED
#define STATUSCOMMAND_H_INCLUDED

#include <string>
#include <vector>

#include "Command.h"

class Game;

//------------------------------------------------------------------------------
// Prints the current Player to stdout
//
class StatusCommand : public Command
{
  public:
    static const std::string NAME;

    StatusCommand();
    virtual bool execute(Game& board, std::vector<std::string> const& params);
};

#endif //STATUSCOMMAND_H_INCLUDED
