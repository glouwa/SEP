#ifndef SETUPSTRINGCORRUPTEXCEPTION_H_INCLUDED
#define SETUPSTRINGCORRUPTEXCEPTION_H_INCLUDED

#include <exception>

class SetupStringCorruptException : public std::exception
{
  public:
    SetupStringCorruptException();
    virtual ~SetupStringCorruptException() throw();
};

#endif // SETUPSTRINGCORRUPTEXCEPTION_H_INCLUDED
