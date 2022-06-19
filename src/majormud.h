#ifndef MAJORMUD_H
#define MAJORMUD_H

#include <cstdint>

/**
 * 126-byte map describing a MajorMUD race
 */
struct MajorMUDRace {
    uint16_t id;                    //   0 - 2 bytes
    uint8_t name[30];               //   2 - 30 bytes
    uint16_t min_intellect;         //  32 - 2 bytes
    uint16_t min_willpower;         //  34 - 2 bytes
    uint16_t min_strength;          //  36 - 2 bytes
    uint16_t min_health;            //  38 - 2 bytes
    uint16_t min_agility;           //  40 - 2 bytes
    uint16_t min_charm;             //  42 - 2 bytes
    int16_t hp_bonus;               //  44 - 2 bytes
    uint8_t unknown_1[4];           //  46 - 4 bytes
    uint16_t ability_ids[10];       //  50 - 20 bytes
    uint16_t initial_cp;            //  70 - 2 bytes
    int16_t ability_values[10];     //  72 - 20 bytes
    uint8_t unknown_2[6];           //  92 - 6 bytes
    uint16_t exp_modifier;          //  98 - 2 bytes
    uint8_t unknown_3[2];           // 100 - 2 bytes
    uint16_t max_intellect;         // 102 - 2 bytes
    uint16_t max_willpower;         // 104 - 2 bytes
    uint16_t max_strength;          // 106 - 2 bytes
    uint16_t max_health;            // 108 - 2 bytes
    uint16_t max_agility;           // 110 - 2 bytes
    uint16_t max_charm;             // 112 - 2 bytes
    uint8_t unknown_4[12];          // 114 - 12 bytes
} __attribute__((__packed__));

/**
 * 157-byte map describing a MajorMUD class
 */
struct MajorMUDClass {
    uint16_t id;                    //   0 - 2 bytes
    uint8_t name[30];               //   2 - 30 bytes
    uint16_t min_hp_per_level;      //  32 - 2 bytes
    uint16_t max_hp_per_level;      //  34 - 2 bytes
    uint16_t exp_modifier;          //  36 - 2 bytes
    uint8_t unknown_1[6];           //  42 - 6 bytes
    uint16_t ability_ids[10];       //  48 - 20 bytes
    uint16_t magic_type;            //  68 - 2 bytes
    uint16_t magic_level;           //  70 - 2 bytes
    uint16_t weapon ;               //  72 - 2 bytes
    uint16_t armour;                //  74 - 2 bytes
    uint16_t combat;                //  76 - 2 bytes
    int16_t ability_values[10];     //  78 - 20 bytes
    uint8_t unknown_2[6];           //  98 - 6 bytes
    uint32_t title_textblock_id;    // 104 - 4 bytes
    uint8_t unknown_3[49];          // 108 - 49 bytes
} __attribute__((__packed__));

/**
 * 253-byte map describing a MajorMUD spell
 */
struct MajorMUDSpell {
    uint16_t id;                    //   0 - 2 bytes
    uint8_t name[30];               //   2 - 30 bytes
    uint8_t description_a[51];      //  32 - 51 bytes
    uint8_t description_b[51];      //  83 - 51 bytes
    uint16_t cast_a_message_id;     // 134 - 2 bytes
    uint8_t unknown_1[23];          // 136 - 23 bytes
    uint16_t level_cap;             // 159 - 2 bytes
    uint8_t unknown_2[4];           // 161 - 4 bytes
    int16_t ability_values[10];     // 165 - 20 bytes
    uint16_t energy;                // 185 - 2 bytes
    uint16_t level;                 // 187 - 2 bytes
    uint16_t min;                   // 189 - 2 bytes
    uint16_t max;                   // 191 - 2 bytes
    uint8_t unknown_3[3];           // 193 - 3 bytes
    uint16_t difficulty;            // 196 - 2 bytes
    uint16_t unknown_4;             // 198 - 2 bytes
    uint16_t target_type_id;        // 200 - 2 bytes
    uint16_t unknown_5;             // 202 - 2 bytes
    uint16_t attack_type;           // 204 - 2 bytes
    uint16_t unknown_6;             // 206 - 2 bytes
    uint8_t unknown_7;              // 208 - 1 byte
    uint16_t first_magery_type_id;  // 209 - 2 bytes
    uint16_t ability_ids[10];       // 211 - 20 bytes
    uint32_t cast_b_message_id;     // 231 - 4 bytes
    uint16_t mana;                  // 235 - 2 bytes
    uint16_t unknown_8;             // 237 - 2 bytes
    uint16_t unknown_9;             // 239 - 2 bytes
    uint16_t unknown_10;            // 241 - 2 bytes
    uint16_t unknown_11;            // 243 - 2 bytes
    uint8_t short_name[6];          // 245 - 6 bytes
    uint16_t unknown_12;            // 251 - 2 bytes
} __attribute__((__packed__));

/**
 * ???-byte map describing a MajorMUD item
 */
