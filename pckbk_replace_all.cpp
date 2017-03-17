//
// Created by Tim Shull on 10/23/16.
//

//import os, sys
//nargs = len(sys.argv)
//if not 3 <= nargs <= 5:
//print "usage: %s search_text replace_text [infile [outfile]]" % \
//        os.path.basename(sys.argv[0])
//else:
//stext = sys.argv[1]
//rtext = sys.argv[2]
//input_file = sys.stdin
//output_file = sys.stdout
//if nargs > 3:
//input_file = open(sys.argv[3])
//if nargs > 4:
//output_file = open(sys.argv[4], 'w')
//for s in input_file:
//        output_file.write(s.replace(stext, rtext))
//output.close()
//input.close()

#include <fstream>
#include <sstream>
#include "util.h"

// TODO:
int main(int argc, char *argv[]) {
    std::ifstream in{argv[1]};
    std::ofstream out{argv[2]};

    std::stringstream iss;
    iss << in.rdbuf();
    std::string contents{iss.str()};

    util::replace_all(contents, "the", "replacement_for_the");
    out << contents;

    in.close();
    out.close();
    return 0;
}
