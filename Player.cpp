//------------------------------------------------------------------------------
// Player.cpp
//
// Group: Group 4015, study assistant Manuel Weber
//
// Authors: Glatzhofer Michael (0230699)
// Hampersberger Aron (0512772)
// Ilic Filip (1130748)
//------------------------------------------------------------------------------
//
#include <iostream>
#include <string>

#include "Player.h"
#include "Chess.h"

using std::vector;

//------------------------------------------------------------------------------
Player::Player(Game const& game, Color const& color) :
  game_(game),
  color_(color),
  name_(Tools::getColorName(color))
{
}

//------------------------------------------------------------------------------
Player::Player(Game const& game, Color const& color, std::string const& name) :
  game_(game),
  color_(color),
  name_(name)
{
}

//------------------------------------------------------------------------------
Player::~Player()
{
}

//------------------------------------------------------------------------------
std::string Player::getFullName() const
{
  return name_ + "(" + Tools::getColorName(color_) + ")";
}

//------------------------------------------------------------------------------
Color Player::getColor() const
{
  return color_;
}

//------------------------------------------------------------------------------
std::string Player::getName() const
{
  return name_;
}

//------------------------------------------------------------------------------
void Player::setColor(Color const& color)
{
  color_ = color;
}

//------------------------------------------------------------------------------
void Player::setName(std::string const& name)
{
  name_ = name;
}

//------------------------------------------------------------------------------
void Player::setKing(Piece& king)
{
  king_ = &king;
}

//------------------------------------------------------------------------------
Piece const& Player::getKing() const
{
  return *king_;
}

//------------------------------------------------------------------------------
BlackPlayer::BlackPlayer(Game const& game) : Player(game, BLACK)
{
}

//------------------------------------------------------------------------------
bool BlackPlayer::isMyPiece(char pieceShortName) const
{
  return islower(pieceShortName);
}

//------------------------------------------------------------------------------
char BlackPlayer::getPlayersPieceShortName(char pieceShortName) const
{
  return tolower(pieceShortName);
}

//------------------------------------------------------------------------------
WhitePlayer::WhitePlayer(Game const& game) : Player(game, WHITE)
{
}

//------------------------------------------------------------------------------
bool WhitePlayer::isMyPiece(char pieceShortName) const
{
  return isupper(pieceShortName);
}

//------------------------------------------------------------------------------
char WhitePlayer::getPlayersPieceShortName(char pieceShortName) const
{
  return toupper(pieceShortName);
}
