/*
 * Arduino JSON library
 * Benoit Blanchon 2014 - MIT License
 */

#pragma once

#include "StringBuilder.h"

class IWriteable
{
public:
    virtual void writeTo(StringBuilder& sb) = 0;
};

template<typename T>
class JsonValue : IWriteable
{    
public:

   /* JsonValue(T value)
        : content(value)
    {

    }*/

    void writeTo(StringBuilder& sb);
   
private:
    JsonValue(const JsonValue& that) = delete;
    

private:

    T content;
};

class C
{
    virtual void toto() {}
};

union JsonValueBuffer
{
    C boolean;
};

