1: /* 19L01.c Access to structure members */
2: #include <stdio.h>
3:
4: main(void)
5: {
6: struct computer {
7: float cost;
8: int year;
9: int cpu_speed;
10: char cpu_type[16];
11: } model;
12:
13: printf(“The type of the CPU inside your computer?\n”);
14: gets(model.cpu_type);
15: printf(“The speed(MHz) of the CPU?\n”);
16: scanf(“%d”, &model.cpu_speed);
17: printf(“The year your computer was made?\n”);
18: scanf(“%d”, &model.year);
19: printf(“How much you paid for the computer?\n”);
20: scanf(“%f”, &model.cost);
21:
22: printf(“Here are what you entered:\n”);
23: printf(“Year: %d\n”, model.year);
24: printf(“Cost: $%6.2f\n”, model.cost);
25: printf(“CPU type: %s\n”, model.cpu_type);
26: printf(“CPU speed: %d MHz\n”, model.cpu_speed);
27:
28: return 0;
29: }