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
    //Constructors
    //Default Constructor, sets song to " ", " ", 0.
    Song();
    Song(string artist, string title, int size);

    //Returns artist of song
    string getArtist() const;
    //Returns title of song
    string getTitle() const;
    //Returns size of song
    int getSize() const;

    //All three parameters must be identical.
    bool operator ==(Song s1);
    //Artist>Title>Song. a<b, 3<5.
    bool operator >(Song s1);
    //Artist>Title>Song. a<b, 3<5.
    bool operator <(Song s1);


    ~Song(){
    }


};


#endif //UNTITLED_SONG_H
