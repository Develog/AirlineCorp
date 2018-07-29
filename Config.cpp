#include "Config.h"

Config::Config()
{

}

void Config::readSetting(int ID)
{
    this->open();
    switch(ID)
    {
        case WIDTHSCREEN:
            configFile.ignore(numeric_limits<int>::max(), ':');
            configFile >> widthScreen;
            break;

        case HEIGHTSCREEN:
            this->stepToLine(1);
            configFile.ignore(numeric_limits<int>::max(), ':');
            configFile >> heightScreen;
            break;

        case WIDTH:
            this->stepToLine(2);
            configFile.ignore(numeric_limits<int>::max(), ':');
            configFile >> width;
            break;

        case HEIGHT:
            this->stepToLine(3);
            configFile.ignore(numeric_limits<int>::max(), ':');
            configFile >> height;
            break;

        case FULLSCREEN:
            this->stepToLine(4);
            configFile.ignore(numeric_limits<int>::max(), ':');
            configFile >> fullscreen;
            break;

        case BORDERSIZE:
            this->stepToLine(5);
            configFile.ignore(numeric_limits<int>::max(), ':');
            configFile >> bordersize;
            break;

        case SOUND:
            this->stepToLine(6);
            configFile.ignore(numeric_limits<int>::max(), ':');
            configFile >> sound;
            break;

        case MUSIC:
            this->stepToLine(7);
            configFile.ignore(numeric_limits<int>::max(), ':');
            configFile >> music;
            break;
    }
    this->close();
}

void Config::updateBuild()
{
    buildFileR.open("Resource/Build.txt", ios::in);
    buildFileR >> build;
    buildFileR.close();

    buildFileW.open("Resource/Build.txt", ios::out | ios::trunc);
    buildFileW << build + 1;
    buildFileW.close();
}

int Config::getBuild()
{
    buildFileR.open("Resource/Build.txt", ios::in);
    buildFileR >> build;
    return build;
}

int Config::getSetting(int ID)
{
    this->readSetting(ID);
    switch(ID)
    {
        case WIDTHSCREEN:
            return widthScreen;
            break;

        case HEIGHTSCREEN:
            return heightScreen;
            break;

        case WIDTH:
            return width;
            break;

        case HEIGHT:
            return height;
            break;

        case FULLSCREEN:
            return fullscreen;
            break;

        case BORDERSIZE:
            return bordersize;
            break;

        case SOUND:
            return sound;
            break;

        case MUSIC:
            return music;
            break;
    }
}

void Config::open()
{
    configFile.open("Resource/Config.txt", fstream::in | fstream::out);
}

void Config::close()
{
    configFile.close();
}

void Config::stepToLine(int line)
{
    for(int i = 0; i < line; i++)
        configFile.ignore(numeric_limits<int>::max(), '\n');
}
