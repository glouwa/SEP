//------------------------------------------------------------------------------
// Chess.cpp
//
// Group: Group 4015, study assistant Manuel Weber
//
// Authors: Glatzhofer Michael (0230699)
// Hampersberger Aron (0512772)
// Ilic Filip (1130748)
//------------------------------------------------------------------------------
//
#include <sstream>
#include <assert.h>

#include "Chess.h"
#include "King.h"
#include "Rook.h"
#include "MoveCommand.h"
#include "Player.h"
#include "Localization.h"
#include "Color.h"
#include "SetupStringInvalidException.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::istringstream;
using std::ostringstream;

const string Chess::DEFAULT_FORMATION = "Ra1Ka2kc2rh8";

//------------------------------------------------------------------------------
Chess::Chess() :
  Game(Point(BOARD_SIZE, BOARD_SIZE), 0, '8', 'a', false, true)
{
  addPlayer(new WhitePlayer(*this));
  addPlayer(new BlackPlayer(*this));

  registerPiece<King>();
  registerPiece<Rook>();

  registerCommand<MoveCommand>();
}

//------------------------------------------------------------------------------
Chess::~Chess() throw()
{
}

//------------------------------------------------------------------------------
Chess::Chess(Chess const& src)
{
  *this = src;
}

//------------------------------------------------------------------------------
Chess& Chess::operator=(Chess const & src)
{
  for (int x = 0; x < BOARD_SIZE; x++)
  {
    for (int y = 0; y < BOARD_SIZE; y++)
    {
      Piece const& piece = findPiece(Point(x,y));
    }
  }
  return *this;
}

//------------------------------------------------------------------------------
void Chess::load(string formation)
{
  istringstream input_parser(formation);

  char piece_type;

  while (input_parser >> piece_type)
  {
    PieceFactoryMap::const_iterator find_result = pieceFactoryMap_.find(tolower(piece_type));

    if (find_result == pieceFactoryMap_.end())
    {
      throw InvalidArgumentException();
    }
    else
    {
      Point piece_position;
      input_parser >> piece_position;
      find_result->second->Create(*this, getPlayerFromPieceShortName(piece_type), piece_position);
    }
  }
  updatePossibleMoves();
}

//------------------------------------------------------------------------------
bool Chess::move(Point const& start, Point const& end)
{
  Piece& piece_to_move = findPiece(start);
  bool is_check_mate = false;

  if (&piece_to_move == NULL)
  {
    throw NoPieceAtThisLocationException();
  }

  if (&piece_to_move.getPlayer() != &getCurrentPlayer())
  {
    throw NoOwnPieceAtThisLocationException();
  }

  Chess peek = *this;
  peek.move(piece_to_move, end);
  if (peek.isSacrifice())
  {
    throw NoSacraficeAllowedException();
  }

  bool is_capture = move(piece_to_move, end);
  bool is_check = isCheck();
  is_check_mate = isCheckMate();

  cout << piece_to_move.toConsoleChar() << start
       << (is_capture ? "x" : "-") << end
       << (is_check ? "+" : "") << (is_check_mate ? "+" : "")
       << endl;

  nextTurn();
  return is_check_mate;
}

bool Chess::move(Piece& piece, Point const& target)
{
  bool is_capture = piece.move(target);
  updatePossibleMoves();
  return is_capture;
}

//------------------------------------------------------------------------------
void Chess::updatePossibleMoves()
{
  for (PlayerList::iterator i = players_.begin(); i != players_.end(); i++)
  {
    (*i)->getPossibleMoves().clear();

    for (int x = 0; x < BOARD_SIZE; x++)
    {
      for (int y = 0; y < BOARD_SIZE; y++)
      {
        Piece const& piece = findPiece(Point(x,y));

        if (&piece != NULL && &piece.getPlayer() == *i)
        {
          (*i)->getPossibleMoves().merge(piece.calcPossibleMoves());
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
bool Chess::isCheck() const
{
  Point const& enemyKingPosition = getCurrentPlayersEnemy().getKing().getPosition();
  return getCurrentPlayer().getPossibleMoves().isSet(enemyKingPosition);
}

//------------------------------------------------------------------------------
bool Chess::isCheckMate() const
{
  return false;


}


//------------------------------------------------------------------------------
bool Chess::isSacrifice () const
{
  Point const& kingPosition = getCurrentPlayer().getKing().getPosition();
  return getCurrentPlayersEnemy().getPossibleMoves().isSet(kingPosition);
}

//------------------------------------------------------------------------------
Player const& Chess::getCurrentPlayersEnemy() const
{
  return *players_[(getTurn() + 1)%players_.size()];
}

//------------------------------------------------------------------------------
Player& Chess::getPlayerFromPieceShortName(char pieceShortName) const
{
  for (PlayerList::const_iterator i = players_.begin(); i != players_.end(); i++)
  {
    if ((*i)->isMyPiece(pieceShortName))
    {
      return **i;
    }
  }
  assert(false);
}

//------------------------------------------------------------------------------
void Chess::save(string fileName) const
{

}

