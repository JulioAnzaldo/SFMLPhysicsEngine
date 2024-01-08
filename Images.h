//
// Created by Julio Anzaldo on 3/5/22.
//

#ifndef GUIPROJECT_IMAGES_H
#define GUIPROJECT_IMAGES_H
#include "EnumNames.h"
#include <map>
#include <SFML/Graphics.hpp>

class Images {
private:
    //Map that holds all the images
    static std::map<ImageNames, sf::Texture> images;
    //Returns content root of images
    static std::string getImagePath(ImageNames imageNames);
    //Sets image in the map accordingly
    static void loadImage(ImageNames imageNames);
public:
    //Returns image as a texture
    static sf::Texture& getImage(ImageNames imageNames);
};

#endif //GUIPROJECT_IMAGES_H
