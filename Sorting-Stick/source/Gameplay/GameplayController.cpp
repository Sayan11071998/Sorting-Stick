#include "Gameplay/GameplayController.h"
#include "Gameplay/GameplayView.h"


namespace Gameplay
{
	void GameplayController::destroy() { delete(gameplay_view); }

	GameplayController::GameplayController() { gameplay_view = new GameplayView(); }

	GameplayController::~GameplayController() { destroy(); }

	void GameplayController::initialize()
	{
		gameplay_view->initialize(this);
		reset();
	}

	void GameplayController::update() { gameplay_view->update(); }

	void GameplayController::render() { gameplay_view->render(); }

	void GameplayController::reset() {}
}