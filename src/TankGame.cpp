#include "TankGame.h"
#include "core/GameCore.h"
#include "gameplay/Game.h"
#include "scene/Scene.h"
#include "scene/Sprite.h"
#include "scene/Camera.h"

void TankGame::MakeGame(core::GameCore* core) {
    core->CreateGame();
    auto* game = core->GetGame();
    auto* scn = game->CreateScene("MainScene");
    {
        auto* hero_node = scn->CreateSceneNode("Hero");
        auto* hero_sprite = new scene::Sprite(); 
        hero_node->AddComponent(hero_sprite);
    }
    {
        auto* camera_node = scn->CreateSceneNode("Camera");
        auto* camera = new scene::Camera(); 
        camera_node->AddComponent(camera);
        // scn->
    }
    // auto* hero_sprite = scn->CreateSprite();

}