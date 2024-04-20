set(headers ${headers} 
src/core/scene.h
src/core/entity.h
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