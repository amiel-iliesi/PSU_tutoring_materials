#include "track_data.h"
#include "tracklist.h"

#include <cctype> //tolower()
#include <print>
#include <iostream>

using namespace std;

// -constants------------------------------------------------------------
const size_t TRACKSIZE_MAX = 1024;
const char FILENAME[] = "tracklist_db.txt";

// -menu prototypes------------------------------------------------------
void menu_main(Track tracklist[], size_t& size, const char filename[]);
bool menu_add_track(Track tracklist[], size_t& size);
bool menu_update_track(Track tracklist[], size_t& size);
bool menu_delete_track(Track tracklist[], size_t& size);
void menu_display_track(const Track tracklist[], size_t& size);


// -main-----------------------------------------------------------------
int main()
{
	Track tracklist[TRACKSIZE_MAX];
	size_t count = 0;

	menu_main(tracklist, count, FILENAME);

	return 0;
}


// -menu implementations-------------------------------------------------
void menu_main(Track tracklist[], size_t& size, const char filename[])
{
	unsigned option;

	load(tracklist, size, filename);

	bool edits_made = false;

	do {
		print("\n1. Add new track.\n"
			   "2. Update track.\n"
			   "3. Delete track.\n"
			   "4. List all tracks.\n"
			   "5. Display track info.\n"
			   "6. Quit.\n");

		print("\n>>> ");
		cin >> option;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		switch (option) {
			case 1:
				edits_made |= menu_add_track(tracklist, size);
				break;
			case 2:
				edits_made |= menu_update_track(tracklist, size);
				break;
			case 3:
				edits_made |= menu_delete_track(tracklist, size);
				break;
			case 4:
				display_all_tracks(tracklist, size);
				break;
			case 5:
				menu_display_track(tracklist, size);
				break;
			case 6:
				if (edits_made) {
					print(">>> save changes? (Y/N): ");
					char choice;
					cin >> choice;
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					choice = tolower(choice);

					if (choice == 'y')
					{
						save(tracklist, size, filename);
					}
				}
				else {
					println("*** no edits made, saving to \"{}\" skipped",
							filename);
				}
				break;
		}
	} while (option != 6);
}

bool menu_add_track(Track tracklist[], size_t& size)
{
	if (size == TRACKSIZE_MAX) {
		println("*** cannot add new track: storage limit reached ({})",
				TRACKSIZE_MAX);
		return false;
	}

	prompt_entry(tracklist[size++]);
	println("*** track added");
	return true;
}

bool menu_update_track(Track tracklist[], size_t& size)
{
	Track* track = find_track(tracklist, size);

	if (not track) {
		println("*** track not found");
		return false;
	}

	println("Found track:");
	display(*track);

	println(">>> overwrite? (Y/N): ");
	char choice;
	cin >> choice;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	choice = tolower(choice);

	if (choice != 'y') {
		return false;
	}

	prompt_entry(*track);
	println("*** track overwritten");
	return true;
}

// NOTE: take a look at our planning sketch to see how we're planning on 
// deleting
bool menu_delete_track(Track tracklist[], size_t& size)
{
	Track* track = find_track(tracklist, size);

	if (not track) {
		println("*** track not found");
		return false;
	}

	if (track != &tracklist[size-1]) {
		copy(*track, tracklist[size-1]);
	}
	--size;

	return true;
}

void menu_display_track(const Track tracklist[], size_t& size)
{
	const Track* track = find_track(tracklist, size);

	if (not track) {
		println("*** track not found");
		return;
	}

	display(*track);
}
