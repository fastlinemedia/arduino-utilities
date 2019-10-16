#include "QueryString.h"

void QueryString::parse(String query, void (*handleVar)(String, String)) {
    int queryLength = query.length() + 1;
    char charArray[queryLength];
    String key = "";
    String value = "";
    bool inKey = false;
    bool inValue = false;

    query.toCharArray(charArray, queryLength);

    for (int i = 0; i < queryLength; i++) {

        if (charArray[ i ] == '?') {
            inKey = true;
            continue;
        } else if (charArray[ i ] == '=') {
            inKey = false;
            inValue = true;
            continue;
        } else if (charArray[ i ] == '&') {
            handleVar(key, value);
            inKey = true;
            inValue = false;
            key = "";
            value = "";
            continue;
        }

        if (inKey) {
            key += charArray[i];
        } else if (inValue) {
            value += charArray[i];
        }
    }

    handleVar(key, value);
}
