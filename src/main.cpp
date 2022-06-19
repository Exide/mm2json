#include <cstdio>
#include "btrieve.h"
#include "majormud.h"

void print_usage() {
    printf("Usage: mm2json --[race|class|spell|item|action|shop|textblock|room|npc] FILE\n"
           "A command-line program for extracting MajorMUD data from the original Btrieve files.\n\n");
}

typedef int (*Transform)(uint8_t*, size_t);

size_t get_lowest_size(size_t actual_size, size_t expected_size) {
    if (actual_size > expected_size) return expected_size;
    else return actual_size;
}

int transform_race(uint8_t* bytes, size_t actual_size) {
    size_t size = get_lowest_size(actual_size, sizeof(MajorMUDRace));

    MajorMUDRace majormud_race = {};
    memcpy(&majormud_race, bytes, size);

    printf("{");
    printf(R"("id":%d,)", majormud_race.id);
    printf(R"("name":"%s",)", majormud_race.name);
    printf(R"("exp_modifier":%1.2f,)", ((int16_t)majormud_race.exp_modifier + 100)/100.0);
    printf(R"("hp_bonus":%d,)", majormud_race.hp_bonus);
    printf(R"("initial_cp":%d,)", majormud_race.initial_cp);
    printf(R"("intellect":{"min":%d,"max":%d},)", majormud_race.min_intellect, majormud_race.max_intellect);
    printf(R"("willpower":{"min":%d,"max":%d},)", majormud_race.min_willpower, majormud_race.max_willpower);
    printf(R"("strength":{"min":%d,"max":%d},)", majormud_race.min_strength, majormud_race.max_strength);
    printf(R"("health":{"min":%d,"max":%d},)", majormud_race.min_health, majormud_race.max_health);
    printf(R"("agility":{"min":%d,"max":%d},)", majormud_race.min_agility, majormud_race.max_agility);
    printf(R"("charm":{"min":%d,"max":%d},)", majormud_race.min_charm, majormud_race.max_charm);
    printf(R"("abilities":[)");
    for (int i = 0; i < 10; ++i) {
        const char *ability_name = get_ability_name(majormud_race.ability_ids[i]);
        if (ability_name != nullptr) {
            printf(R"({"%s":%d})", ability_name, majormud_race.ability_values[i]);
        } else {
            printf(R"({"%d":%d})", majormud_race.ability_ids[i], majormud_race.ability_values[i]);
        }

        if (i < 9) printf(",");
    }
    printf("]");
    printf("}\n");
    
    return 0;
}

int transform_class(uint8_t* bytes, size_t actual_size) {
    size_t size = get_lowest_size(actual_size, sizeof(MajorMUDClass));

    MajorMUDClass majormud_class = {};
    memcpy(&majormud_class, bytes, size);

    printf("{");
    printf(R"("id":%d,)", majormud_class.id);
    printf(R"("name":"%s",)", majormud_class.name);
    printf(R"("exp_modifier":%1.2f,)", ((int16_t)majormud_class.exp_modifier + 100)/100.0);
    printf(R"("hp_per_level":{"min":%d,"max":%d},)", majormud_class.min_hp_per_level, majormud_class.min_hp_per_level + majormud_class.max_hp_per_level);
    printf(R"("magic_type":"%s",)", get_magic_type(majormud_class.magic_type));
    printf(R"("magic_level":%d,)", majormud_class.magic_level);
    printf(R"("weapon":"%s",)", get_weapon_type(majormud_class.weapon));
    printf(R"("armour":"%s",)", get_armour_type(majormud_class.armour));
    printf(R"("combat":%d,)", majormud_class.combat - 2);
    printf(R"("title_textblock_id":%d,)", majormud_class.title_textblock_id);
    printf(R"("abilities":[)");
    for (int i = 0; i < 10; ++i) {
        const char *ability_name = get_ability_name(majormud_class.ability_ids[i]);
        if (ability_name != nullptr) {
            printf(R"({"%s":%d})", ability_name, majormud_class.ability_values[i]);
        } else {
            printf(R"({"%d":%d})", majormud_class.ability_ids[i], majormud_class.ability_values[i]);
        }

        if (i < 9) printf(",");
    }
    printf("]");
    printf("}\n");
    
    return 0;
}

