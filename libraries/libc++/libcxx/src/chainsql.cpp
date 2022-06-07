#pragma once

/**
 * Define specific things for the chainsql system
 */

extern "C" {
   void chainsql_assert(unsigned int, const char*);
   void __cxa_pure_virtual() { chainsql_assert(false, "pure virtual method called"); }
}
