//------------------------------------------------------------------------------
// PossibleMoveMap.cpp
//
// Group: Group 4015, study assistant Manuel Weber
//
// Authors: Glatzhofer Michael (0230699)
// Hampersberger Aron (0512772)
// Ilic Filip (1130748)
//------------------------------------------------------------------------------
//
#include <cassert>

#include "PossibleMoveMap.h"
#include "Chess.h"

using std::vector;

PossibleMoveMap::PossibleMoveMap()
{
  Vector2d::size_type size = Chess::BOARD_SIZE + 1;
  possible_moves_.resize(size, vector<bool>(size, false));
}

void PossibleMoveMap::clear()
{
  for (Vector2d::size_type  x = 0; x < possible_moves_.size(); x++)
  {
    for (Vector2d::size_type  y = 0; y < possible_moves_[x].size(); y++)
    {
      possible_moves_[x][y] = false;
    }
  }
}

void PossibleMoveMap::set(Point const& possible_move)
{
  if(possible_move.isValid())
  {
    possible_moves_[possible_move.getX()][possible_move.getY()] = true;
  }
}

bool PossibleMoveMap::isSet(Point const& possible_move) const
{
  return possible_moves_[possible_move.getX()][possible_move.getY()];
}

void PossibleMoveMap::merge(PossibleMoveMap const& src)
{
  assert(possible_moves_.size() == src.possible_moves_.size());
  for (Vector2d::size_type  x = 0; x < possible_moves_.size(); x++)
  {
    assert(possible_moves_[x].size() == src.possible_moves_[x].size());
    for (Vector2d::size_type  y = 0; y < possible_moves_[x].size(); y++)
    {
      possible_moves_[x][y] = possible_moves_[x][y] || src.possible_moves_[x][y];
    }
  }
}
