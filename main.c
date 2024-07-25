#include <stdio.h>
#include "C:\\raylib\\raylib\\src\\raylib.h"

int main(int argc, char *argv[])
{
	InitWindow(750, 750, "Controller demo");
	SetTargetFPS(60);
	Texture2D TController = LoadTexture("controller.png");
	Texture2D TLStick = LoadTexture("L-stick.png");
	Texture2D TRStick = LoadTexture("R-stick.png");
	
	Texture2D TL1 = LoadTexture("L1.png");
	Texture2D TL2 = LoadTexture("L2.png");
	
	Texture2D TR1 = LoadTexture("R1.png");
	Texture2D TR2 = LoadTexture("R2.png");
	
	Color CLStick = WHITE;
	Color CRStick = WHITE;
	
	while (!WindowShouldClose()) 
	{
		BeginDrawing();
		
		ClearBackground(BLACK);
		
		DrawTexturePro(TController, (Rectangle){0,0,1500,1500}, (Rectangle){0,0,750,750}, (Vector2){0,0}, 0.f, WHITE);
			
		if (IsGamepadAvailable(0))
		{
			// Draw buttons: basic
			if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_MIDDLE_RIGHT))  DrawCircle(447, 210, 15, (Color){0,100,0,100}); // +
			if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_MIDDLE_LEFT))   DrawCircle(302, 210, 15, (Color){0,100,0,100}); // -
			if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_MIDDLE))        DrawCircle(394, 89, 19, RED);
			
			if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN))  DrawCircle(607, 290, 23, (Color){0,100,0,100}); // A
			if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT)) DrawCircle(561, 337, 23, (Color){0,100,0,100}); // B
			if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_LEFT))  DrawCircle(561, 244, 23, (Color){0,100,0,100}); // X
			if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_UP))    DrawCircle(515, 290, 23, (Color){0,100,0,100}); // Y
			

			if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_UP))    DrawRectangle(263, 340, 35, 35, (Color){0,100,0,100});           // UP
			if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_DOWN))  DrawRectangle(263, 340 + 70, 35, 35, (Color){0,100,0,100});      // DOWN
			if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_LEFT))  DrawRectangle(228, 340 + 35, 35, 35, (Color){0,100,0,100});      // LEFT
			if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT)) DrawRectangle(228 + 70, 340 + 35, 35, 35, (Color){0,100,0,100}); // RIGHT
			
			if(IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_TRIGGER_1))
				DrawTexturePro(TL1, (Rectangle){0,0,1500,1500}, (Rectangle){0,0,750,750}, (Vector2){0,0}, 0.f, (Color){0,255,0,255});
			
			if(IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_TRIGGER_2))
				DrawTexturePro(TL2, (Rectangle){0,0,1500,1500}, (Rectangle){0,0,750,750}, (Vector2){0,0}, 0.f, (Color){0,255,0,255});
			
			if(IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_TRIGGER_1))
				DrawTexturePro(TR1, (Rectangle){0,0,1500,1500}, (Rectangle){0,0,750,750}, (Vector2){0,0}, 0.f, (Color){0,255,0,255});
			
			if(IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_TRIGGER_2))
				DrawTexturePro(TR2, (Rectangle){0,0,1500,1500}, (Rectangle){0,0,750,750}, (Vector2){0,0}, 0.f, (Color){0,255,0,255});
			
			if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_THUMB))
				CLStick = (Color){0,0,255,255};
			else if (GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_X) != 0 || GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_Y) != 0)
				CLStick = (Color){0,255,0,255};
			else 
				CLStick = WHITE;
			
			if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_THUMB))
				CRStick = (Color){0,0,255,255};
			else if (GetGamepadAxisMovement(0, GAMEPAD_AXIS_RIGHT_X) != 0 || GetGamepadAxisMovement(0, GAMEPAD_AXIS_RIGHT_Y) != 0)
				CRStick = (Color){0,255,0,255};
			else 
				CRStick = WHITE;
			
			DrawTexturePro(TLStick,     
				(Rectangle){0,0,1500,1500}, 
				(Rectangle){
					(int)(GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_X)*18),
					(int)(GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_Y)*18),
					750,
					750 }, 
				(Vector2){0,0}, 
				0.f, 
				CLStick);
			
			DrawTexturePro(TRStick,     
				(Rectangle){0,0,1500,1500}, 
				(Rectangle){
					(int)(GetGamepadAxisMovement(0, GAMEPAD_AXIS_RIGHT_X)*18),
					(int)(GetGamepadAxisMovement(0, GAMEPAD_AXIS_RIGHT_Y)*18),
					750,
					750 }, 
				(Vector2){0,0}, 
				0.f, 
				CRStick);
		}	
		
		EndDrawing();
	}
	
	return 0;
}