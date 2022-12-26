#pragma once

#include "Endless.hpp"

namespace Endless::Data {
    struct EndlessSong {
        StringW levelID;
        int diffIndex;
        std::optional<float> startTime;
        std::optional<float> length;
        std::optional<StringW> source;
    };
}

// Must be custom-types class so we can zenject it.
DECLARE_CLASS_CODEGEN(Endless::Data, SimpleSongList, Il2CppObject,
    DECLARE_CTOR(ctor);
    public:
        std::vector<EndlessSong> _list;
)

DECLARE_CLASS_CUSTOM(Endless::Data, PlayedSongList, SimpleSongList,
    DECLARE_DEFAULT_CTOR();
    public:
        void addSong(EndlessSong song);
        void clear();
)