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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            double gxRed = 0;
            double gxGreen = 0;
            double gxBlue = 0;
            double gyRed = 0;
            double gyGreen = 0;
            double gyBlue = 0;

            for(int m = -1; m < 2; m++){
                for (int n = -1; n < 2; n++){
                    if ((((i + m) <= (height - 1)) && ((i + m) >= 0)) && (((j + n) <= (width - 1)) && ((j + n) >= 0))){
                        gxRed += copy[i + m][j + n].rgbtRed * gx[m+1][n+1];
                        gxGreen += copy[i + m][j + n].rgbtGreen * gx[m+1][n+1];
                        gxBlue += copy[i + m][j + n].rgbtBlue * gx[m+1][n+1];
                    }else{
                        gxRed += 0 * gx[m+1][n+1];
                        gxGreen += 0 * gx[m+1][n+1];
                        gxBlue += 0 * gx[m+1][n+1];
                    }
                }
            }

            for(int m = -1; m < 2; m++){
                for (int n = -1; n < 2; n++){
                    if ((((i + m) <= (height - 1)) && ((i + m) >= 0)) && (((j + n) <= (width - 1)) && ((j + n) >= 0))){
                        gyRed += copy[i + m][j + n].rgbtRed * gy[m+1][n+1];
                        gyGreen += copy[i + m][j + n].rgbtGreen * gy[m+1][n+1];
                        gyBlue += copy[i + m][j + n].rgbtBlue * gy[m+1][n+1];
                    }else{
                        gyRed += 0 * gy[m+1][n+1];
                        gyGreen += 0 * gy[m+1][n+1];
                        gyBlue += 0 * gy[m+1][n+1];
                    }
                }
            }

            double sobRed = (sqrt((gxRed * gxRed) + (gyRed * gyRed)));
            if (sobRed > 255){
                sobRed = 255;
            }
            double sobGreen = (sqrt((gxGreen * gxGreen) + (gyGreen * gyGreen)));
            if (sobGreen > 255){
                sobGreen = 255;
            }
            double sobBlue = (sqrt((gxBlue * gxBlue) + (gyBlue * gyBlue)));
            if (sobBlue > 255){
                sobBlue = 255;
            }

            image[i][j].rgbtRed = round(sobRed);
            image[i][j].rgbtGreen = round(sobGreen);
            image[i][j].rgbtBlue = round(sobBlue);

        }
    }
    return;
}
