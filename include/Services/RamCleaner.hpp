#pragma once

#include "Endless.hpp"

#include "custom-types/shared/coroutine.hpp"

DECLARE_CLASS_CODEGEN(Endless::Services, RamCleaner, Il2CppObject,
                      DECLARE_DEFAULT_CTOR();
public:
    custom_types::Helpers::Coroutine ClearRam();
)