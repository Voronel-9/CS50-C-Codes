#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            int avgRed = image[i][j].rgbtRed;
            int avgGreen = image[i][j].rgbtGreen;
            int avgBlue = image[i][j].rgbtBlue;
            int avg_rgb = round((avgRed + avgGreen + avgBlue) / 3.0);
            image[i][j].rgbtRed = avg_rgb;
            image[i][j].rgbtGreen = avg_rgb;
            image[i][j].rgbtBlue = avg_rgb;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;

            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            if (sepiaRed > 255){
                sepiaRed = 255;
            }
            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            if (sepiaGreen > 255){
                sepiaGreen = 255;
            }
            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);
            if (sepiaBlue > 255){
                sepiaBlue = 255;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width/2; j++){
            int holderRed = image[i][j].rgbtRed;
            int holderGreen = image[i][j].rgbtGreen;
            int holderBlue = image[i][j].rgbtBlue;
            image[i][j] = image[i][width - 1 - j];
            image[i][width-1-j].rgbtRed = holderRed;
            image[i][width-1-j].rgbtGreen = holderGreen;
            image[i][width-1-j].rgbtBlue = holderBlue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            float holderRed = 0;
            float holderGreen = 0;
            float holderBlue = 0;
            int counter = 0;

            for(int m = -1; m < 2; m++){
                for (int n = -1; n < 2; n++){
                    if ((((i + m) <= (height - 1)) && ((i + m) >= 0)) && (((j + n) <= (width - 1)) && ((j + n) >= 0))){
                        holderRed += copy[i + m][j + n].rgbtRed;
                        holderGreen += copy[i + m][j + n].rgbtGreen;
                        holderBlue += copy[i + m][j + n].rgbtBlue;
                        counter++;
                    }
                }
            }

            image[i][j].rgbtRed = round(holderRed/counter);
            image[i][j].rgbtGreen = round(holderGreen/counter);
            image[i][j].rgbtBlue = round(holderBlue/counter);
        }
    }

    return;
}
