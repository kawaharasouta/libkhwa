#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<getopt.h>
#include<sys/stat.h>

void parse_args(int argc, const char **argv);
int exist_file(char *path);

#define FILE_NAME "Makefile"

int main(int argc, char **argv){
	if (argc != 1){
		fprintf(stderr, "usage: cmake\n");
		exit(1);
	}
	parse_args(argc,argv);

	if (exist_file(FILE_NAME)) {
		fprintf(stderr, "file exsist!!!\n");
		exit(1);
	}

	FILE *fp;
	fp = fopen (FILE_NAME, "a");
	fprintf(fp, "CC=gcc\n");
	fprintf(fp, "vpath %%.c src\n");
	fprintf(fp, "vpath %%.h include\n\n");
	fprintf(fp, "OBJS=main.o\n");
	fprintf(fp, "SRCS=$(OBJS:%%.o=%%.c)\n");
	fprintf(fp, "CFLAGS=-g -Wall\n");
	fprintf(fp, "LDLIBS=\n");
	fprintf(fp, "TARGET=\n");
	fprintf(fp, "INSTALL_PATH=/home/`whoami`/bin\n");
	fprintf(fp, "$(TARGET):$(OBJS)\n");
	fprintf(fp, "\t$(CC) $(CFLAGS) $(LDFLAGS) -o $(TARGET) $(OBJS) $(LDLIBS)\n\n");
	fprintf(fp, ".PHONY: clean install uninstall\n");
	fprintf(fp, "clean:\n");
	fprintf(fp, "\t@rm $(OBJS)\n");
	fprintf(fp, "install:\n");
	fprintf(fp, "\t@cp $(TARGET) $(INSTALL_PATH)/$(TARGET)\n");
	fprintf(fp, "uninstall:\n");
	fprintf(fp, "\t@rm $(INSTALL_PATH)/$(TARGET)\n");
	fclose(fp);

	return 0;
}

void parse_args(int argc, const char **argv){
	int o;
	struct option s_longopts[] = {
		{"help", no_argument, NULL, 'h'},
		{0,0,0,0},
	};

	while ((o = getopt_long(argc, (char * const *)argv, "h", s_longopts, NULL)) != EOF){
		switch (o) {
			case 'h':
				fprintf(stdout, "usage: $ cmake\n");
				fprintf(stdout, "you can get Makefile in your curent directry.");
				break;
			default:
				break;
		}
	}
}

int exist_file(char *path){
	struct stat st;
	if (stat(path, &st) != 0){
		return 0;
	}

	//return (st.st_mode & S_IFMT) == S_IFREG;
	return S_ISREG(st.st_mode);
}
