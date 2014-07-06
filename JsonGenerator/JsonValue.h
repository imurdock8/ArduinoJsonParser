/*
 * Arduino JSON library
 * Benoit Blanchon 2014 - MIT License
 */

#pragma once

#include "Printable.h"
#include "StringBuilder.h"

namespace ArduinoJson
{
    namespace Generator
    {
        class JsonValue
        {
        public:

            JsonValue()
            {
            }

            JsonValue(bool value)
                : type(JSON_BOOLEAN)
            {
                content.asBool = value;
            }

            JsonValue(double value, int digits = 2)
                : type(JSON_DOUBLE), digits(digits)
            {
                content.asDouble = value;
            }

            JsonValue(long value)
                : type(JSON_LONG)
            {
                content.asLong = value;
            }

            JsonValue(int value)
                : type(JSON_LONG)
            {
                content.asLong = value;
            }

            JsonValue(Printable& value)
                : type(JSON_PRINTABLE)
            {
                content.asPrintable = &value;
            }

            JsonValue(const char* value)
                : type(JSON_STRING)
            {
                content.asString = value;
            }

            size_t printTo(Print& p) const;

        private:

            union Content
            {
                bool        asBool;
                double      asDouble;
                long        asLong;
                Printable*  asPrintable;
                const char* asString;
            };

            enum Type
            {
                JSON_BOOLEAN,
                JSON_DOUBLE,
                JSON_LONG,
                JSON_PRINTABLE,
                JSON_STRING,
            };

            Content content;
            uint8_t type : 3;
            uint8_t digits : 5;

            size_t printStringTo(Print& p) const;
        };
    }
}