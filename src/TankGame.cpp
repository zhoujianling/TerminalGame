#include "TankGame.h"
#include "core/GameCore.h"
#include "core/Game.h"
#include "scene/Scene.h"
#include "scene/Sprite.h"
#include "scene/Camera.h"
#include "scene/HeroController.h"

void TankGame::MakeGame(core::GameCore* core) {
    core->CreateGame();
    auto* game = core->GetGame();
    auto* scn = game->CreateScene("MainScene");
    {
        auto* hero_node = scn->CreateSceneNode("Hero");
        auto* hero_sprite = new scene::Sprite(); 
        auto* hero_controller = new scene::HeroController(); 
        hero_node->AddComponent(hero_sprite);
        hero_node->AddComponent(hero_controller);

        scn->GetRoot()->Attach(hero_node);
    }
    {
        auto* camera_node = scn->CreateSceneNode("Camera");
        auto* camera = new scene::Camera(); 
        camera_node->AddComponent(camera);
        scn->SetActiveCamera(camera);
    }
    // auto* hero_sprite = scn->CreateSprite();

}