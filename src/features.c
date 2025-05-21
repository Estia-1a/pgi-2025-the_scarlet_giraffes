#include <estia-image.h>
#include <stdio.h>

#include "features.h"
#include "utils.h"

/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */

void helloWorld() {
    printf("Hello World !");
}

void dimension (char *source_path){
    int width;
    int height;
    int channel_count;
    unsigned char *data;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);

    if (resultat){
        printf("dimension : %d,%d", width, height);
    }
    else{
        printf("ERROR");
    }
}

void first_pixel (char *source_path){
    int width;
    int height;
    int channel_count;
    unsigned char *data;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);
    if (width < 10) {
        printf("L'image doit avoir une largeur d'au moins 10 pixels.\n");
    }

    if (resultat){
        printf("first_pixel : %d, %d, %d", data[0], data[1], data[2]);
    }
    else{
        printf("ERROR");
    }
}
void tenth_pixel (char *source_path){
    int width;
    int height;
    int channel_count;
    unsigned char *data;        
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);
    if (resultat){
        printf("tenth_pixel : %d, %d, %d", data[27], data[28], data[29]);
    }
    else{
        printf("ERROR");
    }

}
void second_line(char *source_path){
    int width;
    int height;
    int channel_count;
    unsigned char *data;        
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);
    if (height < 2) {
        printf("L'image doit avoir une hauteur d'au moins 2 pixels.\n");
    }
    if (resultat){
        printf("second_line : %d, %d, %d", data[4464], data[4465], data[4466]);
    }
    else{
        printf("ERROR");
    }
}
void print_pixel( char *filename, int x, int y ){
    printf("Test");
}