int transform_spell(uint8_t* bytes, size_t actual_size) {
    size_t size = get_lowest_size(actual_size, sizeof(MajorMUDSpell));

    MajorMUDSpell majormud_spell = {};
    memcpy(&majormud_spell, bytes, size);

    printf("{");
    printf(R"("id":%d,)", majormud_spell.id);
    printf(R"("name":"%s",)", majormud_spell.name);
    printf(R"("short_name":"%s",)", majormud_spell.short_name);
    printf(R"("description":)");
    if (*majormud_spell.description_a && *majormud_spell.description_b) {
        printf(R"("%s %s")", majormud_spell.description_a, majormud_spell.description_b);
    }
    else if (*majormud_spell.description_a) {
        printf(R"("%s")", majormud_spell.description_a);
    }
    else if (*majormud_spell.description_b) {
        printf(R"("%s")", majormud_spell.description_b);
    }
    else {
        printf(R"("",)");
    }
    printf(R"("level":%d,)", majormud_spell.level);
    printf(R"("energy":%d,)", majormud_spell.energy);
    printf(R"("mana":%d,)", majormud_spell.mana);
    printf(R"("difficulty":%d,)", majormud_spell.difficulty);
    printf(R"("level_cap":%d)", majormud_spell.level_cap);
    printf(R"("min":%d,)", majormud_spell.min);
    printf(R"("max":%d,)", majormud_spell.max);
    printf(R"("target_type_id":%d,)", majormud_spell.target_type_id);
    printf(R"("attack_type":%d,)", majormud_spell.attack_type);
    printf(R"("first_magery_type_id":%d,)", majormud_spell.first_magery_type_id);
    printf(R"("cast_a_message_id":%d,)", majormud_spell.cast_a_message_id);
    printf(R"("cast_b_message_id":%d,)", majormud_spell.cast_b_message_id);
    printf(R"("abilities":[)");
    for (int i = 0; i < 10; ++i) {
        printf("{");
        printf(R"("id":%d,)", majormud_spell.ability_ids[i]);
        const char* ability_name = get_ability_name(majormud_spell.ability_ids[i]);
        if (ability_name != nullptr) {
            printf(R"("name":"%s",)", ability_name);
        } else {
            printf(R"("name":null,)");
        }
        printf(R"("value":%d)", majormud_spell.ability_values[i]);
        printf("}");

        if (i < 9) printf(",");
    }
    printf("]");
    printf("}\n");

    return 0;
}

