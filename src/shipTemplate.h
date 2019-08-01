#ifndef SHIP_TEMPLATE_H
#define SHIP_TEMPLATE_H

#include <unordered_map>
#include <unordered_set>
#include "engine.h"
#include "modelData.h"

#include "beamTemplate.h"
#include "missileWeaponData.h"
constexpr static int max_beam_weapons = 16;
constexpr static int max_weapon_tubes = 16;
constexpr static int max_shield_count = 8;

enum ESystem
{
    SYS_None = -1,
    SYS_Reactor = 0,
    SYS_BeamWeapons,
    SYS_MissileSystem,
    SYS_Maneuver,
    SYS_Impulse,
    SYS_Warp,
    SYS_JumpDrive,
    SYS_FrontShield,
    SYS_RearShield,
    SYS_COUNT
};
/* Define script conversion function for the ESystem enum. */
template<> void convert<ESystem>::param(lua_State* L, int& idx, ESystem& es);

class ShipRoomTemplate
{
public:
    sf::Vector2i position;
    sf::Vector2i size;
    ESystem system;

    ShipRoomTemplate(sf::Vector2i position, sf::Vector2i size, ESystem system) : position(position), size(size), system(system) {}
};
class ShipDoorTemplate
{
public:
    sf::Vector2i position;
    bool horizontal;

    ShipDoorTemplate(sf::Vector2i position, bool horizontal) : position(position), horizontal(horizontal) {}
};

class SpaceObject;
class ShipTemplate : public PObject
{
public:
    enum TemplateType
    {
        Ship,
        PlayerShip,
        Station
    };
    class TubeTemplate
    {
    public:
        float load_time;
        uint32_t type_allowed_mask;
        float direction;
    };
private:
    static std::unordered_map<string, P<ShipTemplate> > templateMap;
    string name;
    string description;
    string class_name = "No class";
    string sub_class_name = "No sub-class";
    TemplateType type = Ship;
public:
    string getName();
    string getDescription();
    string getClass();
    string getSubClass();
    void setType(TemplateType type);
    TemplateType getType();

    P<ModelData> model_data;

    /*!
     * List of ship classes that can dock with this ship. (only used for ship2ship docking)
     */
    std::unordered_set<string> can_be_docked_by_class;
    bool shares_energy_with_docked = true;
    bool repair_docked = false;
    
    float energy_storage_amount  = 1000;
    int repair_crew_count = 3;
    string default_ai_name;
    BeamTemplate beams[max_beam_weapons];
    int weapon_tube_count = 0;
    TubeTemplate weapon_tube[max_weapon_tubes];
    float hull = 70;
    int shield_count = 0;
    float shield_level[max_shield_count];
    float impulse_speed = 500.0f;
    float turn_speed = 10.0f;
    float warp_speed = 0.0f;
    float impulse_acceleration = 20.0f;
    float combat_maneuver_boost_speed = 0.0f;
    float combat_maneuver_strafe_speed = 0.0f;
    bool has_jump_drive = false;
    bool has_cloaking = false;
    float jump_drive_min_distance = 5000.0;
    float jump_drive_max_distance = 50000.0;
    int weapon_storage[MW_Count] = {0};

    string radar_trace = "RadarArrow.png";

    std::vector<ShipRoomTemplate> rooms;
    std::vector<ShipDoorTemplate> doors;

    ShipTemplate();

    void setName(string name);
    void setClass(string class_name, string sub_class_name);
    void setDescription(string description);
    void setModel(string model_name);
    void setDefaultAI(string default_ai_name);
    void setDockClasses(std::vector<string> classes);
    void setSharesEnergyWithDocked(bool enabled);
    void setRepairDocked(bool enabled);
    void setMesh(string model, string color_texture, string specular_texture, string illumination_texture);
    void setEnergyStorage(float energy_amount);
    void setRepairCrewCount(int amount);

    void setBeam(int index, float arc, float direction, float range, float cycle_time, float damage);
    void setBeamWeapon(int index, float arc, float direction, float range, float cycle_time, float damage);
    void setBeamWeaponTurret(int index, float arc, float direction, float rotation_rate);

    /**
     * Convenience function to set the texture of a beam by index.
     */
    void setBeamTexture(int index, string texture);
    void setBeamWeaponEnergyPerFire(int index, float energy) { if (index < 0 || index >= max_beam_weapons) return; return beams[index].setEnergyPerFire(energy); }
    void setBeamWeaponHeatPerFire(int index, float heat) { if (index < 0 || index >= max_beam_weapons) return; return beams[index].setHeatPerFire(heat); }

    void setTubes(int amount, float load_time);
    void setTubeLoadTime(int index, float load_time);
    void weaponTubeAllowMissle(int index, EMissileWeapons type);
    void weaponTubeDisallowMissle(int index, EMissileWeapons type);
    void setWeaponTubeExclusiveFor(int index, EMissileWeapons type);
    void setTubeDirection(int index, float direction);
    void setHull(float amount) { hull = amount; }
    void setShields(std::vector<float> values);
    void setSpeed(float impulse, float turn, float acceleration);
    void setCombatManeuver(float boost, float strafe);
    void setWarpSpeed(float warp);
    void setJumpDrive(bool enabled);
    void setJumpDriveRange(float min, float max) { jump_drive_min_distance = min; jump_drive_max_distance = max; }
    void setCloaking(bool enabled);
    void setWeaponStorage(EMissileWeapons weapon, int amount);
    void addRoom(sf::Vector2i position, sf::Vector2i size);
    void addRoomSystem(sf::Vector2i position, sf::Vector2i size, ESystem system);
    void addDoor(sf::Vector2i position, bool horizontal);
    void setRadarTrace(string trace);

    P<ShipTemplate> copy(string new_name);

    sf::Vector2i interiorSize();
    ESystem getSystemAtRoom(sf::Vector2i position);

    void setCollisionData(P<SpaceObject> object);
public:
    static P<ShipTemplate> getTemplate(string name);
    static std::vector<string> getAllTemplateNames();
    static std::vector<string> getTemplateNameList(TemplateType type);
};
string getSystemName(ESystem system);
REGISTER_MULTIPLAYER_ENUM(ESystem);

/* Define script conversion function for the ShipTemplate::TemplateType enum. */
template<> void convert<ShipTemplate::TemplateType>::param(lua_State* L, int& idx, ShipTemplate::TemplateType& tt);

#ifdef _MSC_VER
// MFC: GCC does proper external template instantiation, VC++ doesn't.
#include "shipTemplate.hpp"
#endif /* _MSC_VER */

#endif//SHIP_TEMPLATE_H
