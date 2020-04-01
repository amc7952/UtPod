//
// Created by Austin~ on 3/30/2020.
//

#include "Song.h"

Song::Song(){
    Artist = "";
    Title = "";
    Size = 0;
}

Song::Song(string artist, string title, int size){
    Artist = artist;
    Title = title;
    Size = size;
}

string Song::getArtist() const{
    return Artist;
}

string Song::getTitle() const{
    return Title;
}

int Song::getSize() const{
    return Size;
}

bool Song::operator ==(const Song s1){
    return (Artist == s1.Artist) && (Title == s1.Title) && (Size == s1.Size);
}

bool Song::operator >(const Song s1){
    if (Artist > s1.Artist) {
        return true;
    }
    if ((Artist == s1.Artist) && (Title > s1.Title)){
        return true;
    }
    return (Artist == s1.Artist) && (Title == s1.Title) && (Size > s1.Size);
}


bool Song::operator <(const Song s1){
    if (Artist < s1.Artist) {
        return true;
    }
    if ((Artist == s1.Artist) && (Title < s1.Title)){
        return true;
    }
    return (Artist == s1.Artist) && (Title == s1.Title) && (Size < s1.Size);
}

