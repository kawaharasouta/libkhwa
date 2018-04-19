#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<getopt.h>
#include<sys/stat.h>

void parse_args(int argc, const char **argv);
int exist_file(char *path);

int main(int argc, char **argv){
	if (argc != 2){
		fprintf(stderr, "usage: cfile [filename]\n");
		exit(1);
	}
	parse_args(argc,argv);

	if (exist_file(argv[1])) {
		fprintf(stderr, "file exsist!!!\n");
		exit(1);
	}

	FILE *fp;
	fp = fopen (argv[1], "a");
	fprintf(fp, "#include<stdio.h>\n");
	fprintf(fp, "#include<stdlib.h>\n");
	fprintf(fp, "#include<string.h>\n\n");
	fprintf(fp, "int main(int argc, char **argv){\n\n");
	fprintf(fp, "}\n");
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
				fprintf(stdout, "usage: cfile [filename]\n");
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
