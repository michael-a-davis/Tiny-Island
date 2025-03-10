#include "stick.h"

Stick::Stick(int wrldX, int wrldY)
{
    name = "Stick";
    timeSpawned = GetTime();
    width = tileSize / 4;
    height = tileSize / 4;
    worldX = wrldX;
    worldY = wrldY;
    screenX = -worldX;
    screenY = -worldY;
    centerPoint = {screenX + (width / 2), screenY + (height / 2)};

    isRested = false;
    spawnAnimationCounter = 0;
    speed = 6.0f;
}

void Stick::events(Map& map) {
    return;
}

void Stick::update(Map& map) {
    timeAlive = GetTime() - timeSpawned;
    if (!isRested) {
        worldY += speed;
        spawnAnimationCounter++;
        if (spawnAnimationCounter >= 25) {
            isRested = true;
        }
    }

    screenX = worldX + map.getOffsetX();
    screenY = worldY + map.getOffsetY();
    zIndex = screenY - (tileSize / 2);
    centerPoint = {screenX + (width / 2), screenY + (height / 2)};
}

void Stick::draw(Map& map, Assets& assets) {
    DrawTexture(*assets.get("Stick"), screenX, screenY, WHITE);

    if (SHOW_CENTER_POINTS) {
        DrawCircle(centerPoint.x, centerPoint.y, 10.0f, YELLOW);
    }
}