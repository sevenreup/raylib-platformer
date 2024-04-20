#pragma once

#include <queue>
#include <array>
#include <bitset>
#include "models.h"
#include <cassert>

using Signature = std::bitset<MAX_COMPONENTS>;

class EntityManager
{
private:
    std::queue<Entity> m_AvailableEntities;
    std::array<Signature, MAX_ENTITIES> m_Signatures{};
    uint32_t m_LivingEntityCount{};

public:
    EntityManager()
    {
        for (Entity entity = 0; entity < MAX_ENTITIES; ++entity)
        {
            m_AvailableEntities.push(entity);
        }
    }

    ~EntityManager()
    {
    }

    Entity CreateEntity()
    {
        assert(m_LivingEntityCount < MAX_ENTITIES && "Too many entities in existence.");

        Entity id = m_AvailableEntities.front();
        m_AvailableEntities.pop();
        ++m_LivingEntityCount;

        return id;
    }

    void DestroyEntity(Entity entity)
    {
        assert(entity < MAX_ENTITIES && "Entity out of range.");

        m_Signatures[entity].reset();

        m_AvailableEntities.push(entity);
        --m_LivingEntityCount;
    }

    void SetSignature(Entity entity, Signature signature)
    {
        assert(entity < MAX_ENTITIES && "Entity out of range.");

        m_Signatures[entity] = signature;
    }

    Signature GetSignature(Entity entity)
    {
        assert(entity < MAX_ENTITIES && "Entity out of range.");

        return m_Signatures[entity];
    }
};