struct MajorMUDItem {
    uint32_t id;                    //   0 - 4 bytes
    uint16_t unknown_1;             //   4 - 2 bytes
    uint16_t game_limit;            //   6 - 2 bytes
    uint16_t unknown_2;             //   8 - 2 bytes
    uint16_t unknown_3;             //  10 - 2 bytes
    uint16_t unknown_4;             //  12 - 2 bytes
    uint16_t unknown_5;             //  14 - 2 bytes
    uint8_t unknown_6[157];         //  16 - 157 bytes
    uint8_t name[30];               // 173 - 30 bytes
    uint8_t description_1[61];      // 203 - 61 bytes
    uint8_t description_2[61];      // 264 - 61 bytes
    uint8_t description_3[61];      // 325 - 61 bytes
    uint8_t description_4[61];      // 386 - 61 bytes
    uint8_t description_5[61];      // 447 - 61 bytes
    uint8_t description_6[61];      // 508 - 61 bytes
    uint8_t description_7[61];      // 569 - 61 bytes
    uint8_t description_8[61];      // 630 - 61 bytes
    uint8_t description_9[61];      // 691 - 61 bytes
    uint16_t unknown_7;             // 752 - 2 bytes
    uint16_t weight;                // ??? - 2 bytes
    uint16_t type;                  // ??? - 2 bytes
    uint16_t ability_ids[20];
    int16_t uses;
    uint16_t unknown_8;
    uint16_t cost;
    uint16_t classes[10];
    uint16_t unknown_9;
    uint16_t unknown_10;
    uint16_t unknown_11;
    uint16_t min_hit;
    uint16_t max_hit;
    uint16_t armour_class;
    uint16_t races[10];
    uint16_t unknown_12[10];
    uint16_t negate[20];
    uint16_t weapon;
    uint16_t armour;
    uint16_t worn_on;
    uint16_t accuracy;
    uint16_t damage_reduction;
    uint8_t gettable;
    uint8_t unknown_13;
    uint16_t required_strength;
    uint16_t unknown_14[5];
    uint32_t open_runic;
    uint32_t open_platinum;
    uint32_t open_gold;
    uint32_t open_silver;
    uint32_t open_copper;
    uint16_t unknown_15[30];
    uint16_t speed;
    uint16_t unknown_16;
    uint16_t ability_values[20];
    uint16_t unknown_17;
    uint32_t hit_message;
    uint32_t miss_message;
    uint32_t read_tb;                   // what is this?
    uint32_t distruct_message;          // what is this?
    uint16_t unknown_18[6];
    uint8_t not_droppable;
    uint8_t cost_type;
    uint8_t retain_after_uses;
    uint8_t robbable;
    uint8_t destroy_on_death;
    uint8_t unknown_19;
//    uint16_t unknown_20;
} __attribute__((__packed__));

/**
 * ???-byte map describing a MajorMUD action
 */
struct MajorMUDAction {
    uint8_t name[28];
    uint16_t unknown_1;
    uint8_t single_to_user[74];
    uint16_t unknown_2[3];
    uint8_t single_to_room[74];
    uint16_t unknown_3[3];
    uint8_t user_to_user[74];
    uint16_t unknown_4[3];
    uint8_t user_to_other_user[74];
    uint16_t unknown_5[3];
    uint8_t user_to_room[74];
    uint16_t unknown_6[3];
    uint8_t monster_to_user[74];
    uint16_t unknown_7[3];
    uint8_t monster_to_room[74];
    uint16_t unknown_8[3];
    uint8_t inventory_to_user[74];
    uint16_t unknown_9[3];
    uint8_t inventory_to_room[74];
    uint16_t unknown_10[3];
    uint8_t floor_item_to_user[74];
    uint16_t unknown_11[3];
    uint8_t floor_item_to_room[74];
    uint16_t unknown_12[53];
} __attribute__((__packed__));

/**
 * ???-byte map describing a MajorMUD shop
 */
struct MajorMUDShop {
    uint32_t id;
    uint8_t name[39];
    uint16_t unknown_1;
    uint8_t description_1[51];
    uint16_t unknown_2;
    uint8_t description_2[51];
    uint16_t unknown_3;
    uint8_t description_3[51];
    uint16_t unknown_4[2];
    uint16_t type;
    uint16_t min_level;
    uint16_t max_level;
    uint16_t markup;
    uint16_t unknown_5;
    uint8_t class_limit;
    uint8_t unknown_6[3];
    int32_t item_ids[20];
    uint16_t item_max[20];
    uint16_t item_current[20];
    uint16_t item_regen_time[20];
    uint16_t item_regen_quantity[20];
    uint8_t item_regen_percentage[20];
} __attribute__((__packed__));

/**
 * ???-byte map describing a MajorMUD textblock
 */
struct MajorMUDTextblock {
    uint16_t part_number;
    uint8_t lead_in[14];
    uint32_t number;
    uint32_t link_to;
    uint8_t data[2000];
} __attribute__((__packed__));

/**
 * ???-byte map describing a MajorMUD room
 */
