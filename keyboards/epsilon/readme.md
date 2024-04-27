# Epsilon
![epsilon](epsilon.jpg)
42 key split keyboard, based on and inspired by the Cantor, Ferris Sweep, and Corne keyboards.

## Hardware and build guide
See [slideclimb/epsilon](https://github.com/slideclimb/epsilon/blob/master/README.md#build-guide).

## Firmware

### Compiling and flashing

1. Set up QMK (don't forget the [udev rules](https://github.com/qmk/qmk_firmware/blob/master/docs/faq_build.md#linux-udev-rules-idlinux-udev-rules) if on linux).
2. Compile the keymap with `make epsilon:default`.
3. Connect the keyboard in bootloader mode.
4. Flash the keymap with `make epsilon:default:flash`.

> [!CAUTION]
> Never connect or disconnect the TRRS cable while the keyboard is plugged in with the USB.
> Doing so might damage the controller.
 
> [!TIP]
> Create a Makefile run configuration so you can start the flash with the mouse while the keyboard is in bootloader mode.
> Use the following settings:
> - Makefile: `<path_to_qmk_repo>/qmk_firmware/Makefile`
> - Arguments: `epsilon:default:flash`
> - Working Directory: `<path_to_qmk_repo>/qmk_firmware`

When updating the layout afterward it's [often](https://docs.keeb.io/flashing-firmware/#do-i-need-to-flash-both-halves-of-a-split-keyboard) enough to only flash the half connected with USB (the left half).

### Blackpill bootloader
Blackpills are known to be possibly problematic to get into bootloader mode the first time.
First, try the following:

1. Connect the Blackpill to the computer with a USB cable.
2. Press and hold the BOOT0 button.
3. Press and release the NRST button.
4. Release the BOOT0 button.
5. Check if the keyboard is in bootloader mode, e.g. with `dfu-util`.

If this doesn't work (it didn't for me on both of the Blackpills) then try steps 2-4 while connecting pin `A10` to `GND`.
After flashing the firmware once, getting into the bootloader should be much easier thanks to bootmagic.
When flashing the left half, hold the top-left key and then plug in the USB cable.
Hold the top-right key when flashing the right half.