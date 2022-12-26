#pragma once

#include "modloader/shared/modloader.hpp"
#include "beatsaber-hook/shared/utils/logging.hpp"
#include "beatsaber-hook/shared/config/config-utils.hpp"
#include "beatsaber-hook/shared/utils/il2cpp-functions.hpp"
#include "beatsaber-hook/shared/utils/hooking.hpp"

#include "config-utils/shared/config-utils.hpp"
#include "custom-types/shared/custom-types.hpp"
#include "lapiz/shared/zenject/Zenjector.hpp"

#include "EndlessLogger.hpp"

#define DECLARE_OVERRIDE_METHOD_MATCH(retval, name, mptr, ...) \
    DECLARE_OVERRIDE_METHOD(retval, name, il2cpp_utils::il2cpp_type_check::MetadataGetter<mptr>::get(), __VA_ARGS__)

DECLARE_CONFIG(EndlessConfig,
               // Queue Size
               CONFIG_VALUE(queue_sizeLimit, int, "Queue Size Limit", 32, "How many maps can be in the queue at once.");
               CONFIG_VALUE(queue_requeueLimit, int, "Requeue Limit", 32, "How many different songs must be played before a specific song can be played again? (This value is lowered as necessary depending on the amount of valid songs)");

               // Filtering
               CONFIG_VALUE(filter_minSeconds, int, "Min Song Length", 15, "Minimum Song Length");
               CONFIG_VALUE(filter_advancedEnabled, bool, "Enable Advanced Filters", false, "Enable Advanced Filters such as NJS and NPS.");
               CONFIG_VALUE(filter_njs_min, float, "Min Song NJS", 0.0f, "Minimum Song NJS");
               CONFIG_VALUE(filter_njs_max, float,  "Max Song NJS", 30.0f, "Maximum Song NJS");
               CONFIG_VALUE(filter_nps_min, float,  "Min Song NPS", 0.0f,"Minimum Song NPS");
               CONFIG_VALUE(filter_nps_max, float,  "Max Song NPS", 30.0f, "Maximum Song NPS");
               CONFIG_VALUE(filter_bps_max, float, "Min Song BPS", 0.0f, "Minimum Song BPS");
               CONFIG_VALUE(filter_ranked, float, "Song Ranked?", 0.0f);
               CONFIG_VALUE(filter_playlist, bool, "Filter By Playlist?", false);
               CONFIG_VALUE(filter_playlist_val, std::string, "Playlist Name", "", "The name of the playlist to filter by.");

               // Gameplay
               CONFIG_VALUE(gameplay_jumpcut, bool, "Enable Jumpcut", false, "Should the transition be sudden between songs?");
               CONFIG_VALUE(gameplay_transition_reactionTime, float, "Transition Reaction Time", 0.5f, "How fast transition is between songs.");
               CONFIG_VALUE(gameplay_transition_gracePeriod, float, "Transition Break Period", 0.4f, "The amount of time for a break between songs.");
               CONFIG_VALUE(gameplay_prefer_top_difficulty, bool, "Prefer Top Difficulty", false, "Randomizer prefers the hardest difficulties first.");

)