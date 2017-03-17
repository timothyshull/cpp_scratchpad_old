#include "student_record.h"

student_record::student_record(int q1, int q2, int mterm, int fin) : quiz_1{q1}, quiz_2{q2}, midterm{mterm},
                                                                     final{fin} { }

double student_record::get_final_grade() {
    return (.125 * (static_cast<double>(quiz_1) / 100.0)) + (.125 * (static_cast<double>(quiz_2) / 100.0)) +
           (.125 * (static_cast<double>(midterm) / 100.0)) + (.125 * (static_cast<double>(final) / 100.0));
}
