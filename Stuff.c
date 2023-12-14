/* Old/deprecated stuff moved to storage */

// array which determines the colour of each square on the grid
/*uint8_t grid_array [] = {7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,
                         7,  54, 55, 54, 55, 54, 55, 54, 55, 54, 55, 54, 55, 54, 55, 7,
                         7,  55, 7,  7,  7,  55, 54, 55, 54, 55, 54, 55, 54, 55, 54, 7,
                         7,  54, 7,  54, 55, 54, 55, 54, 55, 54, 55, 54, 7,  7,  55, 7,
                         7,  55, 7,  55, 54, 55, 54, 55, 54, 55, 7,  55, 54, 7,  54, 7,
                         7,  54, 55, 54, 55, 54, 7,  7,  55, 54, 7,  54, 55, 7,  55, 7,
                         7,  55, 54, 55, 54, 55, 7,  7,  54, 55, 7,  55, 54, 55, 54, 7,
                         7,  54, 55, 54, 55, 54, 55, 54, 55, 54, 55, 54, 55, 54, 55, 7,
                         7,  55, 54, 55, 54, 55, 54, 55, 54, 55, 54, 55, 54, 55, 54, 7,
                         7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7
};

// array which determines the texture of each square on the grid
uint8_t TextureMap [] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 0,
            0, 2, 0, 0, 0, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 0,
            0, 1, 0, 1, 2, 1, 2, 1, 2, 1, 2, 1, 0, 0, 2, 0,
            0, 2, 0, 2, 1, 2, 1, 2, 1, 2, 0, 2, 1, 0, 1, 0,
            0, 1, 2, 1, 2, 1, 0, 0, 2, 1, 0, 1, 2, 0, 2, 0,
            0, 2, 1, 2, 1, 2, 0, 0, 1, 2, 0, 2, 1, 2, 1, 0,
            0, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 0,
            0, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

uint8_t CollisionMap [] =
{
    7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,
    7,  54, 55, 54, 55, 54, 55, 54, 55, 54, 55, 54, 55, 54, 55, 54, 55, 54, 7,
    7,  55, 7,  7,  7,  55, 54, 55, 54, 55, 54, 55, 54, 55, 54, 55, 54, 55, 7,
    7,  54, 7,  54, 55, 54, 55, 54, 55, 54, 55, 54, 7,  7,  55, 54, 55, 54, 7,
    7,  55, 7,  55, 54, 55, 54, 55, 54, 55, 7,  55, 54, 7,  54, 55, 54, 55, 7,
    7,  54, 55, 54, 55, 54, 7,  7,  55, 54, 7,  54, 55, 7,  55, 54, 55, 54, 7,
    7,  55, 54, 55, 54, 55, 7,  7,  54, 55, 7,  55, 54, 55, 54, 55, 54, 55, 7,
    7,  54, 55, 54, 55, 54, 55, 54, 55, 54, 55, 54, 55, 54, 55, 54, 55, 54, 7,
    7,  55, 54, 55, 54, 55, 54, 55, 54, 55, 54, 55, 54, 55, 54, 55, 54, 55, 7,
    7,  54, 55, 54, 55, 54, 7,  7,  55, 54, 7,  54, 55, 54, 55, 54, 55, 54, 7,
    7,  55, 54, 55, 54, 55, 7,  7,  54, 55, 7,  55, 54, 7,  54, 55, 54, 55, 7,
    7,  54, 55, 54, 55, 54, 55, 54, 55, 54, 55, 54, 55, 54, 55, 54, 55, 54, 7,
    7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7
};

// array which determines the texture of each square on the grid
uint8_t TextureMap [] =
{
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 0,
    0, 2, 0, 0, 0, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 0,
    0, 1, 0, 1, 2, 1, 2, 1, 2, 1, 2, 1, 0, 0, 2, 1, 2, 1, 0,
    0, 2, 0, 2, 1, 2, 1, 2, 1, 2, 0, 2, 1, 0, 1, 2, 1, 2, 0,
    0, 1, 2, 1, 2, 1, 0, 0, 2, 1, 0, 1, 2, 0, 2, 1, 2, 1, 0,
    0, 2, 1, 2, 1, 2, 0, 0, 1, 2, 0, 2, 1, 2, 1, 2, 1, 2, 0,
    0, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 0,
    0, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 0,
    0, 1, 2, 1, 2, 1, 0, 0, 2, 1, 0, 1, 2, 1, 2, 1, 2, 1, 0,
    0, 2, 1, 2, 1, 2, 0, 0, 1, 2, 0, 2, 1, 0, 1, 2, 1, 2, 0,
    0, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

// array which determines the collision data of each square on the grid
uint8_t CollisionMap [] =
{
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0,
  0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0,
  0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0,
  0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0,
  0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0,
  0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
  0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
  0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
  0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
  0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
  0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
  0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

uint8_t TileMap [] =
{
 11, 7, 7, 7, 7,14, 7, 7,14, 7, 7,14, 7, 7, 7, 7,12, 6, 6, 6, 6, 6, 3, 3,
  8, 5, 5, 5, 5, 4, 4,30, 8,31, 4, 4, 5, 5, 5, 5, 8, 1, 1, 1, 1, 1, 3, 3,
  8, 5, 5, 5, 5, 9, 7, 7,13, 7, 7,10, 5, 5, 5, 5, 8, 1, 1, 1, 1, 3, 3, 3,
  8, 5, 5, 5, 5, 5, 5, 5, 8, 5, 5, 5, 5, 5, 5, 5, 8, 1, 1, 1, 1, 3, 3, 3,
  8, 5, 5, 5, 5, 5, 5, 5, 8, 5, 5, 5, 5, 5, 5, 5, 8, 1, 1, 1, 1, 3, 3, 3,
  8, 5, 5, 5, 5, 5, 5, 5, 8, 5, 5, 5, 5, 5, 5, 5, 8, 1, 1, 1, 1, 3, 3, 3,
  9, 7, 7, 7, 7, 7, 7, 5,17, 5, 7, 7, 7, 7, 7, 7,10, 1, 1, 1, 1, 3, 3, 3,
  6, 0, 0, 0, 0, 0, 0,19, 0,19, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 3, 3, 3, 3,
  6, 0, 0, 0, 0, 0, 0,19, 0,19, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 3, 3, 3, 3,
  6, 0, 0, 0, 0,22,18,28,18,26, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 3, 3, 3, 3,
  6, 0, 0, 0, 0,19, 0, 0, 0,19, 0, 0, 0, 0, 0, 0, 0, 1, 1, 3, 3, 3, 3, 3,
  6, 0, 0, 0, 0,19, 0, 0, 0,19, 0, 0, 0, 0, 0, 0, 1, 1, 3, 3, 3, 3, 3, 3,
  6, 0, 0, 0, 0,19, 0, 0, 0,19, 0, 0, 0, 0, 0, 0, 1, 1, 3, 3, 3, 3, 3, 3,
 18,18,18,18,18,24,18,18,18,24,18,18,18,18,18,18, 1, 1, 3, 3, 3, 3, 3, 3,
  6, 0, 0, 0, 0,19, 0, 0, 0,19, 0, 0, 0, 0, 0, 1, 1, 3, 3, 3, 3, 3, 3, 3,
  6, 0, 0, 0, 0,19, 0, 0, 0,19, 0, 0, 0, 0, 0, 1, 1, 3, 3, 3, 3, 3, 3, 3,
  6, 0, 0, 0, 0,20,18,18,18,28,18,18,23, 0, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3,
  6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,19, 0, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3,
  6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,19, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3,
  6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,19, 6, 6, 3, 3, 3, 3, 3, 3, 3, 3, 3
};


void createInitialObjects()
{   
    Game.player_id =
    createObject(170, 350, 0.1, 7, 0, NULL, 0, &Textures[DUDE1]);
    
    createObject(280, 90,  1, 7, 0, AI_IDLE, 1, &Textures[DUDE3]);
    createObject(80,  110, 0.1, 7, 0, AI_IDLE, 2,              &Textures[DUDE2]);
    createObject(200, 350, 0.1, 7, 0, AI_IDLE, 3,              &Textures[DUDE1]);
    createObject(200, 350, 0, 7, 0, AI_IDLE, 2,              &Textures[DUDE1]);
    createObject(200, 350, 0, 7, 0, AI_IDLE, 2,              &Textures[DUDE1]);
    createObject(200, 350, 0, 7, 0, AI_IDLE, 2,              &Textures[DUDE1]);
    createObject(200, 350, 0, 7, 0, AI_IDLE, 2,              &Textures[DUDE1]);
    createObject(200, 350, 0, 7, 0, AI_IDLE, 2,              &Textures[DUDE1]);
    createObject(200, 350, 0, 7, 0, AI_IDLE, 2,              &Textures[DUDE1]);
    createObject(200, 350, 0, 7, 0, AI_IDLE, 2,              &Textures[DUDE1]);
    createObject(200, 350, 0, 7, 0, AI_IDLE, 2,              &Textures[DUDE1]);
    createObject(200, 350, 0, 7, 0, AI_IDLE, 2,              &Textures[DUDE1]);
    createObject(200, 350, 0, 7, 0, AI_IDLE, 2,              &Textures[DUDE1]);
    createObject(200, 350, 0, 7, 0, AI_IDLE, 2,              &Textures[DUDE1]);
    createObject(200, 350, 0, 7, 0, AI_IDLE, 2,              &Textures[DUDE1]);
}*/