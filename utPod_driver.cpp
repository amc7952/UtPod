/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    UtPod t;

    Song s1("Beatles", "Hey Jude1", 4);
    int result = t.addSong(s1);
    cout << "result = " << result << endl;

    Song s2("ABBA", "Mamma Mia", 200);

    Song s3("Smash Mouth", "All Star", 42);

    t.addSong(s2);
    t.addSong(s1);
    t.addSong(s2);
    t.addSong(s1);
    cout << t.addSong(s2) << endl;
    t.addSong(s1);

    cout << "Total Memory = " << t.getTotalMemory() << endl;
    cout << "Remaining Memory = " << t.getRemainingMemory() << endl << endl;

    t.showSongList();
    t.removeSong(s1);
    t.showSongList();

    t.addSong(s3);

    t.shuffle();
    t.showSongList();
    t.shuffle();
    t.showSongList();
    t.shuffle();
    t.showSongList();
    t.sortSongList();
    t.showSongList();

}