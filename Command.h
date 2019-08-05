//------------------------------------------------------------------------------
// Command.h
//
// Group: Group 4015, study assistant Manuel Weber
//
// Authors: Glatzhofer Michael (0230699)
// Hampersberger Aron (0512772)
// Ilic Filip (1130748)
//------------------------------------------------------------------------------
//
#ifndef COMMAND_H_INCLUDED
#define COMMAND_H_INCLUDED

#include <string>
#include <vector>

class Game;

//------------------------------------------------------------------------------
// Command Base class
//
class Command
{
  public:

    //--------------------------------------------------------------------------
    // Consturctor
    //
    Command(std::string name);

    //--------------------------------------------------------------------------
    // Destructor
    //
    virtual ~Command();

    //--------------------------------------------------------------------------
    // Executes the action.
    // @param board The board where action should be performed on
    // @param params Possible parameters neede for the execution
    // @return bool false if the main loop should end,
    //              true if the main loop should proceed
    //
    virtual bool execute(Game& board, std::vector<std::string> const& params)=0;
    
    //--------------------------------------------------------------------------
    // Gets the name of the Command
    //
    const std::string& getName ();

  private:

    //--------------------------------------------------------------------------
    // Private copy constructor
    // Command should not be copied
    //
    Command (const Command& original);

    //--------------------------------------------------------------------------
    // Private assignment operator
    //
    Command& operator= (const Command& original);
    
    //--------------------------------------------------------------------------
    // Name of this command
    //
    std::string command_name_;
};

#endif //COMMAND_H_INCLUDED
