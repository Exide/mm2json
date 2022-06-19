# mm2json
A command-line program for extracting MajorMUD data from the original Btrieve files.

# Use

```shell
$ mm2json
Usage: mm2json --[race|class|spell|item|action|shop|textblock|room|npc] FILE
A command-line program for extracting MajorMUD data from the original Btrieve files.
```

For example, let's look at an un-edited MajorMUD 1.11p race file.
```shell
$ mm2json --race WCCRACE2.DAT
{"id":10,"name":"Half-Ogre","exp_modifier":1.30,"hp_bonus":1,"initial_cp":100,"intellect":{"min":20,"max":60},"willpower":{"min":25,"max":70},"strength":{"min":70,"max":150},"health":{"min":60,"max":150},"agility":{"min":20,"max":60},"charm":{"min":25,"max":60},"abilities":[{"36":15},{"7":20},{"0":100},{"0":3},{"0":0},{"0":0},{"0":0},{"0":0},{"0":0},{"0":0}]}
{"id":1,"name":"Human","exp_modifier":1.00,"hp_bonus":0,"initial_cp":100,"intellect":{"min":40,"max":100},"willpower":{"min":40,"max":100},"strength":{"min":40,"max":100},"health":{"min":40,"max":100},"agility":{"min":40,"max":100},"charm":{"min":40,"max":100},"abilities":[{"0":0},{"0":0},{"0":0},{"0":0},{"0":0},{"0":0},{"0":0},{"0":0},{"0":0},{"0":0}]}
{"id":2,"name":"Dwarf","exp_modifier":1.30,"hp_bonus":0,"initial_cp":100,"intellect":{"min":30,"max":90},"willpower":{"min":50,"max":120},"strength":{"min":50,"max":110},"health":{"min":50,"max":120},"agility":{"min":30,"max":90},"charm":{"min":30,"max":85},"abilities":[{"36":10},{"13":75},{"96":20},{"0":-20},{"0":2},{"0":0},{"0":0},{"0":0},{"0":0},{"0":0}]}
{"id":3,"name":"Gnome","exp_modifier":1.20,"hp_bonus":0,"initial_cp":100,"intellect":{"min":45,"max":110},"willpower":{"min":40,"max":100},"strength":{"min":35,"max":90},"health":{"min":40,"max":100},"agility":{"min":45,"max":110},"charm":{"min":35,"max":90},"abilities":[{"36":5},{"13":65},{"Picklocks":0},{"0":10},{"0":0},{"0":0},{"0":0},{"0":0},{"0":0},{"0":0}]}
{"id":4,"name":"Halfling","exp_modifier":1.25,"hp_bonus":-1,"initial_cp":100,"intellect":{"min":30,"max":90},"willpower":{"min":40,"max":100},"strength":{"min":20,"max":60},"health":{"min":40,"max":100},"agility":{"min":60,"max":150},"charm":{"min":40,"max":100},"abilities":[{"102":0},{"Dodge":10},{"0":0},{"0":0},{"0":0},{"0":0},{"0":0},{"0":0},{"0":0},{"0":0}]}
{"id":5,"name":"Elf","exp_modifier":1.45,"hp_bonus":0,"initial_cp":100,"intellect":{"min":50,"max":120},"willpower":{"min":40,"max":100},"strength":{"min":35,"max":90},"health":{"min":30,"max":80},"agility":{"min":50,"max":120},"charm":{"min":50,"max":120},"abilities":[{"13":50},{"102":0},{"MaxMana":10},{"0":0},{"0":0},{"0":0},{"0":0},{"0":0},{"0":0},{"0":0}]}
{"id":6,"name":"Half-Elf","exp_modifier":1.15,"hp_bonus":0,"initial_cp":100,"intellect":{"min":45,"max":110},"willpower":{"min":40,"max":100},"strength":{"min":40,"max":90},"health":{"min":30,"max":100},"agility":{"min":45,"max":110},"charm":{"min":50,"max":110},"abilities":[{"MaxMana":10},{"13":25},{"0":0},{"0":0},{"0":0},{"0":0},{"0":0},{"0":0},{"0":0},{"0":0}]}
{"id":7,"name":"Dark-Elf","exp_modifier":1.45,"hp_bonus":0,"initial_cp":100,"intellect":{"min":50,"max":120},"willpower":{"min":30,"max":100},"strength":{"min":40,"max":90},"health":{"min":30,"max":90},"agility":{"min":50,"max":120},"charm":{"min":40,"max":110},"abilities":[{"13":80},{"102":0},{"Crits":1},{"106":3},{"0":0},{"0":0},{"0":0},{"0":0},{"0":0},{"0":0}]}
{"id":8,"name":"Half-Orc","exp_modifier":1.00,"hp_bonus":0,"initial_cp":100,"intellect":{"min":30,"max":90},"willpower":{"min":30,"max":95},"strength":{"min":45,"max":110},"health":{"min":50,"max":120},"agility":{"min":40,"max":100},"charm":{"min":30,"max":80},"abilities":[{"0":0},{"0":0},{"0":0},{"0":0},{"0":0},{"0":0},{"0":0},{"0":0},{"0":0},{"0":0}]}
{"id":9,"name":"Goblin","exp_modifier":1.35,"hp_bonus":0,"initial_cp":100,"intellect":{"min":45,"max":115},"willpower":{"min":40,"max":100},"strength":{"min":30,"max":70},"health":{"min":40,"max":100},"agility":{"min":55,"max":125},"charm":{"min":40,"max":100},"abilities":[{"13":65},{"102":0},{"0":0},{"0":0},{"0":0},{"0":0},{"0":0},{"0":0},{"0":0},{"0":0}]}
{"id":11,"name":"Kang","exp_modifier":1.35,"hp_bonus":0,"initial_cp":100,"intellect":{"min":30,"max":90},"willpower":{"min":45,"max":110},"strength":{"min":55,"max":120},"health":{"min":50,"max":110},"agility":{"min":30,"max":90},"charm":{"min":30,"max":85},"abilities":[{"21":100},{"7":10},{"ArmourClass":5},{"0":0},{"0":0},{"0":0},{"0":0},{"0":0},{"0":0},{"0":0}]}
{"id":12,"name":"Nekojin","exp_modifier":1.50,"hp_bonus":0,"initial_cp":100,"intellect":{"min":40,"max":100},"willpower":{"min":30,"max":90},"strength":{"min":40,"max":100},"health":{"min":30,"max":80},"agility":{"min":60,"max":130},"charm":{"min":50,"max":110},"abilities":[{"102":0},{"13":50},{"Tracking":0},{"5":10},{"3":-10},{"0":0},{"0":0},{"0":0},{"0":0},{"0":0}]}
{"id":13,"name":"Gaunt One","exp_modifier":1.50,"hp_bonus":0,"initial_cp":100,"intellect":{"min":60,"max":140},"willpower":{"min":50,"max":100},"strength":{"min":40,"max":100},"health":{"min":30,"max":70},"agility":{"min":50,"max":110},"charm":{"min":30,"max":80},"abilities":[{"13":200},{"77":10},{"0":10},{"0":0},{"0":0},{"0":0},{"0":0},{"0":0},{"0":0},{"0":0}]}
```

# Build

Send [main.cpp](src/main.cpp) to your favorite C++11 compiler.
```shell
$ g++ -std=c++11 -Wall -Werrors -o mm2json src/main.cpp
$ ./mm2json
Usage: mm2json --[race|class|spell|item|action|shop|textblock|room|npc] FILE
A command-line program for extracting MajorMUD data from the original Btrieve files.
```

Or you could use the provided [CMakeLists.txt](CMakeLists.txt) file.
```shell
$ cmake -B build
$ cmake --build build --target mm2json
$ build/mm2json
Usage: mm2json --[race|class|spell|item|action|shop|textblock|room|npc] FILE
A command-line program for extracting MajorMUD data from the original Btrieve files.
```
