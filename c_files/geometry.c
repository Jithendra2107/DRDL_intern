/* Geometry utility functions for basic geometric calculations */
#include <stdio.h>
#include <math.h>

double area_circle(double r) {
    return M_PI * r * r;
}

double area_rectangle(double w, double h) {
    return w * h;
}

double area_triangle(double b, double h) {
    return 0.5 * b * h;
}

double perimeter_rectangle(double w, double h) {
    return 2 * (w + h);
}

double circumference(double r) {
    return 2 * M_PI * r;
}

double distance(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

void midpoint(double x1, double y1, double x2, double y2, double *mx, double *my) {
    *mx = (x1 + x2) / 2;
    *my = (y1 + y2) / 2;
}

double slope(double x1, double y1, double x2, double y2) {
    if (x2 - x1 == 0) {
        return 0;
    }
    return (y2 - y1) / (x2 - x1);
}

int is_colinear(double x1, double y1, double x2, double y2, double x3, double y3) {
    double area = (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
    return area == 0;
}

int is_right_triangle(double a, double b, double c) {
    return (a * a + b * b == c * c) ||
           (a * a + c * c == b * b) ||
           (b * b + c * c == a * a);
}

void print_results() {
    printf("Area of circle (r=2): %.2f\n", area_circle(2));
    printf("Distance (0,0)-(3,4): %.2f\n", distance(0, 0, 3, 4));
    printf("Is right triangle (3,4,5): %d\n", is_right_triangle(3, 4, 5));
}

int main() {
    print_results();
    return 0;
} 