int transform_item(uint8_t* bytes, size_t actual_size) {
    size_t size = get_lowest_size(actual_size, sizeof(MajorMUDItem));

    MajorMUDItem majormud_item = {};
    memcpy(&majormud_item, bytes, size);

    printf("{");
    printf(R"("id":%d,)", majormud_item.id);
    printf(R"("name":"%s",)", majormud_item.name);
    printf(R"("description":")");
    if (*majormud_item.description_1) {
        printf("%s", majormud_item.description_1);
    }
    if (*majormud_item.description_2) {
        printf(" %s", majormud_item.description_2);
    }
    if (*majormud_item.description_3) {
        printf(" %s", majormud_item.description_3);
    }
    if (*majormud_item.description_4) {
        printf(" %s", majormud_item.description_4);
    }
    if (*majormud_item.description_5) {
        printf(" %s", majormud_item.description_5);
    }
    if (*majormud_item.description_6) {
        printf(" %s", majormud_item.description_6);
    }
    if (*majormud_item.description_7) {
        printf(" %s", majormud_item.description_7);
    }
    if (*majormud_item.description_8) {
        printf(" %s", majormud_item.description_8);
    }
    if (*majormud_item.description_9) {
        printf(" %s", majormud_item.description_9);
    }
    printf(R"(",)");
    printf(R"("limit":%d,)", majormud_item.game_limit);
    printf(R"("weight":%d,)", majormud_item.weight);
    printf(R"("type":%d,)", majormud_item.type);
    printf(R"("uses":%d,)", majormud_item.uses);
    printf(R"("retain_after_uses":%d,)", majormud_item.retain_after_uses);
    printf(R"("cost":%d,)", majormud_item.cost);
    printf(R"("cost_type":%d,)", majormud_item.cost_type);
    printf(R"("min_hit":%d,)", majormud_item.min_hit);
    printf(R"("max_hit":%d,)", majormud_item.max_hit);
    printf(R"("hit_message":%d,)", majormud_item.hit_message);
    printf(R"("miss_message":%d,)", majormud_item.miss_message);
    printf(R"("speed":%d,)", majormud_item.speed);
    printf(R"("accuracy":%d,)", majormud_item.accuracy);
    printf(R"("required_strength":%d,)", majormud_item.required_strength);
    printf(R"("weapon":%d,)", majormud_item.weapon);
    printf(R"("armour":%d,)", majormud_item.armour);
    printf(R"("armour_class":%d,)", majormud_item.armour_class);
    printf(R"("damage_reduction":%d,)", majormud_item.damage_reduction);
    printf(R"("open_copper":%d,)", majormud_item.open_copper);
    printf(R"("open_silver":%d,)", majormud_item.open_silver);
    printf(R"("open_gold":%d,)", majormud_item.open_gold);
    printf(R"("open_platinum":%d,)", majormud_item.open_platinum);
    printf(R"("open_runic":%d,)", majormud_item.open_runic);
    printf(R"("worn_on":%d,)", majormud_item.worn_on);
    printf(R"("gettable":%d,)", majormud_item.gettable);
    printf(R"("not_droppable":%d,)", majormud_item.not_droppable);
    printf(R"("robbable":%d,)", majormud_item.robbable);
    printf(R"("destroy_on_death":%d,)", majormud_item.destroy_on_death);
    printf(R"("distruct_message":%d,)", majormud_item.distruct_message);
    printf(R"("read_tb":%d,)", majormud_item.read_tb);
    printf(R"("negate":[)");
    for (uint16_t n : majormud_item.negate) {
        printf("%hu,", n);
    }
    printf("],");
    printf(R"("races":[)");
    for (uint16_t race : majormud_item.races) {
        printf("%hu,", race);
    }
    printf("],");
    printf(R"("classes":[)");
    for (uint16_t race : majormud_item.classes) {
        printf("%hu,", race);
    }
    printf("],");
    printf(R"("abilities":[)");
    for (int i = 0; i < 10; ++i) {
        printf("{");
        printf(R"("id":%d,)", majormud_item.ability_ids[i]);
        const char* ability_name = get_ability_name(majormud_item.ability_ids[i]);
        if (ability_name != nullptr) {
            printf(R"("name":"%s",)", ability_name);
        } else {
            printf(R"("name":null,)");
        }
        printf(R"("value":%d)", majormud_item.ability_values[i]);
        printf("}");

        if (i < 9) printf(",");
    }
    printf("]");
    printf("}\n");

    return 0;
}

int transform_action(uint8_t* bytes, size_t actual_size) {
    size_t size = get_lowest_size(actual_size, sizeof(MajorMUDAction));

    MajorMUDAction majormud_action = {};
    memcpy(&majormud_action, bytes, size);

    printf("{");
    printf(R"("name":"%s",)", majormud_action.name);
    printf(R"("single_to_user":"%s",)", majormud_action.single_to_user);
    printf(R"("single_to_room":"%s",)", majormud_action.single_to_room);
    printf(R"("user_to_user":"%s",)", majormud_action.user_to_user);
    printf(R"("user_to_other_user":"%s",)", majormud_action.user_to_other_user);
    printf(R"("user_to_room":"%s",)", majormud_action.user_to_room);
    printf(R"("monster_to_user":"%s",)", majormud_action.monster_to_user);
    printf(R"("monster_to_room":"%s",)", majormud_action.monster_to_room);
    printf(R"("inventory_to_user":"%s",)", majormud_action.inventory_to_user);
    printf(R"("inventory_to_room":"%s",)", majormud_action.inventory_to_room);
    printf(R"("floor_item_to_user":"%s",)", majormud_action.floor_item_to_user);
    printf(R"("floor_item_to_room":"%s")", majormud_action.floor_item_to_room);
    printf("}\n");

    return 0;
}

