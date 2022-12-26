#include "Data/SongList.hpp"

DEFINE_TYPE(Endless::Data, SimpleSongList);
DEFINE_TYPE(Endless::Data, PlayedSongList);

using namespace Endless::Data;

void SimpleSongList::ctor() {
    this->_list = {};
}

void PlayedSongList::addSong(EndlessSong song) {
    this->_list.push_back(song);
}

void PlayedSongList::clear() {
    this->_list = {};
}