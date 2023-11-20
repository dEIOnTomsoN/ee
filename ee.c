#include <stdio.h>
#include <stdlib.h>

// Define the structure for a polynomial term
struct Term {
    int coefficient; // Coefficient
    int exponent;    // Exponent
    struct Term* next;
};

// Function prototypes
struct Term* create_term(int coefficient, int exponent);
void add_term(struct Term** poly, int coefficient, int exponent);
void display_poly(const char* label, const struct Term* poly);
struct Term* multiply_polynomials(const struct Term* poly1, const struct Term* poly2);
struct Term* add_polynomials(const struct Term* poly1, const struct Term* poly2);
void get_input_poly(struct Term** poly);
void free_poly(struct Term* poly);

int main() {
    struct Term* poly1 = NULL;
    struct Term* poly2 = NULL;
    struct Term* product_result = NULL;
    struct Term* sum_result = NULL;

    // Input for the first polynomial
    printf("Enter the first polynomial:\n");
    get_input_poly(&poly1);

    // Input for the second polynomial
    printf("Enter the second polynomial:\n");
    get_input_poly(&poly2);

    // Display the first and second polynomials
    display_poly("1st Polynomial", poly1);
    display_poly("2nd Polynomial", poly2);

    // (a) Multiply the polynomials
    product_result = multiply_polynomials(poly1, poly2);
    printf("Product of Polynomials: ");
    display_poly("Result", product_result);

    // (b) Add the polynomials
    sum_result = add_polynomials(poly1, poly2);
    printf("Sum of Polynomials: \n");
    display_poly("1st Polynomial", poly1);
    display_poly("2nd Polynomial", poly2);
    display_poly("Result", sum_result);

    // Manual memory deallocation
    free_poly(poly1);
    free_poly(poly2);
    free_poly(product_result);
    free_poly(sum_result);

    return 0;
}

// Function to create a new term
struct Term* create_term(int coefficient, int exponent) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    if (newTerm == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;
    return newTerm;
}

// Function to add a term to the polynomial
void add_term(struct Term** poly, int coefficient, int exponent) {
    struct Term* newTerm = create_term(coefficient, exponent);
    if (*poly == NULL) {
        *poly = newTerm;
    } else {
        struct Term* temp = *poly;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newTerm;
    }
}

// Function to display the polynomial
void display_poly(const char* label, const struct Term* poly) {
    printf("%s: ", label);
    while (poly != NULL) {
        printf("%dx^%d", poly->coefficient, poly->exponent);
        poly = poly->next;
        if (poly != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

// Function to multiply two polynomials
struct Term* multiply_polynomials(const struct Term* poly1, const struct Term* poly2) {
    struct Term* result = NULL;
    struct Term* temp = poly2;

    while (poly1 != NULL) {
        while (temp != NULL) {
            int coeff = poly1->coefficient * temp->coefficient;
            int exp = poly1->exponent + temp->exponent;

            add_term(&result, coeff, exp);
            temp = temp->next;
        }

        poly1 = poly1->next;
        temp = poly2;
    }

    return result;
}

// Function to add two polynomials
struct Term* add_polynomials(const struct Term* poly1, const struct Term* poly2) {
    struct Term* result = NULL;
    while (poly1 != NULL || poly2 != NULL) {
        int coeff1 = (poly1 != NULL) ? poly1->coefficient : 0;
        int exp1 = (poly1 != NULL) ? poly1->exponent : 0;

        int coeff2 = (poly2 != NULL) ? poly2->coefficient : 0;
        int exp2 = (poly2 != NULL) ? poly2->exponent : 0;

        int sum_coeff = coeff1 + coeff2;

        add_term(&result, sum_coeff, exp1);

        if (poly1 != NULL) poly1 = poly1->next;
        if (poly2 != NULL) poly2 = poly2->next;
    }
    return result;
}

// Function to get input polynomial from the user
void get_input_poly(struct Term** poly) {
    int num_terms;
    int coefficient, exponent;

    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &num_terms);

    for (int i = 0; i < num_terms; ++i) {
        printf("Enter coefficient for term %d: ", i + 1);
        scanf("%d", &coefficient);
        printf("Enter exponent for term %d: ", i + 1);
        scanf("%d", &exponent);

        add_term(poly, coefficient, exponent);
    }
}

// Function to free memory used by the polynomial
void free_poly(struct Term* poly) {
    while (poly != NULL) {
        struct Term* temp = poly;
        poly = poly->next;
        free(temp);
    }
}
