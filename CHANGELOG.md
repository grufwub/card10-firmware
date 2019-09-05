# Changelog
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/).

## [Unreleased]


## [v1.10] - 2019-09-05 21:42 - [JerusalemArtichoke]
[JerusalemArtichoke]: https://card10.badge.events.ccc.de/release/card10-v1.10-JerusalemArtichoke.zip

### Added
- **ws2812**: Connect Neopixels to the wristband GPIOs and make your card10
  even more colorful!
- DigiClk is now in the default prelude!
- High-pass filter and pulse detection in default ECG app.
- Actually added `uuid` module - it was not built into the firmware before,
  by accident.
- `leds.get_rgb()`: Get the current color of an LED.
- `leds.get_rocket()`: Get the current brightness of one of the rockets.
- `micropython.mem_use()` function.
- The analog-clock can now also set the time using the buttons.

### Changed
- **Pycardium**: Switched from `long-long` to `mpz` integer representation.
  This should resolve any issues with large numbers which had popped up so far.
- Refactored BME680 sensor interface.
- Made OpenOCD scripts work with more debuggers out of the box.
- Internal changes in preparation for button-interrupts.

### Fixed
- Backlight and Vibration motor were not reset when switching apps.
- Mismatch in default settings of the *Card10 Nickname* app.
- Fixed the PMIC ADC muxer not being properly reset to neutral after a
  measurement.
