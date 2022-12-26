#include "Data/MapPool.hpp"

static bool IsDiffValid(int validDiffsMask, GlobalNamespace::BeatmapDifficulty diff) {
    return (validDiffsMask & (1 << (int)diff)) != 0;
}

static StringW GetHashOfLevelid(StringW levelid) {
    if(levelid->get_Length() < 53 || levelid[12] != '_')
        return "";

    return levelid->Substring(13, 40);
}

static StringW GetLevelIdWithoutUniquenessAddition(StringW levelid) {
    if(levelid->get_Length() <= 53)
        return levelid;

    return levelid->Substring(0, 53);
}

static StringW GetHashOfPreview(GlobalNamespace::IPreviewBeatmapLevel* preview) {
    if(preview->get_levelID()->get_Length() < 53)
        return "";

    return GetHashOfLevelid(preview->get_levelID());
}

DEFINE_TYPE(Endless::Data, ValidSong);
DEFINE_TYPE(Endless::Data, MapPool);

using namespace Endless::Data;

void ValidSong::ctor(GlobalNamespace::IPreviewBeatmapLevel *_level) {
    this->level = _level;
    this->bitsum_validDiffs = 0;
}

GlobalNamespace::BeatmapDifficulty ValidSong::GetRandomValidDiff() {
    int range = GlobalNamespace::BeatmapDifficulty::ExpertPlus - 0 + 1;
    int start = getEndlessConfig().gameplay_prefer_top_difficulty.GetValue() ? 0 : rand() % range + 0;

    int m = 1 + (int)GlobalNamespace::BeatmapDifficulty::ExpertPlus;

    for(int i = m; i-- > 0;) {
        int x = (start + i) % m;

        if((this->bitsum_validDiffs & (1 << x)) != 0)
            return x;
    }
    return 0;
}

void ValidSong::SetDiffValid(GlobalNamespace::BeatmapDifficulty diff) {
    this->bitsum_validDiffs |= (1 << diff);
}

void MapPool::ctor(GlobalNamespace::BeatmapLevelsModel *_beatmapLevelsModel) {
    this->beatmapLevelsModel = _beatmapLevelsModel;
}

void MapPool::Clear() {
    this->filteredLevels->Clear();
}

void MapPool::Dispose() {
    this->Clear();
}

#include "songloader/shared/API.hpp"

ValidSong *MapPool::LevelFilterCheck(GlobalNamespace::IPreviewBeatmapLevel *level,
                                     System::Runtime::CompilerServices::ConditionalWeakTable_2<GlobalNamespace::IBeatmapLevel *, ArrayW<GlobalNamespace::BeatmapDifficulty>> *playlistSongs = nullptr,
                                     bool forceNoFilters = false) {
    if(!forceNoFilters) {
        if(level->get_songDuration() - level->get_songTimeOffset() < minSongLength) {
            return ValidSong::New_ctor(level);
        }

        if(getEndlessConfig().filter_advancedEnabled.GetValue() && level->get_beatsPerMinute() < getEndlessConfig().filter_bps_max.GetValue()) {
            return ValidSong::New_ctor(level);
        }
    }

    ArrayW<GlobalNamespace::BeatmapDifficulty> playlistDiffs = {};

    if(playlistSongs != nullptr) {
        if(!playlistSongs->TryGetValue(reinterpret_cast<GlobalNamespace::IBeatmapLevel *>(level), nullptr)) {
            return ValidSong::New_ctor(level);
        }
    }

    auto songHash = GetHashOfPreview(level);
    std::map<GlobalNamespace::BeatmapDifficulty,

}