int transform_shop(uint8_t* bytes, size_t actual_size) {
    size_t size = get_lowest_size(actual_size, sizeof(MajorMUDShop));

    MajorMUDShop majormud_shop = {};
    memcpy(&majormud_shop, bytes, size);

    printf("{");
    printf(R"("id":%d,)", majormud_shop.id);
    printf(R"("name":"%s",)", majormud_shop.name);
    printf(R"("description_1":"%s",)", majormud_shop.description_1);
    printf(R"("description_2":"%s",)", majormud_shop.description_2);
    printf(R"("description_3":"%s",)", majormud_shop.description_3);
    printf(R"("type":%d,)", majormud_shop.type);
    printf(R"("min_level":%d,)", majormud_shop.min_level);
    printf(R"("max_level":%d,)", majormud_shop.max_level);
    printf(R"("markup":%d,)", majormud_shop.markup);
    printf(R"("class_limit":%d,)", majormud_shop.class_limit);
    printf(R"("items":[)");
    for (int i = 0; i < 20; ++i) {
        printf("{");
        printf(R"("id":%d,)", majormud_shop.item_ids[i]);
        printf(R"("max":%d,)", majormud_shop.item_max[i]);
        printf(R"("current":%d,)", majormud_shop.item_current[i]);
        printf(R"("regen_time":%d,)", majormud_shop.item_regen_time[i]);
        printf(R"("regen_quantity":%d,)", majormud_shop.item_regen_quantity[i]);
        printf(R"("regen_percentage":%d)", majormud_shop.item_regen_percentage[i]);
        printf("}");

        if (i < 19) printf(",");
    }
    printf("]");
    printf("}\n");

    return 0;
}

int transform_textblock(uint8_t* bytes, size_t actual_size) {
    size_t size = get_lowest_size(actual_size, sizeof(MajorMUDTextblock));

    MajorMUDTextblock majormud_textblock = {};
    memcpy(&majormud_textblock, bytes, size);

    printf("{");
    printf("}\n");

    return 0;
}

int transform_room(uint8_t* bytes, size_t actual_size) {
    size_t size = get_lowest_size(actual_size, sizeof(MajorMUDRoom));

    MajorMUDRoom majormud_room = {};
    memcpy(&majormud_room, bytes, size);

    printf("{");
    printf(R"("map_id":%d,)", majormud_room.map_id);
    printf(R"("room_id":%d,)", majormud_room.room_id);
    printf(R"("name":"%s",)", majormud_room.name);
    printf(R"("description":")");
    if (*majormud_room.description_1) {
        printf("%s", majormud_room.description_1);
    }
    if (*majormud_room.description_2) {
        printf(" %s", majormud_room.description_2);
    }
    if (*majormud_room.description_3) {
        printf(" %s", majormud_room.description_3);
    }
    if (*majormud_room.description_4) {
        printf(" %s", majormud_room.description_4);
    }
    if (*majormud_room.description_5) {
        printf(" %s", majormud_room.description_5);
    }
    if (*majormud_room.description_6) {
        printf(" %s", majormud_room.description_6);
    }
    if (*majormud_room.description_7) {
        printf(" %s", majormud_room.description_7);
    }
    printf(R"(",)");
    printf("}\n");

    return 0;
}

