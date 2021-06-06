#include <utils/Utils.h>

#include <random>

int Utils::GetRandomOneOrZero() {
    return rand() % 2;
}
