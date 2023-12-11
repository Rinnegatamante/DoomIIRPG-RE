#ifndef __GAME_H__
#define __GAME_H__

#include "EntityMonster.h"
#include "GameSprite.h"
#include "LerpSprite.h"
#include "ScriptThread.h"

class EntityMonster;
class MayaCamera;
class Entity;
class GameSprite;
class LerpSprite;
class ScriptThread;
class OutputStream;
class InputStream;
class EntityDef;

class Game
{
private:

public:

    static constexpr int32_t dropDirs[] { 64, 0, 64, 64, 0, 64, -64, 64, -64, 0, -64, -64, 0, -64, 64, -64 };
    static constexpr int MAX_GRID_ENTITIES = 9;
    static constexpr int MAX_ENTITIES = 275;
    static constexpr int FILE_NAME_FULLWORLD = 0;
    static constexpr int FILE_NAME_CONFIG = 1;
    static constexpr int FILE_NAME_BRIEFPLAYER = 2;
    static constexpr int FILE_NAME_FULLPLAYER = 3;
    static constexpr int FILE_NAME_BRIEFWORLD = 4;

    uint8_t* monsterSounds;
	int OFS_MAYAKEY_X;
	int OFS_MAYAKEY_Y;
	int OFS_MAYAKEY_Z;
	int OFS_MAYAKEY_PITCH;
	int OFS_MAYAKEY_YAW;
	int OFS_MAYAKEY_ROLL;
	int OFS_MAYAKEY_MS;
    short* ofsMayaTween;
    int camPlayerX;
    int camPlayerY;
    int camPlayerZ;
    int camPlayerYaw;
    int camPlayerPitch;
    MayaCamera* mayaCameras;
    int totalMayaCameras;
    int16_t* mayaCameraKeys;
    int8_t* mayaCameraTweens;
    int16_t* mayaTweenIndices;
    int totalMayaCameraKeys;
    int totalMayaTweens;
    Entity* entities;
    int numEntities;
    Entity* entityDb[1024];
    EntityMonster entityMonsters[80];
    int numMonsters;
    int spawnParam;
    bool disableAI;
    bool skipMinigames;
    Entity* inactiveMonsters;
    Entity* activeMonsters;
    Entity* combatMonsters;
    int cinUnpauseTime;
    int lastTurnTime;
    bool pauseGameTime;
    int firstDropIndex;
    int dropIndex;
    int lastDropEntIndex;
    bool skippingCinematic;
    bool skipDialog;
    bool skipAdvanceTurn;
    bool queueAdvanceTurn;
    char keycode[7];
    int monstersTurn;
    bool monstersUpdated;
    bool interpolatingMonsters;
    bool gotoTriggered;
    bool isSaved;
    bool isLoaded;
    int eventFlags[2];
    GameSprite gsprites[48];
    int activeSprites;
    int activePropogators;
    int animatingEffects;
    int changeMapParam;
    int saveStateMap;
    uint8_t difficulty;
    int activeLoadType;
    bool updateAutomap;
    bool hasSeenIntro;
    bool skipMovie;
    int levelVars[8];
    int16_t* levelNames;
    int levelNamesCount; // Port: New
    int totalLevelTime;
    int curLevelTime;
    uint16_t lootFound;
    uint16_t totalLoot;
    MayaCamera* activeCamera;
    int activeCameraTime;
    int activeCameraKey;
    bool activeCameraView;
    Entity* watchLine;
    LerpSprite lerpSprites[16];
    int numLerpSprites;
    ScriptThread scriptThreads[20];
    int numScriptThreads;
    bool pathVisitedl[64];
    short pathParents[64];
    short pathSearches[64];
    int numPathSearches;
    bool secretActive;
    Entity* openDoors[6];
    int viewX;
    int viewY;
    int viewAngle;
    int destX;
    int destY;
    int destAngle;
    int viewSin;
    int viewCos;
    int viewStepX;
    int viewStepY;
    int viewRightStepX;
    int viewRightStepY;
    short scriptStateVars[128];
    uint8_t mapSecretsFound;
    uint8_t totalSecrets;
    int cinematicWeapon;
    short entityDeathFunctions[128];
    int numDestroyableObj;
    int destroyedObj;
    int placedBombs[4];
    Entity* gridEntities[Game::MAX_GRID_ENTITIES];
    int64_t curPath;
    long field_0x486c_;
    int pathDepth;
    int pathSearchDepth;
    int64_t closestPath;
    int closestPathDepth;
    int closestPathDist;
    int lineOfSight;
    int lineOfSightWeight;
    Entity* findEnt;
    Entity* skipEnt;
    int interactClipMask;
    uint8_t visitOrder[8];
    int visitDist[8];
    int visitedTiles[32];
    int baseVisitedTiles[32];
    int numMallocsForVIOS;
    bool angryVIOS;
    short numLevelLoads[10];
    int totalPlayTime;
    int lastSaveTime;
    Entity* traceEntities[32];
    int traceFracs[32];
    int numTraceEntities;
    int traceBoundingBox[4];
    int tracePoints[4];
    int traceCollisionX;
    int traceCollisionY;
    int traceCollisionZ;
    Entity* traceEntity;
    int posShift;
    int angleShift;
    int numCallThreads;
    ScriptThread* callThreads[16];

	// Constructor
	Game();
	// Destructor
	~Game();

