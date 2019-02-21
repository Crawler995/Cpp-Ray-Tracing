#include "utils.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>

void update_progress(std::string& progress_char) {
    progress_char += "#";
    printf("\r[%-50s] [%d%%]", progress_char.c_str(), progress_char.length() * 2);
}

double rand_num_0_to_1() {
    return rand() % 1000 / 1000.0;
}