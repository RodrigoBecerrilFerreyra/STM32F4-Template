# STM32F4 Nucleo/Black Pill Bare Metal Project Template

This repository serves as a template for starting projects with the STM32F4
family of microcontrollers, including support for the
[Nucleo-F411RE](https://www.st.com/en/evaluation-tools/nucleo-f411re.html) and
[Nucleo-F401RE](https://www.st.com/en/evaluation-tools/nucleo-f401re.html)
boards, plus the popular Black Pill boards running the
[STM32F411CE](https://www.st.com/en/microcontrollers-microprocessors/stm32f411ce.html) and
[STM32F401CC](https://www.st.com/en/microcontrollers-microprocessors/stm32f401cc.html)
microcontrollers. Much of the template can be modified to fit
most STM32-series microcontrollers and NUCLEO evaluation boards.
All files in the CMSIS folder are found in the following repositories:

 - https://github.com/STMicroelectronics/STM32CubeF4
 - https://github.com/STMicroelectronics/cmsis_device_f4

# How to Use

To make use of this template, you must configure the settings for your board/MCU
in `Makefile`.

```
# Define the linker script location and chip architecture.
LD_SCRIPT = $(CMSIS_DIR)/
STARTUP_FILE = $(CMSIS_DIR)/
CHIP_NUMBER = 
# Find the Chip Number in CMSIS/stm32f4xx.h lines 127-172
```

For example, the settings for the F411 Black Pill would be:

```
LD_SCRIPT = $(CMSIS_DIR)/blackpill_STM32F411CE.ld
STARTUP_FILE = $(CMSIS_DIR)/startup_stm32f411xe.s
CHIP_NUMBER = STM32F411xE
```

For the F401 Black Pill:
```
LD_SCRIPT = $(CMSIS_DIR)/blackpill_STM32F401CC.ld
STARTUP_FILE = $(CMSIS_DIR)/startup_stm32f401xc.s
CHIP_NUMBER = STM32F401xC
```

**Make sure to double-check the RAM and ROM sizes for your microcontroller by
consulting the official ST datasheet.** Only YOU are responsible for the safety
of your microcontroller.

All your header files go under `inc/`, and all your source files go under
`src/`. Make sure to add every `.c` file you have to the Makefile by appending
to the `C_SRC` variable.

Then simply run `make`. You can run `make flash` if you are programming your
microcontroller through an ST-LINK interface. By default, it requires
[stlink](https://github.com/stlink-org/stlink) to be installed. Otherwise, feel
free to replace `make flash` with however you flash your device.

Happy programming!

# Licensing

All files found in the CMSIS folder are licensed under the
[Apache License, Version 2.0](https://www.apache.org/licenses/LICENSE-2.0)
(included as LICENSE-2.0.txt).

All other files have their licenses written within them. In case of a missing
license, the file is licensed under the
[GNU All-Permissive License](https://www.gnu.org/prep/maintain/html_node/License-Notices-for-Other-Files.html).
