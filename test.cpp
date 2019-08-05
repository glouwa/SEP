//------------------------------------------------------------------------------
// Filename: main.cpp
// Description: Main program
// Authors: Tutors
// Tutor: Tutors
// Group: 42
// Created: 08.08.2011
// Last change: 08.08.2011
//------------------------------------------------------------------------------

#include "Player.h"
#include "Chess.h"
#include "Localization.h"
#include "SetupStringInvalidException.h"
#include "SetupStringCorruptException.h"
#include "MoveCommand.h"

#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

using std::cout;
using std::endl;
using std::vector;
using std::string;

template <typename Texception>
void testConfigStringException(std::string cfgstr)
{
  try
  {
    Chess game;
    game.load(cfgstr);
    std::cout << cfgstr << ": no exception" << endl;
  }
  catch(Texception const&)
  {
    std::cout << cfgstr << ": OK" << endl;
  }
  catch(std::exception const& e)
  {
    std::cout << cfgstr << ": wrong exception '" << typeid(e).name() << "'" << endl;
  }
  catch(...)
  {
    std::cout << cfgstr << ": wrong exception '...'" << endl;
  }
}

template <typename Texception>
void testMoveException(std::string start, std::string end)
{
  try
  {
    Chess game;
    game.load("Ka1kh8");
    MoveCommand cmd;
    vector<string> params;
    params.push_back(start);
    params.push_back(end);
    std::cout << start << " " << end << " ";
    cmd.execute(game, params);
  }
  catch(...)
  {
    std::cout << start << "->" << end << ": wrong exception '...'" << endl;
  }
}

//------------------------------------------------------------------------------
void test()
{
  // Error: setup string invalid.
  testConfigStringException<SetupStringInvalidException>("Xa1");
  testConfigStringException<InvalidArgumentException>("Ki1");
  testConfigStringException<InvalidArgumentException>("Ka9");
  testConfigStringException<FormatException>("K99");
  testConfigStringException<FormatException>("Kaa");
  testConfigStringException<SetupStringInvalidException>("X");
  testConfigStringException<InvalidArgumentException>("Ki");
  testConfigStringException<InvalidArgumentException>("Ka9K");

  // Error: setup string corrupt.
  testConfigStringException<EofException>("K");
  testConfigStringException<EofException>("Ka");
  testConfigStringException<EofException>("Ka1K");

  // Usage: move startlocation endlocation.
  testMoveException<FormatException>("a", "a2");
  testMoveException<FormatException>("a", "b");
  testMoveException<FormatException>("a", "b3");

  // Error: Incorrect starting location.
  testMoveException<InvalidArgumentException>("a9", "a1");
  testMoveException<InvalidArgumentException>("i1", "a1");

  // Error: Incorrect target location.
  testMoveException<InvalidArgumentException>("a1", "a9");
  testMoveException<InvalidArgumentException>("a1", "i1");
}

