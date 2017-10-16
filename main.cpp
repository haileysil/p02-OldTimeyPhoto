//Project 2 Functional Decomposition

#include <iostream>
#include <string>
#include <vector>
#include "bitmap.h"
#include <cstdlib>  

using namespace std;

int main()
{
        string imageName;

        Bitmap image;
        vector < vector <Pixel> > bmp;
        Pixel rgb;

        bool validBmp;

        do
        {

                //ask user for file name of an image
                cout<<"What is the name of the image you would like to convert to greyscale?"<<endl;
                cin>>imageName;

                //opens image
                image.open(imageName);
                
                validBmp = image.isImage();

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
                        image.fromPixelMatrix(bmp);
                        image.save("OldTimeyPhoto.bmp");
                }
                else 
                {
                        cout<<"This file is not a valid image. Please submit a new image."<<endl;
                }
        } while ( validBmp == false );

        return 0;
}
