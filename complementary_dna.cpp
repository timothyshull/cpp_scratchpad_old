#include <map>
#include <cassert>
#include <string>

std::string DNAStrand(const char* dna)
{
    static std::map<char, char> comps{{'A', 'T'}, {'T', 'A'}, {'C', 'G'}, {'G', 'C'}};
    std::string res;
    for (int i{0}; dna[i] != '\0'; ++i) { res += comps[dna[i]]; }
    return res;
}

std::string DNAStrand(std::string dna)
{
    static std::map<char, char> comps{{'A', 'T'}, {'T', 'A'}, {'C', 'G'}, {'G', 'C'}};
    std::string res;
    for (auto c : dna) { res += comps[c]; }
    return res;
}

// NOTE: many people reuse dna for output since it was passed by value but the kata was wrong (no input type)

int main() {
    assert(DNAStrand("AAAA") == "TTTT");
    assert(DNAStrand("ATTGC") == "TAACG");
    assert(DNAStrand("GTAT") == "CATA");
    return 0;
}