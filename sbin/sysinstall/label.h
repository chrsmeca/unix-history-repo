struct field label_field[] = {
	{ 6, 02, 10, 10, -1, -1, -1, -1, -1, "wd0a", F_TITLE, 0, 0},
	{ 6, 16,  4,  4, -1, 48,  6, 49,  2, "YES", F_EDIT, 0, 0},
	{ 6, 27,  7,  7, -1, 48,  7,  1,  3, "MSDOS", F_EDIT, 0, 0},
	{ 6, 39,  5,  5, -1, 49,  8,  2,  4, "1000", F_EDIT, 0, 0},
	{ 6, 47, 30, 79, -1, 49,  9,  3,  6, "/an/example/mountpoint", F_EDIT, 0, 0},
	{ 8, 02,  4,  4, -1, -1, -1, -1, -1, "wd0b", F_TITLE, 0, 0},
	{ 8, 16,  4,  4, -1,  1, 11,  4,  7, "YES", F_EDIT, 0, 0},
	{ 8, 27,  7,  7, -1,  2, 12,  6,  8, "MSDOS", F_EDIT, 0, 0},
	{ 8, 39,  5,  5, -1,  3, 13,  7,  9, "1000", F_EDIT, 0, 0},
	{ 8, 47, 30, 79, -1,  4, 14,  8, 11, "/an/example/mountpoint", F_EDIT, 0, 0},
	{10, 02, 10, 10, -1, -1, -1, -1, -1, "wd0c", F_TITLE, 0, 0},
	{10, 16,  4,  4, -1,  6, 16,  9, 12, "YES", F_EDIT, 0, 0},
	{10, 27,  7,  7, -1,  7, 17, 11, 13, "MSDOS", F_EDIT, 0, 0},
	{10, 39,  5,  5, -1,  8, 18, 12, 14, "1000", F_EDIT, 0, 0},
	{10, 47, 30, 79, -1,  9, 19, 13, 16, "/an/example/mountpoint", F_EDIT, 0, 0},
	{12, 02, 10, 10, -1, -1, -1, -1, -1, "wd0d", F_TITLE, 0, 0},
	{12, 16,  4,  4, -1, 11, 21, 14, 17, "YES", F_EDIT, 0, 0},
	{12, 27,  7,  7, -1, 12, 22, 16, 18, "MSDOS", F_EDIT, 0, 0},
	{12, 39,  5,  5, -1, 13, 23, 17, 19, "1000", F_EDIT, 0, 0},
	{12, 47, 30, 79, -1, 14, 24, 18, 21, "/an/example/mountpoint", F_EDIT, 0, 0},
	{14, 02, 10, 10, -1, -1, -1, -1, -1, "wd0e", F_TITLE, 0, 0},
	{14, 16,  4,  4, -1, 16, 26, 19, 22, "YES", F_EDIT, 0, 0},
	{14, 27,  7,  7, -1, 17, 27, 21, 23, "MSDOS", F_EDIT, 0, 0},
	{14, 39,  5,  5, -1, 18, 28, 22, 24, "1000", F_EDIT, 0, 0},
	{14, 47, 30, 79, -1, 19, 29, 23, 26, "/an/example/mountpoint", F_EDIT, 0, 0},
	{16, 02, 10, 10, -1, -1, -1, -1, -1, "wd0f", F_TITLE, 0, 0},
	{16, 16,  4,  4, -1, 21, 31, 24, 27, "YES", F_EDIT, 0, 0},
	{16, 27,  7,  7, -1, 22, 32, 26, 28, "MSDOS", F_EDIT, 0, 0},
	{16, 39,  5,  5, -1, 23, 33, 27, 29, "1000", F_EDIT, 0, 0},
	{16, 47, 30, 79, -1, 24, 34, 28, 31, "/an/example/mountpoint", F_EDIT, 0, 0},
	{18, 02, 10, 10, -1, -1, -1, -1, -1, "wd0g", F_TITLE, 0, 0},
	{18, 16,  4,  4, -1, 26, 36, 29, 32, "YES", F_EDIT, 0, 0},
	{18, 27,  7,  7, -1, 27, 37, 31, 33, "MSDOS", F_EDIT, 0, 0},
	{18, 39,  5,  5, -1, 28, 38, 32, 34, "1000", F_EDIT, 0, 0},
	{18, 47, 30, 79, -1, 29, 39, 33, 36, "/an/example/mountpoint", F_EDIT, 0, 0},
	{20, 02, 10, 10, -1, -1, -1, -1, -1, "wd0h", F_TITLE, 0, 0},
	{20, 16,  4,  4, -1, 31, 48, 34, 37, "YES", F_EDIT, 0, 0},
	{20, 27,  7,  7, -1, 32, 48, 36, 38, "MSDOS", F_EDIT, 0, 0},
	{20, 39,  5,  5, -1, 33, 49, 37, 39, "1000", F_EDIT, 0, 0},
	{20, 47, 30, 79,  1, 34, 49, 38, 48, "/an/example/mountpoint", F_EDIT, 0, 0},
	{ 0, 27, 17, 17, -1, -1, -1, -1, -1, "Disk label editor", F_TITLE, 0, 0},
	{ 4,  2, 11, 11, -1, -1, -1, -1, -1, "Partition", F_TITLE, 0, 0},
	{ 4, 14,  8,  8, -1, -1, -1, -1, -1, "Preserve", F_TITLE, 0, 0},
	{ 4, 25, 10, 10, -1, -1, -1, -1, -1, "Filesystem", F_TITLE, 0, 0},
	{ 4, 39,  5,  5, -1, -1, -1, -1, -1, "Size", F_TITLE, 0, 0},
	{ 4, 47, 10, 10, -1, -1, -1, -1, -1, "Mountpoint", F_TITLE, 0, 0},
	{ 2, 02, 11, 11, -1, -1, -1, -1, -1, "Free space:", F_EDIT, 0, 0},
	{ 2, 15,  6,  6, -1, -1, -1, -1, -1, "000000", F_TITLE, 0, 0},
	{22, 20,  2,  2, -1, 36,  1, 39, 49, "OK", F_BUTTON, 0, 0},
	{22, 45,  2,  2, -1, 38,  3, 48,  1, "Cancel", F_BUTTON, 0, 0}
};
