//------------------------------------------------------------------------------
// Game.h
//
// Group: Group 4015, study assistant Manuel Weber
//
// Authors: Glatzhofer Michael (0230699)
// Hampersberger Aron (0512772)
// Ilic Filip (1130748)
//------------------------------------------------------------------------------
//
#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <map>
#include <string>
#include <sstream>
#include <vector>

#include "Point.h"
#include "Color.h"

//------------------------------------------------------------------------------
// forward declarations
//
class Command;
class Player;
class Piece;

//------------------------------------------------------------------------------
// Game Class
// Represents a 2d Game, and accepts actions to motify the playboard and players
//
class Game
{
  private:

    // Piece hat zurgiff auf das pieces_ array
    friend class Piece;

    //--------------------------------------------------------------------------
    // Width and height of playboard
    //
    Point bounds_;

    //--------------------------------------------------------------------------
    // Not enought information yet.
    // Maybe its just a turn counter,
    // or maybe all turns are saved for undo and it's a index.
    //
    int turn_;

    //--------------------------------------------------------------------------
    // name of first row.
    // other rows get
    // incrementing names, if 'increase_row_char_' true,
    // or decrementing names, if 'increase_row_char_' false.
    //
    char first_row_name_;

    //--------------------------------------------------------------------------
    // name of first column.
    // other columns get
    // incrementing names, if 'increase_column_char_' true,
    // or decrementing names, if 'increase_column_char_' false.
    //
    char first_column_name_;

    //--------------------------------------------------------------------------
    // true if row names are incremented,
    // false if row names are decremented
    // from left to right.
    //
    bool increase_row_char_;

    //--------------------------------------------------------------------------
    // true if column names are incremented,
    // false if column names are decremented
    // from left to right.
    //
    bool increase_column_char_;

    typedef std::vector<std::vector<Piece*> > PieceMap;

    //--------------------------------------------------------------------------
    // Array of pointers to all pieces.
    // Not a array of pieces, to avoid include dependency problems.
    //
    // if its going to be chess, the number of pieces will be dynamic,
    // so a array would be ... not so nice. so lets see if stl is
    // allowed later on.
    //
    PieceMap pieces_;

    //--------------------------------------------------------------------------
    // Typedefs for commandMap, otherwise 80 char lines are impossible
    //
    typedef std::map<std::string, Command*> CommandMap;
    typedef std::pair<std::string, Command*> CommandMapPair;

    //--------------------------------------------------------------------------
    // Contains all implemented cmd commands.
    // Commandname is key
    //
    CommandMap commandMap_;

    //--------------------------------------------------------------------------
    // tool function for adding seperation line in toString function
    // @param oss The Separationline will be added to this stream.
    //
    void addSeparationLine(std::ostringstream& oss) const;

  protected:

    typedef std::vector<Player*> PlayerList;

    //--------------------------------------------------------------------------
    // Array of pointers to all players.
    // Not a array of players, to avoid include dependency problems.
    // And if its going to be chess, the number of players will be constant,
    // so a array would be a nice choice.
    //
    PlayerList players_;

    //--------------------------------------------------------------------------
    // Adds 'player' to the game.
    //
    // @param player The player to add
    //
    void addPlayer(Player* player);

    //--------------------------------------------------------------------------
    // To avoid key to command mismatches in commandMap
    //
    template<typename Tcommand>
    inline void registerCommand()
    {
      commandMap_.insert(CommandMapPair(Tools::toLower(Tcommand::NAME), new Tcommand()));
    }

  public:

    //--------------------------------------------------------------------------
    // @param bounds see bounds_
    // @param active_player see active_player_index_
    // @param first_row_name see turn_
    // @param first_column_name see first_column_name_
    // @param increase_row_char see increase_row_char_
    // @param increase_column_char see increase_column_char_
    //
    Game(Point bounds, int turn, char first_row_name,
         char first_column_name, bool increase_row_char,
         bool increase_column_char);

    //--------------------------------------------------------------------------
    // Destructor
    //
    virtual ~Game();

    //--------------------------------------------------------------------------
    // Starts the Game. Game will run until 'quit' is entered.
    //
    void run();

    //--------------------------------------------------------------------------
    // Adds 'piece' to the game.
    //
    // @param piece The piece to add
    //
    Piece& findPiece(Point const& position) const;

    inline Player& getPlayer(int index) const
    {
      return *players_[index];
    }

    inline int getTurn() const
    {
      return turn_;
    }

    //--------------------------------------------------------------------------
    // @return Returns the current Player. That's the player who will
    //         make the next turn.
    //
    Player const& getCurrentPlayer() const;

    virtual bool move(Point const& start, Point const& end) = 0;

    inline void nextTurn() { turn_++; }

    //--------------------------------------------------------------------------
    // @return Returns a ACII art string of the playboard.
    //
    std::string toString() const;
};

#endif //GAME_H_INCLUDED
