#include "GameObjects/PhysicsObject.hpp"
#include "GameStates/GameStateBase.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <memory>
#include <vector>

class PlayingState:public GameStateBase{
    public:
    void init(GameFont& gameFonts)override;
    void show(sf::RenderTarget& target, float dt)override;
    private:
    double leftovertime = 0;
    std::vector<std::unique_ptr<PhysicsObject>> physicsobjects;
    const float PHYSICS_STEP_TIME = 1/60.0f;
};