//------------------------------------------------------------------------------
// MoveCommand.h
//
// Group: Group 4015, study assistant Manuel Weber
//
// Authors: Glatzhofer Michael (0230699)
// Hampersberger Aron (0512772)
// Ilic Filip (1130748)
//------------------------------------------------------------------------------
//
#ifndef MOVECOMMAND_H_INCLUDED
#define MOVECOMMAND_H_INCLUDED

#include <string>
#include <vector>

#include "Command.h"

class Game;
class Point;

//------------------------------------------------------------------------------
// Prints first argument to stdout
//
class MoveCommand : public Command
{
  private:

    bool parseLocation(Point & result, std::string const& param, std::string const& error_message) const;

  public:
    static const std::string NAME;

    MoveCommand();
    virtual bool execute(Game& board, std::vector<std::string> const& params);
};

#endif //MOVECOMMAND_H_INCLUDED
