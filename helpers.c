#include <math.h>
#include <stdio.h>
#include "helpers.h"

void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int grayColor = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = grayColor;
            image[i][j].rgbtGreen = grayColor;
            image[i][j].rgbtRed = grayColor;
        }
    }
    return;
}

void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int n = width / 2;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < n; j++)
        {
            RGBTRIPLE tempImage = image[i][j];
            image[i][j] = image[i][width - (1 + j)];
            image[i][width - (1 + j)] = tempImage;
        }
    }
    return;
}

void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tempImage[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;
            int count = 1;

            if (i > 0)
            {
                red += image[i - 1][j].rgbtRed;
                green += image[i - 1][j].rgbtGreen;
                blue += image[i - 1][j].rgbtBlue;
                count++;
            }

            if (j > 0)
            {
                red += image[i][j - 1].rgbtRed;
                green += image[i][j - 1].rgbtGreen;
                blue += image[i][j - 1].rgbtBlue;
                count++;
            }

            if (i < height - 1)
            {
                red += image[i + 1][j].rgbtRed;
                green += image[i + 1][j].rgbtGreen;
                blue += image[i + 1][j].rgbtBlue;
                count++;
            }

            if (j < width - 1)
            {
                red += image[i][j + 1].rgbtRed;
                green += image[i][j + 1].rgbtGreen;
                blue += image[i][j + 1].rgbtBlue;
                count++;
            }

            if (i > 0 && j > 0)
            {
                red += image[i - 1][j - 1].rgbtRed;
                green += image[i - 1][j - 1].rgbtGreen;
                blue += image[i - 1][j - 1].rgbtBlue;
                count++;
            }

            if (i > 0 && j < width - 1)
            {
                red += image[i - 1][j + 1].rgbtRed;
                green += image[i - 1][j + 1].rgbtGreen;
                blue += image[i - 1][j + 1].rgbtBlue;
                count++;
            }

            if (i < height - 1 && j > 0)
            {
                red += image[i + 1][j - 1].rgbtRed;
                green += image[i + 1][j - 1].rgbtGreen;
                blue += image[i + 1][j - 1].rgbtBlue;
                count++;
            }

            if (i < height - 1 && j < width - 1)
            {
                red += image[i + 1][j + 1].rgbtRed;
                green += image[i + 1][j + 1].rgbtGreen;
                blue += image[i + 1][j + 1].rgbtBlue;
                count++;
            }
            tempImage[i][j].rgbtRed = round(red / (float)count);
            tempImage[i][j].rgbtGreen = round(green / (float)count);
            tempImage[i][j].rgbtBlue = round(blue / (float)count);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = tempImage[i][j];
        }
    }
    return;
}

void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tempImage[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int redX = 0;
            int greenX = 0;
            int blueX = 0;

            int redY = 0;
            int greenY = 0;
            int blueY = 0;

            if (i > 0)
            {
                RGBTRIPLE temp = image[i - 1][j];
                redY -= temp.rgbtRed * 2;
                greenY -= temp.rgbtGreen * 2;
                blueY -= temp.rgbtBlue * 2;
            }

            if (j > 0)
            {
                RGBTRIPLE temp = image[i][j - 1];
                redX -= temp.rgbtRed * 2;
                greenX -= temp.rgbtGreen * 2;
                blueX -= temp.rgbtBlue * 2;
            }

            if (i < height - 1)
            {
                RGBTRIPLE temp = image[i + 1][j];
                redY += temp.rgbtRed * 2;
                greenY += temp.rgbtGreen * 2;
                blueY += temp.rgbtBlue * 2;
            }

            if (j < width - 1)
            {
                RGBTRIPLE temp = image[i][j + 1];
                redX += temp.rgbtRed * 2;
                greenX += temp.rgbtGreen * 2;
                blueX += temp.rgbtBlue * 2;
            }

            if (i > 0 && j > 0)
            {
                RGBTRIPLE temp = image[i - 1][j - 1];
                redX -= temp.rgbtRed;
                greenX -= temp.rgbtGreen;
                blueX -= temp.rgbtBlue;

                redY -= temp.rgbtRed;
                greenY -= temp.rgbtGreen;
                blueY -= temp.rgbtBlue;
            }

            if (i > 0 && j < width - 1)
            {
                RGBTRIPLE temp = image[i - 1][j + 1];
                redX += temp.rgbtRed;
                greenX += temp.rgbtGreen;
                blueX += temp.rgbtBlue;

                redY -= temp.rgbtRed;
                greenY -= temp.rgbtGreen;
                blueY -= temp.rgbtBlue;
            }

            if (i < height - 1 && j > 0)
            {
                RGBTRIPLE temp = image[i + 1][j - 1];
                redX -= temp.rgbtRed;
                greenX -= temp.rgbtGreen;
                blueX -= temp.rgbtBlue;

                redY += temp.rgbtRed;
                greenY += temp.rgbtGreen;
                blueY += temp.rgbtBlue;
            }

            if (i < height - 1 && j < width - 1)
            {
                RGBTRIPLE temp = image[i + 1][j + 1];
                redX += temp.rgbtRed;
                greenX += temp.rgbtGreen;
                blueX += temp.rgbtBlue;

                redY += temp.rgbtRed;
                greenY += temp.rgbtGreen;
                blueY += temp.rgbtBlue;
            }
            int tempRed = round(sqrt(redX * redX + redY * redY));
            if (tempRed > 255)
            {
                tempImage[i][j].rgbtRed = 255;
            }
            else
            {
                tempImage[i][j].rgbtRed = tempRed;
            }

            int tempGreen = round(sqrt(greenX * greenX + greenY * greenY));
            if (tempGreen > 255)
            {
                tempImage[i][j].rgbtGreen = 255;
            }
            else
            {
                tempImage[i][j].rgbtGreen = tempGreen;
            }

            int tempBlue = round(sqrt(blueX * blueX + blueY * blueY));
            if (tempBlue > 255)
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
        for (int j = 0; j < width; j++)
        {
            image[i][j] = tempImage[i][j];
        }
    }
    return;
}

