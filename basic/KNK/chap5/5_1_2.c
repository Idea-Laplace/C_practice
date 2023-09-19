#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// This program involves solutions of the problem 5-1
int main(void){
    
    int answer, prob_num, sub_char, reply;
    bool loop = true, subloop;

    while (loop){
        subloop = true;
        printf("You can choose a problem with a form of [problem_number]-[alphabet], ex) 1-a\n");
        printf("The problem ranges from 1 to 2, while the alphabets ranges from a to d.\n\n");
        printf("Choose which you want to solve: ");
        scanf("%d -", &prob_num);
        sub_char = getchar();
        getchar(); 

        switch (prob_num){
            case 1:
                switch (sub_char){
                    case 'a':
                        while (subloop){
                            printf("1-a) The value of 2*3==6 is: ");
                            scanf("%d", &answer);
                            getchar();

                            if (answer == (2*3==6)){
                                printf("%d, correct.\n\n", answer);
                                subloop = false;
                            }
                            else
                                printf("Wrong, \'*\' precedes \'=\', and \'=\' precedes \'==\'. Try again.\n");
                        }
                        subloop = true;
                        break;

                    case 'b':
                        while (subloop){
                            printf("1-b) The value of 1 > 5 < 10 is: ");
                            scanf("%d", &answer);
                            getchar();

                            if (answer == 1>5<10){
                                printf("%d, correct.\n\n", answer);
                                subloop = false;
                            }
                            else
                                printf("Wrong, relational operators are left associative. Try again.\n");
                        }
                        subloop = true;
                        break;

                    case 'c':
                        while (subloop){
                            printf("1-c) The value of 3<2 == 2<1 is: ");
                            scanf("%d", &answer);
                            getchar();

                            if (answer == (3<2 == 2<1)){
                                printf("%d, correct.\n\n", answer);
                                subloop = false;
                            }
                            else
                                printf("Wrong, relational operators precede \'==\'. Try again.\n");
                        }
                        subloop = true;
                        break;

                    case 'd':
                        while (subloop){
                            printf("1-d) The value of 3%%4+3 < 5 is: ");
                            scanf("%d", &answer);
                            getchar();

                            if (answer == 3%4+3<5){
                                printf("%d, correct.\n\n", 3%4+3<5);
                                subloop = false;
                            }
                            else
                                printf("Wrong, arithmetic operators precede relational operators. Try again.\n");
                        }
                        subloop = true;
                        break;

                    default : printf("Wrong input."); break;
                }
                break;

            case 2:
                switch (sub_char){
                    case 'a':
                        while (subloop){
                            printf("2-a) The value of !10 < 5 is: ");
                            scanf("%d", &answer);
                            getchar();

                            if (answer == !10<5){
                                printf("%d, correct\n\n", answer);
                                subloop = false;
                            }
                            else
                                printf("Wrong, \'!\' has same presedence with that of unary operators.\
                                        Try again.\n");
                        }
                        subloop = true;
                        break;

                    case 'b':
                        while (subloop){
                            printf("2-b) The value of !!2 + !1 is: ");
                            scanf("%d", &answer);
                            getchar();

                            if (answer == !!2 + !1){
                                printf("%d, correct.\n\n", answer);
                                subloop = false;
                            }
                            else
                                printf("Wrong, \'!\' has same presedence with that of unary operators.\
                                        Try again.\n");
                        }
                        subloop = true;
                        break;

                    case 'c':
                        while (subloop){
                            printf("2-c) The value of 5 && 0 || -5 is: ");
                            scanf("%d", &answer);
                            getchar();

                            if (answer == (5 && 0 || -5)){
                                printf("%d, correct.\n\n", answer);
                                subloop = false;
                            }
                            else
                                printf("Wrong, binary logical operators are l-associative and perform short circuit.\
                                        Try again.\n");
                        }
                        subloop = true;
                        break;

                    case 'd':
                        while (subloop){
                            printf("2-d) The value of 1<2||3 is: ");
                            scanf("%d", &answer);
                            getchar();

                            if (answer == (1<2||3)){
                                printf("%d, correct.\n\n", answer);
                                subloop = false;
                            }
                            else
                                printf("Wrong, relational operators precede binary logical operators. Try again.\n");
                        }
                        subloop = true;
                        break;

                    default : printf("Wrong input."); break;
                }
                break;

            default: printf("Wrong input."); break;
        }

        while (subloop){
            printf("Do you want to solve other problems?(y/n): ");
            reply = getchar();
            getchar();

            if (reply == 'y'){
                subloop = false;
                printf("\n==========================================================================\n");
            }
            else if (reply == 'n'){
                subloop = false;
                loop = false;
                printf("[Program terminated.]\n");
                printf("\n==========================================================================\n");
            }
            else
                printf("Type y or n.\n");
        }

    }
    system("pause");
    return 0;
}
