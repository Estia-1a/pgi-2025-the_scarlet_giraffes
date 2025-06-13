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
    int height;
    int channel_count;
    int width; 
    if (read_image_data(source_path, &data, &width, &height, &channel_count) != 0) {
        if(height<2){
            printf("L'image doit avoir au moins 2 pixels en ligne") ;
        }
        int R = data[3 * width + 0];
        int G = data[3 * width + 1];
        int B = data[3 * width + 2]; 
        printf("second_line: %d, %d, %d\n", R, G, B);
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

void color_red(char *source_path){
    unsigned char* data;
    int width;
    int height;
    int channel_count;
    int i;
    if (read_image_data(source_path, &data, &width, &height, &channel_count) !=0){
        for(i=0; i<height*width; i++){
            data[i*channel_count + 1] = 0;
            data[i*channel_count + 2] = 0;
        }
        write_image_data("image_out.bmp", data, width, width);
    }
    else{
        printf("ERROR");
    }
}

void color_blue(char *source_path){
    unsigned char* data;
    int width;
    int height;
    int channel_count;
    int i;
    if (read_image_data(source_path, &data, &width, &height, &channel_count) !=0){
        for(i=0; i<height*width; i++){
            data[i*channel_count] = 0;
            data[i*channel_count + 1] = 0;
        }
        write_image_data("image_out.bmp", data, width, width);
    }
    else{
        printf("ERROR");
    }
}

void color_green(char *source_path){
    unsigned char* data;
    int width;
    int height;
    int channel_count;
    int i;
    if (read_image_data(source_path, &data, &width, &height, &channel_count) !=0){
        for(i=0; i<height*width; i++){
            data[i*channel_count] = 0;
            data[i*channel_count + 2] = 0;
        }
        write_image_data("image_out.bmp", data, width, width);
    }
    else{
        printf("ERROR");
    }
}
void min_component (char *source_path, char c) {
    int width ;
    int height ;
    int channel_count ;
    unsigned char *data ;
    int i, j;
    int ng, xg, yg, min_G ;

    if (read_image_data(source_path, &data, &width, &height, &channel_count) != 0) {
        min_G = data[1] ;
        ng = 1 ;
        for (i = 3; i < width*height*3; i = i + 3) {
            if (data[i+1] < min_G) {
                min_G = data[i+1] ;
                ng = i/3 ;
            }
        }
        for (j = 0; j < height; j++) {
            if (ng >= width*j && ng <= width*j + width - 1) {
                xg = j ;
                yg = ng - width*xg ;
            }
        }

        if (c == 'G') {
            printf ("min_component G (%d, %d): %d\n", yg, xg, min_G) ;
        }
    }
    else {
        printf("Error\n");
    }
}

void max_pixel (char *source_path){
    int width, height, channel_count;
    int i, j, n, x, y;
    int max;
    unsigned char *data;

    if (read_image_data(source_path, &data, &width, &height, &channel_count) !=0){
    
      max = data[0] + data[1] + data[2];
      n=0;
      for(i=3; i<height*width*3; i=i+3){
        if (data[i] + data[i+1] + data[i+2] > max){
            max = data[i] + data[i+1] + data[i+2] ;
            n = i/3;
        }
      }
      for (j=0; j<height; j++){
        if(n>= width*j && n<= width*j + width-1){
            x=j;
            y=n-width*x;
        }
      }
        printf("max_pixel (%d, %d): %d, %d, %d\n", y, x, data[3*n], data[3*n+1], data[3*n+2]);
    }
    else {
        printf("ERROR");
    }
}