#pragma once

#include "Endless.hpp"
#include "lapiz/shared/macros.hpp"
#include "Zenject/MonoInstaller.hpp"
#include "custom-types/shared/macros.hpp"

#define DECLARE_ZENJECT_INSTALLER(a) \
DECLARE_CLASS_CODEGEN(Endless::Installers, a, ::Zenject::MonoInstaller, \
          DECLARE_OVERRIDE_METHOD(void, InstallBindings, il2cpp_utils::il2cpp_type_check::MetadataGetter<&::Zenject::MonoInstaller::InstallBindings>::get());\
)

#define DEFINE_ZENJECT_INSTALLER(a) \
DEFINE_TYPE(Endless::Installers, a) \
void Endless::Installers::a::InstallBindings()