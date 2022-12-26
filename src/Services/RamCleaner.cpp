#include "Services/RamCleaner.hpp"

DEFINE_TYPE(Endless::Services, RamCleaner)

using namespace Endless::Services;

#include "UnityEngine/WaitForSeconds.hpp"
#include "System/GC.hpp"
#include "UnityEngine/Scripting/GarbageCollector.hpp"

custom_types::Helpers::Coroutine RamCleaner::ClearRam() {
    co_yield nullptr;
    auto oldMode = UnityEngine::Scripting::GarbageCollector::GetMode();
    for (int i = 1; i <= 8; ++i) {
        co_yield reinterpret_cast<System::Collections::IEnumerator*>(UnityEngine::WaitForSeconds::New_ctor(0.2f));
        UnityEngine::Scripting::GarbageCollector::SetMode(UnityEngine::Scripting::GarbageCollector::Mode::Enabled);
        System::GC::Collect();
    }
    UnityEngine::Scripting::GarbageCollector::SetMode(oldMode);
}