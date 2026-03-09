#ifndef MAIN_HPP
#define MAIN_HPP

// In this file, all implementations should be done with pointers, not arrays, [ ]
// If there is any bracket [, ], your test will fail

#include <iostream>
#include <string>
#include <iomanip>
#include <numeric>
using namespace std;

#define NUM_SCORES 5
#define NUM_STUDENTS 10

struct Student{
    string name;
    int age;
    double scores[NUM_SCORES];
};

void sortScores(double *scores);
void insertOne(double *scores, int index);
void printStudents(Student *students);
void sortStudents(Student *students, int sortKey);
void insertStudent(Student *students, int index, int sortKey);

void insertOne(double *scores, int index){
    double key = *(scores + index);
    int i = index - 1;
    while(i >= 0 && *(scores + i) > key){
        *(scores + i + 1) = *(scores + i);
        i--;
    }
    *(scores + i + 1) = key;
}

// TODO: Sort scores in ascending order using insertion sort (use pointer arithmetic, no brackets)
void sortScores(double *scores){
    // TODO: Sort scores in ascending order using insertion sort (use pointer arithmetic, no brackets)
    for (int i = 0; i < NUM_SCORES; i++){
        insertOne(scores, i);
    }

}

bool keyCompare(Student a, Student b, int sortKey){
    if(sortKey == 0)
        return a.name > b.name;
    else if(sortKey == 1)
        return a.age > b.age;
    else if (sortKey == 2)
        return accumulate(a.scores, a.scores + NUM_SCORES, 0.0) > accumulate(b.scores, b.scores + NUM_SCORES, 0.0);
    return a.age < b.age;
}

void insertStudent(Student *students, int index, int sortKey){
    Student key = *(students + index);
    int i = index - 1;
    while(i >= 0 && keyCompare(*(students + i), key, sortKey)){
        *(students + i + 1) = *(students + i);
        i--;
    }
    *(students + i + 1) = key;
}

void sortStudents(Student *students, int sortKey){
    for(int i=1; i<NUM_STUDENTS; i++){
        insertStudent(students, i, sortKey);
    }
}

void printStudents(Student *students){
    for(int i=0; i<NUM_STUDENTS; i++){
        cout << setw(10) << (students + i)->name << " " << setw(5) << (students + i)->age << "\t";
        for(int j=0; j<NUM_SCORES; j++){
            cout << fixed << setprecision(2) << *((students + i)->scores+j) << " ";
        }
        cout << "\t\tSum: " << accumulate((students + i)->scores, (students + i)->scores + NUM_SCORES, 0.0) << endl;
    }
}

#endif
