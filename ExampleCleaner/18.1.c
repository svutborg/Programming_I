1: /* 18L01.c: Defining enum data types */
2: #include <stdio.h>
3: /* main() function */
4: main()
5: {
6: enum language {human=100,
7: animal=50,
8: computer};
9: enum days{SUN,
10: MON,
11: TUE,
12: WED,
13: THU,
14: FRI,
15: SAT};
16:
17: printf(“human: %d, animal: %d, computer: %d\n”,
18: human, animal, computer);
19: printf(“SUN: %d\n”, SUN);
20: printf(“MON: %d\n”, MON);
21: printf(“TUE: %d\n”, TUE);
22: printf(“WED: %d\n”, WED);
23: printf(“THU: %d\n”, THU);
24: printf(“FRI: %d\n”, FRI);
25: printf(“SAT: %d\n”, SAT);
26:
27: return 0;
28: }