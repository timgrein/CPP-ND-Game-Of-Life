#include <Utils.h>

#include <random>

int Utils::GetRandomOneOrZero() {
    return rand() % 2;
}
