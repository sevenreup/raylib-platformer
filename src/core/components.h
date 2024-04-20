#pragma once

#include "raylib.h"
#include "raymath.h"
#include "coordinator.h"
#include "models.h"

struct Gravity
{
    Vector3 force;
};

struct RigidBody
{
    Vector3 velocity;
    Vector3 acceleration;
};

struct TransformComp
{
    Vector3 position;
    Vector3 rotation;
    Vector3 scale;
};

extern Coordinator gCoordinator;

class PhysicsSystem : public System
{
public:
    void Update(float dt)
    {
        for (auto const &entity : mEntities)
        {
            auto &rigidBody = gCoordinator.GetComponent<RigidBody>(entity);
            auto &transform = gCoordinator.GetComponent<TransformComp>(entity);
            auto const &gravity = gCoordinator.GetComponent<Gravity>(entity);

            transform.position = Vector3Add(transform.position, Vector3Scale(rigidBody.velocity, dt));

            rigidBody.velocity = Vector3Add(rigidBody.velocity, Vector3Scale(gravity.force, dt));
        }
    }
};