void inverse(int height, int width, RGBTRIPLE image[height][width])
{
    int n = height / 2;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < width; j++)
        {
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
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE* tempImage = &image[i][j];
            if (tempImage->rgbtRed + lightenValue > 255)
            {
                tempImage->rgbtRed = 255;
            }
            else
            {
                tempImage->rgbtRed += lightenValue;
            }

            if (tempImage->rgbtGreen + lightenValue > 255)
            {
                tempImage->rgbtGreen = 255;
            }
            else
            {
                tempImage->rgbtGreen += lightenValue;
            }

            if (tempImage->rgbtBlue + lightenValue > 255)
            {
                tempImage->rgbtBlue = 255;
            }
            else
            {
                tempImage->rgbtBlue += lightenValue;
            }
        }
    }
    return;
}

void fade(int height, int width, RGBTRIPLE image[height][width])
{
    int fadeValue = 16;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE* tempImage = &image[i][j];
            if (tempImage->rgbtRed < fadeValue)
            {
                tempImage->rgbtRed = 0;
            }
            else
            {
                tempImage->rgbtRed -= fadeValue;
            }

            if (tempImage->rgbtGreen < fadeValue)
            {
                tempImage->rgbtGreen = 0;
            }
            else
            {
                tempImage->rgbtGreen -= fadeValue;
            }

            if (tempImage->rgbtBlue < fadeValue)
            {
                tempImage->rgbtBlue = 0;
            }
            else
            {
                tempImage->rgbtBlue -= fadeValue;
            }
        }
    }
    return;
}

void ignoreChannelRed(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
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
    for (int i = 0; i < height; i++)
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
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = 0;
        }
    }
    return;
}

void hallucinate(int height, int width, RGBTRIPLE image[height][width])
{
    int n = width / 2;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < n; j++)
        {
            RGBTRIPLE tempImage = image[i][j];
            switch (j % 4)
            {
                case 0:
                    image[i][j] = image[i][width - (1 + j)];
                    image[i][width - (1 + j)] = tempImage;
                    break;
                case 1:
                    image[i][j] = image[height - (1 + i)][j];
                    image[height - (1 + i)][j] = tempImage;
                    break;
                case 2:
                    image[i][j] = image[height - (1 + i)][width - (1 + j)];
                    image[height - (1 + i)][width - (1 + j)] = tempImage;
                    break;
            }
        }
    }
    return;
}

void sort(int height, int width, RGBTRIPLE image[height][width])
{
    mergeSort(&image[0][0], 0, height * width - 1);

    return;
}

void mergeSort(RGBTRIPLE *arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void merge(RGBTRIPLE *arr, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    RGBTRIPLE L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        int sum1 = L[i].rgbtBlue + L[i].rgbtGreen + L[i].rgbtRed;
        int sum2 = R[j].rgbtBlue + R[j].rgbtGreen + R[j].rgbtRed;
        if (sum1 <= sum2) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
