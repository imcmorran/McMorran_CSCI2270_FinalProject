# McMorran_CSCI2270_FinalProject
ASCII Roguelike
Author: Ian McMorran
Partners: NONE

*IMPORTANT*
if you contribute to the code, readme, or other related files, please add your name to the contibuters list in the "Additional Notes" section. Also be sure to read the entire README as all the information is important. If you wish to add levels, look in the ABOUT.txt file for info on how those files work. Thanks!

::AFTER SUBMISSION EDIT::
In my game rules section I forgot to mention how to use items such as "Health". With it as the active item, in the inventory, press "f" to use it.


***********************************
************DESCRIPTION************
***********************************

In this project I will be attempting to create a simple ASCII Roguelike game. A roguelike game generally "a subgenre of role-playing video games characterized by a dungeon crawl through procedureally generated game levels, turn-based gameplay, tile-based graphics, and permanent death of the player-character," (Wikipedia, Roguelike, https://en.wikipedia.org/wiki/Roguelike). While my game will attempt to incorporate as many of these characteristics as possible, it will likely be missing several key attributes. The game will probably be focused on an objective rather than role-playing for the sake of coding, but will include other elements like a dungeon crawl, permanent death, and simple graphics. I will be using levels based purely on ASCII text to create walls, objects, and enemies. The code should include classes for the following objects: The Game System, Each Level, Enemies/Monsters, Playable Character. Several structs will likely be used out of necessity, but a Linked List is intended to be used as a way of storing an inventory.

UPDATE:
After hitting several roadblocks, and with little time, the game has been simplified further. Here are the details of the final implementation:
1.There are two classes:
	World.h
	Character.h
  These classes contain data for the playing field, the character's stats, and an inventory, as well as methods for interacting with the data.

2.Your character has the following elements:
	Name
	Health
	Inventory

3.Each level contains the following symbols:
	#	|	Walls
	.	|	Playable Area
	8	|	Hole
	i	|	item
	%	|	Key (special item)
	|	|	Door
	_	|	Door
	m	|	Small Monster
	M	|	Large Monster
	&	|	Playable Character
	X	|	Objective Location

***************************************
************GETTING STARTED************
***************************************

You've likely already downloaded a copy of all the files to your harddrive, but if not, do so.

I'd recommend opening the project file in Code::Blocks on the VM provided by the CompSci Department:
	/home/user/Documents/McMorran_CSCI2270_FinalProject/McMorran_CSCI2270_FinalProject/McMorran_CSCI2270_FinalProject.cbp

With the files open, and the project active, pressing F9 should build and run the program. If this does not work, navigate to the following in a terminal window and run "McMorran_CSCI2270_FinalProject:
	McMorran_CSCI2270_FinalProject/McMorran_CSCI2270_FinalProject/bin/Debug
(Known Bug: Sometimes when running from terminal, a segmentation fualt occurs. This has never occured when running from Code::Blocks so it is recommended to use the software)

****************************************
************PLAYING THE GAME************
****************************************

RULES:
The main objective here is to make it to the end of the available levels without dying. If you die, you must start over.

Each individual level is completed by reaching the X location.

You can move around using the W, A, S, D keys. (Note: each keystroke must be followed by ENTER, ensure caps-lock is off)

In your quest to get to the X, you may encounter obstacles. There may be walls blocking your path (#), or holes to fall in (8). If you bump into a wall by accident, you will get scratched and your health will decrease by 10%. Falling into a hole is an immediate death.

Doors may block your path. The only way to open doors (| or _) is with the proper key. A key (%) is a type of item (i) that can be collected by walking over it. When you walk over any item and pick it up automatically, it will be added to your inventory which is displayed right below the map. Here is an example inventory:

	Inventory: | Key | [Sword] | Health | Key |

You may notice that there are two keys in this inventory. Keys are indistingushable on appearance, but only one key will unlock each door. You must have the correct one to open a door. You may also notice that one item, the Sword, is boxed [ ]. This is the active item in your inventory. The active item can be switched by entering either e (right) or q (left). Pressing q twice on the inventory above will result in the following inventory:
	Inventory: | Key | Sword | [Health] | Key |
		then...
	Inventory: | Key | Sword | Health | [Key] |

To test a key on a door, make it active and stand next to the door. If the key fits, the door will dissapear and leave a hole to move through.

Watch out for monsters! smaller monsters (m) will only deal 50% damage, but large ones will kill you without a weapon active.

****************************************
************ADDITIONAL NOTES************
****************************************

BUGS AND PROBLEMS:
-In order to enter a keystroke, you must press enter. This allows you to string together commands, but does not allow for fluid gameplay. One possible contribution could be developing a method for capturing keystrokes without pressing enter.
-There are currently only a few levels created, so feel free to add more. (Read about level files in ABOUT.txt)

CONTRIBUTERS: (Name, Role [author, contributor, reviewer, etc])
	Ian McMorran		|	Author
	...add name here	|	Contributor
