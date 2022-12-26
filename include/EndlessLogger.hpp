#pragma once

#include "Endless.hpp"
#include "paper/shared/logger.hpp"
#include "beatsaber-hook/shared/utils/typedefs-string.hpp"
#include <string>

template <>
struct fmt::formatter<StringW> : formatter<string_view>
{
    // parse is inherited from formatter<string_view>.
    template <typename FormatContext>
    auto format(StringW s, FormatContext& ctx)
    {
        return formatter<string_view>::format(s ? static_cast<std::string>(s) : std::string("NULL"), ctx);
    }
};

#define INFO(...) Paper::Logger::fmtLog<Paper::LogLevel::INF>(__VA_ARGS__)
#define ERROR(...) Paper::Logger::fmtLog<Paper::LogLevel::ERR>(__VA_ARGS__)
#define CRITICAL(...) Paper::Logger::fmtLog<Paper::LogLevel::ERR>(__VA_ARGS__)
#define DEBUG(...) Paper::Logger::fmtLog<Paper::LogLevel::DBG>(__VA_ARGS__)