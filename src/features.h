#ifndef FEATURES_H
#define FEATURES_H


void helloWorld();

void dimension (char *source_path);

void first_pixel (char *source_path);

void second_line(char *source_path);

void tenth_pixel (char *source_path);

void print_pixel( char *source_path, int x, int y );

void color_red(char *source_path);

void color_blue(char *source_path);

void color_green(char *source_path);

void color_gray(char *sourcepath);

void color_invert(char *source_path);

void color_gray_luminance(char *source_path);

void min_component (char *source_path, char c) ;

void max_component (char *source_path, char c) ;

void max_pixel (char *source_path);

void min_pixel (char *source_path) ;

void mirror_vertical (char *source_path) ;

void mirror_horizontal(char *source_path);

void mirror_total(char *source_path);

void color_desaturate(char *source_path);

void rotate_acw(char *source_path);

void rotate_cw(char *source_path);

void scale_bilinear(char *source_path, float scale_x, float scale_y);

void scale_crop(char *source_path, int center_x, int center_y, int crop_width, int crop_height);

void scale_nearest(char *source_path, float facteur);

#endif