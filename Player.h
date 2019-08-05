//------------------------------------------------------------------------------
// Player.h
//
// Group: Group 4015, study assistant Manuel Weber
//
// Authors: Glatzhofer Michael (0230699)
// Hampersberger Aron (0512772)
// Ilic Filip (1130748)
//------------------------------------------------------------------------------
//
#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>

// is not really necessary, should be placed in main.
// but we are not alowwed to add includes in main,
// despite main uses the color enum.
//
#include "Color.h"
#include "Point.h"
#include "PossibleMoveMap.h"

class Game;
class Piece;

//------------------------------------------------------------------------------
// Player Class
// Represents the players of the game
//
class Player
{

  private:

    Game const& game_;
    Color color_;
    std::string name_;
    Piece* king_;

    PossibleMoveMap possible_moves_;

  public:

    //--------------------------------------------------------------------------
    // Constructor
    //
    Player(Game const& game, Color const& color);

    //--------------------------------------------------------------------------
    // Constructor
    //
    Player(Game const& game, Color const& color, std::string const& name);

    //--------------------------------------------------------------------------
    // Destructor
    //
    virtual ~Player();

    //--------------------------------------------------------------------------
    // Function to display the name and color of player
    //
    std::string getFullName() const;

    //--------------------------------------------------------------------------
    // Getter for color and name
    //
    Color getColor() const;
    std::string getName() const;
    void setKing(Piece& king);
    Piece const& getKing() const;

    //--------------------------------------------------------------------------
    // Setter for color and name
    //
    void setColor(Color const& color);
    void setName(std::string const& name);

    virtual bool isMyPiece(char pieceShortName) const =0;
    virtual char getPlayersPieceShortName(char pieceShortName) const =0;

    inline PossibleMoveMap & getPossibleMoves()
    {
      return possible_moves_;
    }

    inline PossibleMoveMap const& getPossibleMoves() const
    {
      return possible_moves_;
    }
};

class BlackPlayer : public Player
{
  public:
    BlackPlayer(Game const& game);
    virtual bool isMyPiece(char pieceShortName) const;
    virtual char getPlayersPieceShortName(char pieceShortName) const;
};

class WhitePlayer : public Player
{
  public:
    WhitePlayer(Game const& game);
    virtual bool isMyPiece(char pieceShortName) const;
    virtual char getPlayersPieceShortName(char pieceShortName) const;
};

#endif // PLAYER_H_INCLUDED
