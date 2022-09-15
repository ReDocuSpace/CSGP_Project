#include "TetrisContent.h"
#include "../../CSGPFrameWork.h"

// SCENE
#include "Scene/TetrisTitle.h" 
#include "Scene/TetrisGame.h" 
#include "Scene/TetrisEnding.h" 


void TetrisContent::OnInit()
{
	sceneManager = new SceneManager();
	sceneManager->SceneInit();

	sceneManager->AddScene("TITLE", new TetrisTitle(this));
	sceneManager->AddScene("GAME", new TetrisGame(this));
	sceneManager->AddScene("ENDING", new TetrisEnding(this));
	//sceneManager->AddScene("TITLE",new )
	
	sceneManager->ChangeScene("TITLE");
}

void TetrisContent::OnRender()
{
	sceneManager->OnRender();
}

void TetrisContent::OnUpdate()
{
	sceneManager->OnUpdate();
}

void TetrisContent::OnRelease()
{
	TIMER->ClearPlayTimer();

	sceneManager->SceneRelease();
}

void TetrisContent::ChangeScene(string scene)
{
	sceneManager->ChangeScene(scene);
}
