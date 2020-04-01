#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "UtPod.h"

using namespace std;

UtPod::UtPod(){
    memSize = MAX_MEMORY;
    songs = NULL;
    unsigned int currentTime = (unsigned) time(0);
    srand(currentTime);
}

UtPod::UtPod(int size){
    if((size>MAX_MEMORY)||(size<=0)){
        memSize = MAX_MEMORY;
    }
    else{
        memSize = size;
    }
    songs = NULL;
    unsigned int currentTime = (unsigned) time(0);
    srand(currentTime);
}

int UtPod::addSong(Song const &s){
    int remainingMemory = getRemainingMemory();
    int songSize = s.getSize();
    if (songSize>remainingMemory){
        return NO_MEMORY;
    }
    SongNode *temp = songs;
    SongNode* newNode = new SongNode;
    newNode->s = s;
    songs = newNode;
    newNode->next = temp;
    return SUCCESS;
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
        //Checks if all three entries are identical. If so, deletes it.
        if((artist==_artist)&&(title==_title)&&(size==_size)){
            if(temp==songs){
                songs=songs->next;
                delete temp;
            }
            else{
                prevTemp->next = temp->next;
                delete temp;
            }
            return SUCCESS;
        }
        prevTemp = temp;
        temp = temp->next;
    }
    return NOT_FOUND;
}

void UtPod::shuffle(){
    int numSongs=0;
    SongNode *p = songs;
    while (p!=NULL){
        numSongs++;
        p = p->next;
    }
    //Randomly selects two nodes, swaps their data. Repeats this process five times the number of songs.
    for(int i=0;i<5*numSongs;i++) {
        SongNode *node1 = songs;
        SongNode *node2 = songs;
        int num1 = (rand() % numSongs);
        int num2 = (rand() % numSongs);
        while (num1 != 0) {
            node1 = node1->next;
            num1--;
        }
        while (num2 != 0) {
            node2 = node2->next;
            num2--;
        }
        Song temp = node2->s;
        node2->s = node1->s;
        node1->s = temp;
    }
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
    cout << endl;
}

void UtPod::sortSongList(){
    int sort = 1;
    //Continue sorting until until the list has been fully traversed with no swaps.
    while(sort==1){
        sort=0;
        SongNode *p = songs;
        while(p->next!=NULL){
            if((p->s)>(p->next->s)) {
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