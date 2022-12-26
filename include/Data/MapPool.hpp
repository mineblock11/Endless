#pragma once

#include "Endless.hpp"

#include "GlobalNamespace/BeatmapDifficulty.hpp"
#include "GlobalNamespace/IPreviewBeatmapLevel.hpp"
#include "GlobalNamespace/IBeatmapLevel.hpp"
#include "GlobalNamespace/BeatmapLevelsModel.hpp"
#include "System/Runtime/CompilerServices/ConditionalWeakTable_2.hpp"
#include "System/IDisposable.hpp"

#include "beatsaber-hook/shared/utils/byref.hpp"

static bool IsDiffValid(int validDiffsMask, GlobalNamespace::BeatmapDifficulty diff);

static StringW GetHashOfLevelid(StringW levelid);
static StringW GetLevelIdWithoutUniquenessAddition(StringW levelid);
static StringW GetHashOfPreview(GlobalNamespace::IPreviewBeatmapLevel* preview);


namespace Endless::Data {
    // Credits; SongCore
    struct RequirementData
    {
    public:
        ArrayW<StringW> _requirements;
        ArrayW<StringW> _suggestions;
        ArrayW<StringW> _warnings;
        ArrayW<StringW> _information;
    };

    class MapColor
    {
    public:
        float r;
        float g;
        float b;

        MapColor(float _r, float _g, float _b) {
            this->r = _r;
            this->g = _g;
            this->b = _b;
        }
    };

    struct DifficultyData {
    public:
        StringW _beatmapCharacteristicName;
        GlobalNamespace::BeatmapDifficulty _difficulty;
        StringW _difficultyLabel;
        RequirementData additionalDifficultyData;
        std::optional<MapColor> _colorLeft;
        std::optional<MapColor> _colorRight;
        std::optional<MapColor> _envColorLeft;
        std::optional<MapColor> _envColorRight;
        std::optional<MapColor> _envColorLeftBoost;
        std::optional<MapColor> _envColorRightBoost;
        std::optional<MapColor> _obstacleColor;

        DifficultyData fromJson() {

        }
    };
}


DECLARE_CLASS_CODEGEN(Endless::Data, ValidSong, Il2CppObject,
                    DECLARE_INSTANCE_FIELD(GlobalNamespace::IPreviewBeatmapLevel*, level);
                    DECLARE_INSTANCE_FIELD(int, bitsum_validDiffs);
                    DECLARE_CTOR(ctor, GlobalNamespace::IPreviewBeatmapLevel* _level);
                    DECLARE_INSTANCE_METHOD(GlobalNamespace::BeatmapDifficulty, GetRandomValidDiff);
                    DECLARE_INSTANCE_METHOD(void, SetDiffValid, GlobalNamespace::BeatmapDifficulty diff);
)

DECLARE_CLASS_CODEGEN(Endless::Data, MapPool, System::IDisposable,
                    // READONLY DO NOT SET
                    DECLARE_INSTANCE_FIELD_PRIVATE(GlobalNamespace::BeatmapLevelsModel*, beatmapLevelsModel);
                    DECLARE_CTOR(ctor, GlobalNamespace::BeatmapLevelsModel* _beatmapLevelsModel);
                    DECLARE_INSTANCE_FIELD(StringW, currentPlaylistFilter);
                    DECLARE_INSTANCE_FIELD(ListWrapper<ValidSong*>, filteredLevels);
                    DECLARE_INSTANCE_FIELD(bool, isFilteredByLevels);
                    DECLARE_INSTANCE_FIELD_PRIVATE(int, minSongLength);

                    DECLARE_INSTANCE_METHOD(void, Clear);
                    DECLARE_INSTANCE_METHOD(ValidSong*, LevelFilterCheck, GlobalNamespace::IPreviewBeatmapLevel* level, System::Runtime::CompilerServices::ConditionalWeakTable_2<GlobalNamespace::IBeatmapLevel*, ArrayW<GlobalNamespace::BeatmapDifficulty>>* playlistSongs, bool forceNoFilters);
                    DECLARE_OVERRIDE_METHOD_MATCH(void, Dispose, &System::IDisposable::Dispose);
                    public:
                        std::tuple<bool, int> PassFilters(GlobalNamespace::IBeatmapLevel* level, bool fullCheck);
)