	bool startup();
    void unlinkEntity(Entity* entity);
    void linkEntity(Entity* entity, int i, int i2);
    void unlinkWorldEntity(int i, int i2);
    void linkWorldEntity(int i, int i2);
    void removeEntity(Entity* entity);
    void trace(int n, int n2, int n3, int n4, Entity* entity, int n5, int n6);
    void trace(int n, int n2, int n3, int traceCollisionX, int traceCollisionY, int traceCollisionZ, Entity* entity, int n4, int n5, bool b);
    void loadMapEntities();
    void loadTableCamera(int i, int i2);
    void setKeyOffsets();
    void loadMayaCameras(InputStream* IS);
    void unloadMapData();
    bool touchTile(int n, int n2, bool b);
    void prepareMonsters();
    Entity* findMapEntity(int n, int n2);
    Entity* findMapEntity(int n, int n2, int n3);
    void activate(Entity* entity);
    void activate(Entity* entity, bool b, bool b2, bool b3, bool b4);
    void killAll();
    void deactivate(Entity* entity);
    void UpdatePlayerVars();
    void monsterAI();
    void monsterLerp();
    void spawnPlayer();
    void eventFlagsForMovement(int n, int n2, int n3, int n4);
    int eventFlagForDirection(int n, int n2);
    void givemap(int n, int n2, int n3, int n4);
    bool performDoorEvent(int n, Entity* entity, int n2);
    bool performDoorEvent(int n, Entity* entity, int n2, bool b);
    bool performDoorEvent(int n, ScriptThread* scriptThread, Entity* watchLine, int n2, bool b);
    void lerpSpriteAsDoor(int n, int n2, ScriptThread* scriptThread);
    void updatePlayerDoors(Entity* entity, bool b);
    bool CanCloseDoor(Entity* entity);
    void advanceTurn();
    void gsprite_clear(int n);
    GameSprite* gsprite_alloc(int n, int n2, int n3);
    GameSprite* gsprite_allocAnim(int n, int n2, int n3, int n4);
    void gsprite_destroy(GameSprite* gameSprite);
    void snapGameSprites();
    void gsprite_update(int n);
    void saveWorldState(OutputStream* OS, bool b);
    void loadWorldState();
    bool loadWorldState(InputStream* IS);
    void saveConfig();
    void loadConfig();
    void saveState(int lastMapID, int loadMapID, int viewX, int viewY, int viewAngle, int viewPitch, int prevX, int prevY, int saveX, int saveY, int saveZ, int saveAngle, int savePitch, int saveType);
    void saveLevelSnapshot();
    bool savePlayerState(OutputStream* OS,int loadMapID, int viewX, int viewY, int viewAngle, int viewPitch, int prevX, int prevY, int saveX, int saveY, int saveZ, int saveAngle, int savePitch);
    bool loadPlayerState(InputStream* IS);
    bool loadState(int activeLoadType);
    bool hasConfig();
    bool hasElement(const char* name);
    bool hasSavedState();
    void removeState(bool b);
    void saveEmptyConfig();
    bool canSnapMonsters();
    bool snapMonsters(bool b);
    void endMonstersTurn();
    void updateMonsters();
    void setLineLocked(Entity* entity, bool b);
    void snapAllMovers();
    void skipCinematic();
    int getNextBombIndex();
    void updateBombs();
    int setDynamite(int x, int y, bool b);
    Entity* getFreeDropEnt();
    void allocDynamite(int n, int n2, int n3, int n4, int n5, int n6);
    Entity* spawnDropItem(int n, int n2, int n3, EntityDef* def, int param, bool b);
    Entity* spawnDropItem(int n, int n2, int n3, int n4, int n5, int n6, int n7, bool b);
    void spawnDropItem(Entity* entity);
    Entity* spawnPlayerEntityCopy(int n, int n2);
    Entity* spawnSentryBotCorpse(int n, int n2, int n3, int n4, int n5);
    void throwDropItem(int dstX, int dstY, int n, Entity* entity);
    int updateLerpSprite(LerpSprite* lerpSprite);
    void snapLerpSprites(int n);
    void updateLerpSprites();
    LerpSprite* allocLerpSprite(ScriptThread* thread, int n, bool b);
    void freeLerpSprite(LerpSprite* lerpSprite);
    void runScriptThreads(int n);
    ScriptThread* allocScriptThread();
    void freeScriptThread(ScriptThread* scriptThread);
    bool isCameraActive();
    int executeTile(int n, int n2, int n3);
    bool doesScriptExist(int n, int n2, int n3);
    int executeTile(int n, int n2, int n3, bool b);
    int executeStaticFunc(int n);
    int queueStaticFunc(int n);
    int getSaveVersion();
    void loadEntityStates(InputStream* IS);
    void saveEntityStates(OutputStream* OS, bool b);
    bool tileObstructsAttack(int n, int n2);
    bool isInputBlockedByScript();
    void updateScriptVars();
    void awardSecret(bool b);
    void addEntityDeathFunc(Entity* entity, int n);
    void removeEntityFunc(Entity* entity);
    void executeEntityFunc(Entity* entity, bool throwAwayLoot);
    void foundLoot(int n, int n2);
    void foundLoot(int n, int n2, int n3, int n4);
    void destroyedObject(int n);
    void raiseCorpses();
    bool isInFront(int n, int n2);
    int VecToDir(int n, int n2, bool b);
    void NormalizeVec(int n, int n2, int* array);
    int64_t FixedSqrt(int64_t n);
    void setMonsterClip(int n, int n2);
    void unsetMonsterClip(int n, int n2);
    bool monsterClipExists(int n, int n2);

    void cleanUpCamMemory();

    const char* Game::GetSaveFile(int i, int i2);
    char* Game::getProfileSaveFileName(const char* name);
    int Game::getMonsterSound(int eSubType, int param, int soundType);
};

#endif