#include <stdio.h>
#include <float.h>
#include <math.h>
// Compute first deriative numerically
long double derive(long double (*f)(long double), long double x0) {
    long double h = 1e-6;
    long double res = (f(x0 + h) - f(x0)) / h;
    return res;
}
// Compute second deriative numerically
long double derive_2(long double (*f)(long double), long double x0) {
    long double h = 1e-6;
    long double res = (f(x0 + h) - 2*f(x0) + f(x0 - h)) / (h*h);
    return res;
}
long double func_23(long double x) {
 // e^x + ln(x) - 10x = 0
 return 3*x - 4 * logl(x) - 5;
}
long double func_23_deriative_1(long double x) {
 return 3 - 4/x;
}
long double func_23_deriative_2(long double x) {
 return 4/powl(x, 2);
}
// Returns 1 if method is covergent, otherwise 0
int is_newton_covergent(
    long double (*f)(long double),
    long double (*deriative_1)(long double),
    long double (*deriative_2)(long double),
    long double a,
    long double b) {
    int flag = 1;
    long double step = (b-a)/1000;
 for (long double x=a; x<=b; x+=step) {
    if (fabsl(f(x) * derive_2(f, x)) >= powl(derive(f, x), 2)) {
        flag = 0;
    }
    if (fabsl(f(x) * deriative_2(x)) >= powl(deriative_1(x), 2)) {
        flag = 0;
    }
 }
 return flag;
}
// Computes newton method using analytic deriative
long double newton_analytic(
 long double (*f)(long double),
 long double (*deriative)(long double),
 long double a,
 long double b) {
 long double x = (a+b)/2;
 long double x_next = x - f(x) / deriative(x);
 while (fabsl(x_next - x) >= LDBL_EPSILON) {
 x = x_next;
  x_next = x - f(x) / deriative(x);
 }
 return x_next;
}
// Computes newton method using numeric deriative
long double newton_numeric(
 long double (*f)(long double),
 long double a,
 long double b) {
 long double x = (a+b)/2;
 long double x_next = x - f(x) / derive(f, x);
 while (fabsl(x_next - x) >= LDBL_EPSILON) {
 x = x_next;
 x_next = x - f(x) / derive(f, x);
 }
 return x_next;
}
long double func_22(long double x) {
    return cosl(sqrtl(1-0.3*powl(x, 3)));
}

long double func_22_hands(long double x) {
    return (9*sqrtl(10)*powl(x, 2)*sinl(sqrtl( (10-3*powl(x, 3))/(10) )))/(20*sqrtl(10-3*powl(x, 3)));
}
// Returns 1 if method is covergent, otherwise 0
int is_iteration_covergent(
 long double (*f)(long double),
 long double (*deriative)(long double),
 long double a,
 long double b) {
 int flag = 1;
 long double step = (b-a)/1000;
 for (long double x=a; x<=b; x+=step) {
 if (derive(f, x) >= 1 || deriative(x) >= 1) {
 flag = 0;
 }
 }
 return flag;
}
// Computes iterations method
long double iterations(
 long double (*f)(long double),
 long double a,
 long double b) {
 long double x = (a+b)/2;
 long double x_next = f(x);
 while (fabsl(x_next - x) >= LDBL_EPSILON) {
 x = x_next;
 x_next = f(x);
 }
 return x_next;
}
int main() {
 long double a = 2, b = 4;
 printf("Function 23\nMethod: newton.\n");
 if (is_newton_covergent(func_23, func_23_deriative_1, func_23_deriative_2, a, b)) {
    printf("Method is covergent.\n");
 long double root_analytic = newton_analytic(func_23, func_23_deriative_1, a, b);
 long double root_numeric = newton_numeric(func_23, a, b);
 printf("Approximated root of the equation:\n");
 printf("\tAnalytic: %.19Lf\n\tNumeric: %.19Lf\n", root_analytic, root_numeric);
 long double res_analytic = func_23(root_analytic);
 long double res_numeric = func_23(root_numeric);
 printf("Inserting root in the equation:\n");
 printf("\tAnalytic: %.19Lf\n\tNumeric: %.19Lf\n", res_analytic, res_numeric);
 } else {
 printf("Method is not covergent.\n");
 }
 putchar('\n');
 a = 0;
 b = 1;
 printf("Function 22\nMethod: iterations.\n");
 if (is_iteration_covergent(func_22, func_22_hands, a, b)) {
 printf("Method is covergent.\n");
 long double root = iterations(func_22, a, b);
 printf("Approximated root of the equation: %.19Lf\n", root);
 long double res = root - 2 + sinl(1/root);
 printf("Inserting root in the equation: %.19Lf\n", res);
 } else {
 printf("Method is not covergent.\n");
 }
 return 0;
}