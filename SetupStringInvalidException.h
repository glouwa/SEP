#ifndef SETUPSTRINGINVALIDEXCEPTION_H_INCLUDED
#define SETUPSTRINGINVALIDEXCEPTION_H_INCLUDED

#include <exception>
#include <string>

#include "Localization.h"


class SetupStringInvalidException : public std::exception
{
  public:
    SetupStringInvalidException();
    virtual ~SetupStringInvalidException() throw();
};

class EofException : public std::exception
{
  public:
    EofException(){}
    virtual ~EofException() throw(){}
};

class FormatException : public std::exception
{
  public:
    FormatException(){}
    virtual ~FormatException() throw(){}
};

class InvalidArgumentException : public std::exception
{
  public:
    InvalidArgumentException(){}
    virtual ~InvalidArgumentException() throw(){}
};

class MoveException : public std::exception
{
    const std::string message_;

  public:
    MoveException(std::string message) : message_(message) {}
    virtual ~MoveException() throw() {}

    inline std::string message() const { return message_; }
};

class NoPieceAtThisLocationException : public MoveException
{
  public:
    NoPieceAtThisLocationException() :
      MoveException(Localization::ERROR_NO_PIECE_AT_THIS_LOCATION) {}
    virtual ~NoPieceAtThisLocationException() throw(){}
};

class NoOwnPieceAtThisLocationException : public MoveException
{
  public:
    NoOwnPieceAtThisLocationException() :
      MoveException(Localization::ERROR_NO_OWN_PIECE_AT_THIS_LOCATION) {}
    virtual ~NoOwnPieceAtThisLocationException() throw(){}
};

class TargetLocationNotReachableException : public MoveException
{
  public:
    TargetLocationNotReachableException() :
      MoveException(Localization::ERROR_TARGET_LOCATION_NOT_REACHABLE) {}
    virtual ~TargetLocationNotReachableException() throw(){}
};

class PieceOnTheWayException : public MoveException
{
  public:
    PieceOnTheWayException() : MoveException(Localization::ERROR_PIECE_ON_THE_WAY) {}
    virtual ~PieceOnTheWayException() throw(){}
};

class OwnPieceOnTargetLocationException : public MoveException
{
  public:
    OwnPieceOnTargetLocationException() :
      MoveException(Localization::ERROR_OWN_PIECE_ON_TARGET_LOCATION)  {}
    virtual ~OwnPieceOnTargetLocationException() throw(){}
};

class NoSacraficeAllowedException : public MoveException
{
  public:
    NoSacraficeAllowedException() :
      MoveException(Localization::ERROR_NO_SACRIFICE_ALLOWED)  {}
    virtual ~NoSacraficeAllowedException() throw(){}
};

#endif // SETUPSTRINGINVALIDEXCEPTION_H_INCLUDED
