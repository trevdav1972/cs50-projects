#include "helpers.h"
#include "stdio.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float ave = image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen;
            ave = ave / 3.0;
            ave = round(ave);
            image[i][j].rgbtBlue = ave;
            image[i][j].rgbtRed = ave;
            image[i][j].rgbtGreen = ave;
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
            int red = image[i][j].rgbtRed;
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;
            float sepiaRed = .393 * red + .769 * green + .189 * blue;
            float sepiaGreen = .349 * red + .686 * green + .168 * blue;
            float sepiaBlue = .272 * red + .534 * green + .131 * blue;
            sepiaRed = round(sepiaRed);
            sepiaGreen = round(sepiaGreen);
            sepiaBlue = round(sepiaBlue);
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        RGBTRIPLE images[width];
        for (int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;
            images[j].rgbtRed = red;
            images[j].rgbtGreen = green;
            images[j].rgbtBlue = blue;
        }
        for (int j = 0; j < width; j++)
        {
            image[i][width - j - 1].rgbtRed = images[j].rgbtRed;
            image[i][width - j - 1].rgbtBlue = images[j].rgbtBlue;
            image[i][width - j - 1].rgbtGreen = images[j].rgbtGreen;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE images[height][width];
    float redtmp = 0;
    float greentmp = 0;
    float bluetmp = 0;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			images[i][j] = image[i][j];
		}
	}
    for (int i = 0; i < height; i++)
    {
            for (int j = 0; j < width; j++)
            {
                //top left
                if (j == 0 && i == 0)
                {
                redtmp =
                    images[i][j].rgbtRed +
                    images[i+1][j].rgbtRed +
                    images[i+1][j + 1].rgbtRed +
                    images[i][j + 1].rgbtRed;
                greentmp =
                    images[i][j].rgbtGreen +
                    images[i+1][j].rgbtGreen +
                    images[i+1][j + 1].rgbtGreen +
                    images[i][j + 1].rgbtGreen;
                bluetmp =
                    images[i][j].rgbtBlue +
                    images[i+1][j].rgbtBlue +
                    images[i+1][j + 1].rgbtBlue +
                    images[i][j + 1].rgbtBlue;
                    image[i][j].rgbtRed = round (redtmp / 4);
                    image[i][j].rgbtGreen = round (greentmp / 4);
                    image[i][j].rgbtBlue = round (bluetmp / 4);
                }
                //top middle
                if (j != 0 && j != width - 1 && i == 0)
                {
                redtmp =
                    images[i][j].rgbtRed +
                    images[i][j-1].rgbtRed +
                    images[i][j + 1].rgbtRed +
                    images[i + 1][j].rgbtRed +
                    images[i + 1][j-1].rgbtRed +
                    images[i + 1][j + 1].rgbtRed;
                greentmp =
                    images[i][j].rgbtGreen +
                    images[i][j-1].rgbtGreen +
                    images[i][j + 1].rgbtGreen +
                    images[i + 1][j].rgbtGreen +
                    images[i + 1][j-1].rgbtGreen +
                    images[i + 1][j + 1].rgbtGreen;
                bluetmp =
                    images[i][j].rgbtBlue +
                    images[i][j-1].rgbtBlue +
                    images[i][j + 1].rgbtBlue +
                    images[i + 1][j].rgbtBlue +
                    images[i + 1][j-1].rgbtBlue +
                    images[i + 1][j + 1].rgbtBlue;
                    image[i][j].rgbtRed = round (redtmp / 6);
                    image[i][j].rgbtGreen = round (greentmp / 6);
                    image[i][j].rgbtBlue = round (bluetmp / 6);
                }
                //top right
                if (j == width - 1 && i == 0)
                {
                redtmp =
                    images[i][j].rgbtRed +
                    images[i + 1][j].rgbtRed +
                    images[i + 1][j - 1].rgbtRed +
                    images[i][j - 1].rgbtRed;
                greentmp =
                    images[i][j].rgbtGreen +
                    images[i + 1][j].rgbtGreen +
                    images[i + 1][j - 1].rgbtGreen +
                    images[i][j - 1].rgbtGreen;
                bluetmp =
                    images[i][j].rgbtBlue +
                    images[i + 1][j].rgbtBlue +
                    images[i + 1][j - 1].rgbtBlue +
                    images[i][j - 1].rgbtBlue;
                    image[i][j].rgbtRed = round (redtmp / 4);
                    image[i][j].rgbtGreen = round (greentmp / 4);
                    image[i][j].rgbtBlue = round (bluetmp / 4);
                }
                //bottom left
                if (j == 0 && i == height -1)
                {
                redtmp =
                    images[i][j].rgbtRed +
                    images[i - 1][j].rgbtRed +
                    images[i - 1][j + 1].rgbtRed +
                    images[i][j + 1].rgbtRed;
                greentmp =
                    images[i][j].rgbtGreen +
                    images[i - 1][j].rgbtGreen +
                    images[i - 1][j + 1].rgbtGreen +
                    images[i][j + 1].rgbtGreen;
                bluetmp =
                    images[i][j].rgbtBlue +
                    images[i - 1][j].rgbtBlue +
                    images[i - 1][j + 1].rgbtBlue +
                    images[i][j + 1].rgbtBlue;
                    image[i][j].rgbtRed = round (redtmp / 4);
                    image[i][j].rgbtGreen = round (greentmp / 4);
                    image[i][j].rgbtBlue = round (bluetmp / 4);
                }
                //top right
                if (j == width - 1 && i == height - 1)
                {
                redtmp =
                    images[i][j].rgbtRed +
                    images[i - 1][j].rgbtRed +
                    images[i - 1][j - 1].rgbtRed +
                    images[i][j - 1].rgbtRed;
                greentmp =
                    images[i][j].rgbtGreen +
                    images[i - 1][j].rgbtGreen +
                    images[i - 1][j - 1].rgbtGreen +
                    images[i][j - 1].rgbtGreen;
                bluetmp =
                    images[i][j].rgbtBlue +
                    images[i - 1][j].rgbtBlue +
                    images[i - 1][j - 1].rgbtBlue +
                    images[i][j - 1].rgbtBlue;
                    image[i][j].rgbtRed = round (redtmp / 4);
                    image[i][j].rgbtGreen = round (greentmp / 4);
                    image[i][j].rgbtBlue = round (bluetmp / 4);
                }
                //middle left
                if ( j == 0 && i != 0 && i != height - 1)
                {
                redtmp =
                    images[i][j].rgbtRed +
                    images[i + 1][j].rgbtRed +
                    images[i + 1][j + 1].rgbtRed +
                    images[i][j + 1].rgbtRed +
                    images[i - 1][j].rgbtRed +
                    images[i - 1][j + 1].rgbtRed;
                greentmp =
                    images[i][j].rgbtGreen +
                    images[i + 1][j].rgbtGreen +
                    images[i + 1][j + 1].rgbtGreen +
                    images[i][j + 1].rgbtGreen +
                    images[i - 1][j].rgbtGreen +
                    images[i - 1][j + 1].rgbtGreen;
                bluetmp =
                    images[i][j].rgbtBlue +
                    images[i + 1][j].rgbtBlue +
                    images[i + 1][j + 1].rgbtBlue +
                    images[i][j + 1].rgbtBlue +
                    images[i - 1][j].rgbtBlue +
                    images[i - 1][j + 1].rgbtBlue;
                    image[i][j].rgbtRed = round (redtmp / 6);
                    image[i][j].rgbtGreen = round (greentmp / 6);
                    image[i][j].rgbtBlue = round (bluetmp / 6);
                }

                if (i == height - 1 && j != 0 && j != width - 1)
                {
                redtmp =
                    images[i][j].rgbtRed +
                    images[i][j - 1].rgbtRed +
                    images[i - 1][j - 1].rgbtRed +
                    images[i - 1][j].rgbtRed +
                    images[i - 1][j + 1].rgbtRed +
                    images[i][j + 1].rgbtRed;
                greentmp =
                    images[i][j].rgbtGreen +
                    images[i][j - 1].rgbtGreen +
                    images[i - 1][j - 1].rgbtGreen +
                    images[i - 1][j].rgbtGreen +
                    images[i - 1][j + 1].rgbtGreen +
                    images[i][j + 1].rgbtGreen;
                bluetmp =
                    images[i][j].rgbtBlue +
                    images[i][j - 1].rgbtBlue +
                    images[i - 1][j - 1].rgbtBlue +
                    images[i - 1][j].rgbtBlue +
                    images[i - 1][j + 1].rgbtBlue +
                    images[i][j + 1].rgbtBlue;
                    image[i][j].rgbtRed = round (redtmp / 6);
                    image[i][j].rgbtGreen = round (greentmp / 6);
                    image[i][j].rgbtBlue = round (bluetmp / 6);
                }

                if (j == width - 1 && i != 0 && i != height - 1)
                {
                redtmp =
                    images[i][j].rgbtRed +
                    images[i - 1][j].rgbtRed +
                    images[i - 1][j - 1].rgbtRed +
                    images[i][j - 1].rgbtRed +
                    images[i + 1][j - 1].rgbtRed +
                    images[i + 1][j].rgbtRed;
                greentmp =
                    images[i][j].rgbtGreen +
                    images[i - 1][j].rgbtGreen +
                    images[i - 1][j - 1].rgbtGreen +
                    images[i][j - 1].rgbtGreen +
                    images[i + 1][j - 1].rgbtGreen +
                    images[i + 1][j].rgbtGreen;
                bluetmp =
                    images[i][j].rgbtBlue +
                    images[i - 1][j].rgbtBlue +
                    images[i - 1][j - 1].rgbtBlue +
                    images[i][j - 1].rgbtBlue +
                    images[i + 1][j - 1].rgbtBlue +
                    images[i + 1][j].rgbtBlue;
                    image[i][j].rgbtRed = round (redtmp / 6);
                    image[i][j].rgbtGreen = round (greentmp / 6);
                    image[i][j].rgbtBlue = round (bluetmp / 6);
                }

                if (j != 0 && i != 0 && j != width - 1 && i != height -1)
                {

                    redtmp =
                        images[i][j].rgbtRed +
                        images[i - 1][j].rgbtRed +
                        images[i - 1][j - 1].rgbtRed +
                        images[i - 1][j + 1].rgbtRed +
                        images[i][j - 1].rgbtRed +
                        images[i][j + 1].rgbtRed +
                        images[i + 1][j + 1].rgbtRed +
                        images[i + 1][j - 1].rgbtRed +
                        images[i + 1][j].rgbtRed;
                    greentmp =
                        images[i][j].rgbtGreen +
                        images[i - 1][j].rgbtGreen +
                        images[i - 1][j - 1].rgbtGreen +
                        images[i - 1][j + 1].rgbtGreen +
                        images[i][j - 1].rgbtGreen +
                        images[i][j + 1].rgbtGreen +
                        images[i + 1][j + 1].rgbtGreen +
                        images[i + 1][j - 1].rgbtGreen +
                        images[i + 1][j].rgbtGreen;
                    bluetmp =
                        images[i][j].rgbtBlue +
                        images[i - 1][j].rgbtBlue +
                        images[i - 1][j - 1].rgbtBlue +
                        images[i - 1][j + 1].rgbtBlue +
                        images[i][j - 1].rgbtBlue +
                        images[i][j + 1].rgbtBlue +
                        images[i + 1][j + 1].rgbtBlue +
                        images[i + 1][j - 1].rgbtBlue +
                        images[i + 1][j].rgbtBlue;
                    image[i][j].rgbtRed = round (redtmp / 9);
                    image[i][j].rgbtGreen = round (greentmp / 9);
                    image[i][j].rgbtBlue = round (bluetmp / 9);
                }
            }
    }
    return;
}
