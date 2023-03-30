#include "bmp.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width]);

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width]);

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width]);

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width]);

// Inverse image
void inverse(int height, int width, RGBTRIPLE image[height][width]);

// Lighten image
void lighten(int height, int width, RGBTRIPLE image[height][width]);

// Fade image
void fade(int height, int width, RGBTRIPLE image[height][width]);

void ignoreChannelRed(int height, int width, RGBTRIPLE image[height][width]);

void ignoreChannelGreen(int height, int width, RGBTRIPLE image[height][width]);

void ignoreChannelBlue(int height, int width, RGBTRIPLE image[height][width]);