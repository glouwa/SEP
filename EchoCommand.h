//------------------------------------------------------------------------------
// EchoCommand.h
//
// Group: Group 4015, study assistant Manuel Weber
//
// Authors: Glatzhofer Michael (0230699)
// Hampersberger Aron (0512772)
// Ilic Filip (1130748)
//------------------------------------------------------------------------------
//
#ifndef ECHOCOMMAND_H_INCLUDED
#define ECHOCOMMAND_H_INCLUDED

#include <string>
#include <vector>

#include "Command.h"

class Game;

//------------------------------------------------------------------------------
// Prints first argument to stdout
//
class EchoCommand : public Command
{
  public:
    static const std::string NAME;

    EchoCommand();
    virtual bool execute(Game& board, std::vector<std::string> const& params);
};

#endif //ECHOCOMMAND_H_INCLUDED
