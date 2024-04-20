#pragma once

#include <cstdint>
#include <set>

using Entity = std::uint32_t;
using ComponentType = std::uint8_t;

const Entity MAX_ENTITIES = 5000;
const ComponentType MAX_COMPONENTS = 32;

class System
{
public:
    std::set<Entity> mEntities;
};