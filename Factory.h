#ifndef FACTORY_H_INCLUDED
#define FACTORY_H_INCLUDED

//#include "Piece.h"

class Game;
class Player;
class Piece;
class Point;

class IPieceFactory
{
  public:
    virtual Piece* Create(Game& game, Player& player, Point const& point) = 0;
};

template<typename T>
class PieceFactory : public virtual IPieceFactory
{
  public:
    virtual Piece* Create(Game& game, Player& player, Point const& point)
    {
      return new T(game, player, point);
    }
};

#endif // FACTORY_H_INCLUDED
