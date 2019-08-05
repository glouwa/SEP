//------------------------------------------------------------------------------
// Piece.h
//
// Group: Group 4015, study assistant Manuel Weber
//
// Authors: Glatzhofer Michael (0230699)
// Hampersberger Aron (0512772)
// Ilic Filip (1130748)
//------------------------------------------------------------------------------
//
#ifndef PIECE_H_INCLUDED
#define PIECE_H_INCLUDED

#include <string>

#include "Point.h"
#include "Player.h"
#include "PossibleMoveMap.h"

class Game;

class Piece
{
    Game& game_;
    Player const& player_;
    Point position_;
		char short_name_;

    void setPosition(Point const& newPosition);

	protected:

    void addUntillCollision(PossibleMoveMap& result, Point const& increment) const;

		// bei jedem zu imlementieren
    virtual void validateTargetLocationReachable(Point const& newPosition) const = 0;

    // überschreibt nur springer
    virtual void validateNoPieceOnTheWay(Point const& newPosition) const;

	public:

    Piece(Game& game, Player const& player, Point const& position, char short_name);
    virtual ~Piece() throw ();

    virtual PossibleMoveMap calcPossibleMoves() const = 0;

		bool move(Point const& newPosition);

    Player const& getPlayer() const;

    Point const& getPosition() const;

    char toBoardChar() const;
    char toConsoleChar() const;

    Piece* clone(Game& game) const = 0;
};

#endif //PIECE_H_INCLUDED
