#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height ; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float average = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0;
            image[i][j].rgbtBlue = round(average);
            image[i][j].rgbtGreen = round(average);
            image[i][j].rgbtRed = round(average);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sred = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
            int sgreen = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            int sblue = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);

            image[i][j].rgbtRed = sred > 255 ? 255 : sred;
            image[i][j].rgbtGreen = sgreen > 255 ? 255 : sgreen;
            image[i][j].rgbtBlue = sblue > 255 ? 255 : sblue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        int rwidth = width - 1;
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][rwidth];
            image[i][rwidth] = temp;
            rwidth--;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int count = 0;
            float red = 0, blue = 0, green = 0;
            int iCoord[]  = {i-1, i, i+1};
            int jCoord[]  = {j-1, j, j+1};
            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    int curI = iCoord[x];
                    int curJ = jCoord[y];

                    if (curI >= 0 && curI < height && curJ >= 0 && curJ < width)
                    {
                        RGBTRIPLE pixel = image[curI][curJ];
                        red += pixel.rgbtRed;
                        blue += pixel.rgbtBlue;
                        green += pixel.rgbtGreen;
                        count++;
                    }
                }
            }
            temp[i][j].rgbtRed = round(red / count);
            temp[i][j].rgbtBlue = round(blue / count);
            temp[i][j].rgbtGreen = round(green / count);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}
