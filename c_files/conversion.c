/* Conversion utility functions for units and number representations */
#include <stdio.h>
#include <string.h>

float celsius_to_fahrenheit(float c) {
    return c * 9 / 5 + 32;
}

float fahrenheit_to_celsius(float f) {
    return (f - 32) * 5 / 9;
}

float km_to_miles(float km) {
    return km * 0.621371;
}

float miles_to_km(float mi) {
    return mi / 0.621371;
}

float meters_to_feet(float m) {
    return m * 3.28084;
}

float feet_to_meters(float ft) {
    return ft / 3.28084;
}

float kg_to_pounds(float kg) {
    return kg * 2.20462;
}

float pounds_to_kg(float lb) {
    return lb / 2.20462;
}

void int_to_binary(int n, char *out) {
    out[0] = 0;
    for (int i = 31; i >= 0; i--) {
        strcat(out, ((n >> i) & 1) ? "1" : "0");
    }
}

int binary_to_int(const char *bin) {
    int n = 0;
    for (int i = 0; bin[i]; i++) {
        n = n * 2 + (bin[i] - '0');
    }
    return n;
}

void print_results() {
    char bin[33];
    int_to_binary(10, bin);
    printf("10 in binary: %s\n", bin);
    printf("Celsius 0 to F: %.2f\n", celsius_to_fahrenheit(0));
    printf("100 pounds to kg: %.2f\n", pounds_to_kg(100));
}

int main() {
    print_results();
    return 0;
} 