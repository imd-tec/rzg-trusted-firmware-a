#include "pmic_table.h"
#include <assert.h>
#include <common/debug.h>
#include <riic.h>
#include <stddef.h>
#define PMIC (0x12)

void plat_pmic_setup(void) {
  INFO("Programming PMIC registers \n");
  riic_setup();

  for (int i = 0; i < sizeof(PMIC_TABLE); i++) {
    INFO("Programming register 0x%x with value 0x%x \n  ", i, PMIC_TABLE[i]);
    riic_write(PMIC, i, PMIC_TABLE[i]);
  }
}
