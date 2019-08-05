//------------------------------------------------------------------------------
// PossibleMoveMap.h
//
// Group: Group 4015, study assistant Manuel Weber
//
// Authors: Glatzhofer Michael (0230699)
// Hampersberger Aron (0512772)
// Ilic Filip (1130748)
//------------------------------------------------------------------------------
//
#ifndef POSSIBLE_MOVE_MAP_H_INCLUDED
#define POSSIBLE_MOVE_MAP_H_INCLUDED

#include <vector>

class Point;

class PossibleMoveMap
{
    typedef std::vector<std::vector<bool> > Vector2d;

    Vector2d possible_moves_;

  public:

    PossibleMoveMap();

    void clear();
    void set(Point const& possible_move);
    bool isSet(Point const& possible_move) const;
    void merge(PossibleMoveMap const& src);
};

#endif //POSSIBLE_MOVE_MAP_H_INCLUDED
