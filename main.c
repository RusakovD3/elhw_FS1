#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename[] = "user_input.txt"; 
    char input[256];

    printf("Enter a line to write to the file: ");
    fgets(input, sizeof(input), stdin);

    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error creating the file!\n");
        return EXIT_FAILURE;
    }
    else {
        fprintf(file, "%s", input);
        fclose(file);
    }

    file = fopen(filename, "r");
    if (!file) {
        printf("Error opening the file!\n");
        return EXIT_FAILURE;
    }
    else {
        printf("The contents of the file:\n");
        while (fgets(input, sizeof(input), file) != NULL) {
            printf("%s", input);
        }
        fclose(file);
    }
    
    return 0;
}
