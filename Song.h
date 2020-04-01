//
// Created by Austin~ on 3/30/2020.
//

#include <string>
#include <iostream>
using namespace std;
#ifndef UNTITLED_SONG_H
#define UNTITLED_SONG_H


class Song {
    private:
        string Artist;
        string Title;
        int Size;

    public:
    //Constructor
    Song(){
        Artist = "";
        Title = "";
        Size = 0;
    }

    Song(string artist, string title, int size){
        Artist = artist;
        Title = title;
        Size = size;
    };

    string getArtist() const
    {return Artist;}
    string getTitle() const
    {return Title;}
    int getSize() const
    {return Size;}


    ~Song(){
    }


};


#endif //UNTITLED_SONG_H
