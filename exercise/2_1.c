#include <stdio.h>

int main() {
	// int cm;
	// scanf("%d", &cm);
	// int foot = cm / 30.48;
	// int inch = (cm/30.48 - foot) * 12;
	// printf("%d %d", foot, inch);

    int cm = 0;
    scanf("%d", &cm);

    float m = cm/100.00;
    int inch = m/0.3048;
    int foot = (m/0.3048 - inch) * 12;

    printf("%d %d", inch, foot);
    
    return 0;
}