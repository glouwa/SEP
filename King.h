//------------------------------------------------------------------------------
// King.h
//
// Group: Group 4015, study assistant Manuel Weber
//
// Authors: Glatzhofer Michael (0230699)
// Hampersberger Aron (0512772)
// Ilic Filip (1130748)
//------------------------------------------------------------------------------
//
#ifndef KING_H_INCLUDED
#define KING_H_INCLUDED

#include "Piece.h"

class King : public Piece
{
	protected:

    virtual PossibleMoveMap calcPossibleMoves() const;
		virtual void validateTargetLocationReachable(Point const& newPosition) const;

	public:

	  static const char NAME = 'k';

		King(Game& game, Player& player, Point const& position);
		virtual ~King() throw();
};

#endif //KING_H_INCLUDED
