/*
 * Arduino JSON library
 * Benoit Blanchon 2014 - MIT License
 */

#include "JsonValue.h"

using namespace ArduinoJson::Generator;

size_t JsonValue::printTo(Print& p) const
{
    switch (type)
    {
    case ArduinoJson::Generator::JsonValue::JSON_BOOLEAN:
        return p.print(content.asBool ? "true" : "false");

    case ArduinoJson::Generator::JsonValue::JSON_DOUBLE:
        return p.print(content.asDouble, digits);

    case ArduinoJson::Generator::JsonValue::JSON_LONG:
        return p.print(content.asLong);

    case ArduinoJson::Generator::JsonValue::JSON_PRINTABLE:
        if (content.asPrintable)
            return content.asPrintable->printTo(p);
        else
            return p.print("null");

    case ArduinoJson::Generator::JsonValue::JSON_STRING:
        return printStringTo(p);

    default:
        return 0;
    }    
}

size_t JsonValue::printStringTo(Print& p) const
{
    const char* s = content.asString;

    if (!s)
    {
        return p.print("null");
    }

    size_t n = 0;

    n += p.write('\"');

    while (*s)
    {
        switch (*s)
        {
        case '"':
            n += p.print("\\\"");
            break;

        case '\\':
            n += p.print("\\\\");
            break;

        case '\b':
            n += p.print("\\b");
            break;

        case '\f':
            n += p.print("\\f");
            break;

        case '\n':
            n += p.print("\\n");
            break;

        case '\r':
            n += p.print("\\r");
            break;

        case '\t':
            n += p.print("\\t");
            break;

        default:
            n += p.write(*s);
            break;
        }

        s++;
    }

    n += p.write('\"');

    return n;
}