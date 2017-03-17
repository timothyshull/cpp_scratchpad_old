#ifndef TEST_REGEX_SIGNATURES_H
#define TEST_REGEX_SIGNATURES_H

// Check full match of regex
bool regex_match(str, regex);
bool regex_match(str, regex, flags);
bool regex_match(beg, end, regex);
bool regex_match(beg, end, regex, flags);

// Check and return full match of regex
bool regex_match(str, matchRet, regex);
bool regex_match(str, matchRet, regex, flags);
bool regex_match(beg, end, matchRet, regex);
bool regex_match(beg, end, matchRet, regex, flags);

// Search match of regex
bool regex_search(str, regex);
bool regex_search(str, regex, flags);
bool regex_search(beg, end, regex);
bool regex_search(beg, end, regex, flags);

// Search and return match of regex
bool regex_search(str, matchRet, regex);
bool regex_search(str, matchRet, regex, flags);
bool regex_search(beg, end, matchRet, regex);
bool regex_search(beg, end, matchRet, regex, flags);

// Replace match(es) according to regex
strRes regex_replace(str, regex, repl);
strRes regex_replace(str, regex, repl, flags);
outPos regex_replace(outPos, beg, end, regex, repl);
outPos regex_replace(outPos, beg, end, regex, repl, flags);

#endif //TEST_REGEX_SIGNATURES_H
