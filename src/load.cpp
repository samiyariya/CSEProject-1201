#include "header.h"

SDL_Texture *BG1 = NULL;
SDL_Texture *Coin = NULL;
SDL_Texture *Man = NULL;
SDL_Texture *Obstacle1 = NULL;
SDL_Texture *Obstacle2 = NULL;
SDL_Texture *Obstacle3 = NULL;
SDL_Texture *gameOver = NULL;
SDL_Texture *menu = NULL;
SDL_Texture *menu1 = NULL;
SDL_Texture *mTexture = NULL;
SDL_Texture *newgame = NULL;
SDL_Texture *help = NULL;
SDL_Texture *highscore = NULL;
SDL_Texture *gEnd = NULL;
SDL_Texture *Continue = NULL;
SDL_Texture *forest = NULL;
SDL_Texture *zombie = NULL;
SDL_Texture *scoreTexture = NULL;
SDL_Texture *gScoretexture = NULL;
SDL_Texture *scoreImage = NULL;
SDL_Texture *menu2 = NULL;
SDL_Texture *EnterName = NULL;
SDL_Texture *life = NULL;
SDL_Texture *tutorial = NULL;
SDL_Texture *sl = NULL;
SDL_Texture *nameTexture = NULL;
SDL_Texture *ScoreName = NULL;
SDL_Texture *HighScore = NULL;

SDL_Texture *BG2 = NULL;
SDL_Texture *Star = NULL;
SDL_Texture *dog = NULL;
SDL_Texture *enemy_zombie = NULL;
SDL_Texture *knife_texture = NULL;
SDL_Texture *enemy_ghost = NULL;

Mix_Music *menusound = NULL;
Mix_Music *forestsound = NULL;
Mix_Music *zombiemsound = NULL;
Mix_Chunk *dogsound = NULL;
Mix_Chunk *zombiesound = NULL;
Mix_Chunk *coinsound = NULL;
Mix_Chunk *diesound = NULL;
Mix_Chunk *collidesound = NULL;
Mix_Chunk *weaponsound = NULL;
Mix_Chunk *mouseclick;

SDL_Rect dog_spriteclips[30];
SDL_Rect zombie_spriteclips[30];
SDL_Rect ghost_spriteclips[30];

TTF_Font *gFont = NULL;

SDL_Rect gSpriteClips[6];

int mWidth;
int mHeight;

