#ifndef IMAGEMANAGER_H
#define IMAGEMANAGER_H

#include "config.h"
#include "data_manager.h"
#include <unordered_map>

namespace ygo {

enum TextureType
{
	SLEEVE = 0,
	AVATAR = 1
};

struct TextureData
{
	TextureType type;
	int player;
	char hostname[256];
	char filename[256];
	char fakename[256];
};

class ImageManager {
public:
	bool Initial();
	void SetDevice(irr::IrrlichtDevice* dev);
	void ClearTexture();
	void RemoveTexture(int code);
	void LoadSleeve(int player, wchar_t* site, wchar_t* dir);
	void LoadPendingTextures();
	Mutex mutex;
	irr::video::ITexture* GetTexture(int code);
	irr::video::ITexture* GetTextureThumb(int code);
	irr::video::ITexture* GetTextureField(int code);
	irr::video::ITexture* GetFieldTexture(int code, int player);

	std::unordered_map<int, irr::video::ITexture*> tMap;
	std::unordered_map<int, irr::video::ITexture*> tThumb;
	std::unordered_map<int, irr::video::ITexture*> tFields;
	std::unordered_map<int, irr::video::ITexture*> tSpellFields;
	irr::IrrlichtDevice* device;
	irr::video::IVideoDriver* driver;
	irr::video::ITexture* tCover[2];
	irr::video::ITexture* tUnknown;
	irr::video::ITexture* tAct;
	irr::video::ITexture* tAttack;
	irr::video::ITexture* tNegated;
	irr::video::ITexture* tChain;
	irr::video::ITexture* tNumber;
	irr::video::ITexture* tLPFrame;
	irr::video::ITexture* tLPBar;
	irr::video::ITexture* tMask;
	irr::video::ITexture* tEquip;
	irr::video::ITexture* tTarget;
	irr::video::ITexture* tLim;
	irr::video::ITexture* tHand[3];
	irr::video::ITexture* tBackGround;
	irr::video::ITexture* tBackGround2;
	irr::video::ITexture* tField;
	irr::video::ITexture* tFieldTransparent;
	irr::video::ITexture* tAvatar[4];

private:
	ITexture* DownloadTexture(TextureData *textureData);
	void ApplyTexture(TextureData *textureData, ITexture *texture);
	std::vector<TextureData *> pendingTextures;
};

extern ImageManager imageManager;

}

#endif // IMAGEMANAGER_H
