#include "game.h"

Coordinator gCoordinator;

Game::Game(float screenWidth, float screenHeight)
{
    mDimension = (Vector2){screenWidth, screenHeight};
    mMainScreen = new Mainscreen(mDimension);
}

Game::~Game()
{
    delete mMainScreen;
}

void Game::Run()
{
    gCoordinator.Init();

    gCoordinator.RegisterComponent<Gravity>();
    gCoordinator.RegisterComponent<RigidBody>();
    gCoordinator.RegisterComponent<TransformComp>();
    gCoordinator.RegisterComponent<CameraComp>();
    gCoordinator.RegisterComponent<Renderable>();

    auto physicsSystem = gCoordinator.RegisterSystem<PhysicsSystem>();
    {
        Signature signature;
        signature.set(gCoordinator.GetComponentType<Gravity>());
        signature.set(gCoordinator.GetComponentType<RigidBody>());
        signature.set(gCoordinator.GetComponentType<TransformComp>());
        gCoordinator.SetSystemSignature<PhysicsSystem>(signature);
    }

    auto renderSystem = gCoordinator.RegisterSystem<RenderSystem>();
	{
		Signature signature;
		signature.set(gCoordinator.GetComponentType<Renderable>());
		signature.set(gCoordinator.GetComponentType<TransformComp>());
		gCoordinator.SetSystemSignature<RenderSystem>(signature);
	}

    std::default_random_engine generator;
    std::uniform_real_distribution<float> randPosition(-100.0f, 100.0f);
    std::uniform_real_distribution<float> randRotation(0.0f, 3.0f);
    std::uniform_real_distribution<float> randScale(3.0f, 5.0f);
    std::uniform_real_distribution<float> randGravity(-10.0f, -1.0f);

    float scale = randScale(generator);

    std::vector<Entity> entities(MAX_ENTITIES);

    for (auto &entity : entities)
    {
        entity = gCoordinator.CreateEntity();

        gCoordinator.AddComponent(
            entity,
            Gravity{(Vector3){0.0f, randGravity(generator), 0.0f}});

        gCoordinator.AddComponent(
            entity,
            RigidBody{
                .velocity = (Vector3){0.0f, 0.0f, 0.0f},
                .acceleration = (Vector3){0.0f, 0.0f, 0.0f}});

        gCoordinator.AddComponent(
            entity,
            TransformComp{
                .position = (Vector3){randPosition(generator), randPosition(generator), randPosition(generator)},
                .rotation = (Vector3){randRotation(generator), randRotation(generator), randRotation(generator)},
                .scale = (Vector3){scale, scale, scale}});
    }

    float dt = 0.0f;

    InitWindow(mDimension.x, mDimension.y, "raylib [core] example - basic screen manager");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        auto startTime = std::chrono::high_resolution_clock::now();

        physicsSystem->Update(dt);

        auto stopTime = std::chrono::high_resolution_clock::now();

        dt = std::chrono::duration<float, std::chrono::seconds::period>(stopTime - startTime).count();
        mMainScreen->Update();
        BeginDrawing();
        mMainScreen->Draw();
        EndDrawing();
    }

    CloseWindow();
}