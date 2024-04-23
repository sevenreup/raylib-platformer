#pragma once

#include <unordered_map>
#include "entity_manager.h"
#include <memory>
#include <fmt/format.h>

class SystemManager
{
private:
    std::unordered_map<const char *, Signature> mSignatures{};
    std::unordered_map<const char *, std::shared_ptr<System>> mSystems{};

public:
    SystemManager()
    {
    }

    ~SystemManager()
    {
    }

    template <typename T>
    std::shared_ptr<T> RegisterSystem()
    {
        const char *typeName = typeid(T).name();

        assert(mSystems.find(typeName) == mSystems.end() && "Registering system more than once.");

        auto system = std::make_shared<T>();
        mSystems.insert({typeName, system});
        return system;
    }

    template <typename T>
    void SetSignature(Signature signature)
    {
        const char *typeName = typeid(T).name();

        assert(mSystems.find(typeName) != mSystems.end() && "System used before registered.");

        mSignatures.insert({typeName, signature});
    }

    void EntityDestroyed(Entity entity)
    {
        for (auto const &pair : mSystems)
        {
            auto const &system = pair.second;

            system->mEntities.erase(entity);
        }
    }

    void EntitySignatureChanged(Entity entity, Signature entitySignature)
    {
        for (auto const &pair : mSystems)
        {
            auto const &type = pair.first;
            auto const &system = pair.second;
            auto const &systemSignature = mSignatures[type];
            fmt::print("Jeff {}, {}, {}\n", (entitySignature & systemSignature).to_string(), systemSignature.to_string(), entitySignature.to_string());
            if ((entitySignature & systemSignature) == systemSignature)
            {
                fmt::print("EntitySignatureChanged: Inserting entity {}, {}\n", entity, type);
                system->mEntities.insert(entity);
            }
            else
            {
                fmt::print("EntitySignatureChanged: Deleting entity {}, {}\n", entity, type);
                system->mEntities.erase(entity);
            }
        }
    }
};