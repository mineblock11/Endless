#include "Installers/AppInstaller.hpp"
#include "Services/RamCleaner.hpp"
#include "Data/SongList.hpp"

#include "Zenject/ConcreteIdBinderGeneric_1.hpp"
#include "Zenject/DiContainer.hpp"
#include "Zenject/FromBinderNonGeneric.hpp"

DEFINE_ZENJECT_INSTALLER(AppInstaller) {
    INFO("AppInstaller::InstallBindings");

    auto container = get_Container();

    container->Bind<Endless::Services::RamCleaner*>()->FromInstance(Endless::Services::RamCleaner::New_ctor())->AsSingle();
    INFO("Bind->Endless::Services::RamCleaner->Instance->AsSingle");

    container->Bind<Endless::Data::PlayedSongList*>()->FromInstance(Endless::Data::PlayedSongList::New_ctor())->AsSingle();
    INFO("Bind->Endless::Data::PlayedSongList->Instance->AsSingle");
}