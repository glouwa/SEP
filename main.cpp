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

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;

//------------------------------------------------------------------------------
int main (int argc, char** argv)
{
  /*
  // Error: setup string invalid.
  testConfigStringException<InvalidArgumentException>("Xa1");
  testConfigStringException<InvalidArgumentException>("Ki1");
  testConfigStringException<InvalidArgumentException>("Ka9");
  testConfigStringException<FormatException>("K99");
  testConfigStringException<FormatException>("Kaa");
  testConfigStringException<InvalidArgumentException>("X");
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
  */

  if (argc > 2)
  {
    cout << Localization::ERROR_INVALID_PARAMTER_COUNT << endl;
    return -1;
  }

  try
  {
    Chess game;

    if (argc == 2)
    {
      game.load(argv[1]);
    }
    else
    {
      game.load();
    }

    game.run();
  }
  catch(std::bad_alloc const&)
  {
    cout << Localization::ERROR_OUT_OF_MEMORY << endl;
    return -2;
  }
  catch(FormatException const&)
  {
    cout << Localization::ERROR_SETUP_STRING_INVALID << endl;
    return -3;
  }
  catch(InvalidArgumentException const&)
  {
    cout << Localization::ERROR_SETUP_STRING_INVALID << endl;
    return -3;
  }
  catch(EofException const&)
  {
    cout << Localization::ERROR_SETUP_STRING_CORRUPT << endl;
    return -4;
  }

  return 0;
}

