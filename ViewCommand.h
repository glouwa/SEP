//------------------------------------------------------------------------------
// ViewCommand.h
//
// Group: Group 4015, study assistant Manuel Weber
//
// Authors: Glatzhofer Michael (0230699)
// Hampersberger Aron (0512772)
// Ilic Filip (1130748)
//------------------------------------------------------------------------------
//
#ifndef VIEWCOMMAND_H_INCLUDED
#define VIEWCOMMAND_H_INCLUDED

#include <string>
#include <vector>

#include "Command.h"

class Game;

//------------------------------------------------------------------------------
// View Command prints the gameboard to stdout
//
class ViewCommand : public Command
{
  public:
    static const std::string NAME;

    ViewCommand();
    virtual bool execute(Game& board, std::vector<std::string> const& params);
};

#endif //VIEWCOMMAND_H_INCLUDED
