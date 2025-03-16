#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 100

struct Student {
    char name[64];
    int math;
    int phy;
    int inf;
    int total;
};

struct Student addStudent(const char *name, int math, int phy, int inf) {
    struct Student newStudent;
    strncpy(newStudent.name, name, sizeof(newStudent.name) - 1);
    newStudent.name[sizeof(newStudent.name) - 1] = '0'; 
    newStudent.math = math;
    newStudent.phy = phy;
    newStudent.inf = inf;
    newStudent.total = math + phy + inf;
    return newStudent;
}

void printStudentInfo(struct Student student) {
    printf("Имя: %s, Математика: %d, Физика: %d, Информатика: %d, Общий балл: %d\n",
           student.name, student.math, student.phy, student.inf, student.total);
}

void insertionSort(struct Student arr[], int n) {
    for (int i = 1; i < n; i++) {
        struct Student key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].total < key.total) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void generateRandomStudents(struct Student students[], int n) {
    const char *names[] = {"artem", "vova", "vika","roma","alena"};
    for (int i = 0; i < n; i++) {
        const char *name = names[rand() % 5];
        int math = rand() % 101;
        int phy = rand() % 101;
        int inf = rand() % 101;
        students[i] = addStudent(name, math, phy, inf);
    }
}

void printStudents(struct Student students[], int n) {
    for (int i = 0; i < n; i++) {
        printStudentInfo(students[i]);
    }
}

int main() {
    srand(time(NULL));
    
    struct Student students[N];
   
    generateRandomStudents(students, N);
    
    printf("Студенты до сортировки:\n");
    printStudents(students, N);
    
    clock_t start = clock();
    insertionSort(students, N);
    clock_t end = clock();
    
    printf("\nСтуденты после сортировки:\n");
    printStudents(students, N);
    
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nВремя сортировки: %f секунд\n", time_spent);
    
    system("cat /proc/cpuinfo | grep 'model name' | uniq");
    
    return 0;
}
