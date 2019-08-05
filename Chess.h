//------------------------------------------------------------------------------
// Chess.h
//
// Group: Group 4015, study assistant Manuel Weber
//
// Authors: Glatzhofer Michael (0230699)
// Hampersberger Aron (0512772)
// Ilic Filip (1130748)
//------------------------------------------------------------------------------
//
#ifndef CHESS_H_INCLUDED
#define CHESS_H_INCLUDED

#include <vector>

#include "Game.h"
#include "Factory.h"
#include "Color.h"

class Chess : public Game
{
	private:

		static const std::string DEFAULT_FORMATION;

    typedef std::map<char, IPieceFactory*> PieceFactoryMap;
    typedef std::pair<char, IPieceFactory*> PieceFactoryMapPair;

    //--------------------------------------------------------------------------
    // Contains all implemented cmd commands.
    // Commandname is key
    //
    PieceFactoryMap pieceFactoryMap_;

    //--------------------------------------------------------------------------
    // To avoid key to command mismatches in commandMap
    //
    template<typename TObjectType>
    inline void registerPiece()
    {
      pieceFactoryMap_.insert(PieceFactoryMapPair(tolower(TObjectType::NAME), new PieceFactory<TObjectType>()));
    }

    bool isCheck() const;
    bool isCheckMate() const;
    bool isSacrifice () const;

    bool move(Piece& piece, Point const& end);

	public:

    static const int BOARD_SIZE = 8;

		Chess();
		virtual ~Chess() throw();

		Chess(Chess const& src);
		Chess& operator=(Chess const & src);

		void load(std::string arguments = DEFAULT_FORMATION);

		virtual bool move(Point const& start, Point const& end);
		void updatePossibleMoves();

    Player const& getCurrentPlayersEnemy() const;

		Player& getPlayerFromPieceShortName(char pieceShortName) const;

		void save(std::string fileName) const;
};

#endif //CHESS_H_INCLUDED
