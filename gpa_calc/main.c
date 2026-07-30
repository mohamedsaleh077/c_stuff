#include <stdio.h>

int main(){
    int subjects = 0;
    float allHours = 0;

    printf("how much subjects?\n");
    scanf("%d", &subjects);

    printf("total hours?\n");
    scanf("%f", &allHours);

    float subjectHours[subjects];
    float subjectGrade[subjects];

    float totalPoints = 0;

    for(int i = 0; i < subjects; i++){
        printf("subject gain hours %d ?\n", i);
        scanf("%f", &subjectHours[i]);
        printf("subject grade %d ?\n", i);
        scanf("%f", &subjectGrade[i]);
        totalPoints += subjectHours[i] * subjectGrade[i];
    }

    float gpa = totalPoints / allHours;
    printf("your GPA is %.3f", gpa);
}