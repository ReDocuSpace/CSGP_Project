#include "CSGPFrameWork.h"
#include "Content/MainGame.h"

int main()
{
	SCREEN->ScreenInit();
	INPUT->InputInit();
	TIMER->TimerInit();
	CONTENTS->SceneInit();
	

	MainGame* main = new MainGame();

	main->OnInit();
	while (true)
	{
		if (INPUT->KeyDown(VK_ESCAPE) || 
			!CONTENTS->GameState())
		{
			break;
		}

		// Looping
		main->OnUpdate();
		SCREEN->ScreenClear();
		// Rendering
		main->OnRender();
		SCREEN->ScreenFliping();

		// Update Check Frame Setup
		TIMER->Tick(FRAME);
	}

	main->OnRelease();

	CONTENTS->SceneRelease();
	TIMER->TimerRelease();
	INPUT->InputRelease();
	SCREEN->ScreenRelease();

	SAFE_DELETE(main);

	return 0;
}