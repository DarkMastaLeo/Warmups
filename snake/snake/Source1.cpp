//#include <iostream>
//#include <string>
//#include <time.h>
//#include <Windows.h>
//using namespace std;
//
//void convert(string& input);
//void walking();
//void pause(int dur);
//
//int main() {
//
//	int rooms = 1;
//	string input;
//	string inventory[7] = { "Flashlight","empty","empty","empty","empty","empty","empty" };
//	while (input != "QUIT") {
//		switch (rooms) {
//		case 0://reset
//			inventory[0] = "Flashlight";
//			inventory[1] = "empty";
//			inventory[2] = "empty";
//			inventory[3] = "empty";
//			inventory[4] = "empty";
//			inventory[5] = "empty";
//			inventory[6] = "empty";
//			inventory[7] = "empty";
//			cin >> input;
//			rooms = 1;
//		case 1://starting room
//			cout << "The Missing Case..." << endl;
//			PlaySound(TEXT("intro.wav"), NULL, SND_FILENAME);
//			pause(2);
//			PlaySound(TEXT("screamhorror.wav"), NULL, SND_FILENAME);
//			pause(2);
//			walking();
//			cout << "____________________________________________________" << endl;
//			cout << "You wake up from a scream, laying on the floor of the basement." << endl;
//			cout << "You turn on your flashlight and found a room ahead." << endl;
//			cout << "You can head NORTH" << endl;
//			cin >> input;
//			convert(input);
//			cout << endl;
//
//			if (input.compare("NORTH") == 0 || input.compare("N") == 0)
//				rooms = 2;
//			else if (input.compare("INV") == 0 || input.compare("INVENTORY") == 0) {
//				for (int i = 0; i < 6; i++) {
//					cout << "____________________________________________________" << endl;
//					cout << inventory[i] << endl;
//				}
//				cin >> input;
//				convert(input);
//			}
//			if (input.compare("NORTH") == 0 || input.compare("N") == 0)
//				rooms = 2;
//
//			else
//				cout << "invalid input" << endl;
//			break;
//		case 2://empty room
//			walking();
//			cout << "____________________________________________________" << endl;
//			cout << "you find yourself in an empty room" << endl;
//			cout << "You can head EAST, SOUTH, AND WEST" << endl;
//			cin >> input;
//			convert(input);
//			cout << endl;
//			if (input.compare("EAST") == 0 || input.compare("E") == 0)
//				rooms = 5;
//			else if (input.compare("SOUTH") == 0 || input.compare("S") == 0)
//				rooms = 29;
//			else if (input.compare("WEST") == 0 || input.compare("W") == 0)
//				if (inventory[1] == "Roses")
//					rooms = 4;
//				else
//					rooms = 3;
//			else if (input.compare("INV") == 0 || input.compare("INVENTORY") == 0) {
//				for (int i = 0; i < 6; i++) {
//					cout << "____________________________________________________" << endl;
//					cout << inventory[i] << endl;
//				}
//				cin >> input;
//				convert(input);
//			}
//			if (input.compare("EAST") == 0 || input.compare("E") == 0)
//				rooms = 5;
//			else if (input.compare("SOUTH") == 0 || input.compare("S") == 0)
//				rooms = 29;
//			else if (input.compare("WEST") == 0 || input.compare("W") == 0)
//				if (inventory[1] == "Roses")
//					rooms = 4;
//				else
//					rooms = 3;
//			else
//				cout << "invalid input" << endl;
//			break;
//		case 3://gravestone with roses
//			walking();
//			cout << "____________________________________________________" << endl;
//			cout << "You have entered a dark room with a gravestone of a friend Kohana." << endl;
//			cout << "There are roses sitting on the gravestone." << endl;
//			cout << "You can take the roses by typing ROSES or travel EAST." << endl;
//			cin >> input;
//			convert(input);
//			cout << endl;
//			if (input.compare("EAST") == 0 || input.compare("E") == 0)
//				rooms = 2;
//			else if (input.compare("ROSES") == 0)
//				rooms = 4;
//			else if (input.compare("INV") == 0 || input.compare("INVENTORY") == 0) {
//				for (int i = 0; i < 6; i++) {
//					cout << "____________________________________________________" << endl;
//					cout << inventory[i] << endl;
//				}
//				cin >> input;
//				convert(input);
//			}
//			if (input.compare("EAST") == 0 || input.compare("E") == 0)
//				rooms = 2;
//			else if (input.compare("ROSES") == 0)
//				rooms = 4;
//			else
//				cout << "invalid input" << endl;
//			break;
//		case 4://just gravestone
//			walking();
//			cout << "____________________________________________________" << endl;
//			cout << "The Gravestone stands alone..." << endl;
//			inventory[1] = "Roses";
//			cout << "You can travel EAST" << endl;
//			cin >> input;
//			convert(input);
//			if (input.compare("EAST") == 0 || input.compare("E") == 0)
//				rooms = 2;
//			else if (input.compare("INV") == 0 || input.compare("INVENTORY") == 0) {
//				for (int i = 0; i < 6; i++) {
//					cout << "____________________________________________________" << endl;
//					cout << inventory[i] << endl;
//				}
//				cin >> input;
//				convert(input);
//			}
//			if (input.compare("EAST") == 0 || input.compare("E") == 0)
//				rooms = 2;
//			else
//				cout << "invalid input" << endl;
//			break;
//		case 5://hanging figure
//			walking();
//			cout << "____________________________________________________" << endl;
//			cout << "You entered a dark corridor to find a dark figure hanging from chains" << endl;
//			cout << "You can TALK or head EAST, NORTH, or WEST" << endl;
//			cin >> input;
//			convert(input);
//			if (input.compare("EAST") == 0 || input.compare("E") == 0)
//				if (inventory[2] == "Key")
//					rooms = 8;
//				else
//					rooms = 7;
//			else if (input.compare("TALK") == 0)
//				rooms = 6;
//			else if (input.compare("NORTH") == 0 || input.compare("N") == 0)
//				rooms = 11;
//			else if (input.compare("WEST") == 0 || input.compare("W") == 0)
//				rooms = 2;
//			else if (input.compare("INV") == 0 || input.compare("INVENTORY") == 0) {
//				for (int i = 0; i < 5; i++) {
//					cout << "____________________________________________________" << endl;
//					cout << inventory[i] << endl;
//				}
//				cin >> input;
//				convert(input);
//			}
//			if (input.compare("EAST") == 0 || input.compare("E") == 0)
//				rooms = 7;
//			else if (input.compare("TALK") == 0)
//				rooms = 6;
//			else if (input.compare("NORTH") == 0 || input.compare("N") == 0)
//				rooms = 11;
//			else if (input.compare("WEST") == 0 || input.compare("W") == 0)
//				rooms = 2;
//			else
//				cout << "invalid input" << endl;
//			break;
//		case 6://talking to figure
//			walking();
//			cout << "____________________________________________________" << endl;
//			PlaySound(TEXT("screamcry.wav"), NULL, SND_FILENAME);
//			cout << "You approach the figure slowly as its head looks up." << endl;
//			cout << "It whispered, Please don't look at me..." << endl;
//			cout << "You chose to continue approaching it." << endl;
//			cout << "Its Raku," << endl;
//			cout << "She looks up at you and screams, Kiyoshi!" << endl;
//			cout << "Kiyoshi?... Kiyoshi is your language teacher, " << endl;
//			cout << "Why would Raku say his name? is she asking for help?" << endl;
//			cout << "You can head north, east, and west." << endl;
//			cin >> input;
//			convert(input);
//			cout << endl;
//
//			if (input.compare("EAST") == 0 || input.compare("E") == 0)
//				if (inventory[2] == "Key")
//					rooms = 8;
//				else
//					rooms = 7;
//			else if (input.compare("NORTH") == 0 || input.compare("N") == 0)
//				rooms = 11;
//			else if (input.compare("WEST") == 0 || input.compare("W") == 0)
//				rooms = 2;
//			else if (input.compare("INV") == 0 || input.compare("INVENTORY") == 0) {
//				for (int i = 0; i < 6; i++) {
//					cout << "____________________________________________________" << endl;
//					cout << inventory[i] << endl;
//				}
//				cin >> input;
//				convert(input);
//			}
//			if (input.compare("EAST") == 0 || input.compare("E") == 0)
//				rooms = 7;
//			else if (input.compare("NORTH") == 0 || input.compare("N") == 0)
//				rooms = 11;
//			else if (input.compare("WEST") == 0 || input.compare("W") == 0)
//				rooms = 2;
//			else
//				cout << "invalid input" << endl;
//			break;
//		case 7://table with key
//			walking();
//			cout << "____________________________________________________" << endl;
//			cout << "You entered a room with a wooden table " << endl;
//			cout << "Approaching the table you see a KEY and hear a" << endl;
//			cout << "whimpering sound SOUTH, there is also a shaft, EAST" << endl;
//			cin >> input;
//			convert(input);
//			cout << endl;
//
//			if (input.compare("EAST") == 0 || input.compare("E") == 0)
//				rooms = 10;
//			else if (input.compare("KEY") == 0)
//				rooms = 8;
//			else if (input.compare("SOUTH") == 0 || input.compare("S") == 0)
//				rooms = 9;
//			else if (input.compare("WEST") == 0 || input.compare("W") == 0)
//				rooms = 5;
//			else if (input.compare("INV") == 0 || input.compare("INVENTORY") == 0) {
//				for (int i = 0; i < 6; i++) {
//					cout << "____________________________________________________" << endl;
//					cout << inventory[i] << endl;
//				}
//				cin >> input;
//				convert(input);
//			}
//			if (input.compare("EAST") == 0 || input.compare("E") == 0)
//				rooms = 10;
//			else if (input.compare("KEY") == 0)
//				rooms = 8;
//			else if (input.compare("SOUTH") == 0 || input.compare("S") == 0)
//				rooms = 9;
//			else if (input.compare("WEST") == 0 || input.compare("W") == 0)
//				rooms = 5;
//			else
//				cout << "invalid input" << endl;
//			break;
//		case 8://table alone
//			walking();
//			cout << "____________________________________________________" << endl;
//			inventory[2] = "Key";
//			cout << "A table stands in the middle of the room, you may go WEST," << endl;
//			cout << "investigate a sound SOUTH or look at a shaft EAST." << endl;
//			cin >> input;
//			convert(input);
//			cout << endl;
//
//			if (input.compare("EAST") == 0 || input.compare("E") == 0)
//				rooms = 10;
//			else if (input.compare("SOUTH") == 0 || input.compare("S") == 0)
//				rooms = 9;
//			else if (input.compare("WEST") == 0 || input.compare("W") == 0)
//				rooms = 5;
//			else if (input.compare("INV") == 0 || input.compare("INVENTORY") == 0) {
//				for (int i = 0; i < 6; i++) {
//					cout << "____________________________________________________" << endl;
//					cout << inventory[i] << endl;
//				}
//				cin >> input;
//				convert(input);
//			}
//			if (input.compare("EAST") == 0 || input.compare("E") == 0)
//				rooms = 10;
//			else if (input.compare("SOUTH") == 0 || input.compare("S") == 0)
//				rooms = 9;
//			else if (input.compare("WEST") == 0 || input.compare("W") == 0)
//				rooms = 5;
//			else
//				cout << "invalid input" << endl;
//			break;
//		case 9://whimpering sound
//			walking();
//			cout << "____________________________________________________" << endl;
//			cout << "You investigate into the whimpering sound" << endl;
//			cout << "You find a shadowy figure in the corner of the room." << endl;
//			cout << "Hello, you said and the shadow turned around." << endl;
//			cout << "Please leave, Kiyoshi, you have gone too far" << endl;
//			cout << "You realized that that was Shizuko, another missing " << endl;
//			cout << "student. Why? What is with Kiyoshi?... You may head NORTH" << endl;
//			cin >> input;
//			convert(input);
//			cout << endl;
//
//			if (input.compare("NORTH") == 0 || input.compare("N") == 0)
//				if (inventory[2] == "Key")
//					rooms = 8;
//				else
//					rooms = 7;
//			else if (input.compare("INV") == 0 || input.compare("INVENTORY") == 0) {
//				for (int i = 0; i < 6; i++) {
//					cout << "____________________________________________________" << endl;
//					cout << inventory[i] << endl;
//				}
//				cin >> input;
//				convert(input);
//			}
//			if (input.compare("NORTH") == 0 || input.compare("N") == 0)
//				if (inventory[2] == "Key")
//					rooms = 8;
//				else
//					rooms = 7;
//			else
//				cout << "invalid input" << endl;
//			break;
//		case 10://shaft death
//			walking();
//			cout << "____________________________________________________" << endl;
//			cout << "You slowly begin to approach the shaft..." << endl;
//			PlaySound(TEXT("doorcreak.wav"), NULL, SND_FILENAME);
//			cout << "You feel a hand on your back but it was too late." << endl;
//			cout << "You fall to your death do you wish to restart" << endl;
//			cin >> input;
//			convert(input);
//			cout << endl;
//
//			if (input.compare("YES") == 0)
//				rooms = 0;
//			else if (input.compare("NO") == 0)
//				input = "QUIT";
//			else
//				cout << "invalid input" << endl;
//			break;
//		case 11://wrong way 1
//			walking();
//			cout << "____________________________________________________" << endl;
//			cout << "You entered a hallway and see a door way NORTH but a signs states: " << endl;
//			cout << "Private Property Please Turn Around and Proceed SOUTH." << endl;
//			cin >> input;
//			convert(input);
//			cout << endl;
//
//			if (input.compare("SOUTH") == 0 || input.compare("S") == 0)
//				rooms = 5;
//			else if (input.compare("NORTH") == 0 || input.compare("N") == 0)
//				rooms = 12;
//			else if (input.compare("INV") == 0 || input.compare("INVENTORY") == 0) {
//				for (int i = 0; i < 6; i++) {
//					cout << "____________________________________________________" << endl;
//					cout << inventory[i] << endl;
//				}
//				cin >> input;
//				convert(input);
//			}
//			if (input.compare("SOUTH") == 0 || input.compare("S") == 0)
//				rooms = 5;
//			else if (input.compare("NORTH") == 0 || input.compare("N") == 0)
//				rooms = 12;
//			else
//				cout << "invalid input" << endl;
//			break;
//		case 12://wrong way 2
//			walking();
//			cout << "____________________________________________________" << endl;
//			cout << "A sign now says, You are now tresspassing, you should go back!" << endl;
//			cout << "Now you are more suspious about this basement. You can now head" << endl;
//			cout << "NORTH, SOUTH, EAST, or WEST." << endl;
//			cin >> input;
//			convert(input);
//			cout << endl;
//
//			if (input.compare("EAST") == 0 || input.compare("E") == 0)
//				rooms = 13;
//			else if (input.compare("SOUTH") == 0 || input.compare("S") == 0)
//				rooms = 11;
//			else if (input.compare("NORTH") == 0 || input.compare("N") == 0)
//				rooms = 14;
//			else if (input.compare("WEST") == 0 || input.compare("W") == 0)
//				if (inventory[6] == "Talk")
//					rooms = 17;
//				else
//					rooms = 16;
//			else if (input.compare("INV") == 0 || input.compare("INVENTORY") == 0) {
//				for (int i = 0; i < 6; i++) {
//					cout << "____________________________________________________" << endl;
//					cout << inventory[i] << endl;
//				}
//				cin >> input;
//				convert(input);
//			}
//			if (input.compare("EAST") == 0 || input.compare("E") == 0)
//				rooms = 13;
//			else if (input.compare("SOUTH") == 0 || input.compare("S") == 0)
//				rooms = 11;
//			else if (input.compare("NORTH") == 0 || input.compare("N") == 0)
//				rooms = 14;
//			else if (input.compare("WEST") == 0 || input.compare("W") == 0)
//				if (inventory[6] == "Talk")
//					rooms = 17;
//				else
//					rooms = 16;
//			else
//				cout << "invalid input" << endl;
//			break;
//		case 13://dead end
//			walking();
//			cout << "____________________________________________________" << endl;
//			cout << "Dead End..." << endl;
//			cout << "You may head WEST" << endl;
//			cin >> input;
//			convert(input);
//			cout << endl;
//
//			if (input.compare("WEST") == 0 || input.compare("W") == 0)
//				rooms = 12;
//			else if (input.compare("INV") == 0 || input.compare("INVENTORY") == 0) {
//				for (int i = 0; i < 6; i++) {
//					cout << "____________________________________________________" << endl;
//					cout << inventory[i] << endl;
//				}
//				cin >> input;
//				convert(input);
//			}
//			if (input.compare("WEST") == 0 || input.compare("W") == 0)
//				rooms = 12;
//			else
//				cout << "invalid input" << endl;
//			break;
//		case 14://death reaper
//			walking();
//			cout << "____________________________________________________" << endl;
//			cout << "you entered the room and the door closes behind you" << endl;
//			PlaySound(TEXT("slamdoor.wav"), NULL, SND_FILENAME);
//			cout << "When you turn around a male figure raises his hand and strikes" << endl;
//			cout << "You are on the verge of death as the reaper himself stands" << endl;
//			cout << "Do you wish to die and restart?" << endl;
//			cin >> input;
//			convert(input);
//			cout << endl;
//
//			if (input.compare("YES") == 0)
//				rooms = 0;
//			else if (input.compare("NO") == 0)
//				rooms = 15;
//			else
//				cout << "invalid input" << endl;
//			break;
//		case 15://refuse death
//			walking();
//			inventory[5] = "Caution is the Password";
//			cout << "____________________________________________________" << endl;
//			cout << "You stand up, screaming. Charging at death..." << endl;
//			cout << "Flailing at the dark figure, he begins to run." << endl;
//			pause(5);
//			cout << "After resting you decide to leave, you may head SOUTH" << endl;
//			cin >> input;
//			convert(input);
//			cout << endl;
//
//			if (input.compare("SOUTH") == 0 || input.compare("S") == 0)
//				rooms = 12;
//			else if (input.compare("INV") == 0 || input.compare("INVENTORY") == 0) {
//				for (int i = 0; i < 6; i++) {
//					cout << "____________________________________________________" << endl;
//					cout << inventory[i] << endl;
//				}
//				cin >> input;
//				convert(input);
//			}
//			if (input.compare("SOUTH") == 0 || input.compare("S") == 0)
//				rooms = 12;
//			else
//				cout << "invalid input" << endl;
//			break;
//		case 16://Hoshiko with Kiyoshi
//			walking();
//			cout << "____________________________________________________" << endl;
//			cout << "You entered a room with two people in the center talking" << endl;
//			cout << "One of them is Hoshiko, A Star Student, and the other.." << endl;
//			cout << "Kiyoshi! eavesdropping onto what they are saying, you hear:" << endl;
//			cout << "Someone else is down here we need to leave. " << endl;
//			cout << "They left WEST and you can also head EAST" << endl;
//			inventory[6] = "Talk";
//			cin >> input;
//			convert(input);
//			cout << endl;
//
//			if (input.compare("EAST") == 0 || input.compare("E") == 0)
//				rooms = 12;
//			else if (input.compare("WEST") == 0 || input.compare("W") == 0)
//				if (inventory[1] == "Roses")
//					rooms = 19;
//				else
//					rooms = 18;
//			else if (input.compare("INV") == 0 || input.compare("INVENTORY") == 0) {
//				for (int i = 0; i < 5; i++) {
//					cout << "____________________________________________________" << endl;
//					cout << inventory[i] << endl;
//				}
//				cin >> input;
//				convert(input);
//			}
//			if (input.compare("EAST") == 0 || input.compare("E") == 0)
//				rooms = 12;
//			else if (input.compare("WEST") == 0 || input.compare("W") == 0)
//				if (inventory[1] == "Roses")
//					rooms = 19;
//				else
//					rooms = 18;
//			else
//				cout << "invalid input" << endl;
//			break;
//		case 17://room that hoshiko talked to kiyoshi
//			walking();
//			cout << "____________________________________________________" << endl;
//			cout << "This was where the room Hoshiko was talking to Kiyoshi" << endl;
//			cout << "you can head EAST and WEST" << endl;
//			cin >> input;
//			convert(input);
//			cout << endl;
//
//			if (input.compare("EAST") == 0 || input.compare("E") == 0)
//				rooms = 12;
//			else if (input.compare("WEST") == 0 || input.compare("W") == 0)
//				if (inventory[1] == "Roses")
//					rooms = 19;
//				else
//					rooms = 18;
//			else if (input.compare("INV") == 0 || input.compare("INVENTORY") == 0) {
//				for (int i = 0; i < 6; i++) {
//					cout << "____________________________________________________" << endl;
//					cout << inventory[i] << endl;
//				}
//				cin >> input;
//				convert(input);
//			}
//			if (input.compare("EAST") == 0 || input.compare("E") == 0)
//				rooms = 12;
//			else if (input.compare("WEST") == 0 || input.compare("W") == 0)
//				if (inventory[1] == "Roses")
//					rooms = 19;
//				else
//					rooms = 18;
//			else
//				cout << "invalid input" << endl;
//			break;
//		case 18://Hanako Attacks (death)
//			walking();
//			cout << "____________________________________________________" << endl;
//			cout << "You enter the room and see Hanako" << endl;
//			cout << "she hasnt been that stable since Kohana passed away." << endl;
//			cout << "You slowly approach her and she stands up and charge towards you." << endl;
//			PlaySound(TEXT("fastfootsteps.wav"), NULL, SND_FILENAME);
//			cout << "She tackles and chokes you to death..." << endl;
//			cout << "Do you wish to restart?" << endl;
//			cin >> input;
//			convert(input);
//			cout << endl;
//
//			if (input.compare("YES") == 0)
//				rooms = 0;
//			else if (input.compare("NO") == 0)
//				input = "quit";
//			else
//				cout << "invalid input" << endl;
//			break;
//		case 19://Hanako peaceful
//			walking();
//			cout << "____________________________________________________" << endl;
//			cout << "You enter the room and see Hanako," << endl;
//			cout << "she hasnt been that stable since Kohana passed away." << endl;
//			cout << "You slowly approach her and she stands up and charge towards you." << endl;
//			PlaySound(TEXT("fastfootsteps.wav"), NULL, SND_FILENAME);
//			cout << "She stand a foot away and looks at the roses and heads back " << endl;
//			cout << "to the center of the room. You may head EAST, or WEST." << endl;
//			cin >> input;
//			convert(input);
//			cout << endl;
//
//			if (input.compare("EAST") == 0 || input.compare("E") == 0)
//				if (inventory[5] == "Talk")
//					rooms = 17;
//				else
//					rooms = 16;
//			else if (input.compare("WEST") == 0 || input.compare("W") == 0)
//				rooms = 20;
//			else if (input.compare("INV") == 0 || input.compare("INVENTORY") == 0) {
//				for (int i = 0; i < 6; i++) {
//					cout << "____________________________________________________" << endl;
//					cout << inventory[i] << endl;
//				}
//				cin >> input;
//				convert(input);
//			}
//			if (input.compare("EAST") == 0 || input.compare("E") == 0)
//				if (inventory[5] == "Talk")
//					rooms = 17;
//				else
//					rooms = 16;
//			else if (input.compare("WEST") == 0 || input.compare("W") == 0)
//				rooms = 20;
//			else
//				cout << "invalid input" << endl;
//			break;
//		case 20://wrong way 3
//			walking();
//			cout << "____________________________________________________" << endl;
//			cout << "A Sign on the floor, WEST, says: TEACHERS ONLY" << endl;
//			cout << "You've seen signs like this before, but this sign seems " << endl;
//			cout << "a little more dangerous. Maybe take a different route." << endl;
//			cout << "or you can head back EAST." << endl;
//			cin >> input;
//			convert(input);
//			cout << endl;
//
//			if (input.compare("EAST") == 0 || input.compare("E") == 0)
//				if (inventory[1] == "Roses")
//					rooms = 19;
//				else
//					rooms = 18;
//			else if (input.compare("NORTH") == 0 || input.compare("N") == 0)
//				if (inventory[3] == "Knife")
//					rooms = 22;
//				else
//					rooms = 21;
//			else if (input.compare("WEST") == 0 || input.compare("W") == 0)
//				if (inventory[4] == "Knife")
//					rooms = 26;
//				else
//					rooms = 25;
//			else if (input.compare("INV") == 0 || input.compare("INVENTORY") == 0) {
//				for (int i = 0; i < 6; i++) {
//					cout << "____________________________________________________" << endl;
//					cout << inventory[i] << endl;
//				}
//				cin >> input;
//				convert(input);
//			}
//			if (input.compare("EAST") == 0 || input.compare("E") == 0)
//				if (inventory[1] == "Roses")
//					rooms = 19;
//				else
//					rooms = 18;
//			else if (input.compare("NORTH") == 0 || input.compare("N") == 0)
//				rooms = 21;
//			else if (input.compare("WEST") == 0 || input.compare("W") == 0)
//				if (inventory[3] == "Knife")
//					rooms = 26;
//				else
//					rooms = 25;
//			else
//				cout << "invalid input" << endl;
//			break;
//		case 21://table with knife
//			walking();
//			cout << "____________________________________________________" << endl;
//			cout << "You entered a room with a desk in the center of the room." << endl;
//			cout << "A drawer of the desk is open and a KNIFE is inside." << endl;
//			cout << "You may continue WEST or SOUTH." << endl;
//			cin >> input;
//			convert(input);
//			cout << endl;
//
//			if (input.compare("SOUTH") == 0 || input.compare("S") == 0)
//				rooms = 20;
//			else if (input.compare("KNIFE") == 0)
//				rooms = 22;
//			else if (input.compare("WEST") == 0 || input.compare("W") == 0)
//				if (inventory[3] == "Key")
//					rooms = 24;
//				else
//					rooms = 23;
//			else if (input.compare("INV") == 0 || input.compare("INVENTORY") == 0) {
//				for (int i = 0; i < 6; i++) {
//					cout << "____________________________________________________" << endl;
//					cout << inventory[i] << endl;
//				}
//				cin >> input;
//				convert(input);
//			}
//			if (input.compare("SOUTH") == 0 || input.compare("S") == 0)
//				rooms = 20;
//			else if (input.compare("KNIFE") == 0)
//				rooms = 22;
//			else if (input.compare("WEST") == 0 || input.compare("W") == 0)
//				if (inventory[3] == "Key")
//					rooms = 24;
//				else
//					rooms = 23;
//			else
//				cout << "invalid input" << endl;
//			break;
//		case 22://table without knife
//			walking();
//			cout << "____________________________________________________" << endl;
//			cout << "The table is the only thing in the room now." << endl;
//			inventory[4] = "Knife";
//			cout << "You may head WEST or SOUTH." << endl;
//			cin >> input;
//			convert(input);
//			cout << endl;
//			if (input.compare("SOUTH") == 0 || input.compare("S") == 0)
//				rooms = 20;
//			else if (input.compare("WEST") == 0 || input.compare("W") == 0)
//				if (inventory[3] == "Key")
//					rooms = 24;
//				else
//					rooms = 23;
//			else if (input.compare("INV") == 0 || input.compare("INVENTORY") == 0) {
//				for (int i = 0; i < 6; i++) {
//					cout << "____________________________________________________" << endl;
//					cout << inventory[i] << endl;
//				}
//				cin >> input;
//				convert(input);
//			}
//			if (input.compare("SOUTH") == 0 || input.compare("S") == 0)
//				rooms = 20;
//			else if (input.compare("WEST") == 0 || input.compare("W") == 0)
//				if (inventory[3] == "Key")
//					rooms = 24;
//				else
//					rooms = 23;
//			else
//				cout << "invalid input" << endl;
//			break;
//		case 23://empty room with key
//			walking();
//			cout << "____________________________________________________" << endl;
//			cout << "Another empty room?..." << endl;
//			pause(3);
//			cout << "Wait, there's a slot in the wall, with a KEY" << endl;
//			cout << "You can head EAST or SOUTH" << endl;
//			cin >> input;
//			convert(input);
//			cout << endl;
//
//			if (input.compare("SOUTH") == 0 || input.compare("S") == 0)
//				if (inventory[4] == "Knife")
//					rooms = 26;
//				else
//					rooms = 25;
//			else if (input.compare("EAST") == 0 || input.compare("E") == 0)
//				if (inventory[3] == "Knife")
//					rooms = 22;
//				else
//					rooms = 21;
//			else if (input.compare("KEY") == 0)
//				rooms = 24;
//			else if (input.compare("INV") == 0 || input.compare("INVENTORY") == 0) {
//				for (int i = 0; i < 6; i++) {
//					cout << "____________________________________________________" << endl;
//					cout << inventory[i] << endl;
//				}
//				cin >> input;
//				convert(input);
//			}
//			if (input.compare("SOUTH") == 0 || input.compare("S") == 0)
//				if (inventory[4] == "Knife")
//					rooms = 26;
//				else
//					rooms = 25;
//			else if (input.compare("EAST") == 0 || input.compare("E") == 0)
//				if (inventory[3] == "Knife")
//					rooms = 22;
//				else
//					rooms = 21;
//			else
//				cout << "invalid input" << endl;
//			break;
//		case 24://empty room w/o key
//			walking();
//			cout << "____________________________________________________" << endl;
//			cout << "An empty room?..." << endl;
//			pause(3);
//			cout << "You can head EAST or SOUTH" << endl;
//			inventory[3] = "Key";
//			cin >> input;
//			convert(input);
//			cout << endl;
//
//			if (input.compare("SOUTH") == 0 || input.compare("S") == 0)
//				if (inventory[4] == "Knife")
//					rooms = 26;
//				else
//					rooms = 25;
//			else if (input.compare("EAST") == 0 || input.compare("E") == 0)
//				if (inventory[3] == "Knife")
//					rooms = 22;
//				else
//					rooms = 21;
//			else if (input.compare("INV") == 0 || input.compare("INVENTORY") == 0) {
//				for (int i = 0; i < 6; i++) {
//					cout << "____________________________________________________" << endl;
//					cout << inventory[i] << endl;
//				}
//				cin >> input;
//				convert(input);
//			}
//			if (input.compare("SOUTH") == 0 || input.compare("S") == 0)
//				if (inventory[4] == "Knife")
//					rooms = 26;
//				else
//					rooms = 25;
//			else if (input.compare("EAST") == 0 || input.compare("E") == 0)
//				if (inventory[3] == "Knife")
//					rooms = 22;
//				else
//					rooms = 21;
//			else
//				cout << "invalid input" << endl;
//			break;
//
//		case 25: //no knife = death
//			walking();
//			cout << "____________________________________________________" << endl;
//			cout << "You go into the room Koshiko was in.." << endl;
//			cout << "Hiding in the shadows Koshiko raises his hand and strikes" << endl;
//			cout << "You defend against his first strike but escape is not an option" << endl;
//			cout << "Would you like to restart?" << endl;
//			cin >> input;
//			convert(input);
//			cout << endl;
//
//			if (input.compare("YES") == 0)
//				rooms = 0;
//			else if (input.compare("NO") == 0)
//				input = "QUIT";
//			else
//				cout << "invalid input" << endl;
//			break;
//
//		case 26: //knife = progress
//			walking();
//			cout << "____________________________________________________" << endl;
//			cout << "You go into the room Koshiko was in.." << endl;
//			cout << "Hiding in the shadows Koshiko raises his hand and strikes" << endl;
//			cout << "You defend against his first strike but escape is not an option" << endl;
//			pause(7);
//			cout << "pulling out your knife, he backs up and runs SOUTH." << endl;
//			cout << "you can also head EAST or North," << endl;
//			cin >> input;
//			convert(input);
//			cout << endl;
//
//			if (input.compare("EAST") == 0 || input.compare("E") == 0)
//				rooms = 20;
//			else if (input.compare("SOUTH") == 0 || input.compare("S") == 0)
//				rooms = 27;
//			else if (input.compare("NORTH") == 0 || input.compare("N") == 0)
//				if (inventory[3] == "Key")
//					rooms = 24;
//				else
//					rooms = 23;
//			else if (input.compare("INV") == 0 || input.compare("INVENTORY") == 0) {
//				for (int i = 0; i < 5; i++) {
//					cout << "____________________________________________________" << endl;
//					cout << inventory[i] << endl;
//				}
//				cin >> input;
//				convert(input);
//			}
//			if (input.compare("EAST") == 0 || input.compare("E") == 0)
//				rooms = 20;
//			else if (input.compare("SOUTH") == 0 || input.compare("S") == 0)
//				rooms = 27;
//			else if (input.compare("NORTH") == 0 || input.compare("N") == 0)
//				if (inventory[3] == "Key")
//					rooms = 24;
//				else
//					rooms = 23;
//			else
//				cout << "invalid input" << endl;
//			break;
//
//		case 27://password room
//			walking();
//			cout << "____________________________________________________" << endl;
//			cout << "You chase after Kiyoshi as he slams a door behind him" << endl;
//			PlaySound(TEXT("slamdoor.wav"), NULL, SND_FILENAME);
//			cout << "The door closed and locked. A password is required." << endl;
//			cout << "Go BACK or Input the Password:" << endl;
//			cin >> input;
//			convert(input);
//			cout << endl;
//
//			if (input.compare("BACK") == 0)
//				rooms = 26;
//			else if (input.compare("CAUTION") == 0)
//				rooms = 28;
//			else if (input.compare("INV") == 0 || input.compare("INVENTORY") == 0) {
//				for (int i = 0; i < 5; i++) {
//					cout << "____________________________________________________" << endl;
//					cout << inventory[i] << endl;
//				}
//				cin >> input;
//				convert(input);
//			}
//			if (input.compare("BACK") == 0)
//				rooms = 26;
//			else if (input.compare("CAUTION") == 0)
//				rooms = 28;
//			else
//				cout << "invalid input" << endl;
//			break;
//		case 28://end game
//			walking();
//			cout << "____________________________________________________" << endl;
//			cout << "Slowly opening the door, Kiyoshi attacks you with a pocket" << endl;
//			cout << "knife. Ready at hand you stab Kiyoshi in the chest pulling the" << endl;
//			cout << "knife again to stab him once more, remembering about the other students" << endl;
//			system("color 4d");
//			cout << "Finding Hoshiko in a chair was relieving but someone else was with her..." << endl;
//			pause(15);
//			cout << "MOM?" << endl;
//			input = "QUIT";
//			break;
//		case 29://beginning secret
//			walking();
//			cout << "____________________________________________________" << endl;
//			cout << "You came back to the beginning of the map are you lost?" << endl;
//			cout << "You can only head NORTH" << endl;
//			cin >> input;
//			convert(input);
//			cout << endl;
//			if (input.compare("SOUTH") == 0 || input.compare("S") == 0)
//				if (inventory[2] == "Key" && inventory[3] == "Key")
//					rooms = 30;
//				else
//					rooms = 29;
//			else if (input.compare("NORTH") == 0 || input.compare("N") == 0)
//				rooms = 2;
//			else if (input.compare("INV") == 0 || input.compare("INVENTORY") == 0) {
//				for (int i = 0; i < 6; i++) {
//					cout << "____________________________________________________" << endl;
//					cout << inventory[i] << endl;
//				}
//				cin >> input;
//				convert(input);
//			}
//			if (input.compare("SOUTH") == 0 || input.compare("S") == 0)
//				if (inventory[2] == "Key" && inventory[3] == "Key")
//					rooms = 30;
//				else
//					rooms = 29;
//			else if (input.compare("NORTH") == 0 || input.compare("N") == 0)
//				rooms = 2;
//			else
//				cout << "invalid input" << endl;
//			break;
//		case 30://secret intro
//			walking();
//			cout << "secret" << endl;
//			cout << "You can head WEST or NORTH to exit" << endl;
//			cin >> input;
//			convert(input);
//			if (input.compare("WEST") == 0 || input.compare("W") == 0)
//				rooms = 31;
//			else if (input.compare("NORTH") == 0 || input.compare("N") == 0)
//				rooms = 29;
//			break;
//		case 31://secret final
//			walking();
//			cout << "secret" << endl;
//			cout << "You can head EAST" << endl;
//			cin >> input;
//			convert(input);
//			if (input.compare("EAST") == 0 || input.compare("E") == 0)
//				rooms = 30;
//			break;
//		}// end switch
//	}// end while
//}//end main
//
//
//void pause(int dur)//pause function
//{
//	int temp = time(NULL) + dur;
//
//	while (temp > time(NULL));
//}
//
//void convert(string& input) {//toupper fucntion
//
//	for (int i = 0; i < input.length(); i++) {
//		input[i] = toupper(input[i]);
//	}
//}
//
//void walking() {//walking sound function
//	PlaySound(TEXT("walking.wav"), NULL, SND_FILENAME);
//}
//
//
////http://soundbible.com/1627-Female-Scream-Horror.html
////http://soundbible.com/911-Footsteps.html
////http://soundbible.com/1717-Creaking-Door-Spooky.html
////http://soundbible.com/2041-News-Intro.html
////http://soundbible.com/2057-Footsteps-On-Cement.html
////http://soundbible.com/297-Cellar-Door-Slam-Shut.html