struct MajorMUDRoom {
    uint32_t map_id;
    uint32_t room_id;
    uint8_t unknown_1[253];
    uint8_t name[53];
    uint8_t description_1[71];
    uint8_t description_2[71];
    uint8_t description_3[71];
    uint8_t description_4[71];
    uint8_t description_5[71];
    uint8_t description_6[71];
    uint8_t description_7[71];
} __attribute__((__packed__));

/**
 * ???-byte map describing a MajorMUD NPC
 */
struct MajorMUDNPC {
    uint32_t id;
    uint8_t unknown_1[50];
    uint8_t name[30];
    uint16_t group;
    uint16_t unknown_2;
    uint32_t exp_multiplier;
    uint16_t index;
    uint16_t unknown_3;
    uint32_t unknown_4;
    uint32_t weapon_id;
    uint16_t damage_reduction;
    uint16_t armour_class;
    uint16_t unknown_5;
    uint16_t follow_percentage;
    uint16_t magic_resistance;
    uint16_t backstab_resistance;
    uint32_t experience;
    uint16_t hitpoints;
    uint16_t energy;
    uint16_t hitpoint_regen;
    uint16_t ability_ids[10];
    uint16_t ability_values[10];
    uint16_t game_limit;
    uint16_t active;
    uint16_t type;
    uint8_t unknown_6;
    uint8_t is_undead;
    uint16_t alignment;
    uint16_t unknown_7;
    uint16_t regen_time;
    uint16_t date_killed;
    uint16_t time_killed;
    uint32_t move_message;
    uint32_t death_message;
    uint32_t item_ids[10];
    uint16_t item_uses[10];
    uint8_t item_drop_percentage[10];
    uint16_t unknown_8;
    uint32_t runic;
    uint32_t platinum;
    uint32_t gold;
    uint32_t silver;
    uint32_t copper;
    uint32_t greet_text;
    uint16_t charm_level;
    uint16_t unknown_9;
    uint32_t description_text;
    uint8_t attack_type[5];
    uint8_t unknown_10;
    uint16_t attack_accuracy[5];
    uint8_t attack_percentage[5];
    uint8_t unknown_11;
    uint16_t attack_min_or_spell_percentage[5];
    uint16_t attack_max_or_spell_attack_level[5];
    uint16_t unknown_12;
    uint32_t attack_hit_message_id[5];
    uint32_t attack_dodge_message_id[5];
    uint32_t attack_miss_message_id[5];
    uint16_t attack_energy[5];
    uint16_t unknown_13;
    uint32_t talk_text;
    uint16_t charm_resistance;
    uint16_t unknown_14;
    uint16_t attack_hit_spell[5];
    uint16_t death_spell_id;
    uint16_t unknown_15;
    uint16_t unknown_16;
    uint16_t unknown_17;
    uint16_t unknown_18;
    uint16_t unknown_19;
    uint16_t unknown_20;
    uint16_t unknown_21;
    uint16_t create_spell_id;
    uint16_t spell_id[5];
    uint8_t spell_cast_per[5];
    uint8_t spell_cast_level[5];
    uint8_t description_1[71];
    uint8_t description_2[71];
    uint8_t description_3[71];
    uint8_t description_4[71];
    uint8_t gender;
    uint8_t unknown_22;
    uint16_t unknown_23;
} __attribute__((__packed__));

const char* get_ability_name(uint16_t ability_code) {
    switch (ability_code) {
        case 2: return "ArmourClass";
        case 4: return "MaxDamage";
        case 22: return "Accuracy";
        case 27: return "Stealth";
        case 29: return "Punch";
        case 30: return "Kick";
        case 31: return "Bash";
        case 34: return "Dodge";
        case 35: return "Jumpkick";
        case 37: return "Picklocks";
        case 38: return "Tracking";
        case 39: return "Thievery";
        case 40: return "Traps";
        case 51: return "MagicResist";
        case 57: return "GauntSeeHidden";
        case 58: return "Crits";
        case 69: return "MaxMana";
        case 70: return "Spellcasting";
        case 117: return "MinBackstab";
        case 118: return "MaxBackstab";
        case 103: return "ClassStealth";
        case 142: return "HitMagic";
        case 186: return "PerfectStealth";
        case 187: return "Meditate";
        default: return nullptr;
    }
}

const char* get_magic_type(uint16_t code) {
    switch (code) {
        case 0: return "None";
        case 1: return "Mage";
        case 2: return "Priest";
        case 3: return "Druid";
        case 4: return "Bard";
        case 5: return "Kai";
        default: return "???";
    }
}

const char* get_weapon_type(uint16_t code) {
    switch (code) {
        case 4: return "One-handed";
        case 7: return "Blunt";
        case 8: return "All";
        case 9: return "Staves";
        default: return "???";
    }
}

const char* get_armour_type(uint16_t code) {
    switch (code) {
        case 1: return "Robe";
        case 2: return "Ninja";
        case 6: return "Leather";
        case 7: return "Chainmail";
        case 8: return "Scale";
        case 9: return "Plate";
        default: return "???";
    }
}

#endif //MAJORMUD_H