int transform_npc(uint8_t* bytes, size_t actual_size) {
    size_t size = get_lowest_size(actual_size, sizeof(MajorMUDNPC));

    MajorMUDNPC majormud_npc = {};
    memcpy(&majormud_npc, bytes, size);

    printf("{");
    printf(R"("room_id":%d,)", majormud_npc.id);
    printf(R"("name":"%s",)", majormud_npc.name);
    printf(R"("group":%d,)", majormud_npc.group);
    printf(R"("description":")");
    if (*majormud_npc.description_1) {
        printf("%s", majormud_npc.description_1);
    }
    if (*majormud_npc.description_2) {
        printf(" %s", majormud_npc.description_2);
    }
    if (*majormud_npc.description_3) {
        printf(" %s", majormud_npc.description_3);
    }
    if (*majormud_npc.description_4) {
        printf(" %s", majormud_npc.description_4);
    }
    printf(R"(",)");
    printf(R"("exp_multiplier":%d,)", majormud_npc.exp_multiplier);
    printf(R"("index":%d,)", majormud_npc.index);
    printf(R"("weapon_id":%d,)", majormud_npc.weapon_id);
    printf(R"("damage_reduction":%d,)", majormud_npc.damage_reduction);
    printf(R"("armour_class":%d,)", majormud_npc.armour_class);
    printf(R"("follow_percentage":%d,)", majormud_npc.follow_percentage);
    printf(R"("magic_resistance":%d,)", majormud_npc.magic_resistance);
    printf(R"("backstab_resistance":%d,)", majormud_npc.backstab_resistance);
    printf(R"("experience":%d,)", majormud_npc.experience);
    printf(R"("hitpoints":%d,)", majormud_npc.hitpoints);
    printf(R"("hitpoint_regen":%d,)", majormud_npc.hitpoint_regen);
    printf(R"("energy":%d,)", majormud_npc.energy);
    printf(R"("game_limit":%d,)", majormud_npc.game_limit);
    printf(R"("active":%d,)", majormud_npc.active);
    printf(R"("type":%d,)", majormud_npc.type);
    printf(R"("is_undead":%d,)", majormud_npc.is_undead);
    printf(R"("alignment":%d,)", majormud_npc.alignment);
    printf(R"("regen_time":%d,)", majormud_npc.regen_time);
    printf(R"("date_killed":%d,)", majormud_npc.date_killed);
    printf(R"("time_killed":%d,)", majormud_npc.time_killed);
    printf(R"("move_message":%d,)", majormud_npc.move_message);
    printf(R"("death_message":%d,)", majormud_npc.death_message);
    printf(R"("runic":%d,)", majormud_npc.runic);
    printf(R"("platinum":%d,)", majormud_npc.platinum);
    printf(R"("gold":%d,)", majormud_npc.gold);
    printf(R"("silver":%d,)", majormud_npc.silver);
    printf(R"("copper":%d,)", majormud_npc.copper);
    printf(R"("charm_level":%d,)", majormud_npc.charm_level);
    printf(R"("charm_resistance":%d,)", majormud_npc.charm_resistance);
    printf(R"("greet_text":%d,)", majormud_npc.greet_text);
    printf(R"("description_text":%d,)", majormud_npc.description_text);
    printf(R"("talk_text":%d,)", majormud_npc.talk_text);
    printf(R"("create_spell_id":%d,)", majormud_npc.create_spell_id);
    printf(R"("death_spell_id":%d,)", majormud_npc.death_spell_id);
    printf(R"("gender":%d,)", majormud_npc.gender);
    printf(R"("items":[)");
    for (int i = 0; i < 10; ++i) {
        printf("{");
        printf(R"("id":%d,)", majormud_npc.item_ids[i]);
        printf(R"("uses":%d,)", majormud_npc.item_uses[i]);
        printf(R"("drop_percentage":%d)", majormud_npc.item_drop_percentage[i]);
        printf("}");
        if (i < 9) printf(",");
    }
    printf("],");
    printf(R"("attacks":[)");
    for (int i = 0; i < 5; ++i) {
        printf("{");
        printf(R"("type":%d,)", majormud_npc.attack_type[i]);
        printf(R"("energy":%d,)", majormud_npc.attack_energy[i]);
        printf(R"("percentage":%d,)", majormud_npc.attack_percentage[i]);
        printf(R"("hit_message_id":%d,)", majormud_npc.attack_hit_message_id[i]);
        printf(R"("miss_message_id":%d,)", majormud_npc.attack_miss_message_id[i]);
        printf(R"("dodge_message_id":%d,)", majormud_npc.attack_dodge_message_id[i]);
        printf(R"("hit_spell":%d,)", majormud_npc.attack_hit_spell[i]);
        printf(R"("accuracy_spell":%d,)", majormud_npc.attack_accuracy[i]);
        printf(R"("attack_min_or_spell_percentage":%d,)", majormud_npc.attack_min_or_spell_percentage[i]);
        printf(R"("attack_max_or_spell_attack_level":%d)", majormud_npc.attack_max_or_spell_attack_level[i]);
        printf("}");
        if (i < 4) printf(",");
    }
    printf("],");
    printf(R"("spells":[)");
    for (int i = 0; i < 5; ++i) {
        printf("{");
        printf(R"("id":%d,)", majormud_npc.spell_id[i]);
        printf(R"("cast_per":%d,)", majormud_npc.spell_cast_per[i]);
        printf(R"("cast_level":%d)", majormud_npc.spell_cast_level[i]);
        printf("}");
        if (i < 4) printf(",");
    }
    printf("],");
    printf(R"("abilities":[)");
    for (int i = 0; i < 10; ++i) {
        const char *ability_name = get_ability_name(majormud_npc.ability_ids[i]);
        if (ability_name != nullptr) {
            printf(R"({"%s":%d})", ability_name, majormud_npc.ability_values[i]);
        } else {
            printf(R"({"%d":%d})", majormud_npc.ability_ids[i], majormud_npc.ability_values[i]);
        }

        if (i < 9) printf(",");
    }
    printf("]");
    printf("}\n");

    return 0;
}

