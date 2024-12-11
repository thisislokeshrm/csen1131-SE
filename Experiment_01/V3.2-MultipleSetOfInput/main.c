#include <stdio.h>
#include <math.h>

void solve_quadratic(double a, double b, double c) {
    if (a == 0) {
        printf("Coefficient 'a' cannot be zero.\n");
        return;
    }

    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        printf("The equation has two distinct real roots.\n");
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Roots: %.2f and %.2f\n", root1, root2);
    } else if (discriminant == 0) {
        printf("The equation has one real root.\n");
        double root = -b / (2 * a);
        printf("Root: %.2f\n", root);
    } else {
        printf("The equation has no real roots.\n");
    }

    double x_value = 1.0; // Example x value
    double temp = a * x_value * x_value + b * x_value + c;
    printf("For x = %.2f, Temperature = %.2f\n", x_value, temp);
}

int main() {
    FILE *file = fopen("multiple_inputs.txt", "r");
    if (file == NULL) {
        printf("Input file not found.\n");
        return 1;
    }

    double a, b, c;
    while (fscanf(file, "%lf %lf %lf", &a, &b, &c) == 3) {
        printf("Solving for coefficients: a=%.2f, b=%.2f, c=%.2f\n", a, b, c);
        solve_quadratic(a, b, c);
        printf("--------------------------\n");
    }

    fclose(file);
    return 0;
}