- Fixed wrong timezone offset calculation in `utime.time_ms()`.
- Fixed bug where `\` characters were not parsed as path separators.
- Fixed the alignment request check in our ELF l0der.
- Fixed a buffer-overflow in the config-parser.


## [v1.9] - 2019-08-28 23:23 - [IcebergLettuce]
[IcebergLettuce]: https://card10.badge.events.ccc.de/release/card10-v1.9-IcebergLettuce.zip

### Added
- `tools/pycard10.py`: Tool to interact with card10's serial connection and
  upload files directly:
  ```bash
  ./tools/pycard10.py path/to/python-script.py
  ```
- `epic_disp_print_adv` & `Display.print(font=...)`: Print with different
  fonts!  The following fonts are supported: `8px`, `12px`, `16px`, `20px`,
  and `24px`.
- **pycardium**: Support for RAW REPL mode.
- **bhi160**: Function to disable all sensors (`bhi160.disable_all_sensors()`).
- `ls_cmsis_dap`: A tool to enumerate CMSIS-DAP debuggers.
- Tons of new features to `simple_menu`: Timeout, scrolling of long texts,
  robustness against crashes, and proper exiting.
- `card10.cfg` config file which allows enabling *ELF* files.
- Analog read for wristband GPIOs.

### Changed
- Refactored *menu* and *personal-state* apps.
- `main.py` was moved into an app to allow easier reconfiguration of the
  default app.  The new `main.py` points to the "old" one so behavior is not
  changed.
- After a timeout, the menu will close and `main.py` will run again.
- BLE security updates.
- More detailed battery state display in nickname app.
- Improved ECG app.

### Removed
- Some unused font files.

### Fixed
- Fixed a regression which made the ECG app no longer work.
- Fixed card10 advertising support for AT-commands.
- Rectangles being one pixel too small.



## [v1.8] - 2019-08-27 11:38 - [HabaneroChilli]
[HabaneroChilli]: https://card10.badge.events.ccc.de/release/card10-v1.8-HabaneroChilli.zip

### Added
- API-call for direct light-sensor readout: `epic_light_sensor_read`.
- Pause mode in ECG-App.
- `bin` field in metatdata for an alternate entrypoint.
- `shell.nix`: Nix-Shell which installs patched OpenOCD and dependencies.
- Cool LED animation in default ECG app.

### Changed
- No longer require locking the display for setting the backlight.


## [v1.7] - 2019-08-24 21:48 - [Garlic]
[Garlic]: https://card10.badge.events.ccc.de/release/card10-v1.7-Garlic.zip

### Added
- **ESB**: Epic Serial Bus (Better than USB!), stability improvements of the
  USB module.  Preparation for mass-storage access in the Firmware.
- Enabled the Hardware Watchdog;  Card10 will reset itself if the firmware crashes
- Log messages when BLE is pairing / connected.
- The name of the offending app is printed to the serial console, if an app
  crashes the metatdata parser.

### Changed
- Improved log messages in cases of lock-contention.
- Menu will show an error message if a crash occurs.

### Fixed
- Fixed race-conditions in serial writes by using a queue.
- "Card10 Nickname" crashing if only `nickname.txt` exists.
- Lockup when debug prints are enabled.
- Delayed BHI160 startup a bit so the PMIC task can check the battery first.
- Relaxed the PMIC lock-timeouts so other task can take a little more time.
- Fixed off-by-one error in `gfx_line()`.
- Fixed the API interrupts sometimes getting stuck.
- Fixed binary building on MacOS.
- Fixed race-conditions in serial console prints by introducing a queue.
- Fixed API & MAX30001 mutexes being initialized late sometimes.
- Fixed wrong stripe width in bi flag.


## [v1.6] - 2019-08-23 20:30 - [Fennel]
[Fennel]: https://card10.badge.events.ccc.de/release/card10-v1.6-Fennel.zip

- Maxim BLE SDK update

### Added
- **BLE**: Added personal state API to card10 SVC.
- **ECG**: Support for ECG + Python app
- **BLE**: Characteristic to read the time

### Changed
- Improved performance of circle-drawing algorithm.

### Fixed
- Removed a debug print in the `bhi160` module.


## [v1.5] - 2019-08-23 00:18 - [Eggppppplant]
[Eggppppplant]: https://card10.badge.events.ccc.de/release/card10-v1.5-Eggppppplant.zip

### Added
- **bootloader**: Add an error message when flashing fails.
- **display**: Option to set backlight from Python
- **utime**: Function to read time in ms from Python

### Changed
- **gpio**: Rename constants for consistency.
- **ble**: Storing pairings outside BLE stack context
- **security**: Disable ELFs by default, prevent access to some more files

### Fixed
- **gpio**: Fix field-setting in `gpio_cfg_t`.


## [v1.4] - 2019-08-22 19:43 - [DaikonRadish]
[DaikonRadish]: https://card10.badge.events.ccc.de/release/card10-v1.4-DaikonRadish.zip

### Added
- Support for the `bme680` environmental sensor.
- Support for the `bhi160` sensor fusion.
- `simple_menu` module for creating simple menus in Python.
- `power` module to access the voltage and current measurements from the PMIC.
- Support for color themes in the default clock script:
  Color themes are read from a json file, so people can customize their clock.
  Last selected theme is saved in the `clock.json` so it is persistent.

### Changed
- Refactored BLE card10 service.
- Improved BLE file-transfer (added security).
- Replaced dynamic attribute creation with static attributes.

### Fixed
- Fixed menu listing files starting with `.`.
- Fixed `utime.set_time()` applying the timezone offset in the wrong direction.
- Fixed the PMIC driver not releasing some locks properly.


## [v1.3] - 2019-08-22 00:12 - [CCCauliflower]
[CCCauliflower]: https://card10.badge.events.ccc.de/release/card10-v1.3-cccauliflower.zip

### Added
- A splashscreen in Epicardium showing the version number.
- `os.urandom()` function.

### Changed
- BLE file-transfers now create missing folders.

### Fixed
- **gfx**: Add a linebreak before character, not after.  This prevent the last
  character being cut off.
- Fixed serial task overflowing because it had a too small stack size.
- Removed confusing MAXUSB messages.


## [v1.2] - 2019-08-21 18:18 - [Broccoli]
[Broccoli]: https://card10.badge.events.ccc.de/release/card10-v1.2-broccoli.zip

```text
8e8d8614 feat(apps): Add scope to preload
e1a7684a fix(cdcacm): Disable before printing error
4c74f061 fix(utime.c): set_time should operate in local tz
e0824843 feat(pmic): Switch off if battery is low
46ef3985 feat(pmic): Add API-call to read battery voltage
79e2fb15 feat(epicardium): Periodically check the battery voltage
5da9e074 feat(pmic): Implement AMUX reading
8c59935e py: timezone workaround
c7f59d3e fix(text_reader): Convert to unix line-endings
78a7a7f4 docs: Fix underlines in ble/card10
15649293 feat(app): Add some preloads
b12e4ef9 chore(docs): Fix utime module docs
3efbab13 feat(utime.c): add python functions to set time
38f83243 chore(docs): Fix color documentation
a966e221 chore(docs): Fix python-directives with double-module
66cd10d4 docs: Document os.reset()
5fe5fe31 docs: Document pride module
338132e5 apped apps folder to search module search path
cda91555 rename Main Clock to Home
c2935c8c fixed syntax
3017591a Rename preloaded apps to make use of hatchery folder structure
842e9ad8 feat(menu.py): support scrolling for long menu entries
fbf7c8c0 fix(menu.py) Refactored menu.py based on !138
8aa8c31f feat(ble): Store bondings
5e5c7a4f fix(menu.py): Fix color-mismatch of selector background
```

## [v1.1] - 2019-08-21 03:14 - Asparagus
### Added
- Seed ``urandom`` PRNG with ``TRNG`` peripheral.
- Show linenumbers in MicroPython tracebacks.

### Fixed
- **buttons**: Acquire lock before accessing I2C.
- **rtc**: Fix RTC getting stuck because of improper initialization.
- Make lifecycle task more important than dispatcher.

## [v1.0] - 2019-08-21 00:50
Initial release.

[Unreleased]: https://git.card10.badge.events.ccc.de/card10/firmware/compare/v1.10...master
[v1.10]: https://git.card10.badge.events.ccc.de/card10/firmware/compare/v1.9...v1.10
[v1.9]: https://git.card10.badge.events.ccc.de/card10/firmware/compare/v1.8...v1.9
[v1.8]: https://git.card10.badge.events.ccc.de/card10/firmware/compare/v1.7...v1.8
[v1.7]: https://git.card10.badge.events.ccc.de/card10/firmware/compare/v1.6...v1.7
[v1.6]: https://git.card10.badge.events.ccc.de/card10/firmware/compare/v1.5...v1.6
[v1.5]: https://git.card10.badge.events.ccc.de/card10/firmware/compare/v1.4...v1.5
[v1.4]: https://git.card10.badge.events.ccc.de/card10/firmware/compare/v1.3...v1.4
[v1.3]: https://git.card10.badge.events.ccc.de/card10/firmware/compare/v1.2...v1.3
[v1.2]: https://git.card10.badge.events.ccc.de/card10/firmware/compare/v1.1...v1.2
[v1.1]: https://git.card10.badge.events.ccc.de/card10/firmware/compare/v1.0...v1.1
[v1.0]: https://git.card10.badge.events.ccc.de/card10/firmware/-/tags/v1.0
