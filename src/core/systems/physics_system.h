#pragma once

#include "raylib.h"
#include "raymath.h"
#include "core/coordinator.h"
#include "core/models.h"

#include "core/components/rigid_body.h"
#include "core/components/transform.h"
#include "core/components/gravity.h"

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
