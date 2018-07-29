#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

class Config
{
    public:
        enum Settings{WIDTHSCREEN, HEIGHTSCREEN, WIDTH, HEIGHT, FULLSCREEN, BORDERSIZE, SOUND, MUSIC};

        Config();

        void readSetting(int ID);
        void updateBuild();
        int getBuild();
        int getSetting(int ID);
        void open();
        void close();
        void stepToLine(int line);
    private:
        fstream configFile;

        ifstream buildFileR;
        ofstream buildFileW;

        int widthScreen, heightScreen, width, height, fullscreen, bordersize, sound, music;

        int build;
};

#endif // CONFIG_H
