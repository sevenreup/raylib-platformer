set(headers ${headers} 
src/core/scene.h
src/core/component_array.h
src/core/models.h
src/core/component_manager.h
src/core/system_manager.h
src/core/coordinator.h
src/core/entity_manager.h

src/core/components/camera.h
src/core/components/gravity.h
src/core/components/rigid_body.h
src/core/components/transform.h
src/core/components/renderable.h

src/core/systems/physics_system.h
src/core/systems/render_system.h

src/game/game.h
src/game/mainscreen.h
src/game/player.h
)

set(sources ${sources}
${headers}
    src/game/game.cpp 
    src/game/mainscreen.cpp 
    src/game/player.cpp 
)