int main(int argc, char* argv[]) {

    if (argc == 1) {
        print_usage();
        return 0;
    }

    if (argc != 3) {
        print_usage();
        fprintf(stderr, "error: invalid number of arguments\n");
        return 1;
    }

    Transform transform;
    if (strcasecmp(argv[1], "--race") == 0) {
        transform = &transform_race;
    }
    else if (strcasecmp(argv[1], "--class") == 0) {
        transform = &transform_class;
    }
    else if (strcasecmp(argv[1], "--spell") == 0) {
        transform = &transform_spell;
    }
    else if (strcasecmp(argv[1], "--item") == 0) {
        transform = &transform_item;
    }
    else if (strcasecmp(argv[1], "--action") == 0) {
        transform = &transform_action;
    }
    else if (strcasecmp(argv[1], "--shop") == 0) {
        transform = &transform_shop;
    }
    else if (strcasecmp(argv[1], "--textblock") == 0) {
        transform = &transform_textblock;
    }
    else if (strcasecmp(argv[1], "--room") == 0) {
        transform = &transform_room;
    }
    else if (strcasecmp(argv[1], "--npc") == 0) {
        transform = &transform_npc;
    }
    else {
        print_usage();
        fprintf(stderr, "error: unknown type: %s\n", argv[1]);
        return 1;
    }

    FILE* file = fopen(argv[2], "rb");
    if (!file) {
        fprintf(stderr, "file not found\n");
        return 1;
    }

    struct BtrieveFile btrieve_file = {};
    if(load(file, &btrieve_file)) {
        fprintf(stderr, "unable to load Btrieve file\n");
        return 1;
    }

    fclose(file);

    size_t size_of_all_records = btrieve_file.record_count * btrieve_file.physical_length;
    void* records = malloc(size_of_all_records);
    if(get_records(&btrieve_file, records)) {
        fprintf(stderr, "unable to get records from Btrieve file\n");
        return 1;
    }

    for (int record_index = 0; record_index < btrieve_file.record_count; ++record_index) {
        size_t record_offset = btrieve_file.physical_length * record_index;
        void* record_pointer = (void*)((size_t) records + record_offset);
        if (transform((unsigned char*)record_pointer, btrieve_file.physical_length)) {
            fprintf(stderr, "unable to transform data\n");
            return 1;
        }
    }

    return 0;
}
