/*
 * Author: Thales F.
 *
 * Description: Basic 'ls' implementation.
 * 
 * Acknowledgement: (Based on / copied from / inspired by) the sample code and
 * exercises used by the class "Advanced Programming in the UNIX Environment"
 * taught by Jan Schaumann at Stevens Institute of Technology.
 */

#include <sys/types.h>

#include <errno.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(int argc, char **argv)
{
	DIR *dp;
	struct dirent *dirp;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s dir_name\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((dp = opendir(argv[1])) == NULL) {
		fprintf(stderr, "Unable to open '%s': %s\n", argv[1], strerror(errno));
		exit(EXIT_FAILURE);
	}

	while ((dirp = readdir(dp)) != NULL) {
		printf("%s\n", dirp->d_name);
	}

	(void)closedir(dp);
	return EXIT_SUCCESS;
}

