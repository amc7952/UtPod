#include <iostream>
#include <string>
#include "UtPod.h"

using namespace std;

UtPod::UtPod(){
    memSize = MAX_MEMORY;
    songs = NULL;
}

UtPod::UtPod(int size){
    if((size>MAX_MEMORY)||(size<=0)){
        memSize = MAX_MEMORY;
    }
    else{
        memSize = size;
    }
    songs = NULL;
}

int UtPod::addSong(Song const &s){
    int remainingMemory = getRemainingMemory();
    int songSize = s.getSize();
    if (songSize>remainingMemory){
        return -1;
    }
    SongNode *temp = songs;
    SongNode* newNode = new SongNode;
    newNode->s = s;
    songs = newNode;
    newNode->next = temp;
    return 0;
}

int UtPod::removeSong(Song const &s){
    SongNode *prevTemp=NULL;
    SongNode *temp = songs;
    string artist = s.getArtist();
    string title = s.getTitle();
    int size = s.getSize();
    while (temp!=NULL){
        string _artist = temp->s.getArtist();
        string _title = temp->s.getTitle();
        int _size = temp->s.getSize();
        if((artist==_artist)&&(title==_title)&&(size==_size)){
            if(temp==songs){
                songs=songs->next;
            }
            else{
                prevTemp->next = temp->next;
            }
            return 0;
        }
        prevTemp = temp;
        temp = temp->next;
    }
    return -2;

}

void UtPod::showSongList(){
    if(songs==NULL){
        cout << "Empty\n";
    }
    SongNode *p = songs;
    while(p!=NULL) {
        cout << p->s.getArtist() << ", ";
        cout << p->s.getTitle() << ", ";
        cout << p->s.getSize() << endl;
        p = p->next;
    }
}

void UtPod::sortSongList(){
    int sort = 1;
    while(sort==1){
        sort=0;
        SongNode *p = songs;
        while(p->next!=NULL){
            if((p->s)>(p->next->s)) {
                cout << "trying to sort";
                Song temp = p->next->s;
                p->next->s = p->s;
                p->s = temp;
                sort=1;
            }
            p = p->next;
        }
    }
}

void UtPod::clearMemory(){
    while (songs!=NULL){
        SongNode *temp = songs;
        songs = songs->next;
        delete temp;
    }
}

int UtPod::getRemainingMemory(){
    SongNode *temp = songs;
    int remainingMemory = memSize;
    while (temp!=NULL){
        int songSize = temp->s.getSize();
        remainingMemory = remainingMemory - songSize;
        temp = temp->next;
    }
    return remainingMemory;
}

UtPod::~UtPod(){
    while (songs!=NULL){
        SongNode *temp = songs;
        songs = songs->next;
        delete temp;
    }
    cout<< "\nGoodbye World" << endl;
}