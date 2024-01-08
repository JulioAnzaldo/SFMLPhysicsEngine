//
// Created by Julio Anzaldo on 3/22/22.
//

#ifndef GUIPROJECT_FONTS_H
#define GUIPROJECT_FONTS_H
#include <SFML/Graphics.hpp>
#include "EnumNames.h"
#include <map>

class Fonts {
private:
    static std::vector<sf::Font> fonts;
    static std::vector<bool> loadedFonts;

    static std::string getFontPath(FontNames fontNames);

    static void loadFont(FontNames fontNames, std::string filepath);
    static void loadFont(FontNames fontNames);
    static void loadFonts();
public:

    static sf::Font& getFont(FontNames fontNames);
    static std::string toString(FontNames fontNames);
};
#endif //GUIPROJECT_FONTS_H
