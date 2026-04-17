#include <stdio.h>
#include "project_version.h"

int main(void)
{
    printf("Version:  %s\n", PROJECT_VERSION);
    printf("Build ID: %s\n", PROJECT_BUILD_ID);
    printf("Git Hash: %s\n", PROJECT_GIT_HASH);
    return 0;
}
