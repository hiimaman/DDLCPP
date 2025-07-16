#include "raylib.h"
#include <iostream>
#include "textbox.h"

// soo im too lazy to comment. Sorry Cherno
int next_text = 1;

const char* texts[] = 
{
  "Heeeeey!",
  "I see an annoying girl running toward me from the\n distance, waving her arms in the air like\n she's totally oblivious to any\n attention she might draw to herself.",
  "That girl is Sayori, my neighbor and good friend\n since we were children.",
  "You know, the kind of friend you'd never see\n yourself making today, but it just kind of works\n out because you've known each other for so long?",
  "We used to walk to school together on days\n like this, but starting around high school she\n would oversleep more and more frequently,\n and I would get tired of waiting up.",
  "But if she's going to chase after me like this,\n I almost feel better off running away.",
  "However, I just sigh and idle in front of the\n crosswalk and let Sayori catch up to me",
  "S: Haaahhh...haaahhh...",
  "S: I overslept again!",
  "S: But I caught you this time!",
  "MC: Maybe, but only because I decided to stop\n and wait for you.",
  "S: Eeehhhhh, you say that like you were\n thinking about ignoring me!",
  "MC: I was hahahahahaahahahahahahahahahahahahahhhhhahahahahahahahahaha",
  "S: That's mean, MC!",
  "MC: Well, if people stare at you for acting\n weird then I don't want them to think\n we're a couple or something",
  "S: Fine, fine.",
  "S: Have you decided on a club to join yet?",
  "MC: No, Im not interested",
  "MCL And thus, today marks the day I\n sold my soul for a cupcake.",
  "MC: Why am I suddenely here? IDK,\n Abdul was to lazy to program\n all the little details",
  "Y: Welcome to the Literature Club. It's a pleasure meeting you.",
  "Y: Sayori always says nice things about you.",
  "N: Seriously? You brought a boy?\n Way to kill the atmosphere",
  "MC: Shut up dwarf",
  "MC: Ah, MC, Im going to skip some\n normal dialogue ok?",
  "MC: I never said I would join\n this club!",
  "N: That's a bit random",
  "M: I skipped all the boring\n bits",
  "N: Ok",
  "MC: All four girls stare back\n at me with dejected eyes",
  "MC: Ok, if I get to simp more",
  "EVERYONE: ok pookie",
  "EVERYONE: Oh, write a poem",
  "MC: OK",
  "THE END",

};

int current_text = 0;
const int total_texts = sizeof(texts) / sizeof(texts[0]);


int main() {
  int screenWidth = 1280;
  int screenHeight = 720;
  InitWindow(screenWidth, screenHeight, "DDLC++");
  init_textbox();
  SetWindowState(FLAG_WINDOW_RESIZABLE);
  SetTargetFPS(60);

  // character textures
  Texture2D sayori = LoadTexture("images/characters/sayori.png");
  Texture2D yuri = LoadTexture("images/characters/yuri.png");
  Texture2D natsuki = LoadTexture("images/characters/natuski.png");
  Texture2D monika = LoadTexture("images/characters/monika.png");

  // background textures
  Texture2D club = LoadTexture("images/BG/club.png");
  Texture2D residential = LoadTexture("images/BG/residential.png");
  std::string current_bg;
  
  while (!WindowShouldClose()) {
    BeginDrawing();
    if (IsKeyPressed(KEY_F))
    {
      ToggleFullscreen();
    }
    ClearBackground(BLACK);

    if (IsKeyPressed(KEY_SPACE) && current_text < total_texts - 1)
    {
      current_text++;
    }

    // backgrounds
    if (current_text < 18)
    {
      DrawTexture(residential, 0, 0, WHITE);
    }
    else
    {
      DrawTexture(club, 0, 0, WHITE);
    }

    // character animations
    if (current_text < 18)
    {
      DrawTexture(sayori, (screenWidth - sayori.width) / 2, (screenHeight - sayori.height) / 2, WHITE);
    }
    if (current_text > 19 && current_text < 22)
    {
      UnloadTexture(sayori);
      DrawTexture(yuri, (screenWidth - sayori.width) / 2, (screenHeight - sayori.height) / 2, WHITE);
    }
    if (current_text > 21 && current_text < 25)
    {
      UnloadTexture(yuri);
      DrawTexture(natsuki, (screenWidth - sayori.width) / 2, (screenHeight - sayori.height) / 2, WHITE);
    }
    if (current_text > 25 && current_text < total_texts)
    {
      UnloadTexture(natsuki);
      DrawTexture(monika, (screenWidth - sayori.width) / 2, (screenHeight - sayori.height) / 2, WHITE);
    }

    // textbox
    draw_textbox(screenWidth);
    DrawText(texts[current_text], (screenWidth - textbox_width() + 10) / 2, 520, 30, RAYWHITE);
    

    DrawText("Roast my code because I want the video to be entertaining", 20, 20, 20, BLACK);
    EndDrawing();
  }

  UnloadTexture(sayori);
  UnloadTexture(yuri);
  UnloadTexture(natsuki);
  UnloadTexture(monika);
  UnloadTexture(residential);
  UnloadTexture(club);

  CloseWindow();
  return 0;
}