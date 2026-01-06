#include <Geode/Geode.hpp>
#include <Geode/utils/cocos.hpp>
#include <Geode/modify/GJBaseGameLayer.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>
#include <Geode/modify/LevelBrowserLayer.hpp>
#include <Geode/modify/FLAlertLayer.hpp>
#include <Geode/modify/CreatorLayer.hpp>
#include <Geode/modify/LevelSearchLayer.hpp>
#include <Geode/modify/SecretRewardsLayer.hpp>
#include <Geode/modify/GJShopLayer.hpp>
#include <Geode/modify/GauntletSelectLayer.hpp>
#include <Geode/modify/GauntletLayer.hpp>
#include <Geode/modify/LeaderboardsLayer.hpp>
#include <Geode/modify/LevelSelectLayer.hpp>
#include <Geode/modify/GJDropDownLayer.hpp>
#include <Geode/modify/SecretLayer.hpp>
#include <Geode/modify/SecretLayer2.hpp>
#include <Geode/modify/SecretLayer3.hpp>
#include <Geode/modify/SecretLayer4.hpp>
#include <Geode/modify/SecretLayer5.hpp>
#include <Geode/modify/LevelAreaLayer.hpp>
#include <Geode/modify/LevelAreaInnerLayer.hpp>
#include <Geode/modify/GJGarageLayer.hpp>
#include <Geode/modify/LevelListLayer.hpp>
#include <Geode/modify/PlayerObject.hpp>
#include <Geode/modify/LevelSettingsObject.hpp>
using namespace geode::prelude;
class $modify(PlayerObject) {
	virtual void update(float dt) {
		this->update(dt);
		if (Mod::get()->getSettingValue<bool>("no-wave-trail")) this->m_waveTrail->reset();
		this->m_waveTrail->m_waveSize=Mod::get()->getSettingValue<double>("wave-trail-size")*this->m_vehicleSize;
	};
	void playSpawnEffect() {
        if (!Mod::get()->getSettingValue<bool>("no-respawn-flash")) PlayerObject::playSpawnEffect();
	};
};
class $modify(LevelSettingsObject) {
	virtual bool init() {
		auto r=LevelSettingsObject::init();
		if (Mod::get()->getSettingValue<bool>("auto-legacy")) {
			this->m_fixGravityBug=false;
			this->m_allowMultiRotation=false;
			this->m_sortGroups=false;
			this->m_dynamicLevelHeight=false;
			this->m_enablePlayerSqueeze=false;
			this->m_fixRobotJump=false;
			this->m_fixNegativeScale=false;
			this->m_allowStaticRotate=false;
			this->m_enable22Changes=false;
			this->m_fixRadiusCollision=false;
		};
		return r;
	};
};
class $modify(GJBaseGameLayer) {
    void createBackground(int background) {
        if (Mod::get()->getSettingValue<int64_t>("force-background")!=0) {
            GJBaseGameLayer::createBackground(Mod::get()->getSettingValue<int64_t>("force-background"));
        } else {
            GJBaseGameLayer::createBackground(background);
        };
    };
};
class $modify(GJDropDownLayer) {
	bool init(char const* title, float height, bool noBack) {
		if (Mod::get()->getSettingValue<bool>("remove-controller-glyphs")) {
			auto r=GJDropDownLayer::init(title, height, noBack);
			auto backHint=this->getChildByIDRecursive("controller-back-hint");
			if (backHint) backHint->removeFromParent();
			return r;
		};
		return GJDropDownLayer::init(title, height, noBack);
	};
};
class $modify(LevelSelectLayer) {
	bool init(int page) {
		if (Mod::get()->getSettingValue<bool>("remove-controller-glyphs")) {
			auto r=LevelSelectLayer::init(page);
			auto backHint=this->getChildByIDRecursive("controller-back-hint");
			if (backHint) backHint->removeFromParent();
			if (this->getChildByIDRecursive("controller-start-sprite")) {
				this->getChildByIDRecursive("level-page-1")->getChildByIDRecursive("controller-start-sprite")->removeFromParent();
				this->getChildByIDRecursive("level-page-2")->getChildByIDRecursive("controller-start-sprite")->removeFromParent();
				this->getChildByIDRecursive("level-page-3")->getChildByIDRecursive("controller-start-sprite")->removeFromParent();
			};
			return r;
		};
		return LevelSelectLayer::init(page);
	};
};
class $modify(LeaderboardsLayer) {
	bool init(LeaderboardState state) {
		if (Mod::get()->getSettingValue<bool>("remove-controller-glyphs")) {
			auto r=LeaderboardsLayer::init(state);
			this->removeChildByID("controller-back-hint");
			return r;
		};
		return LeaderboardsLayer::init(state);
	};
};
class $modify(SecretRewardsLayer) {
	bool init(bool fromShop) {
		if (Mod::get()->getSettingValue<bool>("remove-controller-glyphs")) {
			auto r=SecretRewardsLayer::init(fromShop);
			this->removeChildByID("key-icon");
			return r;
		};
		return SecretRewardsLayer::init(fromShop);
	};
};
class $modify(GJGarageLayer) {
	bool init() {
		if (Mod::get()->getSettingValue<bool>("remove-controller-glyphs")) {
			auto r=GJGarageLayer::init();
			this->removeChildByID("controller-back-hint");
			return r;
		};
		return GJGarageLayer::init();
	};
};
class $modify(LevelListLayer) {
	void onEnter() {
		LevelListLayer::onEnter();
		if (Mod::get()->getSettingValue<bool>("remove-controller-glyphs")) {
			this->removeChildByID("controller-back-hint");
		};
	};
};
class $modify(SecretLayer) {
	bool init() {
		if (Mod::get()->getSettingValue<bool>("remove-controller-glyphs")) {
			auto r=SecretLayer::init();
			this->removeChildByID("controller-back-hint");
			return r;
		};
		return SecretLayer::init();
	};
};
class $modify(SecretLayer2) {
	bool init() {
		if (Mod::get()->getSettingValue<bool>("remove-controller-glyphs")) {
			auto r=SecretLayer2::init();
			this->removeChildByID("the-challenge-text1"); //???
			return r;
		};
		return SecretLayer2::init();
	};
};
class $modify(SecretLayer3) {
	bool init() {
		if (Mod::get()->getSettingValue<bool>("remove-controller-glyphs")) {
			auto r=SecretLayer3::init();
			this->removeChildByID("back-menu");
			return r;
		};
		return SecretLayer3::init();
	};
};
class $modify(SecretLayer4) {
	bool init() {
		if (Mod::get()->getSettingValue<bool>("remove-controller-glyphs")) {
			auto r=SecretLayer4::init();
			this->removeChildByID("controller-back-hint");
			return r;
		};
		return SecretLayer4::init();
	};
};
class $modify(SecretLayer5) {
	bool init() {
		if (Mod::get()->getSettingValue<bool>("remove-controller-glyphs")) {
			auto r=SecretLayer5::init();
			this->removeChildByID("controller-back-hint");
			return r;
		};
		return SecretLayer5::init();
	};
};
class $modify(LevelAreaLayer) {
	bool init() {
		if (Mod::get()->getSettingValue<bool>("remove-controller-glyphs")) {
			auto r=LevelAreaLayer::init();
			this->removeChildByID("background"); //???
			return r;
		};
		return LevelAreaLayer::init();
	};
};
class $modify(LevelAreaInnerLayer) {
	bool init(bool returning) {
		if (Mod::get()->getSettingValue<bool>("remove-controller-glyphs")) {
			auto r=LevelAreaInnerLayer::init(returning);
			this->removeChildByID("controller-back-hint");
			return r;
		};
		return LevelAreaInnerLayer::init(returning);
	};
};
class $modify(GauntletLayer) {
	bool init(GauntletType type) {
		if (Mod::get()->getSettingValue<bool>("remove-controller-glyphs")) {
			auto r=GauntletLayer::init(type);
			this->removeChildByID("controller-back-hint");
			return r;
		};
		return GauntletLayer::init(type);
	};
};
class $modify(GauntletSelectLayer) {
	bool init(int unused) {
		if (Mod::get()->getSettingValue<bool>("remove-controller-glyphs")) {
			auto r=GauntletSelectLayer::init(unused);
			this->removeChildByID("controller-back-hint");
			return r;
		};
		return GauntletSelectLayer::init(unused);
	};
};
class $modify(GJShopLayer) {
	bool init(ShopType type) {
		if (Mod::get()->getSettingValue<bool>("remove-controller-glyphs")) {
			auto r=GJShopLayer::init(type);
			this->removeChildByID("controller-back-hint");
			return r;
		};
		return GJShopLayer::init(type);
	};
};
class $modify(LevelInfoLayer) {
	bool init(GJGameLevel* level, bool challenge) {
		if (Mod::get()->getSettingValue<bool>("remove-controller-glyphs")) {
			auto r=LevelInfoLayer::init(level, challenge);
			this->removeChildByID("controller-back-hint");
			auto playGlyph=geode::cocos::getChildBySpriteFrameName(this->getChildByIDRecursive("play-button")->getChildByIndex(0), "controllerBtn_Start_001.png");
			if (playGlyph) playGlyph->removeFromParent();
			return r;
		};
		return LevelInfoLayer::init(level, challenge);
	};
};
class $modify(CreatorLayer) {
	bool init() { 
		if (Mod::get()->getSettingValue<bool>("remove-controller-glyphs")) {
			auto r=CreatorLayer::init();
			this->removeChildByID("controller-back-hint");
			return r;
		};
		return CreatorLayer::init();
	};
};
class $modify(LevelSearchLayer) {
	bool init(int type) { 
		if (Mod::get()->getSettingValue<bool>("remove-controller-glyphs")) {
			auto r=LevelSearchLayer::init(type);
			this->removeChildByID("controller-back-hint");
			return r;
		};
		return LevelSearchLayer::init(type);
	};
};
class $modify(FLAlertLayer) {
	bool init(FLAlertLayerProtocol* delegate, char const* title, gd::string desc, char const* btn1, char const* btn2, float width, bool scroll, float height, float textScale) {
		auto r=FLAlertLayer::init(delegate, title, desc, btn1, btn2, width, scroll, height, textScale);
        if (Mod::get()->getSettingValue<bool>("remove-controller-glyphs")) {
			auto ml=this->getChildByID("main-layer");
        	ml->removeChildByID("controller-back-hint");
        	ml->removeChildByID("controller-ok-hint");
        };
		return r;
	};
};
class $modify(PauseLayer) {
    void customSetup() {
        PauseLayer::customSetup();
        if (Mod::get()->getSettingValue<bool>("remove-controller-glyphs")) {
            this->removeChildByID("controller-practice-hint");
            this->removeChildByID("controller-back-hint");
            this->removeChildByID("controller-play-hint");
        };
    };
};
class $modify(LevelBrowserLayer) {
	bool init(GJSearchObject* object) {
		auto r=LevelBrowserLayer::init(object);
        if (Mod::get()->getSettingValue<bool>("remove-controller-glyphs")) {
        	this->removeChildByID("controller-back-hint");
        	this->removeChildByID("controller-scroll-rthumb");
			this->removeChildByID("controller-scroll-down");
			this->removeChildByID("controller-scroll-up");
        };
		return r;
	};
};
class $modify(MenuLayer) {
    bool init() {
		auto r=MenuLayer::init();
        if (Mod::get()->getSettingValue<bool>("remove-controller-glyphs")) {
        	this->removeChildByID("controller-back-hint");
        	this->removeChildByID("click-gamepad-icon");
        	this->removeChildByID("mouse-gamepad-label");
        	this->removeChildByID("mouse-gamepad-icon");
        	this->removeChildByID("click-gamepad-label");
        	this->removeChildByID("editor-gamepad-icon");
        	this->removeChildByID("play-gamepad-icon");
			this->removeChildByID("icon-kit-gamepad-icon");
        };
        return r;
    };
	// Socials Confirmation
	void onTwitch(cocos2d::CCObject* sender) {
		if (Mod::get()->getSettingValue<bool>("socials-confirmation")) {
			geode::createQuickPopup(
    			"Twitch",
    			"Are you sure you want to open RobTop\'s <cp>Twitch</c>?",
    			"Cancel", "Yes",
    			[](auto, bool btn2) {
        			if (btn2) {
            			geode::utils::web::openLinkInBrowser("https://www.twitch.tv/robtopgames");
        			};
    			}
			);
		};
		if (!Mod::get()->getSettingValue<bool>("socials-confirmation")) {
            geode::utils::web::openLinkInBrowser("https://www.twitch.tv/robtopgames");
		};
	};
	void onYouTube(cocos2d::CCObject* sender) {
		if (Mod::get()->getSettingValue<bool>("socials-confirmation")) {
			geode::createQuickPopup(
    			"YouTube",
    			"Are you sure you want to open RobTop\'s <cr>YouTube</c>?",
    			"Cancel", "Yes",
    			[](auto, bool btn2) {
        			if (btn2) {
            			geode::utils::web::openLinkInBrowser("https://www.youtube.com/@robtopgames");
        			};
    			}
			);
		};
		if (!Mod::get()->getSettingValue<bool>("socials-confirmation")) {
            geode::utils::web::openLinkInBrowser("https://www.youtube.com/@robtopgames");
		};
	};
	void onTwitter(cocos2d::CCObject* sender) {
		if (Mod::get()->getSettingValue<bool>("socials-confirmation")) {
			geode::createQuickPopup(
    			"Twitter",
    			"Are you sure you want to open RobTop\'s <cj>Twitter</c>?",
    			"Cancel", "Yes",
    			[](auto, bool btn2) {
        			if (btn2) {
            			geode::utils::web::openLinkInBrowser("https://x.com/robtopgames");
        			};
    			}
			);
		}; 
		if (!Mod::get()->getSettingValue<bool>("socials-confirmation")) {
            geode::utils::web::openLinkInBrowser("https://x.com/robtopgames");
		};
	};
	void onFacebook(cocos2d::CCObject* sender) {
		if (Mod::get()->getSettingValue<bool>("socials-confirmation")) {
			geode::createQuickPopup(
    			"Facebook",
    			"Are you sure you want to open RobTop\'s <cb>Facebook</c>?",
    			"Cancel", "Yes",
    			[](auto, bool btn2) {
        			if (btn2) {
            			geode::utils::web::openLinkInBrowser("https://www.facebook.com/people/RobTop-Games/100081802506994/");
        			};
    			}
			);
		}; 
		if (!Mod::get()->getSettingValue<bool>("socials-confirmation")) {
            geode::utils::web::openLinkInBrowser("https://www.facebook.com/people/RobTop-Games/100081802506994/");
		};
	};
	void onDiscord(cocos2d::CCObject* sender) {
		if (Mod::get()->getSettingValue<bool>("socials-confirmation")) {
			geode::createQuickPopup(
    			"Discord",
    			"Are you sure you want to open the Geometry Dash <cl>Discord</c>?",
    			"Cancel", "Yes",
    			[](auto, bool btn2) {
        			if (btn2) {
            			geode::utils::web::openLinkInBrowser("https://discord.com/invite/geometrydash");
        			};
    			}
			);
		}; 
		if (!Mod::get()->getSettingValue<bool>("socials-confirmation")) {
            geode::utils::web::openLinkInBrowser("https://discord.com/invite/geometrydash");
		};
	};
};