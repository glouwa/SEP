//------------------------------------------------------------------------------
// Game.cpp
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
#include <string>
#include <sstream>

#include "Game.h"
#include "ViewCommand.h"
#include "StatusCommand.h"
#include "EchoCommand.h"
#include "QuitCommand.h"
#include "Player.h"
#include "Piece.h"
#include "Localization.h"
#include "SetupStringInvalidException.h"

using std::string;
using std::endl;
using std::map;
using std::vector;
using std::cout;
using std::cin;
using std::ostringstream;
using std::istringstream;

Game::Game(Point bounds, int turn, char first_row_name,
           char first_column_name, bool increase_row_char,
           bool increase_column_char) :
  bounds_(bounds),
  turn_(turn),
  first_row_name_(first_row_name),
  first_column_name_(first_column_name),
  increase_row_char_(increase_row_char),
  increase_column_char_(increase_column_char)
{
  pieces_.resize(bounds_.getX() + 1, vector<Piece*>(bounds_.getY() + 1));

  registerCommand<ViewCommand>();
  registerCommand<EchoCommand>();
  registerCommand<StatusCommand>();
  registerCommand<QuitCommand>();
  // move
  // draw
  // history
  // setname
  // save
}

//------------------------------------------------------------------------------
Game::~Game()
{
  CommandMap::iterator command_delete_iterator = commandMap_.begin();
  while(command_delete_iterator != commandMap_.end())
  {
    delete command_delete_iterator->second;
    commandMap_.erase(command_delete_iterator);
    command_delete_iterator = commandMap_.begin();
  }

  vector<Player*>::iterator player_delete_iterator = players_.begin();
  while(player_delete_iterator != players_.end())
  {
    delete *player_delete_iterator;
    players_.erase(player_delete_iterator);
    player_delete_iterator = players_.begin();
  }

  /*
  vector<Piece*>::iterator piece_delete_iterator = pieces_.begin();
  while(piece_delete_iterator != pieces_.end())
  {
    delete *piece_delete_iterator;
    pieces_.erase(piece_delete_iterator);
    piece_delete_iterator = pieces_.begin();
  }*/
}

//------------------------------------------------------------------------------
void Game::run()
{
  bool proceed = true;

  do
  {
    cout << Localization::PROMPT;

    // read inputline, yes the hole line!
    string inputString;
    getline(cin, inputString);

    if (inputString.size())
    {
      // parse command string
      istringstream inputParser(inputString);

      string commandString;
      vector<string> arguments;

      if (inputParser >> commandString)
      {
        // parse argument string into vector
        string currentArgument;
        while(inputParser >> currentArgument)
        {
          arguments.push_back(currentArgument);
        }
      }

      // find command
      CommandMap::iterator find_result = commandMap_.find(Tools::toLower(commandString));

      if (find_result == commandMap_.end())
      {
        cout << Localization::ERROR_UNKNOWN_COMMAND << endl;
      }
      else
      {
        proceed = find_result->second->execute(*this, arguments);
      }
    }
  }
  while(proceed);
}

//------------------------------------------------------------------------------

Piece& Game::findPiece(Point const& position) const
{
  return *pieces_.at(position.getX()).at(position.getY());
}

//------------------------------------------------------------------------------
void Game::addPlayer(Player* player)
{
  players_.push_back(player);
}

//------------------------------------------------------------------------------
Player const& Game::getCurrentPlayer() const
{
  return *players_[turn_%players_.size()];
}

//------------------------------------------------------------------------------
string Game::toString() const
{
  ostringstream outputStream;

  // header
  outputStream << " ";
  for (char x_offset = 0; x_offset < bounds_.getX(); x_offset++)
  {
    char current_column_name = first_column_name_ - x_offset;

    if (increase_column_char_ == true)
    {
      current_column_name = first_column_name_ + x_offset;
    }

    outputStream << "|" << current_column_name;
  }

  outputStream << "| " << endl;
  addSeparationLine(outputStream);

  // all other rows
  for (char y_offset = 0; y_offset < bounds_.getY(); y_offset++)
  {
    char current_row_name = first_row_name_ - y_offset;
    int current_row = bounds_.getY() - y_offset - 1;

    if (increase_row_char_ == true)
    {
      current_row_name = first_row_name_ + y_offset;
      current_row = y_offset;
    }

    outputStream << endl << current_row_name;

    for (char x_offset = 0; x_offset <= bounds_.getX(); x_offset++)
    {
      int currnet_column =  bounds_.getX() - x_offset - 1;

      if (increase_column_char_ == true)
      {
        currnet_column = x_offset;
      }

      Point current_position(currnet_column, current_row);

      string piece_name = getCurrentPlayer().getPossibleMoves().isSet(current_position) ? "." : " ";
      Piece& piece = findPiece(current_position);
      if (&piece != NULL)
      {
        piece_name = piece.toBoardChar();
      }

      outputStream << "|" << piece_name;
    }
    outputStream << endl;
    addSeparationLine(outputStream);
  }

  return outputStream.str();
}

//------------------------------------------------------------------------------
void Game::addSeparationLine(ostringstream& outputStream) const
{
  for (int x_offset = 0; x_offset <= bounds_.getX(); x_offset++)
  {
    outputStream << "-+";
  }
  outputStream << " ";
}

