//------------------------------------------------------------------------------
// QuitCommand.h
//
// Group: Group 4015, study assistant Manuel Weber
//
// Authors: Glatzhofer Michael (0230699)
// Hampersberger Aron (0512772)
// Ilic Filip (1130748)
//------------------------------------------------------------------------------
//
#ifndef QUITCOMMAND_H_INCLUDED
#define QUITCOMMAND_H_INCLUDED

#include <string>
#include <vector>

#include "Command.h"

class Game;

//------------------------------------------------------------------------------
// Quits the application
//
class QuitCommand : public Command
{
  public:
    static const std::string NAME;

    QuitCommand();
    virtual bool execute(Game& board, std::vector<std::string> const& params);
};

#endif //QUITCOMMAND_H_INCLUDED
