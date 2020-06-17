#include "helpers.h"
#include <math.h>



// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int r;
    int g;
    int b;
    int avg;
    
    for (int row = 0; row < height; row++){
        for (int c = 0; c < width; c++){
            r = image[row][c].rgbtRed;
            g = image[row][c].rgbtGreen;
            b = image[row][c].rgbtBlue;
            
            avg = round((r+g+b)/3);
            
            image[row][c].rgbtRed = avg;
            image[row][c].rgbtGreen = avg;
            image[row][c].rgbtBlue = avg;
        }
    }
    
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE icopy[height][width];
    
    for (int row = 0; row < height; row++){
        for (int c = 0; c < width; c++){
            icopy[row][c].rgbtRed = image[row][c].rgbtRed;
            icopy[row][c].rgbtGreen = image[row][c].rgbtGreen;
            icopy[row][c].rgbtBlue = image[row][c].rgbtBlue;
        }
    }
    
    for (int row = 0; row < height; row++){
        for (int c = 0; c < width; c++){
            image[row][(width-1)-c].rgbtRed = icopy[row][c].rgbtRed;
            image[row][(width-1)-c].rgbtGreen = icopy[row][c].rgbtGreen;
            image[row][(width-1)-c].rgbtBlue = icopy[row][c].rgbtBlue;
        }
    }
    
    
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    
    /*for (int row = 0; row < height; row++){
        for (int c = 0; c < width; c++){
            
            int r = 0;
            int g = 0;
            int b = 0;
            int ravg = 0;
            int gavg = 0;
            int bavg = 0;
            
            
            if (row == 0)
            {
                if (c == 0)
                {
                    for (int i = 0; i <= row + 1; i++)
                    {
                        for (int k = 0; k <= c + 1; k++)
                        {
                            r += image[row][c].rgbtRed;
                            g += image[row][c].rgbtGreen;
                            b += image[row][c].rgbtBlue;
                        }
                    }
                    //averaging the colors
                    ravg = round(r/4);
                    gavg = round(g/4);
                    bavg = round(b/4);
                
                    //setting the color
                    image[row][c].rgbtRed = ravg;
                    image[row][c].rgbtGreen = gavg;
                    image[row][c].rgbtBlue = bavg;
                }
                else if (c == width - 1)
                {
                    for (int i = 0; i <= row + 1; i++)
                    {
                        for (int k = c - 1; k <= c; k++)
                        {
                            r += image[row][c].rgbtRed;
                            g += image[row][c].rgbtGreen;
                            b += image[row][c].rgbtBlue;
                        }
                    }
                    ravg = round(r/4);
                    gavg = round(g/4);
                    bavg = round(b/4);
                
                    //setting the color
                    image[row][c].rgbtRed = ravg;
                    image[row][c].rgbtGreen = gavg;
                    image[row][c].rgbtBlue = bavg;
                }
                else 
                {
                    for (int i = 0; i <= row + 1; i++)
                    {
                        for (int k = c-1; k <= c + 1; k++)
                        {
                            r += image[row][c].rgbtRed;
                            g += image[row][c].rgbtGreen;
                            b += image[row][c].rgbtBlue;
                        }
                    }
                    ravg = round(r/6);
                    gavg = round(g/6);
                    bavg = round(b/6);
                
                    //setting the color
                    image[row][c].rgbtRed = ravg;
                    image[row][c].rgbtGreen = gavg;
                    image[row][c].rgbtBlue = bavg;
                }
            }
            else if (row == height - 1)
            {
                if (c == 0)
                {
                    for (int i = row-1; i <= row; i++)
                    {
                        for (int k = 0; k <= c + 1; k++)
                        {
                            r += image[row][c].rgbtRed;
                            g += image[row][c].rgbtGreen;
                            b += image[row][c].rgbtBlue;
                        }
                    }
                    ravg = round(r/4);
                    gavg = round(g/4);
                    bavg = round(b/4);
                
                    //setting the color
                    image[row][c].rgbtRed = ravg;
                    image[row][c].rgbtGreen = gavg;
                    image[row][c].rgbtBlue = bavg;
                }
                else if (c == width - 1)
                {
                    for (int i = row-1; i <= row; i++)
                    {
                        for (int k = c - 1; k <= c; k++)
                        {
                            r += image[row][c].rgbtRed;
                            g += image[row][c].rgbtGreen;
                            b += image[row][c].rgbtBlue;
                        }
                    }
                    ravg = round(r/4);
                    gavg = round(g/4);
                    bavg = round(b/4);
                
                    //setting the color
                    image[row][c].rgbtRed = ravg;
                    image[row][c].rgbtGreen = gavg;
                    image[row][c].rgbtBlue = bavg;
                }
                else 
                {
                    for (int i = row-1; i <= row; i++)
                    {
                        for (int k = c-1; k <= c + 1; k++)
                        {
                            r += image[row][c].rgbtRed;
                            g += image[row][c].rgbtGreen;
                            b += image[row][c].rgbtBlue;
                        }
                    }
                    ravg = round(r/6);
                    gavg = round(g/6);
                    bavg = round(b/6);
                
                    //setting the color
                    image[row][c].rgbtRed = ravg;
                    image[row][c].rgbtGreen = gavg;
                    image[row][c].rgbtBlue = bavg;
                }
                
            }
            else if (c == 0)
            {
                for (int i = row-1; i <= row + 1; i++){
                    for (int k = 0; k <= c + 1; k++){
                        r += image[row][c].rgbtRed;
                        g += image[row][c].rgbtGreen;
                        b += image[row][c].rgbtBlue;
                    }
                }
                ravg = round(r/6);
                    gavg = round(g/6);
                    bavg = round(b/6);
                
                    //setting the color
                    image[row][c].rgbtRed = ravg;
                    image[row][c].rgbtGreen = gavg;
                    image[row][c].rgbtBlue = bavg;
            }
            else if (c == width - 1)
            {
                for (int i = row-1; i <= row + 1; i++){
                    for (int k = c - 1; k <= c; k++){
                        r += image[row][c].rgbtRed;
                        g += image[row][c].rgbtGreen;
                        b += image[row][c].rgbtBlue;
                    }
                }
                ravg = round(r/6);
                gavg = round(g/6);
                bavg = round(b/6);
                
                //setting the color
                image[row][c].rgbtRed = ravg;
                image[row][c].rgbtGreen = gavg;
                image[row][c].rgbtBlue = bavg;
            }
            //not edge
            else 
            {
                for (int i = row-1; i <= row + 1; i++)
                {
                    for (int k = c-1; k <= c + 1; k++)
                    {
                        r += image[row][c].rgbtRed;
                        g += image[row][c].rgbtGreen;
                        b += image[row][c].rgbtBlue;
                    }
                }
                //averaging the colors
                ravg = round(r/9);
                gavg = round(g/9);
                bavg = round(b/9);
                
                //setting the color
                image[row][c].rgbtRed = ravg;
                image[row][c].rgbtGreen = gavg;
                image[row][c].rgbtBlue = bavg;
            }
        }
    }*/
    
    RGBTRIPLE newImage[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            newImage[i][j] = image[i][j];
        }
    }

    for (int i = 0, red, green, blue, counter; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            red = green = blue = counter = 0;
            // add the center pixel
            if (i >= 0 && j >= 0)
            {
                red += newImage[i][j].rgbtRed;
                green += newImage[i][j].rgbtGreen;
                blue += newImage[i][j].rgbtBlue;
                counter++;
            }
            // add below pixel
            if (i >= 0 && j - 1 >= 0)
            {
                red += newImage[i][j-1].rgbtRed;
                green += newImage[i][j-1].rgbtGreen;
                blue += newImage[i][j-1].rgbtBlue;
                counter++;
            }
            // add right pixel
            if ((i >= 0 && j + 1 >= 0) && (i >= 0 && j + 1 < width))
            {
                red += newImage[i][j+1].rgbtRed;
                green += newImage[i][j+1].rgbtGreen;
                blue += newImage[i][j+1].rgbtBlue;
                counter++;
            }
            // add left pixel
            if (i - 1 >= 0 && j >= 0)
            {
                red += newImage[i-1][j].rgbtRed;
                green += newImage[i-1][j].rgbtGreen;
                blue += newImage[i-1][j].rgbtBlue;
                counter++;
            }
            // add left below pixel
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                red += newImage[i-1][j-1].rgbtRed;
                green += newImage[i-1][j-1].rgbtGreen;
                blue += newImage[i-1][j-1].rgbtBlue;
                counter++;
            }
            // add left upper pixel
            if ((i - 1 >= 0 && j + 1 >= 0) && (i - 1 >= 0 && j + 1 < width))
            {
                red += newImage[i-1][j+1].rgbtRed;
                green += newImage[i-1][j+1].rgbtGreen;
                blue += newImage[i-1][j+1].rgbtBlue;
                counter++;
            }
            // add upper pixel
            if ((i + 1 >= 0 && j >= 0) && (i + 1 < height && j >= 0))
            {
                red += newImage[i+1][j].rgbtRed;
                green += newImage[i+1][j].rgbtGreen;
                blue += newImage[i+1][j].rgbtBlue;
                counter++;
            }
            // add below right pixel
            if ((i + 1 >= 0 && j - 1 >= 0) && (i + 1 < height && j - 1 >= 0))
            {
                red += newImage[i+1][j-1].rgbtRed;
                green += newImage[i+1][j-1].rgbtGreen;
                blue += newImage[i+1][j-1].rgbtBlue;
                counter++;
            }
            // add upper right pixel
            if ((i + 1 >= 0 && j + 1 >= 0) && (i + 1 < height && j + 1 < width))
            {
                red += newImage[i+1][j+1].rgbtRed;
                green += newImage[i+1][j+1].rgbtGreen;
                blue += newImage[i+1][j+1].rgbtBlue;
                counter++;
            }

            image[i][j].rgbtRed = round(red / (counter * 1.0));
            image[i][j].rgbtGreen = round(green / (counter * 1.0));
            image[i][j].rgbtBlue = round(blue / (counter * 1.0));
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    
    RGBTRIPLE newImage[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            newImage[i][j] = image[i][j];
        }
    }

    for (int i = 0, redx, greenx, bluex, redy, greeny, bluey, rf, bf, gf; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            redx = greenx = bluex = redy = bluey = greeny = 0;
            // center pixel(zero for both)
            /*if (i >= 0 && j >= 0)
            {
                red += newImage[i][j].rgbtRed;
                green += newImage[i][j].rgbtGreen;
                blue += newImage[i][j].rgbtBlue;
                counter++;
            }*/
            // gy below pixel (zero for x)
            if (i >= 0 && j - 1 >= 0)
            {
                redy += newImage[i][j-1].rgbtRed * 2;
                greeny += newImage[i][j-1].rgbtGreen * 2;
                bluey += newImage[i][j-1].rgbtBlue * 2;
                
            }
            // gx right pixel (0 for y)
            if ((i >= 0 && j + 1 >= 0) && (i >= 0 && j + 1 < width))
            {
                redx += newImage[i][j+1].rgbtRed * 2;
                greenx += newImage[i][j+1].rgbtGreen * 2;
                bluex += newImage[i][j+1].rgbtBlue * 2;
                
            }
            // gx left pixel (0 for y)
            if (i - 1 >= 0 && j >= 0)
            {
                redx += newImage[i-1][j].rgbtRed * -2;
                greenx += newImage[i-1][j].rgbtGreen * -2;
                bluex += newImage[i-1][j].rgbtBlue * -2;
                
            }
            // gx and gy left below pixel
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                //gx
                redx += newImage[i-1][j-1].rgbtRed * -1;
                greenx += newImage[i-1][j-1].rgbtGreen * -1;
                bluex += newImage[i-1][j-1].rgbtBlue * -1;
                //gy
                redy += newImage[i-1][j-1].rgbtRed * 1;
                greeny += newImage[i-1][j-1].rgbtGreen * 1;
                bluey += newImage[i-1][j-1].rgbtBlue * 1;
            }
            // gx and gy left upper pixel
            if ((i - 1 >= 0 && j + 1 >= 0) && (i - 1 >= 0 && j + 1 < width))
            {
                //gx
                redx += newImage[i-1][j+1].rgbtRed * -1;
                greenx += newImage[i-1][j+1].rgbtGreen * -1;
                bluex += newImage[i-1][j+1].rgbtBlue * -1;
                //gy
                redy += newImage[i-1][j+1].rgbtRed * -1;
                greeny += newImage[i-1][j+1].rgbtGreen * -1;
                bluey += newImage[i-1][j+1].rgbtBlue * -1;
            }
            // gy upper pixel (0 for x)
            if ((i + 1 >= 0 && j >= 0) && (i + 1 < height && j >= 0))
            {
                redy += newImage[i+1][j].rgbtRed * -2;
                greeny += newImage[i+1][j].rgbtGreen * -2;
                bluey += newImage[i+1][j].rgbtBlue * -2;
                
            }
            // gx and gy below right pixel
            if ((i + 1 >= 0 && j - 1 >= 0) && (i + 1 < height && j - 1 >= 0))
            {
                //gx
                redx += newImage[i+1][j-1].rgbtRed * 1;
                greenx += newImage[i+1][j-1].rgbtGreen * 1;
                bluex += newImage[i+1][j-1].rgbtBlue * 1;
                //gy
                redy += newImage[i+1][j-1].rgbtRed * 1;
                greeny += newImage[i+1][j-1].rgbtGreen * 1;
                bluey += newImage[i+1][j-1].rgbtBlue * 1;
            }
            // gx and gy upper right pixel
            if ((i + 1 >= 0 && j + 1 >= 0) && (i + 1 < height && j + 1 < width))
            {
                //gx
                redx += newImage[i+1][j+1].rgbtRed * 1;
                greenx += newImage[i+1][j+1].rgbtGreen * 1;
                bluex += newImage[i+1][j+1].rgbtBlue * 1;
                //gy
                redx += newImage[i+1][j+1].rgbtRed * -1;
                greenx += newImage[i+1][j+1].rgbtGreen * -1;
                bluex += newImage[i+1][j+1].rgbtBlue * -1;
            }
            rf = round(sqrt((pow(redx, 2)) + (pow(redy, 2))));
            gf = round(sqrt((pow(greenx, 2)) + (pow(greeny, 2))));
            bf = round(sqrt((pow(bluex,2)) + (pow(bluey,2))));
            
            
            if (rf > 255){
                image[i][j].rgbtRed = 255;
            }
            else{
                image[i][j].rgbtRed = rf;
            }
            
            if (gf > 255){
                image[i][j].rgbtGreen = 255;
            }
            else{
                image[i][j].rgbtGreen = gf;
            }
            
            if (bf > 255){
                image[i][j].rgbtBlue = 255;
            }
            else{
                image[i][j].rgbtBlue = bf;
            }
        }
    }
    
    
    
    return;
}
