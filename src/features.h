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

void min_component (char *source_path, char c) ;

void max_component (char *source_path, char c) ;

void max_pixel (char *source_path);

void min_pixel (char *source_path) ;

void mirror_vertical (char *source_path) ;

void color_gray(char *source_path);

void color_desaturate(char *source_path);

#endif