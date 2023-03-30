#include <math.h>
#include <stdio.h>
#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)    //Iterate over the pixels of the image
    {
        for (int j = 0; j < width; j++)
        {
            //Calculate the average and assign it to the rgb values of the pixels
            int grayColor = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = grayColor;
            image[i][j].rgbtGreen = grayColor;
            image[i][j].rgbtRed = grayColor;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int n = width / 2;
    for (int i = 0; i < height; i++)    //Iterate over the pixels of the image
    {
        for (int j = 0; j < n; j++)
        {
            //Swap the pixels between each other
            RGBTRIPLE tempImage = image[i][j];
            image[i][j] = image[i][width - (1 + j)];
            image[i][width - (1 + j)] = tempImage;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tempImage[height][width];
    for (int i = 0; i < height; i++)    //Iterate over the pixels of the image
    {
        //Get the adjacent pixels and store the rgb values in variables and keep counting the number of adjacents
        for (int j = 0; j < width; j++)
        {
            //Initialize them with current pixels values
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;
            //Keeps track of number of adjacents to get the average
            int count = 1;

            if (i > 0)  //Calculation for upper pixel
            {
                red += image[i - 1][j].rgbtRed;
                green += image[i - 1][j].rgbtGreen;
                blue += image[i - 1][j].rgbtBlue;
                count++;
            }

            if (j > 0)  //Calculation for left pixel
            {
                red += image[i][j - 1].rgbtRed;
                green += image[i][j - 1].rgbtGreen;
                blue += image[i][j - 1].rgbtBlue;
                count++;
            }

            if (i < height - 1) //Calculation for lower pixel
            {
                red += image[i + 1][j].rgbtRed;
                green += image[i + 1][j].rgbtGreen;
                blue += image[i + 1][j].rgbtBlue;
                count++;
            }

            if (j < width - 1)  //Calculation for right pixel
            {
                red += image[i][j + 1].rgbtRed;
                green += image[i][j + 1].rgbtGreen;
                blue += image[i][j + 1].rgbtBlue;
                count++;
            }

            if (i > 0 && j > 0) //Calculation for upper left pixel
            {
                red += image[i - 1][j - 1].rgbtRed;
                green += image[i - 1][j - 1].rgbtGreen;
                blue += image[i - 1][j - 1].rgbtBlue;
                count++;
            }

            if (i > 0 && j < width - 1) //Calculation for upper right pixel
            {
                red += image[i - 1][j + 1].rgbtRed;
                green += image[i - 1][j + 1].rgbtGreen;
                blue += image[i - 1][j + 1].rgbtBlue;
                count++;
            }

            if (i < height - 1 && j > 0)    //Calculation for lower left pixel
            {
                red += image[i + 1][j - 1].rgbtRed;
                green += image[i + 1][j - 1].rgbtGreen;
                blue += image[i + 1][j - 1].rgbtBlue;
                count++;
            }

            if (i < height - 1 && j < width - 1)    //Calculation for lower right pixel
            {
                red += image[i + 1][j + 1].rgbtRed;
                green += image[i + 1][j + 1].rgbtGreen;
                blue += image[i + 1][j + 1].rgbtBlue;
                count++;
            }
            //Store the new blured pixels in other array in order to not damage the original file
            tempImage[i][j].rgbtRed = round(red / (float)count);
            tempImage[i][j].rgbtGreen = round(green / (float)count);
            tempImage[i][j].rgbtBlue = round(blue / (float)count);
        }
    }

    for (int i = 0; i < height; i++)
    {
        //Update the image
        for (int j = 0; j < width; j++)
        {
            //Assign calculated values to each pixel
            image[i][j] = tempImage[i][j];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tempImage[height][width];
    for (int i = 0; i < height; i++)    //Iterate over the pixels of image
    {
        //Apply the sobel oretaion to calculate Gx and Gy
        for (int j = 0; j < width; j++)
        {
            //Initialize them with 0 since both of the Gx and Gy matrices multiplies self with 0
            int redX = 0;
            int greenX = 0;
            int blueX = 0;

            int redY = 0;
            int greenY = 0;
            int blueY = 0;

            if (i > 0)  //Calculation for upper pixel
            {
                RGBTRIPLE temp = image[i - 1][j];
                redY -= temp.rgbtRed * 2;
                greenY -= temp.rgbtGreen * 2;
                blueY -= temp.rgbtBlue * 2;
            }

            if (j > 0)  //Calculation for left pixel
            {
                RGBTRIPLE temp = image[i][j - 1];
                redX -= temp.rgbtRed * 2;
                greenX -= temp.rgbtGreen * 2;
                blueX -= temp.rgbtBlue * 2;
            }

            if (i < height - 1) //Calculation for lower pixel
            {
                RGBTRIPLE temp = image[i + 1][j];
                redY += temp.rgbtRed * 2;
                greenY += temp.rgbtGreen * 2;
                blueY += temp.rgbtBlue * 2;
            }

            if (j < width - 1)  //Calculation for right pixel
            {
                RGBTRIPLE temp = image[i][j + 1];
                redX += temp.rgbtRed * 2;
                greenX += temp.rgbtGreen * 2;
                blueX += temp.rgbtBlue * 2;
            }

            if (i > 0 && j > 0) //Calculation for upper left pixel
            {
                RGBTRIPLE temp = image[i - 1][j - 1];
                redX -= temp.rgbtRed;
                greenX -= temp.rgbtGreen;
                blueX -= temp.rgbtBlue;

                redY -= temp.rgbtRed;
                greenY -= temp.rgbtGreen;
                blueY -= temp.rgbtBlue;
            }

            if (i > 0 && j < width - 1) //Calculation for upper right pixel
            {
                RGBTRIPLE temp = image[i - 1][j + 1];
                redX += temp.rgbtRed;
                greenX += temp.rgbtGreen;
                blueX += temp.rgbtBlue;

                redY -= temp.rgbtRed;
                greenY -= temp.rgbtGreen;
                blueY -= temp.rgbtBlue;
            }

            if (i < height - 1 && j > 0)    //Calculation for lower left pixel
            {
                RGBTRIPLE temp = image[i + 1][j - 1];
                redX -= temp.rgbtRed;
                greenX -= temp.rgbtGreen;
                blueX -= temp.rgbtBlue;

                redY += temp.rgbtRed;
                greenY += temp.rgbtGreen;
                blueY += temp.rgbtBlue;
            }

            if (i < height - 1 && j < width - 1)    //Calculation for lower right pixel
            {
                RGBTRIPLE temp = image[i + 1][j + 1];
                redX += temp.rgbtRed;
                greenX += temp.rgbtGreen;
                blueX += temp.rgbtBlue;

                redY += temp.rgbtRed;
                greenY += temp.rgbtGreen;
                blueY += temp.rgbtBlue;
            }
            //Clamping rounding and square root operation.
            int tempRed = round(sqrt(redX * redX + redY * redY));
            if (tempRed > 255)  //if red value is higher than 255 clamp it to the 255 just assign it otherwise
            {
                tempImage[i][j].rgbtRed = 255;
            }
            else
            {
                tempImage[i][j].rgbtRed = tempRed;
            }

            int tempGreen = round(sqrt(greenX * greenX + greenY * greenY));
            if (tempGreen > 255)    //if green value is higher than 255 clamp it to the 255 just assign it otherwise
            {
                tempImage[i][j].rgbtGreen = 255;
            }
            else
            {
                tempImage[i][j].rgbtGreen = tempGreen;
            }

            int tempBlue = round(sqrt(blueX * blueX + blueY * blueY));
            if (tempBlue > 255) //if blue value is higher than 255 clamp it to the 255 just assign it otherwise
            {
                tempImage[i][j].rgbtBlue = 255;
            }
            else
            {
                tempImage[i][j].rgbtBlue = tempBlue;
            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        //Update the original values
        for (int j = 0; j < width; j++)
        {
            //Assign the calculated values to image
            image[i][j] = tempImage[i][j];
        }
    }
    return;
}

// Inverse image
void inverse(int height, int width, RGBTRIPLE image[height][width])
{
    int n = height / 2;
    for (int i = 0; i < n; i++)    //Iterate over the pixels of the image
    {
        for (int j = 0; j < width; j++)
        {
            //Swap the pixels between each other
            RGBTRIPLE tempImage = image[i][j];
            image[i][j] = image[height - (1 + i)][j];
            image[height - (1 + i)][j] = tempImage;
        }
    }
    return;
}

void lighten(int height, int width, RGBTRIPLE image[height][width])
{
    int lightenValue = 16;
    int clampValue = 255 - lightenValue;
    for (int i = 0; i < height; i++)    //Iterate over the pixels of the image
    {
        for (int j = 0; j < width; j++)
        {
            if (image[i][j].rgbtRed <= clampValue &&
                image[i][j].rgbtGreen <= clampValue &&
                image[i][j].rgbtBlue <= clampValue)
            {
                image[i][j].rgbtRed += lightenValue;
                image[i][j].rgbtGreen += lightenValue;
                image[i][j].rgbtBlue += lightenValue;
            }
        }
    }
    return;
}

void fade(int height, int width, RGBTRIPLE image[height][width])
{
    int fadeValue = 16;
    for (int i = 0; i < height; i++)    //Iterate over the pixels of the image
    {
        for (int j = 0; j < width; j++)
        {
            if (image[i][j].rgbtRed >= fadeValue &&
                image[i][j].rgbtGreen >= fadeValue &&
                image[i][j].rgbtBlue >= fadeValue)
            {
                image[i][j].rgbtRed -= fadeValue;
                image[i][j].rgbtGreen -= fadeValue;
                image[i][j].rgbtBlue -= fadeValue;
            }
        }
    }
    return;
}

void ignoreChannelRed(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)    //Iterate over the pixels of the image
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = 0;
        }
    }
    return;
}

void ignoreChannelGreen(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)    //Iterate over the pixels of the image
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtGreen = 0;
        }
    }
    return;
}

void ignoreChannelBlue(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)    //Iterate over the pixels of the image
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = 0;
        }
    }
    return;
}
