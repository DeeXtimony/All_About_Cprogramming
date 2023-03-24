#include <stdio.h>

int main() {
    float units, total_bill;

    printf("Enter the total units consumed: ");
    scanf("%f", &units);

    if (units <= 50) {
        total_bill = units * 0.50;
    } else if (units <= 150) {
        total_bill = 25 + ((units - 50) * 0.75);
    } else if (units <= 250) {
        total_bill = 100 + ((units - 150) * 1.20);
    } else {
        total_bill = 220 + ((units - 250) * 1.50);
    }

    // add fixed charges
    total_bill += 50;

    printf("Total bill = %.2f\n", total_bill);

    return 0;
}

