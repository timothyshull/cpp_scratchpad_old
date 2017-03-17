#include <iostream>
#include "student_record.h"

enum args : int {
    ARG_PROGNAME, ARG_QUIZ_1, ARG_QUIZ_2, ARG_MIDTERM, ARG_FINAL, ARG_NARGS
};

int main(int argc, char* argv[]) {
    if (argc < args::ARG_NARGS) {
        std::cerr << "Usage: ex_1 <quiz 1 grade> <quiz 2 grade> <midterm grade> <final grade>\n";
        return 1;
    }

    int q1, q2, mterm, fin;

    q1 = atoi(argv[ARG_QUIZ_1]);

    if (q1 < 0 || q1 > 10) {
        std::cerr << "Error: Grade for quiz 1 must be a grade from 0 to 10\n";
        return 1;
    }

    q2 = atoi(argv[ARG_QUIZ_2]);

    if (q2 < 0 || q2 > 10) {
        std::cerr << "Error: Grade for quiz 2 must be a grade from 0 to 10\n";
        return 1;
    }

    mterm = atoi(argv[ARG_MIDTERM]);

    if (mterm < 0 || mterm > 100) {
        std::cerr << "Error: Grade for the midterm must be a grade from 0 to 100\n";
        return 1;
    }

    fin = atoi(argv[ARG_FINAL]);

    if (fin < 0 || fin > 100) {
        std::cerr << "Error: Grade for the final must be a grade from 0 to 100\n";
        return 1;
    }

    student_record record{q1, q2, mterm, fin};

    std::cout << "The student received a final grade of: " << record.get_final_grade() << std::endl;

    return 0;
}
