//------------------------------------------------------------------------------
// Rook.cpp
//
// Group: Group 4015, study assistant Manuel Weber
//
// Authors: Glatzhofer Michael (0230699)
// Hampersberger Aron (0512772)
// Ilic Filip (1130748)
//------------------------------------------------------------------------------
//
#include <cstdlib>

#include "Rook.h"
#include "SetupStringInvalidException.h"

using std::string;

Rook::Rook(Game& game, Player const& player, Point const& position) : Piece(game, player, position, NAME)
{
}

Rook::~Rook() throw()
{
}

PossibleMoveMap Rook::calcPossibleMoves() const
{
  PossibleMoveMap result;
  addUntillCollision(result, Point( 0, 1));
  addUntillCollision(result, Point( 0,-1));
  addUntillCollision(result, Point( 1, 0));
  addUntillCollision(result, Point(-1, 0));
  return result;
}

void Rook::validateTargetLocationReachable(Point const& newPosition) const
{
  int dx = abs(getPosition().getX() - newPosition.getX());
  int dy = abs(getPosition().getY() - newPosition.getY());

  if (dx != 0 && dy != 0) throw TargetLocationNotReachableException();
  if (dx == 0 && dy == 0) throw TargetLocationNotReachableException();
}
