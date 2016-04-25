# McMorran_CSCI2270_FinalProject
ASCII Roguelike

************DESCRIPTION************
In this project I will be attempting to create a simple ASCII Roguelike game. A roguelike game generally "a subgenre of role-playing video games characterized by a dungeon crawl through procedureally generated game levels, turn-based gameplay, tile-based graphics, and permanent death of the player-character," (Wikipedia, Roguelike, https://en.wikipedia.org/wiki/Roguelike). While my game will attempt to incorporate as many of these characteristics as possible, it will likely be missing several key attributes. The game will probably be focused on an objective rather than role-playing for the sake of coding, but will include other elements like a dungeon crawl, permanent death, and simple graphics. I will be using levels based purely on ASCII text to create walls, objects, and enemies. The code should include classes for the following objects: The Game System, Each Level, Enemies/Monsters, Playable Character. Several structs will likely be used out of necessity, but a Linked List is intended to be used as a way of storing an inventory.

************GETTING STARTED************
For this code to work, you will need to download and install the <ncurses.h> library. In order to successfully get this working, be sure that you are using the VM provided by the department of computer science. The following are the steps to take to get this set up:

1.Open a web browser and navigate to:
	ftp://ftp.gnu.org/gnu/ncurses/
  Here you will find a list of versions and various files. Click the download link for "ncurses-6.0.tar.gz" (3.0 MB, 8/8/15).

2.After the file has downloaded you will notice it is archived. Navigate to the folder in your file browser or in a terminal window and extract the contents. It doesn't matter the location. If you do this in the terminal, use commands:
	tar zxvf ncurses-6.0.tar.gz

3.Regardless of how you extracted the contents of the folder, you will now need to open a terminal window and cd to the directory:
	if in you downloads folder: cd ./Downloads/ncurses-6.0

4.Next you need to configure the library according to your environment. Do this by running the configure executable with the following command:
	./configure
  After it is configured, you should see the following message:
** Configuration summary for NCURSES 6.0 20150808:

       extended funcs: yes
       xterm terminfo: xterm-new

        bin directory: /usr/bin
        lib directory: /usr/lib
    include directory: /usr/include
        man directory: /usr/share/man
   terminfo directory: /usr/share/terminfo

5.To continue, you need to make it. so type:
	make
  This will run for a while, just let it do its thing.

6.Nearly there. next type the following command:
	sudo make install

7.Now Code::Blocks will be able to find <ncurses.h> and the code should work. If there are issues, check to see if the header file was found by retyping "#include <n" to see if "<ncurses.h> is an autocomplete option. If not, the library was not properly installed. If it is working, we can move on.


************PLAYING THE GAME************


************ADDITIONAL NOTES************

ERROR CODE LIST
0	|	No Error
-1	|	x or y coordinate not set
101	|	Inventory Full
102	|	Item not found
201	|	File not found