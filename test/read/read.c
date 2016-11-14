#include <stdio.h>
#include <stdlib.h>
static int rad_map(char *fp, char ***raw_map, int *height, int *width) {
    fprintf(stderr, "ENTER \n");
    FILE *stream = NULL;
    ssize_t len = 0;

    stream = fopen(fp, "r");
    if(stream == NULL) {
        return -1;
    }
    int i;
    for(i = 0; i < 3; i++) {
        raw_map[i] = NULL;
    }
    i = 0;

    size_t linecapp = 0;
    while((len = getline(raw_map[i], &linecapp, stream)) != -1) {
        fprintf(stderr, "LINE: %s\n", raw_map[i]);
        *width = (len > *width)? len:*width;
        (*height)++;
        i++;
    }
    perror("huh?");

    fclose(stream);
    fprintf(stderr, "DONE \n");
    return 0;
}

char **read_map(char *fp, int *height, int *width) {
    FILE *stream = NULL;

    if((stream = fopen(fp, "r")) == NULL) {
        return NULL;
    }

    char **raw_map = NULL;
    char *line = NULL;
    size_t linecap = 0;
    ssize_t linelen;
    *width = 0;
    *height = 0;
    int i = 0;
    while((linelen = getline(&line, &linecap, stream)) > 0) {
        if(i == 0) {
            raw_map = malloc(sizeof(char*));
        } else {
            raw_map = realloc(raw_map, sizeof(char*)*(i+1));
        }
        raw_map[i] = line;
        line = NULL;
        linecap = 0;
        *width = (linelen > *width)? linelen:*width;
        i++;
    }
    *height = i;
    fclose(stream);
    return raw_map;
}

#include <signal.h>
int main() {
    int height;
    int width;
    char *fp = "/Users/Klas/Git/my-projects/jump-squad/levels/special/world_1_1";
    char **raw_map = read_map(fp, &height, &width);
    int i;
    int j;
    printf("height: %d\n", height);
    for(i = 0; i < height; i++) {
        for(j = 0; j < 16; j++) {
            printf("%c", raw_map[i][j]);
        }
        printf("\n");
    }
}
