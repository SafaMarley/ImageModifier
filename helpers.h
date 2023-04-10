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

// Ignore red channel
void ignoreChannelRed(int height, int width, RGBTRIPLE image[height][width]);

// Ignore green channel
void ignoreChannelGreen(int height, int width, RGBTRIPLE image[height][width]);

// Ignore blue channel
void ignoreChannelBlue(int height, int width, RGBTRIPLE image[height][width]);

// Hallucinate the image
void hallucinate(int height, int width, RGBTRIPLE image[height][width]);

// Sort the image by color values
void sort(int height, int width, RGBTRIPLE image[height][width]);

//Merge sort algorithm
void mergeSort(RGBTRIPLE *arr, int left, int right);

void merge(RGBTRIPLE *arr, int left, int mid, int right);
