//------------------------------------------------------------------------------
// King.cpp
//
// Group: Group 4015, study assistant Manuel Weber
//
// Authors: Glatzhofer Michael (0230699)
// Hampersberger Aron (0512772)
// Ilic Filip (1130748)
//------------------------------------------------------------------------------
//
#include <cstdlib>

#include "King.h"
#include "SetupStringInvalidException.h"

using std::string;

King::King(Game& game, Player& player, Point const& position) : Piece(game, player, position, NAME)
{
  player.setKing(*this);
}

King::~King() throw()
{
}

PossibleMoveMap King::calcPossibleMoves() const
{
  PossibleMoveMap result;
  result.set(getPosition() + Point(-1, 1));
  result.set(getPosition() + Point(-1, 0));
  result.set(getPosition() + Point(-1,-1));
  result.set(getPosition() + Point( 0,-1));
  result.set(getPosition() + Point( 1,-1));
  result.set(getPosition() + Point( 1, 0));
  result.set(getPosition() + Point( 1, 1));
  result.set(getPosition() + Point( 0, 1));
  return result;
}

void King::validateTargetLocationReachable(Point const& newPosition) const
{
  int dx = abs(getPosition().getX() - newPosition.getX());
  int dy = abs(getPosition().getY() - newPosition.getY());

  if (dx > 1 || dy > 1) throw TargetLocationNotReachableException();
  if (dx == 0 && dy == 0) throw TargetLocationNotReachableException();
}
