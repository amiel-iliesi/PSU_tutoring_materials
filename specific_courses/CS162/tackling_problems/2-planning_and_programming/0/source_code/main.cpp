#include "track_data.h"
#include "tracklist.h"

#include <print>
#include <iostream>

using namespace std;

// -constants------------------------------------------------------------
const size_t TRACKSIZE_MAX = 1024;
const char FILENAME[] = "tracklist_db.txt";

// -menu prototypes------------------------------------------------------
void menu_main(Track tracklist[], size_t& size, const char filename[]);
void menu_add_track(Track tracklist[], size_t& size);
void menu_update_track(Track tracklist[], size_t& size);
void menu_delete_track(Track tracklist[], size_t& size);
void menu_display_track(Track tracklist[], size_t& size);


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

	do {
		print("1. Add new track.\n"
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
				menu_add_track(tracklist, size);
				break;
			case 2:
				menu_update_track(tracklist, size);
				break;
			case 3:
				menu_delete_track(tracklist, size);
				break;
			case 4:
				display_all_tracks(tracklist, size);
				break;
			case 5:
				menu_display_track(tracklist, size);
				break;
			case 6:
				save(tracklist, size, filename);
				break;
		}
	} while (option != 6);
}

// TODO
void menu_add_track(Track tracklist[], size_t& size)
{
	// no-op to suppress unused parameter compiler warning
	(void)tracklist;
	(void)size;
	println("*** menu_add_track()::not yet implemented");
}

// TODO
void menu_update_track(Track tracklist[], size_t& size)
{
	(void)tracklist;
	(void)size;
	println("*** menu_update_track()::not yet implemented");
}

// TODO
void menu_delete_track(Track tracklist[], size_t& size)
{
	(void)tracklist;
	(void)size;
	println("*** menu_delete_track()::not yet implemented");
}

// TODO
void menu_display_track(Track tracklist[], size_t& size)
{
	(void)tracklist;
	(void)size;
	println("*** menu_display_track()::not yet implemented");
}
