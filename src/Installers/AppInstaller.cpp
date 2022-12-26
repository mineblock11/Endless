#include "Installers/AppInstaller.hpp"
#include "Services/RamCleaner.hpp"

DEFINE_ZENJECT_INSTALLER(AppInstaller) {
    INFO("AppInstaller::InstallBindings")

    auto container = get_Container();

    container->Bind<Endless::Services::RamCleaner*>()->FromInstance(Endless::Services::RamCleaner::New_ctor())->AsSingle();
}