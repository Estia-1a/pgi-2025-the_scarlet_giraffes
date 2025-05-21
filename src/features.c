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
    printf("Hello World !!!!");
}
void dimension (char *source_path){

    int width;
    int height;
    int channel_count;
    unsigned char *data;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);
   
    if (resultat){
        printf("dimension: %d, %d", width, height);
    }
    else{
        printf("ERROR");
    }
}

void first_pixel (char *source_path){
    unsigned char *data;
    int width, height, channel_count;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);
    if (read_image_data(source_path, &data, &width, &height, &channel_count)) {
    }
         if (resultat){
        printf("first_pixel: %d, %d, %d\n", data[0], data[1], data[2]);
    }
    else{
        printf("ERROR");
    }
    
}

void second_line(char *source_path){
    unsigned char *data;
    int width, height, channel_count;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);
    if (read_image_data(source_path, &data, &width, &height, &channel_count)) {
    }
         if (resultat){
        printf("second_line: %d, %d, %d\n", data[4464], data[4465], data[4466]);
    }
    else{
        printf("ERROR");
    }
}
void tenth_pixel(char *source_path){
    unsigned char *data;
    int width, height, channel_count;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);
    if (read_image_data(source_path, &data, &width, &height, &channel_count)) {
    }
         if (resultat){
        printf("tenth_pixel: %d, %d, %d\n", data[27], data[28], data[29]);
    }
    else{
        printf("ERROR");
    }
}

void print_pixel(char *source_path, int x, int y){
    int width;
    int height;
    int channel_count;
    unsigned char* data;
    int R,G,B;
    if (read_image_data(source_path, &data, &width, &height, &channel_count) !=0){
        unsigned int position = 3*(y*width+x);
        R = data[position];
        G = data[position+1];
        B = data[position+2];
        printf("print_pixel (%d, %d): %d, %d, %d", x, y, R, G, B);
    }
    else {
        printf("ERROR");
    }
}