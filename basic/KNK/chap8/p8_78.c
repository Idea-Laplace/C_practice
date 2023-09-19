#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define QUIZ 5
#define STUDENTS 5

int main (void) {
	bool loop = true;

	while (loop) {
		int score[QUIZ][STUDENTS];

		for (int i = 0; i < QUIZ; ++i) {
			printf("Enter %d scores for quiz %d: ", STUDENTS, i + 1);
			for (int j = 0; j < STUDENTS; ++j)
				scanf("%d", &score[i][j]);
		}
		getchar();
		
		printf("\n");
		for (int j = 0; j < STUDENTS; ++j) {
			float student_info = 0;
			for (int i = 0; i < QUIZ; ++i)
				student_info += score[i][j];
			printf("Score information of student %d: total %3.1f, average %3.1f\n",\
					j + 1, student_info, student_info / QUIZ);
		}

		printf("\n");
		for (int i = 0; i < QUIZ; ++i) {
			float quiz_average = 0;
			int highest, lowest;
			highest = lowest = score[i][0];
			for (int j = 0; j < STUDENTS; ++j) {
				quiz_average += score[i][j];
				if (highest < score[i][j])
					highest = score[i][j];
				if (lowest > score[i][j])
					lowest = score[i][j];
			}
			quiz_average = quiz_average / STUDENTS;
			printf("Score information of quiz %d: average %3.1f, highest %d, lowest %d\n",\
					i + 1, quiz_average, highest, lowest);
		}

		// Loop decision
		char reply;
		do {
			printf("Loop this program?(y/n): ");
			reply = getchar();
			getchar();

			switch (reply) {
				case 'y': printf("\n=========================\n"); break;
				case 'n': printf("Program terminated.\n"); loop = false; break;
				default : printf("Type y or n.\n"); break;
			}
		} while (reply != 'y' && reply != 'n');
	}
	system("pause");
	return 0;
}
