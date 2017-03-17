#ifndef SIMPLE_LEXER_STRINGTOKENIZER_H
#define SIMPLE_LEXER_STRINGTOKENIZER_H

#include <string>
#include <vector>

// NOTE: look at 4-12.cpp

extern class NullPointerException;

extern class NoSuchElementException;

class StringTokenizer {
private:
    int currentPosition;
    int newPosition;
    int maxPosition;
    std::string str;
    std::string delimiters;
    bool retDelims;
    bool delimsChanged;
    int maxDelimCodePoint;

    /**
     * If delimiters include any surrogates (including surrogate
     * pairs), hasSurrogates is true and the tokenizer uses the
     * different code path. This is because String.indexOf(int)
     * doesn't handle unpaired surrogates as a single character.
     */
    bool hasSurrogates{false};

    /**
     * When hasSurrogates is true, delimiters are converted to code
     * points and isDelimiter(int) is used to determine if the given
     * codepoint is a delimiter.
     */
    std::vector<int> delimiterCodePoints;

    // From Character
    static const wchar_t MIN_HIGH_SURROGATE = '\uD800';
    static const wchar_t MAX_LOW_SURROGATE = '\uDFFF';

public:
    void setMaxDelimCodePoint() {
        // delimiters == null
        if (delimiters.empty()) {
            maxDelimCodePoint = 0;
            return;
        }

        int m = 0;
        int c;
        int count = 0;
        for (int i = 0; i < delimiters.length(); i += sizeof(c)) {
            c = delimiters.at(static_cast<unsigned long>(i));
            if (c >= MIN_HIGH_SURROGATE && c <= MAX_LOW_SURROGATE) {
                c = delimiters.at(static_cast<unsigned long>(i));
                hasSurrogates = true;
            }
            if (m < c)
                m = c;
            count++;
        }
        maxDelimCodePoint = m;

        if (hasSurrogates) {
            delimiterCodePoints.resize(static_cast<unsigned long>(count));
            for (int i = 0, j = 0; i < count; i++, j += sizeof(c)) {
                c = delimiters.at(static_cast<unsigned long>(j));
                delimiterCodePoints[i] = c;
            }
        }
    }

    StringTokenizer(std::string str, std::string delim, bool returnDelims) {
        currentPosition = 0;
        newPosition = -1;
        delimsChanged = false;
        this->str = str;
        maxPosition = static_cast<int>(str.length());
        delimiters = delim;
        retDelims = returnDelims;
        setMaxDelimCodePoint();
    }

    StringTokenizer(std::string str, std::string delim) : StringTokenizer(str, delim, false) {}

private:
    int skipDelimiters(int startPos) {
        if (delimiters.empty())
            throw new NullPointerException();

        int position = startPos;
        while (!retDelims && position < maxPosition) {
            if (!hasSurrogates) {
                char c = str.at(static_cast<unsigned long>(position));
                if ((c > maxDelimCodePoint) || (delimiters.find_first_of(c) < 0))
                    break;
                position++;
            } else {
                int c = str.at(static_cast<unsigned long>(position));
                if ((c > maxDelimCodePoint) || !isDelimiter(c)) {
                    break;
                }
                position += sizeof(c);
            }
        }
        return position;
    }

    int scanToken(int startPos) {
        int position = startPos;
        while (position < maxPosition) {
            if (!hasSurrogates) {
                char c = str.at(static_cast<unsigned long>(position));
                if ((c <= maxDelimCodePoint) && (delimiters.find_first_of(c) >= 0))
                    break;
                position++;
            } else {
                int c = str.at(static_cast<unsigned long>(position));
                if ((c <= maxDelimCodePoint) && isDelimiter(c))
                    break;
                position += sizeof(c);
            }
        }
        if (retDelims && (startPos == position)) {
            if (!hasSurrogates) {
                char c = str.at(static_cast<unsigned long>(position));
                if ((c <= maxDelimCodePoint) && (delimiters.find_first_of(c) >= 0))
                    position++;
            } else {
                int c = str.at(static_cast<unsigned long>(position));
                if ((c <= maxDelimCodePoint) && isDelimiter(c))
                    position += sizeof(c);
            }
        }
        return position;
    }

    bool isDelimiter(int codePoint) {
        for (int i = 0; i < delimiterCodePoints.size(); i++) {
            if (delimiterCodePoints[i] == codePoint) {
                return true;
            }
        }
        return false;
    }

public:
    bool hasMoreTokens() {
        /*
         * Temporarily store this position and use it in the following
         * nextToken() method only if the delimiters haven't been changed in
         * that nextToken() invocation.
         */
        newPosition = skipDelimiters(currentPosition);
        return (newPosition < maxPosition);
    }

    std::string nextToken() {
        /*
         * If next position already computed in hasMoreElements() and
         * delimiters have changed between the computation and this invocation,
         * then use the computed value.
         */

        currentPosition = (newPosition >= 0 && !delimsChanged) ?
                          newPosition : skipDelimiters(currentPosition);

        /* Reset these anyway */
        delimsChanged = false;
        newPosition = -1;

        if (currentPosition >= maxPosition)
            throw new NoSuchElementException();
        int start = currentPosition;
        currentPosition = scanToken(currentPosition);
        return str.substr(static_cast<unsigned long>(start), static_cast<unsigned long>(currentPosition));
    }

    std::string nextToken(std::string delim) {
        delimiters = delim;

        /* delimiter string specified, so set the appropriate flag. */
        delimsChanged = true;

        setMaxDelimCodePoint();
        return nextToken();
    }

    bool hasMoreElements() {
        return hasMoreTokens();
    }

    std::string nextElement() {
        return nextToken();
    }

    int countTokens() {
        int count = 0;
        int currpos = currentPosition;
        while (currpos < maxPosition) {
            currpos = skipDelimiters(currpos);
            if (currpos >= maxPosition)
                break;
            currpos = scanToken(currpos);
            count++;
        }
        return count;
    }


};


#endif //SIMPLE_LEXER_STRINGTOKENIZER_H
