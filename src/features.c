#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>

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
    int nr, xr, yr, min_R ;
    int ng, xg, yg, min_G ;
    int nb, xb, yb, min_B ;


    if (read_image_data(source_path, &data, &width, &height, &channel_count) != 0) {
        min_R = data[0];
        min_G = data[1] ;
        min_B = data[2];
        nr = 0 ;
        ng = 1 ;
        nb = 2;

        for (i = 3; i < width*height*3; i = i + 3) {
            if (data[i] < min_R){
                min_R = data[i];
                nr = i/3;
            }
            if (data[i+1] < min_G) {
                min_G = data[i+1] ;
                ng = i/3 ;
            }
            if (data[i+2] < min_B) {
                min_B = data[i+2] ;
                nb = i/3 ;
            }
        }
        for (j = 0; j < height; j++) {
            if (nr >= width*j && nr <= width*j + width - 1){
                xr = j;
                yr = nr - width*xr;
            }
            if (ng >= width*j && ng <= width*j + width - 1) {
                xg = j ;
                yg = ng - width*xg ;
            }
            if (nb >= width*j && nb <= width*j + width - 1) {
                xb = j ;
                yb = nb - width*xb ;
            }
        }

        if (c == 'R') {
            printf ("min_component R (%d, %d): %d\n", yr, xr, min_R) ;
        }
        else if (c == 'G') {
            printf ("min_component G (%d, %d): %d\n", yg, xg, min_G) ;
        }
        else if (c == 'B') {
            printf ("min_component B (%d, %d): %d\n", yb, xb, min_B) ;
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

void max_component (char *source_path, char c) {
    int width ;
    int height ;
    int channel_count ;
    unsigned char *data ;
    int i, j ;
    int nr, xr, yr, max_R;
    int nb, xb, yb, max_B;
    int ng, xg, yg, max_G;

    if (read_image_data(source_path, &data, &width, &height, &channel_count) != 0) {
        max_R = data[0];
        max_B = data[2];
        max_G = data[1];
        nr = 0 ;
        nb = 2;
        ng = 1 ;
        for (i = 3; i < width*height*3; i = i + 3) {
            if (data[i] > max_R) {
                max_R = data[i] ;
                nr = i/3 ;
            }
            if (data[i+2] > max_B){
                max_B = data[i+2];
                nb = i/3;
            }
            if (data[i+1] > max_G) {
                max_G = data[i+1] ;
                ng = i/3 ;
            }
        }
        for (j = 0; j < height; j++) {
            if (nr >= width*j && nr <= width*j + width - 1) {
                xr = j ;
                yr = nr - width*xr ;
            }
            if (nb >= width*j && nb <= width*j + width - 1){
                xb = j;
                yb = nb - width*xb;
            }
            if (ng >= width*j && ng <= width*j + width - 1) {
                xg = j ;
                yg = ng - width*xg ;
            }

        }

        if (c == 'R') {
            printf ("max_component R (%d, %d): %d\n", yr, xr, max_R) ;
        }
        else if (c == 'B') {
            printf ("max_component B (%d, %d): %d\n", yb, xb, max_B) ;
        }
        else if (c == 'G') {
            printf ("max_component G (%d, %d): %d\n", yg, xg, max_G) ;
        }
    }
    else {
        printf("ERROR");
    }
}

void min_pixel (char *source_path) {
    int width ;
    int height ;
    int channel_count ;
    unsigned char *data ;
    int i, j, n, x, y ;
    int min ;

    if (read_image_data(source_path, &data, &width, &height, &channel_count) != 0) {
        min = data[0] + data[1] + data[2] ;
        n = 0 ;
        for (i = 3; i < height*width*3; i = i + 3) {
            if (data[i] + data[i+1] + data[i+2] < min) {
                min = data[i] + data[i+1] + data[i+2] ;
                n = i/3 ;
            }
        }
        for (j = 0; j < height; j++) {
            if (n >= width*j && n <= width*j + width - 1) {
                x = j ;
                y = n - width*x ;
            }
        }
        printf ("min_pixel (%d, %d): %d, %d, %d\n", y, x, data[3*n], data[3*n+1], data[3*n+2]) ;
    }
    else {
        printf("ERROR") ;
    }
}


void mirror_horizontal(char *source_path) {
    int width;
    int height;
    int channel_count;
    unsigned char *data;

    if (read_image_data(source_path, &data, &width, &height, &channel_count) != 0) {
        int ligne, colonne, i;
        unsigned char temp;
        for (ligne = 0; ligne < height; ligne++) {
            for (colonne = 0; colonne < width / 2; colonne++) {
                int left = (ligne * width + colonne) * channel_count;
                int right = (ligne * width + (width - 1 - colonne)) * channel_count;
                for (i = 0; i < channel_count; i++) {
                    temp = data[left + i];
                    data[left + i] = data[right + i];
                    data[right + i] = temp;
                }
            }
        }
        write_image_data("image_out.bmp", data, width, height);
    } 
    else {
        printf("ERROR\n");
    }
}



void color_gray(char *source_path){
    int width;
    int height;
    int channel_count;
    unsigned char *data;
    int i;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    for(i = 0; i < width*height; i++){
        data[i*channel_count] = (data[i*channel_count] + data[i*channel_count + 1] + data[i*channel_count + 2]) / 3;
        data[i*channel_count + 1] = data[i*channel_count];
        data[i*channel_count + 2] = data[i*channel_count];
    }
    write_image_data("image_out.bmp", data, width, height);
}

void color_desaturate(char *source_path) {
    int width, height, channel_count;
    unsigned char* data;
    char *destination_path = "image_out.bmp";
    int new_val, j, i;

    if (read_image_data(source_path, &data, &width, &height, &channel_count) != 0) {
        for ( i = 0; i < height; i++) {
            for (j = 0; j < width; j++) {
                int position = (i * width + j) * channel_count;

                int R = data[position];
                int G = data[position + 1];
                int B = data[position + 2];

                new_val = (R < G) ? ((R < B) ? R : B) : ((G < B) ? G : B);
                int max_val = (R > G) ? ((R > B) ? R : B) : ((G > B) ? G : B);

                new_val = (new_val + max_val) / 2;

                data[position] = new_val;
                data[position + 1] = new_val;
                data[position + 2] = new_val;
            }
        }
    }

    write_image_data(destination_path, data, width, height);
}
void mirror_vertical(char *source_path) {
    int width;
    int height;
    int channel_count;
    unsigned char *data;
 
    if (read_image_data(source_path, &data, &width, &height, &channel_count) != 0) {
        int ligne, colonne, top, bottom ;
        for (ligne = 0; ligne < height / 2; ligne++) {
            for (colonne = 0; colonne < width; colonne++) {
                bottom = (ligne * width + colonne) * channel_count;
                top = ((height - 1 - ligne) * width + colonne) * channel_count;
 
                for (int x = 0; x < channel_count; x++) {
                    unsigned char temp = data[top + x];
                    data[top + x] = data[bottom + x];
                    data[bottom + x] = temp;
                }
            }
        }
 
        write_image_data("image_out.bmp", data, width, height);
        
    } else {
        printf("ERROR\n");
    }
}

void color_invert(char *source_path){
    int width;
    int height;
    int channel;
    unsigned char *data;
    int i;
    read_image_data(source_path, &data, &width, &height, &channel);
    for(i = 0; i < width*height; i++){
        data[i*channel] = 255 - data[i*channel];
        data[i*channel + 1] = 255 - data[i*channel + 1];
        data[i*channel + 2] = 255 - data[i*channel + 2];
    }
    write_image_data("image_out.bmp", data, width, height);
}

void color_gray_luminance(char *source_path){
    int width;
    int height;
    int channel;
    unsigned char *data;
    int i;
    read_image_data(source_path, &data, &width, &height, &channel);


 for (i = 0; i < width * height; i++) {
    unsigned char gray = (data[i * channel] + data[i * channel + 1] + data[i * channel + 2]) / 3;
    data[i * channel] = gray;
    data[i * channel + 1] = gray;
    data[i * channel + 2] = gray;
    }
    write_image_data("image_out.bmp", data, width, height);
}

void mirror_total(char *source_path) {
    int width;
    int height;
    int channel_count;
    unsigned char *data;
 
    if (read_image_data(source_path, &data, &width, &height, &channel_count) != 0) {
        for (int ligne = 0; ligne < height / 2; ligne++) {
            for (int colonne = 0; colonne < width; colonne++) {
                int top_left = (ligne * width + colonne) * channel_count;
                int bottom_right = ((height - 1 - ligne) * width + (width - 1 - colonne)) * channel_count;
 
                for (int c = 0; c < channel_count; c++) {
                    unsigned char temp = data[top_left + c];
                    data[top_left + c] = data[bottom_right + c];
                    data[bottom_right + c] = temp;
                }
            }
        }
 
        if (height % 2 != 0) {
            int mi_ligne = height / 2;
            for (int colonne = 0; colonne < width / 2; colonne++) {
                int left = (mi_ligne * width + colonne) * channel_count;
                int right = (mi_ligne * width + (width - 1 - colonne)) * channel_count;
 
                for (int c = 0; c < channel_count; c++) {
                    unsigned char temp = data[left + c];
                    data[left + c] = data[right + c];
                    data[right + c] = temp;
                }
            }
        }
 
        if (write_image_data("image_out.bmp", data, width, height)) {
            printf("Symetrie totale appliquee avec succes.\n");
        } else {
            printf("ERROR\n");
        }
    } else {
        printf("Erreur : impossible de lire l'image.\n");
    }
}

void rotate_acw(char *sourcepath){
    int width, height, channel_count;
    unsigned char *data;

    if ( !read_image_data(sourcepath, &data, &width, &height, &channel_count)){
        printf("Erreur");
        return;
    }

    unsigned char *rotation = malloc(width * height * channel_count);
    if(!rotation) {
        printf("Erreur");
        free(data);
        return;
    }

    for (int y = 0; y< height; y++){
        for (int x = 0; x< width; x++) {
            int src = (y * width + x) * channel_count;
            int xrot = y;
            int yrot = width - 1 - x;
            int idx = (yrot * height + xrot) * channel_count;

            for (int c = 0; c < channel_count; c++) {
                rotation[idx + c] = data[src + c];
            }
        }
    }
    write_image_data("image_out.bmp",rotation, height, width);

    free(data);
    free(rotation);
}

void rotate_cw(char *sourcepath){
    int width, height, channel_count;
    unsigned char *data;

    if ( !read_image_data(sourcepath, &data, &width, &height, &channel_count)){
        printf("Erreur");
        return;
    }

    unsigned char *rotation = malloc(width * height * channel_count);
    if(!rotation) {
        printf("Erreur");
        free(data);
        return;
    }

    for (int y = 0; y< height; y++){
        for (int x = 0; x< width; x++) {
            int src = (y * width + x) * channel_count;
            int xrot = width - 1 - y;
            int yrot = x;
            int idx = (yrot * height + xrot) * channel_count;

            for (int c = 0; c < channel_count; c++) {
                rotation[idx + c] = data[src + c];
            }
        }
    }
    write_image_data("image_out.bmp",rotation, height, width);

    free(data);
    free(rotation);
}

void scale_bilinear(char *chemin_image, float scale_x, float scale_y) {
    int largeur, hauteur, nb_canaux;
    unsigned char *donnees;

    if (read_image_data(chemin_image, &donnees, &largeur, &hauteur, &nb_canaux) != 0) {
        int nouvelle_largeur = largeur * scale_x;
        int nouvelle_hauteur = hauteur * scale_y;

        unsigned char *image_redim = malloc(nouvelle_largeur * nouvelle_hauteur * nb_canaux);


        for (int ligne = 0; ligne < nouvelle_hauteur; ligne++) {
            float y_source = (float)ligne / scale_y;
            int y0 = (int)y_source;
            int y1 = y0 + 1;
            if (y1 >= hauteur) y1 = hauteur - 1;
            float dy = y_source - y0;

            for (int colonne = 0; colonne < nouvelle_largeur; colonne++) {
                float x_source = (float)colonne / scale_x;
                int x0 = (int)x_source;
                int x1 = x0 + 1;
                if (x1 >= largeur) x1 = largeur - 1;
                float dx = x_source - x0;

                for (int canal = 0; canal < nb_canaux; canal++) {
                    unsigned char Q11 = donnees[(y0 * largeur + x0) * nb_canaux + canal];
                    unsigned char Q12 = donnees[(y0 * largeur + x1) * nb_canaux + canal];
                    unsigned char Q21 = donnees[(y1 * largeur + x0) * nb_canaux + canal];
                    unsigned char Q22 = donnees[(y1 * largeur + x1) * nb_canaux + canal];

                    float P1 = Q11 * (1 - dx) + Q12 * dx;
                    float P2 = Q21 * (1 - dx) + Q22 * dx;
                    float P = P1 * (1 - dy) + P2 * dy;

                    image_redim[(ligne * nouvelle_largeur + colonne) * nb_canaux + canal] = (unsigned char)(P);
                }
            }
        }

        write_image_data("image_out.bmp", image_redim, nouvelle_largeur, nouvelle_hauteur);

    } else {
        printf("ERROR.\n");
    }
}

void scale_crop(char *chemin_image, int center_x, int center_y, int crop_width, int crop_height) {
    int largeur, hauteur, nb_canaux;
    unsigned char *donnees;

    if (read_image_data(chemin_image, &donnees, &largeur, &hauteur, &nb_canaux) != 0) {
        int x0 = center_x - crop_width / 2;
        int y0 = center_y - crop_height / 2;

        if (x0 < 0) x0 = 0;
        if (y0 < 0) y0 = 0;
        if (x0 + crop_width > largeur) crop_width = largeur - x0;
        if (y0 + crop_height > hauteur) crop_height = hauteur - y0;

        unsigned char *image_crop = malloc(crop_width * crop_height * nb_canaux);

        for (int y = 0; y < crop_height; y++) {
            for (int x = 0; x < crop_width; x++) {
                for (int c = 0; c < nb_canaux; c++) {
                    int source_index = ((y0 + y) * largeur + (x0 + x)) * nb_canaux + c;
                    int dest_index = (y * crop_width + x) * nb_canaux + c;
                    image_crop[dest_index] = donnees[source_index];
                }
            }
        }

        write_image_data("image_out.bmp", image_crop, crop_width, crop_height);
    } else {
        printf("ERROR.\n");
    }
}




void scale_nearest(char *chemin_image, float facteur) {
    int largeur, hauteur, nb_canaux;
    unsigned char *donnees;
 
    if (read_image_data(chemin_image, &donnees, &largeur, &hauteur, &nb_canaux) != 0) {
        int nouvelle_largeur = largeur * facteur;
        int nouvelle_hauteur = hauteur * facteur;
 
        unsigned char *resized = malloc(nouvelle_largeur * nouvelle_hauteur * nb_canaux);
 
        for (int y = 0; y < nouvelle_hauteur; y++) {
            int src_y = y / facteur;
            if (src_y >= hauteur) src_y = hauteur - 1;
 
            for (int x = 0; x < nouvelle_largeur; x++) {
                int src_x = x / facteur;
                if (src_x >= largeur) src_x = largeur - 1;
 
                for (int c = 0; c < nb_canaux; c++) {
                    resized[(y * nouvelle_largeur + x) * nb_canaux + c] = donnees[(src_y * largeur + src_x) * nb_canaux + c];
                }
            }
        }
        write_image_data("image_out.bmp", resized, nouvelle_largeur, nouvelle_hauteur);
    } else {
        printf("ERROR.\n");
    }
}