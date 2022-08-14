// interpreter for bash language
// Author: Takahashi Akari <akaritakahashioss@gmail.com>
// Date: 2022/08/14
// Version: 0.0.1
// License: MIT License copyright (c) 2022 Takahashi Akari
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the MIT License.
// You can get a copy of the MIT License at <https://opensource.org/licenses/MIT>.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the MIT License for more details.
//
// You should have received a copy of the MIT License along with this program.
// If not, see <https://opensource.org/licenses/MIT>.
//
//=============================================================================


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *exec_command(char *command) {
    FILE *fp;
    char *result;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    fp = popen(command, "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        exit(1);
    }
    while ((read = getline(&line, &len, fp)) != -1) {
        result = line;
    }
    pclose(fp);
    if (line) {
        free(line);
    }

    if (result) {
        *result = '\0';
    }

    return result;
}

void interactive_exec() {
    char *command;
    char *result;
    printf("$ ");
    while (1) {
        command = malloc(sizeof(char) * 1024);
        fgets(command, 1024, stdin);
        if (strcmp(command, "exit\n") == 0) {
            break;
        }
        result = exec_command(command);
        if (result != NULL) {
            printf("%s\n", result);
        }
        free(command);
        printf("$ ");
    }
}

int main() {
    interactive_exec();
    return 0;
}