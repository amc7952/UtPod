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
    Song();
    Song(string artist, string title, int size);

    string getArtist() const;
    string getTitle() const;
    int getSize() const;

    bool operator ==(Song s1);
    bool operator >(Song s1);
    bool operator <(Song s1);


    ~Song(){
    }


};


#endif //UNTITLED_SONG_H
