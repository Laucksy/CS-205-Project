#include "baseclass.h"

// Initialize the static variable that tracks
// number of objects created.
int BaseClass::id_cnt = 0;
BaseClass::BaseClass()
{

    // Uniquely identify the object.
    id = id_cnt;

    // Increment the created object count.
    id_cnt++;
}
