//------------------------------------------------------------------------------
// Rook.h
//
// Group: Group 4015, study assistant Manuel Weber
//
// Authors: Glatzhofer Michael (0230699)
// Hampersberger Aron (0512772)
// Ilic Filip (1130748)
//------------------------------------------------------------------------------
//
#ifndef ROOK_H_INCLUDED
#define ROOK_H_INCLUDED

#include "Piece.h"

class Rook : public Piece
{
	protected:

    virtual PossibleMoveMap calcPossibleMoves() const;
		virtual void validateTargetLocationReachable(Point const& newPosition) const;

	public:

	  static const char NAME = 'r';

		Rook(Game& game, Player const& player, Point const& position);
		virtual ~Rook() throw();
};

#endif //ROOK_H_INCLUDED
