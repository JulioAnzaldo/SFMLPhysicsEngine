//
// Created by Julio Anzaldo on 3/5/22.
//
#include "Images.h"

std::map<ImageNames, sf::Texture> Images::images;

std::string Images::getImagePath(ImageNames imageNames)
{
    switch(imageNames)
    {
        case EQUATIONS : return "/Users/julioanzaldo/Coding Projects/Physics Engine/Images/Equations.png";
        case LASTIMAGE : break;
    }
}

void Images::loadImage(ImageNames imageNames)
{
    images[imageNames].loadFromFile(getImagePath(imageNames));
}

sf::Texture &Images::getImage(ImageNames imageNames)
{
    loadImage(imageNames);
    return images[imageNames];
}