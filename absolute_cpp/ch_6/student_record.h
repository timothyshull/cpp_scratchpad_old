//
// Created by Timothy Shull on 2/14/16.
//

#ifndef ABSOLUTE_CPP_STUDENT_RECORD_H
#define ABSOLUTE_CPP_STUDENT_RECORD_H


struct student_record {
    int quiz_1{0};
    int quiz_2{0};
    int midterm{0};
    int final{0};

    student_record(int q1, int q2, int mterm, int fin);

    double get_final_grade();
};


#endif //ABSOLUTE_CPP_STUDENT_RECORD_H
