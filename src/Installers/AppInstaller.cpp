#include "Installers/AppInstaller.hpp"
#include "Services/RamCleaner.hpp"

#include "Zenject/ConcreteIdBinderGeneric_1.hpp"
#include "Zenject/DiContainer.hpp"
#include "Zenject/FromBinderNonGeneric.hpp"

DEFINE_ZENJECT_INSTALLER(AppInstaller) {
    INFO("AppInstaller::InstallBindings");

    auto container = get_Container();

    container->Bind<Endless::Services::RamCleaner*>()->FromInstance(Endless::Services::RamCleaner::New_ctor())->AsSingle();
}