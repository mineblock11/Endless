#include "Endless.hpp"

#include "Installers/AppInstaller.hpp"

static ModInfo modInfo;

extern "C" void setup(ModInfo& info) {
    info.id = MOD_ID;
    info.version = VERSION;
    modInfo = info;
    INFO("Setup!");
}

extern "C" void load() {
    il2cpp_functions::Init();
    custom_types::Register::AutoRegister();

    INFO("Installing Zenjectors...");

    auto zenjector = ::Lapiz::Zenject::Zenjector::Get();
    zenjector->Install<Endless::Installers::AppInstaller*>(Lapiz::Zenject::Location::App);

    INFO("Installed Zenjectors.")
}