bool loadMedia()
{
    bool success = true;
    BG1 = loadtexture("Images/bg.png");
    if (BG1 == NULL)
    {
        printf("Failed to load background texture!\n");
        success = false;
    }
    Man = loadtexture("Images/man.png");
    if (Man == NULL)
    {
        printf("Failed to load survivalRun texture!\n");
        success = false;
    }
    else
    {
        man_sprite();
    }
    Coin = loadtexture("Images/coin.png");
    if (Coin == NULL)
    {
        printf("Failed to load survivalRun texture!\n");
        success = false;
    }
    Obstacle1 = loadtexture("Images/obstacle1.png");
    if (Obstacle1 == NULL)
    {
        printf("Failed to load obstacle texture!\n");
        success = false;
    }
    Obstacle2 = loadtexture("Images/obstacle2.png");
    if (Obstacle2 == NULL)
    {
        printf("Failed to load obstacle texture!\n");
        success = false;
    }
    Obstacle3 = loadtexture("Images/obstacle3.png");
    if (Obstacle3 == NULL)
    {
        printf("Failed to load obstacle texture!\n");
        success = false;
    }
    gameOver = loadtexture("Images/gameover.png");
    if (gameOver == NULL)
    {
        printf("Failed to load gameover texture!\n");
        success = false;
    }
    tutorial = loadtexture("Images/help.png");
    if (tutorial == NULL)
    {
        printf("Failed to load help texture!\n");
        success = false;
    }
    life = loadtexture("Images/life.png");
    if (life == NULL)
    {
        printf("Failed to load gameover texture!\n");
        success = false;
    }
    BG2 = loadtexture("Images/bg2.png");
    if (BG2 == NULL)
    {
        printf("Failed to load background texture!\n");
        success = false;
    }

    dog = loadtexture("Images/zombie.png");
    if (dog == NULL)
    {
        printf("FAILED TO LOAD DOG %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        dog_sprite();
    }

    enemy_zombie = loadtexture("Images/zombie2.png");
    if (enemy_zombie == NULL)
    {
        printf("FAILED TO LOAD MONKEY %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        zombie_sprite();
    }

    knife_texture = loadtexture("Images/weapon.png");
    if (knife_texture == NULL)
    {
        printf("FAILED TO LOAD NINJA STAR %s/n", SDL_GetError());
        success = false;
    }

    enemy_ghost = loadtexture("Images/ghost.png");
    if (enemy_ghost == NULL)
    {
        printf("FAILED TO LOAD GHOST IMAGES %s/n", SDL_GetError());
        success = false;
    }
    else
    {
        ghost_sprite();
    }

    menu = loadtexture("Images/menu.png");
    if (menu == NULL)
    {
        printf("Failed to load menu texture!\n");
        success = false;
    }
    menu1 = loadtexture("Images/menu1.png");
    if (menu1 == NULL)
    {
        printf("Failed to load menu texture!\n");
        success = false;
    }
    menu2 = loadtexture("Images/mode.png");
    if (menu1 == NULL)
    {
        printf("Failed to load menu texture!\n");
        success = false;
    }
    HighScore = loadtexture("Images/highscore.png");
    if (HighScore == NULL)
    {
        printf("Failed to load menu texture!\n");
        success = false;
    }

    gFont = TTF_OpenFont("Oswald-HeavyItalic.ttf", 50);
    if (gFont == NULL)
    {
        printf("Failed to load ttf font! SDL_ttf Error: %s\n", TTF_GetError());
        success = false;
    }

    SDL_Color textColor = {0xFF, 0xFF, 0xFF};
    // SDL_Color textColor = {255, 87, 51};

    EnterName = loadFromRenderedText("ENTER YOUR NAME", textColor);
    if (EnterName == NULL)
    {
        printf("Failed to load text texture!\n");
        success = false;
    }
    sl = loadFromRenderedText("SL", textColor);
    if (sl == NULL)
    {
        printf("Failed to load text texture!\n");
        success = false;
    }
    nameTexture = loadFromRenderedText("NAME", textColor);
    if (nameTexture == NULL)
    {
        printf("Failed to load text texture!\n");
        success = false;
    }
    ScoreName = loadFromRenderedText("SCORE", textColor);
    if (ScoreName == NULL)
    {
        printf("Failed to load text texture!\n");
        success = false;
    }
    gScoretexture = loadFromRenderedText("SCORE : ", textColor);
    if (gScoretexture == NULL)
    {
        printf("Failed to load menu texture!\n");
        success = false;
    }
    newgame = loadFromRenderedText(" NEW GAME", textColor);
    if (newgame == NULL)
    {
        printf("Failed to load text texture!\n");
        success = false;
    }
    highscore = loadFromRenderedText(" HIGHSCORE ", textColor);
    if (highscore == NULL)
    {
        printf("Failed to load text texture!\n");
        success = false;
    }
    help = loadFromRenderedText(" HELP ", textColor);
    if (help == NULL)
    {
        printf("Failed to load text texture!\n");
        success = false;
    }

    gEnd = loadFromRenderedText(" EXIT ", textColor);
    if (gEnd == NULL)
    {
        printf("Failed to load text texture!\n");
        success = false;
    }
    Continue = loadFromRenderedText(" CONTINUE ", textColor);
    if (Continue == NULL)
    {
        printf("Failed to load text texture!\n");
        success = false;
    }

    forest = loadFromRenderedText("FOREST MODE ", textColor);
    if (forest == NULL)
    {
        printf("Failed to load text texture!\n");
        success = false;
    }
    zombie = loadFromRenderedText("ZOMBIE MODE ", textColor);
    if (zombie == NULL)
    {
        printf("Failed to load text texture!\n");
        success = false;
    }

    menusound = Mix_LoadMUS("sound/menusound.mp3");
    if (menusound == NULL)
    {
        printf("Failed to load menusound %s\n", Mix_GetError());
        success = false;
    }
    forestsound = Mix_LoadMUS("sound/forestsound.mp3");
    if (forestsound == NULL)
    {
        printf("Failed to load forestsound %s\n", Mix_GetError());
        success = false;
    }
    zombiemsound = Mix_LoadMUS("sound/zombiemsound.mp3");
    if (zombiemsound == NULL)
    {
        printf("Failed to load zombiemsound %s\n", Mix_GetError());
        success = false;
    }
    coinsound = Mix_LoadWAV("sound/coinsound.mp3");
    if (coinsound == NULL)
    {
        printf("Failed to load coinsound %s\n", Mix_GetError());
        success = false;
    }
    collidesound = Mix_LoadWAV("sound/collidesound.mp3");
    if (collidesound == NULL)
    {
        printf("Failed to load collidesound %s\n", Mix_GetError());
        success = false;
    }
    diesound = Mix_LoadWAV("sound/diesound.mp3");
    if (diesound == NULL)
    {
        printf("Failed to load diesound %s\n", Mix_GetError());
        success = false;
    }
    dogsound = Mix_LoadWAV("sound/dogsound.mp3");
    if (dogsound == NULL)
    {
        printf("Failed to load dogsoundn %s\n", Mix_GetError());
        success = false;
    }
    weaponsound = Mix_LoadWAV("sound/weaponsound.mp3");
    if (weaponsound == NULL)
    {
        printf("Failed to load weaponsound %s\n", Mix_GetError());
        success = false;
    }
    zombiesound = Mix_LoadWAV("sound/zombiesound.mp3");
    if (zombiesound == NULL)
    {
        printf("Failed to load zombiesound %s\n", Mix_GetError());
        success = false;
    }
    mouseclick = Mix_LoadWAV("sound/mouseclick.mp3");
    if (mouseclick == NULL)
    {
        printf("Failed to mouseclick %s\n", Mix_GetError());
        success = false;
    }

    return success;
}

SDL_Texture *loadtexture(std::string path)
{
    void free();
    SDL_Texture *newTexture = NULL;
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL)
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    else
    {
        newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
        if (newTexture == NULL)
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());

        else
        {
            SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0xFF, 0xFF, 0xFF));
        }
        SDL_FreeSurface(loadedSurface);
    }
    return newTexture;
}

SDL_Texture *loadFromRenderedText(std::string textureText, SDL_Color textColor)
{

    // Render text surface
    SDL_Surface *textSurface = TTF_RenderText_Solid(gFont, textureText.c_str(), textColor);
    if (textSurface == NULL)
    {
        printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
    }
    else
    {
        // Create texture from surface pixels
        mTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
        if (mTexture == NULL)
        {
            printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
        }
        else
        {
            // Get image dimensions
            mWidth = textSurface->w;
            mHeight = textSurface->h;
        }
        // Get rid of old surface
        SDL_FreeSurface(textSurface);
    }

    // Return success
    return mTexture;
}
