#include "Piece.h"
#include "Game.h"
#include "Color.h"
#include "SetupStringInvalidException.h"

Piece::Piece(
  Game& game,
  Player const& player,
  Point const& position,
  char short_name) :
game_(game),
player_(player),
position_(position),
short_name_(short_name)
{
  setPosition(position);
}

Piece::~Piece() throw()
{
}

void Piece::addUntillCollision(PossibleMoveMap& result, Point const& increment) const
{
  Point current_location = getPosition() + increment;

  while (current_location.isValid())
  {
    Piece& pieceOnTargetLocation = game_.findPiece(current_location);

    if(&pieceOnTargetLocation != NULL)
    {
      if (&pieceOnTargetLocation.getPlayer() != &getPlayer())
      {
        result.set(current_location);
      }

      break;
    }

    result.set(current_location);
    current_location += increment;
  }

  //addUntillCollision(result, increment * -1);
}

void Piece::validateNoPieceOnTheWay(Point const& newPosition) const
{
}

bool Piece::move(Point const& newPosition)
{
  validateTargetLocationReachable(newPosition);
  validateNoPieceOnTheWay(newPosition);

  Piece& pieceOnTargetLocation = game_.findPiece(newPosition);

  if(&pieceOnTargetLocation != NULL &&
     &pieceOnTargetLocation.getPlayer() == &getPlayer())
  {
    throw OwnPieceOnTargetLocationException();
  }

  setPosition(newPosition);
  return &pieceOnTargetLocation != NULL;
}

void Piece::setPosition(Point const& newPosition)
{
  game_.pieces_[getPosition().getX()][getPosition().getY()] = NULL;
  position_ = newPosition;
  game_.pieces_[getPosition().getX()][getPosition().getY()] = this;
}

Point const& Piece::getPosition() const
{
  return position_;
}

Player const& Piece::getPlayer() const
{
  return player_;
}

char Piece::toBoardChar() const
{
  return player_.getPlayersPieceShortName(short_name_);
}

char Piece::toConsoleChar() const
{
  return toupper(short_name_);
}
