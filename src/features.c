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
void dimension (char *source_path) {
    int width, height, channel_count;
    unsigned char *data;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);
    if (resultat) {
        printf("dimension: %d, %d", width, height); 
    }
    else {
        printf("ERREUR DE LECTURE FICHIER");
    }
}
void first_pixel(char *source_path){
    int width, height, channel_count;
    unsigned char *data;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);
    if (resultat) {
        printf("first_pixel: %d, %d, %d", data[0], data[1], data[2]);
    }
    else {
        printf("ERREUR DE LECTURE FICHIER"); 
    }
}

    
void second_line (char *source_path){
    int width, height, channel_count ;
    unsigned char *data;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);
    if (resultat) {
        printf("second_line: %d, %d, %d", data[4464], data[4465], data[4466]);
    }
    else {
        printf("ERREUR DE LECTURE FICHIER"); 
    }
}

void tenth_pixel (char *source_path){
    int width, height, channel_count ;
    unsigned char *data;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);
    if (resultat) {
        printf("tenth_pixel: %d, %d, %d", data[27], data[28], data[29]);
    }
    else {
        printf("ERREUR DE LECTURE FICHIER"); 
    }
}

void print_pixel (char *source_path, int x, int y){
    int width, height, channel_count ;
    unsigned char *data;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);
    if (resultat) {
        printf("tenth_pixel: %d, %d, %d", data[(x*3-3)+((y-1)*(width*3))], data[(x*3-2)+((y-1)*(width*3))], data[(x*3-1)+((y-1)*(width*3))]);
    }
    else {
        printf("ERREUR DE LECTURE FICHIER"); 
    }
}
