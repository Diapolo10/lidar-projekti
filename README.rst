LiDAR-projekti
==============

An Arduino project that measures distances using a LiDAR sensor.

Features
--------

- Reads LiDAR data via UART
- Stores to and reads measurement unit configuration from EEPROM
- Unit can be changed via a button
- An RGB LED displays the current measurement unit
    * Green: centimetres
    * Yellow: millimetres
    * Red: Pixhawk-drone internal units
- [UNIMPLEMENTED] Measures battery level via voltage tracking
- Sends output to external USART

Hardware requirements
*********************

- Arduino Every (x1)
- TFMini Plus -LiDAR sensor (x1)
- Push button (x1)
- RGB LED or equivalent (x1)
- Wires

For the pin layout, please see the source code or documentation for the pin numbers.

Installation
------------

You can either run the source code via
AVRdude yourself, or build it with PlatformIO.
For the latter, a configuration file is provided
within the repository itself for your convenience.

-------------------------------------------------------------------------------

Contribute
----------

- `Issue tracker`_
- `Source Code`_
- `Documentation`_

Support
-------

If you are having issues, please let us know by
writing an issue report on GitHub.

License
-------

The project is licensed under the permissive `MIT License`_.

.. ---------------------------------- Links -----------------------------------
.. _`Issue Tracker`: github.com/Diapolo10/lidar-projekti/issues
.. _`Source Code`: github.com/Diapolo10/lidar-projekti
.. _`Documentation`: lidar-projekti.readthedocs.io/en/latest/
.. _`MIT License`: ./LICENSE
