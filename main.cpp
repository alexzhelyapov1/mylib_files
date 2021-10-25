#include "mylib_files.h"


int main () {
	REDIR(freopen ("stdout.txt", "w", stdout);)
	int res = Remove_r ("input.txt");
	if (!res) {
		printf ("RESULT - OK\n");
	}
	else {
		printf ("ERROR = %d\n", res);
	}
	REDIR(fclose (stdout);)
	return 0;
}