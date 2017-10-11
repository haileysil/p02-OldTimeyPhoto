//Project 2 Functional Decomposition

#include <iostream>
#include <string>
#include <vector>
#include "bitmap.h"
#include <cstdlib>  

using namespace std;

int main()
{
        /*

           -ask user for file name of an image
           -convert image so every pixel is greyscale
           -test to make sure the picture has been saved
           -convert image to a vector of vectors, i.e. a matrix, of pixels
           -for the pixel located at [0][0], find the integer values of the 3 components R/G/B
           -find the average of the three values
           -assign all 3 components to that average value
           -repeat as long as the counter is less than the number of elements in that row
           -repeat for every row and element in each row

         */

        // after code has compiled successfully:
        //update/save file with different name
        // add, commit, push onto github

        Bitmap image;
        vector <vector <Pixel> > bmp;
        Pixel rgb;

        image.open("machupicchu.bmp");

        /*
           int numRows = bmp.size();
           int numCols = bmp[0].size();

           cout<<"machupicchu.bmp has been loaded. It is "<<numCols<<" pixels wide and "<<numRows<<" pixels high."<<endl;
         */

        bool validBmp = image.isImage();

        if ( validBmp == true )
        {
                bmp = image.toPixelMatrix();

                for (int r = 0; r < bmp.size(); r++)
                {
                        for (int c = 0; c < bmp[r].size(); c++)
                        {
                        rgb = bmp[r][c];

                        //convert pixels to black and white
                        int avgColor = (rgb.red + rgb.green + rgb.blue)/3;
                        rgb.red = avgColor;
                        rgb.green = avgColor;
                        rgb.blue = avgColor;
                        bmp[r][c] = rgb; 
                        }

                }
//        image.fromPixelMatrix(bmp);
//        image.save("machupicchu.bmp");
        }
        else 
        {
                cout<<"This file is not a valid image. Please try again or submit a new image."<<endl;
        }
        return 0;
}
