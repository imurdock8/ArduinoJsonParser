/*
 * Arduino JSON library
 * Benoit Blanchon 2014 - MIT License
 */

#include "JsonValue.h"
#include "JsonObjectBase.h"

void JsonValue<bool>::writeTo(StringBuilder& sb)
{
    sb.append(content ? "true" : "false");
}


void JsonValue<double>::writeTo(StringBuilder& sb)
{
    sb.append(content);
}

void JsonValue<JsonObjectBase*>::writeTo(StringBuilder& sb)
{
    if (content)
        ((JsonObjectBase*) content)->writeTo(sb);
    else
        sb.append("null");
}

void JsonValue<const char*>::writeTo(StringBuilder& sb)
{
    sb.appendEscaped(content);
}