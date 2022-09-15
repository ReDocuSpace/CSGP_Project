#include "SnakeContent.h"
#include "../../CSGPFrameWork.h"

#include "Game/SnakeStage.h"
#include "Game/SnakeTitle.h"

void SnakeContent::OnInit()
{
	// SNAKE ½ºÇÇµå
	TIMER->AddPlayTimer(0, 0.1f);
}


void SnakeContent::OnRender()
{
	
}

void SnakeContent::OnUpdate()
{
	
}
void SnakeContent::OnRelease()
{

	TIMER->ClearPlayTimer();
}

void SnakeContent::ChangeScene(string sceneName)
{

}

